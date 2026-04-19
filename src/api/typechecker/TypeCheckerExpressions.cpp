#include "api/typechecker/TypeChecker.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {
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
        "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
          tempFuncType->getName(),
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
      
      // TODO: handle type coercions
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

    Type* arrayType = std::any_cast<Type*>(this->visit(ctx->array));
    Type* indexType = std::any_cast<Type*>(this->visit(ctx->index));

    Type* asPointerType = arrayType->as<Pointer>();
    Type* voidPointer = Pointer::get(this->M_currentScope->resolve("void")->as<Struct>(), 1);

    bool ok = true;
    if(
      asPointerType == nullptr
      or asPointerType == Struct::getErrorType()
      or asPointerType == voidPointer
    ) {
      ok = false;
      this->errorAt(
        ctx->array->getStart(),
        "Array expression '{}' of type '{}' is not a valid array or pointer that can be dereferenced."_f.format(
          ctx->array->getText(),
          arrayType->getName()
        )
      );
    }

    // TODO: handle type coercions
    if(indexType != this->M_currentScope->resolve("int")->as<Struct>()) {
      ok = false;
      this->errorAt(
        ctx->index->getStart(),
        "Array subcript index expression '{}' of type '{}' is not convertible to int. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f.format(
          ctx->index->getText(),
          indexType->getName()
        )
      );
    }

    return (Type*)(ok ? arrayType->as<Pointer>()->getPointedType() : (Type*)Struct::getErrorType());
  }

  auto TypeChecker::visitBinary(FridayParser::BinaryContext *ctx) -> std::any {
    Console::debug("BinaryContext: {}"_f.format(ctx->getText()));

    Type* lhsType = std::any_cast<Type*>(this->visit(ctx->left));
    Type* rhsType = std::any_cast<Type*>(this->visit(ctx->right));
    u64 oper = ctx->binaryOperator->getType();

    String binaryOperatorName = Type::getBinaryOperatorName(oper, lhsType, rhsType);
    String suggestion = "";

    // TODO handle pointer and function types (?)
    if(lhsType->is<Struct>() and rhsType->is<Struct>()) {
      if(lhsType == rhsType) {
        if(const Function* binaryOperator = lhsType->as<Struct>()->getMethod(binaryOperatorName)) {
          return (Type*)binaryOperator->getType()->as<const FunctionType>()->getReturnType();
        }
      } else suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
    }

    this->errorAt(
      ctx->binaryOperator,
      "No matching function for call to '{}' with operands of types '{}' and '{}'.{}"_f.format(
        binaryOperatorName,
        lhsType->getName(),
        rhsType->getName(),
        suggestion
      )
    );

    return (Type*)Struct::getErrorType();
  }

  auto TypeChecker::visitUnary(FridayParser::UnaryContext *ctx) -> std::any {
    Console::debug("UnaryContext: {}"_f.format(ctx->getText()));

    Type* type = std::any_cast<Type*>(this->visit(ctx->expr()));
    u64 oper = ctx->unaryOperator->getType();
    String unaryOperatorName = Type::getUnaryOperatorName(oper, type);

    // TODO handle pointer and function types (?)
    if(Struct* asStruct = type->as<Struct>()) {
      if(const Function* unaryOperator = asStruct->getMethod(unaryOperatorName)) {
        return (Type*)unaryOperator->getType()->as<const FunctionType>()->getReturnType();
      }
    }

    this->errorAt(
      ctx->unaryOperator,
      "No matching function for call to '{}' with operand of type '{}'"_f.format(
        unaryOperatorName,
        type->getName()
      )
    );
    
    return (Type*)Struct::getErrorType();
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

}