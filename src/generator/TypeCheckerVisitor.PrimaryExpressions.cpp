#include <fridayc.hpp>

namespace friday::inline api {

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitArrayLiteralExpression({})", ctx->getText()));

    this->visitChildren(ctx);
    if(ctx->values.empty()) {
      this->error_at(ctx, ctx->getStart(), "Cannot form an array from 0 elements");
      return {};
    }

    Type* type = $(ctx->values[0]).value.get_type();
    bool ok = true;
    for(auto element : ctx->values | views::drop(1)) {
      if($(element).value.get_type() != type) {
        ok = false;
        this->error_at(
          ctx,
          element->getStart(),
          format(
            "Array elements must be of the same type: expression '{}' of type '{}' is not of type '{}'",
            element->getText(),
            $(element).value.get_type()->get_name(),
            type->get_name()
          )
        );
      }
    }

    if(not ok) return {};

    $(ctx).value = Value::from_rvalue(ArrayType::get(*type), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitIdentifierExpression({})", ctx->getText()));
    ISymbolTable* scope = this->top();
    string id = ctx->id->getText();

    auto is_not_struct_field = [](ISymbol* sym) {
      return dynamic_cast<Struct*>(sym->get_declaring_symbol_table()) == nullptr;
    };

    auto find_by_lookup = [this, &id, is_not_struct_field](ISymbolTable* table) {
      return this->get_current_unit()->look_up_if(id, table, is_not_struct_field, {});
    };

    ISymbol* symbol = (scope != nullptr ? make_optional(scope) : nullopt)
    .transform(find_by_lookup)
    .value_or({});

    if(symbol == nullptr) {
      this->error_at(ctx, ctx->getStart(), format("There is no object named '{}' in the current scope.", id));
    } else $(ctx).value = Value::from_symbol(symbol);

    return {};
  }

  auto TypeCheckerVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitCharLiteralExpression({})", ctx->getText()));
    $(ctx).value = Value::from_constant(this->BYTE(), Constant::from_byte(ctx->getText()[1]));
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitStringLiteralExpression({})", ctx->getText()));

    string value = ctx->getText();
    string_view unquoted = value;
    unquoted.remove_prefix(1);
    unquoted.remove_suffix(1);

    $(ctx).value = Value::from_constant(
      PointerType::get(*this->BYTE(), 1), 
      Constant::from_str(string(unquoted))
    );
    
    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitBoolLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      this->BOOL(), 
      Constant::from_bool(ctx->getText() == "true")
    );
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitFloatLiteralExpression({})", ctx->getText()));
    
    $(ctx).value = Value::from_constant(
      this->FLOAT(), 
      Constant::from_float(stod(ctx->getText()))
    );
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitIntLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      this->INT(), 
      Constant::from_int(stoll(ctx->getText()))
    );
    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitNullLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      this->VOIDPTR(),
      Constant::from_null()
    );
    return {};
  }
}