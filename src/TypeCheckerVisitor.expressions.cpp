#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  auto TypeCheckerVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    Console::debug("CallExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    auto candidate = ctx->func->typeId;

    if(candidate == ErrorType::get() or not rtti::instanceOf<FunctionType>(candidate)) {
      this->errorAt(
        ctx->getStart(),
        "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
          ctx->func->getText(),
          candidate->getName()
        )
      );
      return {};
    }

    auto funcType = rtti::cast<FunctionType>(candidate);

    auto argsTypes = ctx->args
    | views::transform(&FridayParser::ExpressionContext::typeId)
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

    if(ok) ctx->typeId = funcType->getReturnType();

    return {};
  }

  auto TypeCheckerVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Console::debug("IdentifierExpressionContext: {}"_f.format(ctx->getText()));

    auto isVariableOrFunction = [](ISymbol* symbol) -> bool {
      return rtti::instanceOf<Variable>(symbol) or rtti::instanceOf<Overload>(symbol);
    };
    
    string id = ctx->IDENTIFIER()->getText();
    weak<ISymbolTable> scope = this->top();
    if(scope.expired()) throw OperationNotSupportedError("Internal error.");

    weak<ISymbol> symbol = scope.lock()->lookUpIf(id, isVariableOrFunction, {});

    if(symbol.expired()) {
      auto toSuggestion = [](string const& message) {
        return format(" Did you mean '{}'?", message);
      };

      // string suggestion = this->top()->mostSimilar(id, isVariableOrFunction, 3);
      // .transform(toSuggestion)
      string suggestion = "";

      this->errorAt(
        ctx->getStart(),
        "There is no object named '{}' in the current scope.{}"_f.format(
          id,
          suggestion
        )
      );
    } else ctx->typeId = dynamic_pointer_cast<TypedEntity>(symbol.lock())->getType();
    
    return {};
  }

  auto TypeCheckerVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Console::debug("CharLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->BYTE();
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug("stringLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = PointerType::get(*this->BYTE(), 1);
    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug("BoolLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->BOOL();
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug("FloatLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->FLOAT();
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug("IntLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->INT();
    return {};
  }

  auto TypeCheckerVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    Console::debug("GroupingExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    ctx->typeId = ctx->typeId;
    return {};
  }

  auto TypeCheckerVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    Console::debug("SubscriptExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Type* arrayType = ctx->array->typeId;
    Type* indexType = ctx->index->typeId;

    ArrayType* asArrayType = rtti::cast<ArrayType>(arrayType);

    bool ok = true;
    if(
      asArrayType == nullptr
      or rtti::cast<Type>(asArrayType) == ErrorType::get()  
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

    if(ok) ctx->typeId = asArrayType->getElementType();
    return {};
  }

  auto TypeCheckerVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    Console::debug("BinaryExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Type* lhsType = ctx->left->typeId;
    Type* rhsType = ctx->right->typeId;

    string operatorName = "operator{}"_f.format(ctx->binaryOperator->getText());
    weak<Function> function = this->findBinaryOperator(operatorName, lhsType, rhsType);

    string suggestion = "";

    if(function.expired()) {
      if(lhsType == rhsType) {
        suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
      }
      this->errorAt(
        ctx->binaryOperator,
        "No matching function for call to '{}' with operands of types '{}' and '{}'.{}"_f.format(
          operatorName,
          lhsType->getName(),
          rhsType->getName(),
          suggestion
        )
      );
    } else ctx->typeId = function.lock()->getReturnType();

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    Console::debug("UnaryPrefixExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    
    // Type* type = any_cast<Type*>(this->visit(ctx->expression()));
    // u64 oper = ctx->unaryOperator->getType();
    // string unaryOperatorName = Type::getUnaryPrefixExpressionOperatorName(oper, type);


    // if(Struct* asStruct = type->as<Struct>()) {
    //   if(const Function* unaryOperator = asStruct->getMethod(unaryOperatorName)) {
    //     ctx->typeId = unaryOperator->getType()->as<const FunctionType>()->getReturnType();
    //   }
    // }

    // this->errorAt(
    //   ctx->unaryOperator,
    //   "No matching function for call to '{}' with operand of type '{}'"_f.format(
    //     unaryOperatorName,
    //     type->getName()
    //   )
    // );
    
    return {};
  }

  auto TypeCheckerVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    Console::debug("MemberAccessExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug("ArrayLiteralExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    Console::debug("ExplicitCastExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    Console::debug("NewExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug("UnaryPostfixExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug("NullLiteralExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }
}