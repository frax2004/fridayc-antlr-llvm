#include <fridayc.hpp>

namespace friday::inline api {
  static auto to_member_access_expr(FridayParser::ExpressionContext* expr) {
    return dynamic_cast<FridayParser::MemberAccessExpressionContext*>(expr);
  }

  auto TypeCheckerVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitCallExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    auto candidate = $(ctx->func).value
    .to_overload()
    .value_or({});

    if(candidate == nullptr) {
      this->error_at(
        ctx,
        ctx->getStart(),
        format(
          "The underlined expression '{}' of type '{}' is not a function and cannot be called.",
          ctx->func->getText(),
          $(ctx->func).value.get_type()->get_name()
        )
      );
      return {};
    }

    Overload* overload = candidate;
    Function* function = {};

    if(auto memberAccess = to_member_access_expr(ctx->func); memberAccess != nullptr) {
      auto params_with_this = [memberAccess, ctx] -> generator<Type*> {
        co_yield PointerType::get(*$(memberAccess->object).value.get_type(), 1);
        for(auto arg : ctx->args) co_yield $(arg).value.get_type();
      };

      function = overload->try_match(params_with_this() | ranges::to<vector>());
    }
    
    auto try_static = [ctx, &overload]() {
      auto obj = overload
      ->try_match(
        ctx->args 
        | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
        | views::transform(&Value::get_type)
        | ranges::to<vector>()
      );

      return obj != nullptr ? optional{ obj } : nullopt;
    };

    
    function = (function != nullptr ? optional{ function } : nullopt)
    .or_else(try_static)
    .value_or({});

    if(function == nullptr) {
      function = overload->try_match(
        ctx->args
        | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
        | views::transform(&Value::get_type)
        | ranges::to<vector>()
      );
    }

    if(function == nullptr) {
      this->error_at(
        ctx,
        ctx->func->getStart(),
        format(
          "No overload of function '{}' matches the given arguments ({}):\nAvailable overloads:\n{}",
          overload->get_qualified_id(),
          ctx->args
          | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
          | views::transform(&Value::get_type)
          | views::transform(&Type::get_name)
          | views::join_with(", "s)
          | ranges::to<string>(),
          overload->get_instances()
          | views::transform(&Function::get_type)
          | views::transform(&Type::get_name)
          | views::join_with("\n"s)
          | ranges::to<string>()
        )
      );
      return {};
    }

    auto funcType = dynamic_cast<FunctionType*>(function->get_type());
    $(ctx).value = Value::from_rvalue(funcType->get_return_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitGroupingExpression({})", ctx->getText()));
    this->visitChildren(ctx);
    $(ctx).value = Value::from_rvalue($(ctx->expression()).value.get_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitSubscriptExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* arrayType = $(ctx->array).value.get_type();
    Type* indexType = $(ctx->index).value.get_type();

    bool ok = true;
    if(not ArrayType::is_array(arrayType) or ArrayType::to_array(arrayType)->get_element_type() == this->VOID()) {
      ok = false;
      this->error_at(
        ctx,
        ctx->array->getStart(),
        format(
          "Array expression '{}' of type '{}' is not a valid array or pointer that can be dereferenced.",
          ctx->array->getText(),
          arrayType->get_name()
        )
      );
    }

    if(indexType != this->INT()) {
      ok = false;
      this->error_at(
        ctx,
        ctx->index->getStart(),
        format(
          "Array subcript index expression '{}' of type '{}' is not convertible to int. Implicit cast are not permitted, if this is the problem, try adding an explicit cast.",
          ctx->index->getText(),
          indexType->get_name()
        )
      );
    }

    if(not ok) return {};

    $(ctx).value = Value::from_unknown(
      ArrayType::to_array(arrayType)->get_element_type(),
      $(ctx->array).value.get_category()
    );
    
    return {};
  }

  auto TypeCheckerVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitBinaryExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* lhsType = $(ctx->left).value.get_type();
    Type* rhsType = $(ctx->right).value.get_type();
    
    string operatorName = format("operator{}", ctx->binaryOperator->getText());
    Function* function = this->find_binary_operator(operatorName, lhsType, rhsType);

    string suggestion = "";

    if(function == nullptr) {
      if(lhsType != rhsType) {
        suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
      }
      this->error_at(
        ctx,
        ctx->binaryOperator,
        format(
          "No matching function for call to '{}' with operands of types '{}' and '{}'.{}",
          operatorName,
          lhsType->get_name(),
          rhsType->get_name(),
          suggestion
        )
      );
    } else $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitMemberAccessExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    auto memberName = ctx->member->getText();
    auto always = [](ISymbol* symbol) { (void)symbol; return true; };
    auto is_value = [](Value const& value) {
      return (value.is_lvalue() or value.is_rvalue()) and (
        dynamic_cast<Struct*>(value.get_type()) != nullptr or (
          PointerType::is_pointer(value.get_type()) and 
          dynamic_cast<Struct*>(PointerType::to_pointer(value.get_type())->get_pointed_type()) != nullptr
        )
      );
    };

    bool ok = $(ctx->object).value.is_struct() 
    or $(ctx->object).value.is_namespace() 
    or is_value($(ctx->object).value);

    if(not ok) {
      this->error_at(
        ctx,
        ctx->object->getStart(),
        format(
          "The underlined expression '{}' of type '{}' is not an instance of a struct or a struct or a namespace",
          ctx->object->getText(),
          $(ctx->object).value.get_type()->get_name()
        )
      );
    } 

    if(is_value($(ctx->object).value)) {
      auto asStruct = dynamic_cast<Struct*>($(ctx->object).value.get_type());
      // attempt auto dereference
      if(not asStruct) asStruct = dynamic_cast<Struct*>(PointerType::to_pointer($(ctx->object).value.get_type())->get_pointed_type());

      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else $(ctx).value = Value::from_symbol(asStruct->retrieve(memberName));
    }

    if($(ctx->object).value.is_struct()) {
      auto asStruct = *$(ctx->object).value.to_struct();
      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else $(ctx).value = Value::from_symbol(asStruct->retrieve(memberName));
    }

    if($(ctx->object).value.is_namespace()) {
      auto asNamespace = *$(ctx->object).value.to_namespace();
      if(not asNamespace->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Namespace '{}' has no variable or function or struct called '{}'", asNamespace->get_qualified_id(), memberName)
        );
      } else $(ctx).value = Value::from_symbol(asNamespace->retrieve(memberName));
    }

    return {};
  }

  auto TypeCheckerVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitExplicitCastExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* lhsType = $(ctx->expr).value.get_type();
    Type* rhsType = $(ctx->type()).type;
    Type* valueType = lhsType;
    Type* targetType = rhsType;

    if(PointerType::is_pointer(valueType)) {
      valueType = this->VOIDPTR();
    }

    if(PointerType::is_pointer(valueType)) {
      targetType = this->VOIDPTR();
    }

    auto to_type_index = [this](Type* type) -> i32 {
      if(type == this->VOIDPTR()) return 0;
      else if(type == this->INT()) return 1;
      else if(type == this->FLOAT()) return 2;
      else if(type == this->BYTE()) return 3;
      else if(type == this->BOOL()) return 4;
      else return -1;
    };

    using __entry_type = bool;
    using __coercion_table = __entry_type[5][5];

    static constexpr __coercion_table coercion_table = {
                  /* *any   int    float  byte   bool */
      /* *any  */   {true,  false, false, false, false},
      /* int   */   {false, true , true , true , false},
      /* float */   {false, true , true , false, false},
      /* byte  */   {false, true , false, true , false},
      /* bool  */   {false, false, false, false, true },
    };

    i32 lhs = to_type_index(valueType);
    i32 rhs = to_type_index(targetType);

    if((lhs < 0 or rhs < 0) or not coercion_table[lhs][rhs]) {
      this->error_at(
        ctx,
        ctx->AS()->getSymbol(),
        format(
          "Invalid explicit conversion: cannot convert an expression of type '{}' into an expression of type '{}'",
          lhsType->get_name(),
          rhsType->get_name()
        )
      );
    } else $(ctx).value = Value::from_rvalue(rhsType, nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitNewExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* type = $(ctx->type()).type;


    if(auto asStruct = dynamic_cast<Struct*>(type)) {
      auto fieldsNames = ctx->fields 
      | views::transform(&ant::Token::getText);
      
      auto initializers = ctx->initializers 
      | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
      | views::transform(&Value::get_type);
      
      bool ok = true;
      for(auto [i, field_and_type] : views::zip(fieldsNames, initializers) | views::enumerate) {
        auto [name, actual] = field_and_type;

        auto field = asStruct->find_field(name);
        if(field == nullptr) {
          ok = false;
          this->error_at(
            ctx,
            ctx->fields[i],
            format(
              "In new expression (#{}-th field), struct '{}' has no field named '{}'",
              i, 
              asStruct->get_name(), 
              name
            )
          );
          continue;
        }

        Type* expected = field->get_type();
        if(expected != actual) {
          ok = false;
          this->error_at(
            ctx,
            ctx->initializers[i]->getStart(),
            format(
              "In new expression, in the assignment of field '{}' requires an expression of type '{}' but got a value of type '{}'",
              name,
              expected->get_name(),
              actual->get_name()
            )
          );
        }
      }

      if(not ok) return {};

      $(ctx).value = Value::from_rvalue(type, nullptr);

    } else {
      this->error_at(
        ctx,
        ctx->type()->getStart(),
        format(
          "In new expression '{}', cannot create instance of type '{}'",
          ctx->getText(),
          type->get_name()
        )
      );
    }
    
    return {};
  }

  auto to_simple_operator(u64 token_type) -> string_view {
    switch(token_type) {
      case FridayParser::PLUS_ASSIGN: return "+"sv;
      case FridayParser::MINUS_ASSIGN: return "-"sv;
      case FridayParser::STAR_ASSIGN: return "*"sv;
      case FridayParser::SLASH_ASSIGN: return "/"sv;
      case FridayParser::MODULO_ASSIGN: return "%"sv;
      case FridayParser::LSHIFT_ASSIGN: return "<<"sv;
      case FridayParser::RSHIFT_ASSIGN: return ">>"sv;
      case FridayParser::AMPERSAND_ASSIGN: return "&"sv;
      case FridayParser::PIPELINE_ASSIGN: return "|"sv;
      default: throw InvalidArgumentError{};
    }

    return "";
  }

  auto TypeCheckerVisitor::visitAssignmentExpression(FridayParser::AssignmentExpressionContext* ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitAssignmentExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* resultType = ErrorType::get();

    if(ctx->binaryOperator->getType() == FridayParser::ASSIGN) {
      resultType = $(ctx->right).value.get_type();
    } else {
      Type* lhsType = $(ctx->left).value.get_type();
      Type* rhsType = $(ctx->right).value.get_type();

      string_view op = to_simple_operator(ctx->binaryOperator->getType());
      string operatorName = format("operator{}", op);
      Function* function = this->find_binary_operator(operatorName, lhsType, rhsType);

      string suggestion = "";

      if(function == nullptr) {
        if(lhsType != rhsType) {
          suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
        }
        this->error_at(
          ctx,
          ctx->binaryOperator,
          format(
            "No matching function for call to '{}' with operands of types '{}' and '{}'.{}",
            operatorName,
            lhsType->get_name(),
            rhsType->get_name(),
            suggestion
          )
        );
      } else resultType = function->get_return_type();
    }

    bool ok = true;
    if(ErrorType::is_error_type($(ctx->left).value.get_type())) {
      ok = false;
      this->error_at(
        ctx,
        ctx->left->getStart(),
        format("Cannot assign to an expression of an invalid type '{}'", $(ctx->left).value.get_type()->get_name())
      );
    }

    if($(ctx->left).value.get_category() != ValueCategory::LVALUE) {
      ok = false;
      this->error_at(
        ctx,
        ctx->left->getStart(),
        "Left side of an assignment expression must be an lvalue"
      );
    }

    if($(ctx->left).value.get_type() != resultType) {
      ok = false;
      this->error_at(
        ctx,
        ctx->binaryOperator,
        format(
          "In assignment expression, cannot assign an expression of type '{}' to an object of type '{}'.",
          resultType->get_name(),
          $(ctx->left).value.get_type()->get_name()
        )
      );
    }

    if(not ok) return {};

    $(ctx).value = Value::from_lvalue(resultType, nullptr);

    return {};
  }
}