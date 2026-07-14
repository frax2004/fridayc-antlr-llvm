#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    this->visitChildren(ctx);
    if(ctx->values.empty()) {
      this->error_at(ctx->getStart(), "Cannot form an array from 0 elements");
      return {};
    }

    Pointer<Type> type = ctx->values[0]->value.get_type();
    bool ok = true;
    for(auto element : ctx->values | views::drop(1)) {
      if(element->value.get_type() != type) {
        ok = false;
        this->error_at(
          element->getStart(),
          "Array elements must be of the same type: expression '{}' of type '{}' is not of type '{}'"_f.format(
            element->getText(),
            element->value.get_type()->get_name(),
            type->get_name()
          )
        );
      }
    }

    if(not ok) return {};

    ctx->value = Value::from_value(ArrayType::get(*type, ctx->values.size()), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Pointer<ISymbolTable> scope = this->top();
    string id = ctx->id->getText();

    auto look_up_by_id = [&id](Pointer<ISymbolTable> table) {
      return table->look_up(id, {});
    };

    weak<ISymbol> symbol = (scope != nullptr ? make_optional(scope) : nullopt)
    .transform(look_up_by_id)
    .value_or({});

    if(symbol.expired()) {
      this->error_at(ctx->getStart(), "There is no object named '{}' in the current scope."_f.format(id));
    } else ctx->value = Value::from_symbol(symbol);

    return {};
  }

  auto TypeCheckerVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(this->BYTE(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(PointerType::get(*this->BYTE(), 1), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(this->BOOL(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(this->FLOAT(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(this->INT(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    ctx->value = Value::from_value(PointerType::get(*this->VOID(), 1), nullptr);
    return {};
  }
}