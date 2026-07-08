#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  auto TypeChecker::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    Console::debug("CallExpressionContext: {}"_f.format(ctx->getText()));

    constexpr auto toType = (Type*(*)(any const&))&any_cast<Type*>;
    auto candidate = toType(this->visit(ctx->func));

    if(candidate == ErrorType::get() or not rtti::instanceOf<FunctionType>(candidate)) {
      this->errorAt(
        ctx->getStart(),
        "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
          candidate->getName(),
          ctx->func->getText()
        )
      );
      return ErrorType::get();
    }

    auto funcType = (FunctionType*)candidate;

    auto argsTypes = ctx->args
    | views::transform(this->byVisiting<FridayParser::ExpressionContext>())
    | views::transform(toType)
    | ranges::to<vector>();

    bool ok = true;
    if(funcType->getParametersCount() != argsTypes.size()) {
      ok = false;
      this->errorAt(
        ctx->RIGHT_PAREN()->getSymbol(),
        "In function call '{}' of type '{}' : the function expects {} arguments but {} were given."_f.format(
          ctx->func->getText(),
          funcType->getName(),
          funcType->getParametersCount(),
          argsTypes.size()
        )
      );
    }

    for(u64 i = 0; i < min(argsTypes.size(), funcType->getParametersCount()); i++) {
      Type* T = argsTypes[i];

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
  
    return (Type*)(ok ? funcType->getReturnType() : ErrorType::get());
  }

  auto TypeChecker::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Console::debug("IdentifierExpressionContext: {}"_f.format(ctx->getText()));
    
    auto isVariableOrFunction = [](ISymbol* symbol) -> bool {
      return rtti::instanceOf<Variable>(symbol) or rtti::instanceOf<Overload>(symbol);
    };
    
    string id = ctx->IDENTIFIER()->getText();
    ISymbol* symbol = this->top()->lookUpIf(id, isVariableOrFunction);

    bool ok = true;
    if(symbol == nullptr) {
      ok = false;

      auto toSuggestion = [](string const& message) {
        return format(" Did you mean '{}'?", message);
      };

      string suggestion = this->top()->mostSimilar(id, isVariableOrFunction, 3)
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

    return (Type*)(ok ? ((TypedEntity*)symbol)->getType() : ErrorType::get());
  }

  auto TypeChecker::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Console::debug("CharLiteralExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)this->BYTE();
  }

  auto TypeChecker::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug("stringLiteralExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)PointerType::get(*this->BYTE(), 1);
  }

  auto TypeChecker::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug("BoolLiteralExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)this->BOOL();
  }

  auto TypeChecker::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug("FloatLiteralExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)this->FLOAT();
  }

  auto TypeChecker::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug("IntLiteralExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)this->INT();
  }

  auto TypeChecker::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    Console::debug("GroupingExpressionContext: {}"_f.format(ctx->getText()));
    return (Type*)any_cast<Type*>(this->visit(ctx->expression()));
  }

  auto TypeChecker::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    Console::debug("SubscriptExpressionContext: {}"_f.format(ctx->getText()));

    Type* arrayType = any_cast<Type*>(this->visit(ctx->array));
    Type* indexType = any_cast<Type*>(this->visit(ctx->index));

    ArrayType* asArrayType = rtti::cast<ArrayType>(arrayType);

    bool ok = true;
    if(
      asArrayType == nullptr
      or (Type*)asArrayType == ErrorType::get()  
      or asArrayType->getElementType() == this->VOID()
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

    if(indexType != this->INT()) {
      ok = false;
      this->errorAt(
        ctx->index->getStart(),
        "Array subcript index expression '{}' of type '{}' is not convertible to int. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f.format(
          ctx->index->getText(),
          indexType->getName()
        )
      );
    }

    return (Type*)(ok ? asArrayType->getElementType() : ErrorType::get());
  }

  auto TypeChecker::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    Console::debug("BinaryExpressionContext: {}"_f.format(ctx->getText()));

    // Type* lhsType = any_cast<Type*>(this->visit(ctx->left));
    // Type* rhsType = any_cast<Type*>(this->visit(ctx->right));

    // auto operatorName = "operator{}({}, {})"_f.format(
    //   ctx->binaryOperator->getText(),
    //   lhsType->getName(),
    //   rhsType->getName()
    // );

    // string suggestion = "";

    // if(rtti::instanceOf<Struct>(lhsType) and rtti::instanceOf<Struct>(rhsType)) {
    //   if(lhsType == rhsType) {
    //     if(const Function* binaryOperator = dynamic_cast<Struct*>(lhsType)->getMethod(binaryOperatorName)) {
    //       return (Type*)binaryOperator->getType()->as<const FunctionType>()->getReturnType();
    //     }
    //   } else suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
    // }

    // this->errorAt(
    //   ctx->binaryOperator,
    //   "No matching function for call to '{}' with operands of types '{}' and '{}'.{}"_f.format(
    //     binaryOperatorName,
    //     lhsType->getName(),
    //     rhsType->getName(),
    //     suggestion
    //   )
    // );

    return ErrorType::get();
  }

  auto TypeChecker::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    Console::debug("UnaryPrefixExpressionContext: {}"_f.format(ctx->getText()));

    // Type* type = any_cast<Type*>(this->visit(ctx->expression()));
    // u64 oper = ctx->unaryOperator->getType();
    // string unaryOperatorName = Type::getUnaryPrefixExpressionOperatorName(oper, type);


    // if(Struct* asStruct = type->as<Struct>()) {
    //   if(const Function* unaryOperator = asStruct->getMethod(unaryOperatorName)) {
    //     return (Type*)unaryOperator->getType()->as<const FunctionType>()->getReturnType();
    //   }
    // }

    // this->errorAt(
    //   ctx->unaryOperator,
    //   "No matching function for call to '{}' with operand of type '{}'"_f.format(
    //     unaryOperatorName,
    //     type->getName()
    //   )
    // );
    
    return ErrorType::get();
  }

  auto TypeChecker::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    Console::debug("MemberAccessExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }

  auto TypeChecker::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug("ArrayLiteralExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }

  auto TypeChecker::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    Console::debug("ExplicitCastExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }

  auto TypeChecker::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    Console::debug("NewExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }

  auto TypeChecker::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug("UnaryPostfixExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }

  auto TypeChecker::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug("NullLiteralExpressionContext: {}"_f.format(ctx->getText()));

    return ErrorType::get();
  }
}