#include <fridayc.hpp>
#include <llvm/Support/YAMLParser.h>


namespace friday::inline api {

  auto unescape_string(string_view s) -> string {
    string r{};
    r.reserve(r.length());

    struct StringScanner {
    private:
      string_view M_source {};
      u64 M_position { 0 };

    public:
      explicit StringScanner(string_view str)
        : M_source { str }
      {}

    public:
      auto peek(u64 offset = 0) -> i8 {
        return this->M_position + offset >= this->M_source.length() ? 
          '\0' : this->M_source[this->M_position + offset];
      }

      auto consume() -> i8 {
        if(this->M_position >= this->M_source.length()) return '\0';
        return this->M_source[this->M_position++];
      }

      auto finished() const -> bool {
        return this->M_position >= this->M_source.length();
      }

      auto rewind() -> void {
        this->M_position = 0;
      }
    };

    StringScanner scanner{s};

    while(not scanner.finished()) {
      if(scanner.peek() == '\\') {
        scanner.consume();
        switch(scanner.peek()) {
          case '\'': scanner.consume(); r.push_back('\''); break;
          case '"': scanner.consume(); r.push_back('"'); break;
          case '\\': scanner.consume(); r.push_back('\\'); break;
          case 'a': scanner.consume(); r.push_back('\a'); break;
          case 'b': scanner.consume(); r.push_back('\b'); break;
          case 'f': scanner.consume(); r.push_back('\f'); break;
          case 'n': scanner.consume(); r.push_back('\n'); break;
          case 'r': scanner.consume(); r.push_back('\r'); break;
          case 't': scanner.consume(); r.push_back('\t'); break;
          case 'v': scanner.consume(); r.push_back('\v'); break;
        }
      } else r.push_back(scanner.consume());
    }

    return r;
  }

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitArrayLiteralExpression({})", ctx->getText()));

    this->visitChildren(ctx);
    if(ctx->values.empty()) {
      this->error_at(ctx, ctx->getStart(), "Cannot form an array from 0 elements");
      return {};
    }

    Type* type = $(ctx->values[0]).value.type();
    bool ok = true;
    for(auto element : ctx->values | views::drop(1)) {
      if($(element).value.type() != type) {
        ok = false;
        this->error_at(
          ctx,
          element->getStart(),
          format(
            "Array elements must be of the same type: expression '{}' of type '{}' is not of type '{}'",
            element->getText(),
            $(element).value.type()->get_name(),
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

    auto find_by_lookup = [this, &id](ISymbolTable* table) {
      auto is_not_struct_field = [](ISymbol* sym) {
        return dynamic_cast<Struct*>(sym->get_declaring_symbol_table()) == nullptr;
      };
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
    $(ctx).value = Value::from_constant(Type::get_byte_type(), Constant::from_byte(ctx->getText()[1]));
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitStringLiteralExpression({})", ctx->getText()));

    string value = ctx->getText();
    string_view unquoted = value;
    unquoted.remove_prefix(1);
    unquoted.remove_suffix(1);

    $(ctx).value = Value::from_constant(
      Type::get_byteptr_type(), 
      Constant::from_str(unescape_string(unquoted))
    );

    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitBoolLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      Type::get_bool_type(), 
      Constant::from_bool(ctx->getText() == "true")
    );
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitFloatLiteralExpression({})", ctx->getText()));
    
    $(ctx).value = Value::from_constant(
      Type::get_float_type(), 
      Constant::from_float(stod(ctx->getText()))
    );
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitIntLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      Type::get_int_type(), 
      Constant::from_int(stoll(ctx->getText()))
    );
    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitNullLiteralExpression({})", ctx->getText()));

    $(ctx).value = Value::from_constant(
      Type::get_voidptr_type(),
      Constant::from_null()
    );
    return {};
  }

  auto TypeCheckerVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitGroupingExpression({})", ctx->getText()));
    this->visitChildren(ctx);
    $(ctx).value = Value::from_rvalue($(ctx->expression()).value.type(), nullptr);

    return {};
  }
}