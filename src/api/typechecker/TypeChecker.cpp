#include "api/typechecker/TypeChecker.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {

  TypeChecker::TypeChecker(TranslationUnit& unit) noexcept
    : M_unit { &unit }
    , M_currentScope { nullptr }
  {
    llvm::LLVMContext& ctx = unit.getModule()->getContext();
    llvm::Module& mod = *unit.getModule();
  }

  auto TypeChecker::check() -> Vector<SemanticError> {
    auto result = this->visit(this->M_unit->getParseTree());
    /// TODO: do something with 'result'

    return this->M_errors;
  }
  
  auto TypeChecker::errorAt(ant::Token* token, String message) -> void {

    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_unit->getPath().generic_string(),
          token->getLine(),
          token->getCharPositionInLine()+1
        }, 
        std::move(message) 
      }
    );
  }

  auto TypeChecker::beginScope(SymbolTable& scope) noexcept -> void {
    this->M_currentScope = &scope;
  }

  auto TypeChecker::endScope() noexcept -> void {
    this->M_currentScope = this->M_currentScope->getParent();
  }

  auto TypeChecker::visitProgram(FridayParser::ProgramContext *ctx) -> std::any {
    Console::debug("ProgramContext: {}"_f.format(ctx->getText()));

    SymbolTable globalScope = SymbolTable::builtins(*this->M_unit->getModule());
    
    this->beginScope(globalScope);
    std::any result = this->visitChildren(ctx);
    this->endScope();

    return std::move(result);
  }

  auto TypeChecker::visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any {
    Console::debug("TopLevelStatementContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any {
    Console::debug("ReturnStatementContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any {
    Console::debug("PrintStatementContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitStatement(FridayParser::StatementContext *ctx) -> std::any {
    Console::debug("StatementContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitBlock(FridayParser::BlockContext *ctx) -> std::any {
    Console::debug("BlockContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitInlineBlock(FridayParser::InlineBlockContext *ctx) -> std::any {
    Console::debug("InlineBlockContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any {
    Console::debug("FunctionStatementContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitCall(FridayParser::CallContext *ctx) -> std::any {
    Console::debug("CallContext: {}"_f.format(ctx->getText()));

    auto byVisiting = [this](FridayParser::ExprContext* ctx) -> std::any {
      return this->visit(ctx);
    };

    constexpr auto toType = (Type*(*)(std::any const&))&std::any_cast<Type*>;

    auto tempFuncType = std::any_cast<Type*>(this->visit(ctx->func));
    if(tempFuncType == Struct::getErrorType() or not tempFuncType->is<FunctionType>()) {
      this->errorAt(
        ctx->getStart(),
        "The underlined expression '{}' is not a function and cannot be called."_f.format(
          ctx->func->getText()
        )
      );
      return (Type*)Struct::getErrorType();
    }

    auto funcType = (FunctionType*)tempFuncType;

    auto argsTypes = ctx->args
    | std::views::transform(byVisiting)
    | std::views::transform(toType)
    | std::ranges::to<std::vector>();

    bool ok = true;
    if(funcType->getParametersCount() != argsTypes.size()) {
      ok = false;
      this->errorAt(
        ctx->RIGHT_PAREN()->getSymbol(),
        "In function call '{}' of type '{}' : the function expects {} arguments but {} where given."_f.format(
          ctx->func->getText(),
          funcType->getName(),
          funcType->getParametersCount(),
          argsTypes.size()
        )
      );
    }
    
    for(u64 i = 0; i < std::min(argsTypes.size(), funcType->getParametersCount()); i++) {
      Type* T = argsTypes[i];
      
      // TODO handle type coercions
      if(T != funcType->getParameterType(i)) {
        ok = false;
        this->errorAt(
          ctx->args[i]->getStart(),
          "In function call '{}' of type '{}' : argument type mismatch. Expected '{}', got '{}'"_f.format(
            ctx->getText(),
            funcType->getName(),
            funcType->getParameterType(i)->getName(),
            T->getName()
          )
        );
      }
    }
  
    return (Type*)(ok ? funcType->getReturnType() : (Type*)Struct::getErrorType());
  }

  auto TypeChecker::visitIdentifier(FridayParser::IdentifierContext *ctx) -> std::any {
    Console::debug("IdentifierContext: {}"_f.format(ctx->getText()));
    
    auto isVariableOrFunction = [](Symbol* symbol) -> bool {
      return symbol->is<Variable>() or symbol->is<Function>();
    };
    
    String id = ctx->IDENTIFIER()->getText();
    Symbol* symbol = this->M_currentScope->resolveIf(id, isVariableOrFunction);

    bool ok = true;
    if(symbol == nullptr) {
      ok = false;

      auto toSuggestion = [](String const& message) {
        return std::format(" Did you mean '{}'?", message);
      };

      String suggestion = this->M_currentScope->mostSimilar(id, 3, isVariableOrFunction)
      .transform(toSuggestion)
      .value_or("");

      this->errorAt(
        ctx->getStart(),
        "There is no variable or function named '{}' in the current scope.{}"_f.format(
          id,
          suggestion
        )
      );
    }

    return (Type*)(ok ? symbol->getType() : (Type*)Struct::getErrorType());
  }

  auto TypeChecker::visitCharLiteral(FridayParser::CharLiteralContext *ctx) -> std::any {
    Console::debug("CharLiteralContext: {}"_f.format(ctx->getText()));
    return (Type*)this->M_currentScope->resolve("byte")->as<Struct>();
  }

  auto TypeChecker::visitStringLiteral(FridayParser::StringLiteralContext *ctx) -> std::any {
    Console::debug("StringLiteralContext: {}"_f.format(ctx->getText()));
    return (Type*)Pointer::get(
      this->M_currentScope->resolve("byte")->as<Struct>(), 
      1
    );
  }

  auto TypeChecker::visitBoolLiteral(FridayParser::BoolLiteralContext *ctx) -> std::any {
    Console::debug("BoolLiteralContext: {}"_f.format(ctx->getText()));
    return (Type*)this->M_currentScope->resolve("bool")->as<Struct>();
  }

  auto TypeChecker::visitFloatLiteral(FridayParser::FloatLiteralContext *ctx) -> std::any {
    Console::debug("FloatLiteralContext: {}"_f.format(ctx->getText()));
    return (Type*)this->M_currentScope->resolve("float")->as<Struct>();
  }

  auto TypeChecker::visitIntLiteral(FridayParser::IntLiteralContext *ctx) -> std::any {
    Console::debug("IntLiteralContext: {}"_f.format(ctx->getText()));
    return (Type*)this->M_currentScope->resolve("int")->as<Struct>();
  }

  auto TypeChecker::visitGrouping(FridayParser::GroupingContext *ctx) -> std::any {
    Console::debug("GroupingContext: {}"_f.format(ctx->getText()));
    return (Type*)std::any_cast<Type*>(this->visit(ctx->expr()));
  }

  auto TypeChecker::visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any {
    Console::debug("SubscriptContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitBinary(FridayParser::BinaryContext *ctx) -> std::any {
    Console::debug("BinaryContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitUnary(FridayParser::UnaryContext *ctx) -> std::any {
    Console::debug("UnaryContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any {
    Console::debug("SimpleTypeContext: {}"_f.format(ctx->getText()));

    auto id = ctx->IDENTIFIER()->getSymbol();
    
    Type* T = this->M_currentScope->resolveIf(
      id->getText(), 
      &Symbol::is<Struct>,
      (Struct*)Struct::getErrorType()
    )->as<Struct>();

    if(T == Struct::getErrorType()) {
      auto toSuggestion = [](String const& message) {
        return std::format(" Did you mean '{}'?", message);
      };

      String suggestion = this->M_currentScope->mostSimilar(id->getText(), 3, &Symbol::is<Struct>)
      .transform(toSuggestion)
      .value_or("");
      
      this->errorAt(id, "There is no type named '{}' in the current scope.{}"_f.format(
        id->getText(),
        suggestion
      ));
    }

    return (Type*)T;
  }

  auto TypeChecker::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any {
    Console::debug("FunctionTypeContext: {}"_f.format(ctx->getText()));

    auto byVisiting = [this](FridayParser::TypeContext* ctx) {
      return this->visit(ctx);
    };

    constexpr auto toType = (Type*(*)(std::any const&))&std::any_cast<Type*>;

    Type* retType = std::any_cast<Type*>(this->visit(ctx->returnType));
    Vector<Type*> paramsTypes = ctx->paramsTypes
    | std::views::transform(byVisiting)
    | std::views::transform(toType)
    | std::ranges::to<std::vector>();


    bool ok = true;
    for(u64 i = 0; auto T : paramsTypes) {
      if(T == Struct::getErrorType()) {
        ok = false;
        this->errorAt(
          ctx->paramsTypes[i]->getStart(),
          "The function-type '{}' has an invalid parameter-type '{}' for the {}-th parameter"_f.format(
            ctx->getText(),
            ctx->paramsTypes[i]->getText(),
            i+1
          )
        );
      }
      i++;
    }

    if(retType == Struct::getErrorType()) {
      ok = false;
      this->errorAt(
        ctx->returnType->getStart(),
        "The function-type '{}' has an invalid return-type '{}'"_f.format(
          ctx->getText(),
          ctx->returnType->getText()
        )
      );
    }

    return ok ? FunctionType::get(retType, std::move(paramsTypes)) : Struct::getErrorType();
  }

  auto TypeChecker::visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any {
    Console::debug("PointerTypeContext: {}"_f.format(ctx->getText()));
    
    Type* type = std::any_cast<Type*>(this->visit(ctx->pointedType()));
    u64 dimensions = ctx->STAR().size();

    if(type == Struct::getErrorType()) {
      this->errorAt(
        ctx->pointedType()->getStart(), 
        "Cannot form {}-th dimensional pointer '{}' from non-existent pointed-type '{}'"_f.format(
          dimensions,
          ctx->getText(),
          ctx->pointedType()->getText()
        )
      );
    } else type = Pointer::get(type, dimensions);

    return type;
  }

  auto TypeChecker::visitPointedType(FridayParser::PointedTypeContext *ctx) -> std::any {
    Console::debug("PointedTypeContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

  auto TypeChecker::visitType(FridayParser::TypeContext *ctx) -> std::any {
    Console::debug("TypeContext: {}"_f.format(ctx->getText()));
    return this->visitChildren(ctx);
  }

}