#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitArrayLiteralExpression({})"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    if(ctx->values.empty()) {
      this->error_at(ctx, ctx->getStart(), "Cannot form an array from 0 elements");
      return {};
    }

    Pointer<Type> type = ctx->values[0]->value.get_type();
    bool ok = true;
    for(auto element : ctx->values | views::drop(1)) {
      if(element->value.get_type() != type) {
        ok = false;
        this->error_at(
          ctx,
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

    ctx->value = Value::from_value(ArrayType::get(*this->comp_context().get_global(), *type), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitIdentifierExpression({})"_f.format(ctx->getText()));
    Pointer<ISymbolTable> scope = this->top();
    string id = ctx->id->getText();

    auto is_not_struct_field = [](Pointer<ISymbol> sym) {
      return not rtti::instance_of<Struct>(sym->get_declaring_symbol_table());
    };

    auto find_by_lookup = [this, &id, is_not_struct_field](Pointer<ISymbolTable> table) {
      return this->get_current_unit()->look_up_if(id, table, is_not_struct_field, {});
    };

    weak<ISymbol> symbol = (scope != nullptr ? make_optional(scope) : nullopt)
    .transform(find_by_lookup)
    .value_or({});

    if(symbol.expired()) {
      this->error_at(ctx, ctx->getStart(), "There is no object named '{}' in the current scope."_f.format(id));
    } else ctx->value = Value::from_symbol(symbol);

    return {};
  }

  auto TypeCheckerVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitCharLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(this->BYTE(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitStringLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(PointerType::get(*this->BYTE(), 1), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitBoolLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(this->BOOL(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitFloatLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(this->FLOAT(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitIntLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(this->INT(), nullptr);
    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug("TypeCheckerVisitor::visitNullLiteralExpression({})"_f.format(ctx->getText()));
    ctx->value = Value::from_value(PointerType::get(*this->VOID(), 1), nullptr);
    return {};
  }
}