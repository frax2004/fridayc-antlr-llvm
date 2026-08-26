#include <fridayc.hpp>

namespace friday::inline api {
  static auto to_member_access_expr(FridayParser::ExpressionContext* expr) {
    return dynamic_cast<FridayParser::MemberAccessExpressionContext*>(expr);
  }

  auto TypeCheckerVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitCallExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Value candidate = $(ctx->func).value;
    Type* callerType = candidate.type();

    if(UnresolvedOverloadType::is_unresolved_overload_type(callerType)) {
      Overload* overload = *candidate.unwrap<Overload*>();

      auto try_member = [ctx, overload]() -> optional<Function*> {
        auto memberAccess = to_member_access_expr(ctx->func);
        if(memberAccess == nullptr) return nullopt;

        auto this_bound_args = [memberAccess, ctx] -> generator<Type*> {
          co_yield PointerType::get(*$(memberAccess->object).value.type(), 1);
          for(auto arg : ctx->args) co_yield $(arg).value.type();
        };

        auto match = overload->try_match(this_bound_args() | ranges::to<vector>());
        return match != nullptr ? make_optional(match) : nullopt;
      };

      auto try_static = [ctx, overload]() {
        auto obj = overload
        ->try_match(
          ctx->args 
          | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
          | views::transform(&Value::type)
          | ranges::to<vector>()
        );

        return obj != nullptr ? optional{ obj } : nullopt;
      };

      Function* function = try_member()
      .or_else(try_static)
      .value_or(nullptr);

      if(function == nullptr) {
        this->error_at(
          ctx,
          ctx->func->getStart(),
          format(
            "No overload of function '{}' matches the given arguments ({}):\nAvailable overloads:\n{}",
            overload->get_qualified_id(),
            ctx->args
            | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
            | views::transform(&Value::type)
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

      FunctionType* funcType = FunctionType::to_function(function->get_type());
      $(ctx).value = Value::from_rvalue(funcType->get_return_type(), nullptr);
      $(ctx).caller = function;

    } else if(FunctionType::is_function(callerType)) {

      FunctionType* funcType = FunctionType::to_function(callerType);
      auto matches = views::zip(
        views::iota(0ULL, min(funcType->params_size(), ctx->args.size())),
        funcType->get_params_types(),
        ctx->args
        | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
        | views::transform(&Value::type)
      );

      if(funcType->params_size() != ctx->args.size()) {
        this->error_at(
          ctx,
          ctx->getStop(),
          format(
            "Candidate expects {} arguments, but {} were given.",
            funcType->params_size(),
            ctx->args.size()
          )
        );
      }

      for(auto [i, expected, actual] : matches) {
        if(expected != actual) {
          this->error_at(
            ctx,
            ctx->args[i]->getStart(),
            format(
              "Argument {} of type {} does not match parameter of type {}.",
              i,
              actual->get_name(),
              expected->get_name()
            )
          );
        }
      }

      $(ctx).value = Value::from_rvalue(funcType->get_return_type(), nullptr);
      $(ctx).caller = nullptr;
    } else {
      this->error_at(
        ctx,
        ctx->getStart(),
        format(
          "The underlined expression '{}' of type '{}' is not a callable and cannot be called.",
          ctx->func->getText(),
          $(ctx->func).value.type()->get_name()
        )
      );
    }

    return {};
  }


  auto TypeCheckerVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitSubscriptExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* arrayType = $(ctx->array).value.type();
    Type* indexType = $(ctx->index).value.type();

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
      $(ctx->array).value.category()
    );
    
    return {};
  }

  auto TypeCheckerVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitBinaryExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* lhsType = $(ctx->left).value.type();
    Type* rhsType = $(ctx->right).value.type();
    
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
    } else {
      $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);
      $(ctx)._operator = function;
    }

    return {};
  }

  auto TypeCheckerVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitMemberAccessExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    auto memberName = ctx->member->getText();
    auto always = [](ISymbol* symbol) { (void)symbol; return true; };
    auto is_value = [](Value const& value) {
      return (value.is(ValueCategory::RVALUE) or value.is(ValueCategory::LVALUE)) and (
        dynamic_cast<Struct*>(value.type()) != nullptr or (
          PointerType::is_pointer(value.type()) and 
          dynamic_cast<Struct*>(PointerType::to_pointer(value.type())->get_pointed_type()) != nullptr
        )
      );
    };

    bool ok = $(ctx->object).value.holds(Value::Kind::STRUCT) 
    or $(ctx->object).value.holds(Value::Kind::NAMESPACE)
    or is_value($(ctx->object).value);

    if(not ok) {
      this->error_at(
        ctx,
        ctx->object->getStart(),
        format(
          "The underlined expression '{}' of type '{}' is not an instance of a struct or a struct or a namespace",
          ctx->object->getText(),
          $(ctx->object).value.type()->get_name()
        )
      );
    } 

    if(is_value($(ctx->object).value)) {
      auto asStruct = dynamic_cast<Struct*>($(ctx->object).value.type());
      // attempt auto dereference
      if(not asStruct) asStruct = dynamic_cast<Struct*>(PointerType::to_pointer($(ctx->object).value.type())->get_pointed_type());

      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else $(ctx).value = Value::from_symbol(asStruct->retrieve(memberName));
    }

    if($(ctx->object).value.holds(Value::Kind::STRUCT)) {
      auto asStruct = *$(ctx->object).value.unwrap<Struct*>();
      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else $(ctx).value = Value::from_symbol(asStruct->retrieve(memberName));
    }

    if($(ctx->object).value.holds(Value::Kind::NAMESPACE)) {
      auto asNamespace = *$(ctx->object).value.unwrap<Namespace*>();
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

    Type* lhsType = $(ctx->expr).value.type();
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
      resultType = $(ctx->right).value.type();
    } else {
      Type* lhsType = $(ctx->left).value.type();
      Type* rhsType = $(ctx->right).value.type();

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
    if(ErrorType::is_error_type($(ctx->left).value.type())) {
      ok = false;
      this->error_at(
        ctx,
        ctx->left->getStart(),
        format("Cannot assign to an expression of an invalid type '{}'", $(ctx->left).value.type()->get_name())
      );
    }

    if($(ctx->left).value.category() != ValueCategory::LVALUE) {
      ok = false;
      this->error_at(
        ctx,
        ctx->left->getStart(),
        "Left side of an assignment expression must be an lvalue"
      );
    }

    if($(ctx->left).value.type() != resultType) {
      ok = false;
      this->error_at(
        ctx,
        ctx->binaryOperator,
        format(
          "In assignment expression, cannot assign an expression of type '{}' to an object of type '{}'.",
          resultType->get_name(),
          $(ctx->left).value.type()->get_name()
        )
      );
    }

    if(not ok) return {};

    $(ctx).value = Value::from_lvalue(resultType, nullptr, nullptr);

    return {};
  }
}