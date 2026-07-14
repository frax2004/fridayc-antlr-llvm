#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {

  auto TypeCheckerVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Pointer<Type> type = ctx->expression()->value.get_type();

    string operatorName = "operator{}"_f.format(ctx->unaryOperator->getText());
    weak<Function> function = this->find_unary_operator(operatorName, type);

    string suggestion = "";

    if(function.expired()) {
      this->error_at(
        ctx->unaryOperator,
        "No matching function for call to '{}' with operand of type '{}'. Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast."_f.format(
          operatorName,
          type->get_name()
        )
      );
    } else ctx->value = Value::from_value(function.lock()->get_return_type(), nullptr);

    return {};
  }


  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Pointer<Type> type = ctx->expression()->value.get_type();

    string operatorName = "operator{}"_f.format(ctx->postfixOperator->getText());
    weak<Function> function = this->find_unary_operator(operatorName, type);

    string suggestion = "";

    if(function.expired()) {
      this->error_at(
        ctx->postfixOperator,
        "No matching function for call to '{}' with operand of type '{}'. Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast."_f.format(
          operatorName,
          type->get_name()
        )
      );
    } else ctx->value = Value::from_value(function.lock()->get_return_type(), nullptr);

    return {};
  }

}