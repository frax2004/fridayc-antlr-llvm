#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>
#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline pipeline {

  auto TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression({})"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    switch(ctx->unaryOperator->getType()) {
      case FridayParser::SIZEOF: {
        ctx->value = Value::from_value(this->INT(), nullptr);
        break;
      } case FridayParser::ALIGNOF: {
        ctx->value = Value::from_value(this->INT(), nullptr);
        break;
      } default: throw InvalidArgumentError{"Illegal unary operator '{}'"_f.format(ctx->unaryOperator->getText())};
    }

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitUnaryPrefixExpression({})"_f.format(ctx->getText()));
    this->visitChildren(ctx);


    switch(ctx->unaryOperator->getType()) {
      case FridayParser::AMPERSAND: {
        bool ok = true;
        if(ctx->operand->value.get_category() != ValueCategory::LVALUE) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "Operand of a reference expression must be an lvalue (cannot take the address of a temporary)"
          );
        }

        if(ErrorType::is_error_type(ctx->operand->value.get_type())) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "Cannot take the address of an expression with invalid type '{}'"_f.format(ErrorType::get()->get_name())
          );
        }

        if(not ok) break;

        ctx->value = Value::from_value(
          PointerType::get(*ctx->operand->value.get_type(), 1), 
          nullptr
        );

        break;
      } case FridayParser::STAR: {

        auto pointer = PointerType::to_pointer(ctx->operand->value.get_type());
        if(not pointer or pointer->get_pointed_type() == this->VOID()) {
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "Cannot dereference an expression of type '{}'"_f.format(ctx->operand->value.get_type()->get_name())
          );
        } else ctx->value = Value::from_variable(pointer->get_pointed_type(), nullptr);

        break;
      } default: {
        Pointer<Type> type = ctx->expression()->value.get_type();
        string operatorName = "operator{}"_f.format(ctx->unaryOperator->getText());
        weak<Function> function = this->find_unary_operator(operatorName, type);
    
        string suggestion = "";
    
        if(function.expired()) {
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "No matching function for call to '{}' with operand of type '{}'. Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast."_f.format(
              operatorName,
              type->get_name()
            )
          );
        } else ctx->value = Value::from_value(function.lock()->get_return_type(), nullptr);

        break;
      }
    }
    

    return {};
  }


  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitUnaryPostfixExpression({})"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Pointer<Type> type = ctx->expression()->value.get_type();

    string operatorName = "operator{}"_f.format(ctx->postfixOperator->getText());
    weak<Function> function = this->find_unary_operator(operatorName, type);

    string suggestion = "";

    if(function.expired()) {
      this->error_at(
        ctx,
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