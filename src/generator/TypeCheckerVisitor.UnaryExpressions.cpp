#include <fridayc.hpp>


namespace friday::inline api {
  auto TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    switch(ctx->unaryOperator->getType()) {
      case FridayParser::SIZEOF: {
        $(ctx).value = Value::from_rvalue(this->INT(), nullptr);
        break;
      } case FridayParser::ALIGNOF: {
        $(ctx).value = Value::from_rvalue(this->INT(), nullptr);
        break;
      } default: throw InvalidArgumentError{};
    }

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitUnaryPrefixExpression({})", ctx->getText()));
    this->visitChildren(ctx);


    switch(ctx->unaryOperator->getType()) {
      case FridayParser::AMPERSAND: {
        bool ok = true;
        if($(ctx->operand).value.get_category() != ValueCategory::LVALUE) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "Operand of a reference expression must be an lvalue (cannot take the address of a temporary)"
          );
        }

        if(ErrorType::is_error_type($(ctx->operand).value.get_type())) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            format("Cannot take the address of an expression with invalid type '{}'", ErrorType::get()->get_name())
          );
        }

        if(not ok) break;

        $(ctx).value = Value::from_rvalue(
          PointerType::get(*$(ctx->operand).value.get_type(), 1), 
          nullptr
        );

        break;
      } case FridayParser::STAR: {

        auto pointer = PointerType::to_pointer($(ctx->operand).value.get_type());
        if(not pointer or pointer->get_pointed_type() == this->VOID()) {
          this->error_at(
            ctx,
            ctx->unaryOperator,
            format("Cannot dereference an expression of type '{}'", $(ctx->operand).value.get_type()->get_name())
          );
        } else $(ctx).value = Value::from_lvalue(pointer->get_pointed_type(), nullptr);

        break;
      } default: {
        Type* type = $(ctx->expression()).value.get_type();
        string operatorName = format("operator{}", ctx->unaryOperator->getText());
        Function* function = this->find_unary_operator(operatorName, type);
    
        string suggestion = "";
    
        if(function == nullptr) {
          this->error_at(
            ctx,
            ctx->unaryOperator,
            format(
              "No matching function for call to '{}' with operand of type '{}'. Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.",
              operatorName,
              type->get_name()
            )
          );
        } else $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);

        break;
      }
    }
    

    return {};
  }


  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitUnaryPostfixExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* type = $(ctx->expression()).value.get_type();

    string operatorName = format("operator{}", ctx->postfixOperator->getText());
    Function* function = this->find_unary_operator(operatorName, type);

    string suggestion = "";

    if(function == nullptr) {
      this->error_at(
        ctx,
        ctx->postfixOperator,
        format(
          "No matching function for call to '{}' with operand of type '{}'. Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.",
          operatorName,
          type->get_name()
        )
      );
    } else $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);

    return {};
  }

}