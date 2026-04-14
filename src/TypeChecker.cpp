#include "api/typechecker/TypeChecker.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {

  /**
   * - structs (tipi fondamentali sono struct)
   * - fields
   * - member functions
   * - functions
   * - variables
   * - interfaces (rust's traits)
   * - overloading & operator overloading
   * - generics
   * - functions & types first class citizens
   * - anonymous structs (zig's tuples)
   * - reflection
   */

  TypeChecker::TypeChecker(TranslationUnit& unit) noexcept
    : M_unit { &unit }
    , M_currentScope { &M_globalScope }
  {
    llvm::LLVMContext& ctx = unit.getModule()->getContext();
    llvm::Module& mod = *unit.getModule();
    this->M_globalScope = SymbolTable::builtins(mod);

    this->M_voidType = (Struct*)this->M_globalScope.resolve("void");
    this->M_intType = (Struct*)this->M_globalScope.resolve("int");
    this->M_floatType = (Struct*)this->M_globalScope.resolve("float");
    this->M_byteType = (Struct*)this->M_globalScope.resolve("byte");
    this->M_boolType = (Struct*)this->M_globalScope.resolve("bool");
  }

  auto TypeChecker::checkType(Struct* expected, std::any actual) -> bool {
    return actual.has_value() 
    and actual.type() == typeid(expected) 
    and std::any_cast<Struct*>(actual) == expected;
  }
  
  auto TypeChecker::check() -> Vector<SyntaxError> {
    auto result = this->visit(this->M_unit->getParseTree());
    /// TODO: do something with 'result'

    return this->M_errors;
  }

  auto TypeChecker::visitProgram(FridayParser::ProgramContext *ctx) -> std::any {
    Console::debug("ProgramContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any {
    Console::debug("TopLevelStatementContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any {
    Console::debug("ReturnStatementContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any {
    Console::debug("PrintStatementContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitStatement(FridayParser::StatementContext *ctx) -> std::any {
    Console::debug("StatementContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitBlock(FridayParser::BlockContext *ctx) -> std::any {
    Console::debug("BlockContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }
  
  auto TypeChecker::visitInlineBlock(FridayParser::InlineBlockContext *ctx) -> std::any {
    Console::debug("InlineBlockContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any {
    Console::debug("FunctionStatementContext : {}"_f.format(ctx->getText()));

    const auto visitor = [this](FridayParser::TypeContext* ctx) { return visitType(ctx); };
    const auto name = ctx->name->getText();

    bool ok = true;
    if(this->M_currentScope->isDefined(name)) {
      this->errorAt(
        ctx->name,
        "Redefinition of symbol '{}'"_f.format(name)
      );
      ok = false;
    }

    const auto paramsNames = ctx->paramsNames
    | std::views::transform(ant::Token::getText)
    | std::ranges::to<std::vector>();

    const auto types = ctx->paramsTypes
    | std::views::transform(visitor)
    | std::ranges::to<std::vector>();

    for(u64 i = 0; i < ctx->paramsNames.size(); ++i) {
      const auto paramType = ctx->paramsTypes[i];

      if(checkType(Struct::getErrorType(), types[i])) {
        this->errorAt(
          paramType->getStart(), 
          "Parameter #{} '{}' has an invalid <error-type> parameter type '{}'"_f.format(
            i+1, paramsNames[i], paramType->getText()
          )
        );
        ok = false;
      }
    }

    const auto retInfo = visitType(ctx->returnType);

    if(checkType(Struct::getErrorType(), retInfo)) {
      ok = false;
      this->errorAt(
        ctx->returnType->getStart(),
        "Invalid <error-type> return type '{}'"_f.format(
          ctx->returnType->getText()
        )
      );
    }
    
    if(not ok) return Struct::getErrorType();
    ok = true;

    // this->M_currentScope->define(name, new Function(name, ));
    // SymbolTable functionScope { M_currentScope };
    // this->M_currentScope = &functionScope;

    // for(u64 i = 0; i < paramsNames.size(); ++i) {
    //   auto const& paramName = paramsNames[i];
    //   auto paramType = funcType->getParamType(i);

    //   if(this->M_currentScope->isDefined(paramName)) {
    //     this->errorAt(
    //       ctx->paramsNames[i],
    //       "Redefinition of symbol '{}' at parameter #{}"_f.format(paramName, i+1)
    //     );
    //     ok = false;
    //   } else {
    //     llvm::Argument* arg = function->getArg(i);
    //     arg->setName(paramName);
    //     this->M_currentScope->define(paramName, arg);
    //   }
    // }

    // const auto actualRetInfo = this->visit(ctx->block() != nullptr ? (ant::tree::ParseTree*)ctx->block() : (ant::tree::ParseTree*)ctx->inlineBlock());


    // this->M_currentScope = this->M_currentScope->getParent();
    // return ok ? this->M_voidType : Struct::getErrorType();
    return (Struct*)nullptr;
  }

  auto TypeChecker::visitCall(FridayParser::CallContext *ctx) -> std::any {
    Console::debug("CallContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitPrimary(FridayParser::PrimaryContext *ctx) -> std::any {
    Console::debug("PrimaryContext : {}"_f.format(ctx->getText()));
    // llvm::Type* exprType = Struct::getErrorType();

    // if(ctx->FLOAT_LIT() != nullptr) exprType = this->M_floatType;
    // else if(ctx->INT_LIT() != nullptr) exprType = this->M_intType;
    // else if(ctx->CHAR_LIT() != nullptr) exprType = this->M_byteType;
    // else if(ctx->STRING_LIT() != nullptr) exprType = this->M_byteType->getPointerTo();
    // else if(ctx->BOOL_LIT() != nullptr) exprType = this->M_boolType;
    // else if(ctx->NULL_LIT() != nullptr) exprType = this->M_voidType->getPointerTo();
    // else if(auto id = ctx->IDENTIFIER()) {
    //   auto name = id->getText();
    //   if(auto value = this->M_currentScope->resolveValue(name)) {
    //     exprType = value->getType();
    //   } else {

    //     constexpr auto toSuggestion = [](String const& s) {
    //       return ", did you mean '{}' ?"_f.format(s);
    //     };

    //     auto mostSimilarValue = this->M_currentScope
    //     ->mostSimilarValue(name, 3)
    //     .transform(toSuggestion)
    //     .value_or("");

    //     this->errorAt(
    //       id->getSymbol(),
    //       "There is no variable or function named '{}' in the current scope{}"_f.format(name, mostSimilarValue)
    //     );
    //   }
    // }

    // return exprType;
    return (Struct*)nullptr;
  }

  auto TypeChecker::visitGrouping(FridayParser::GroupingContext *ctx) -> std::any {
    Console::debug("GroupingContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any {
    Console::debug("SubscriptContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::visitBinary(FridayParser::BinaryContext *ctx) -> std::any {
    Console::debug("BinaryContext : {}"_f.format(ctx->getText()));

    return visitChildren(ctx);
  }

  auto TypeChecker::visitUnary(FridayParser::UnaryContext *ctx) -> std::any {
    Console::debug("UnaryContext : {}"_f.format(ctx->getText()));

    auto exprType = this->visit(ctx->expr());
    auto oper = ctx->unaryOperator;

    if(checkType(Struct::getErrorType(), exprType)) {
      this->errorAt(
        ctx->expr()->getStart(),
        "No matching unary operator '{}' with operand of type <error-type>"_f.format(
          oper->getText()
        )
      );
      return Struct::getErrorType();
    }

    auto type = toType(exprType);
    return (Struct*)nullptr;
  }

  auto TypeChecker::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any {
    Console::debug("SimpleTypeContext : {}"_f.format(ctx->getText()));
    const auto symbol = ctx->IDENTIFIER()->getSymbol();
    const auto name = symbol->getText();

    auto type = this->M_currentScope->resolve(name, Struct::getErrorType())->as<Struct>();
    if(type != Struct::getErrorType()) {
      constexpr auto toSuggestion = [](String const& s) {
        return " did you mean '{}' ?"_f.format(s);
      };

      auto mostSimilarType = this->M_currentScope
      ->mostSimilar(name, 3, &Symbol::is<Struct>)
      .transform(toSuggestion)
      .value_or("");

      this->errorAt(
        symbol,
        "There is no type named '{}'{}"_f.format(name, mostSimilarType)
      );
      return Struct::getErrorType();
    }

    return (Struct*)this->M_currentScope->resolve(name);
  }

  auto TypeChecker::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any {
    Console::debug("FunctionTypeContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }
  
  auto TypeChecker::visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any {
    Console::debug("PointerTypeContext : {}"_f.format(ctx->getText()));

    const auto dims = ctx->STAR().size();
    const auto info = visitChildren(ctx);

    if(checkType(Struct::getErrorType(), info)) {
      this->errorAt(
        ctx->getStart(), 
        "Invalid <error-type> pointer type '{}'"_f.format(ctx->getText())
      );
      return Struct::getErrorType();
    }

    return Struct::getErrorType();
  }

  auto TypeChecker::visitType(FridayParser::TypeContext *ctx) -> std::any {
    Console::debug("TypeContext : {}"_f.format(ctx->getText()));
    return visitChildren(ctx);
  }

  auto TypeChecker::toType(std::any info) -> Struct* {
    if(info.has_value() and info.type() == typeid(Struct*)) {
      return std::any_cast<Struct*>(info);
    } else throw OperationNotSupportedError{
      "Bad type in TypeChecker::toType() : expected \"Struct*\" but got \"{}\""_f
      .format(Type(info.type()).name())
    };
    return Struct::getErrorType();
  }

  auto TypeChecker::errorAt(ant::Token* token, String message) -> void {

    this->M_errors.push_back(
      SyntaxError{
        SourceLocation {
          this->M_unit->getPath().generic_string(),
          token->getLine(),
          token->getCharPositionInLine()+1
        }, 
        std::move(message) 
      }
    );
  }

}