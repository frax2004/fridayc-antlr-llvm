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
      vector<Type*> args = ctx->args
      | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
      | views::transform(&Value::type)
      | ranges::to<vector>();

      Function* function = nullptr;
      do {
        auto MAEC = to_member_access_expr(ctx->func);

        if(MAEC == nullptr) break;

        Type* objectType = $(MAEC->object).value.type();
        bool isStruct = objectType->is_aggregate_type();
        bool isPointerToStruct = PointerType::is_pointer(objectType)
        and PointerType::to_pointer(objectType)->get_pointed_type()->is_aggregate_type();

        if(not (isStruct or isPointerToStruct)) break;

        args.insert(args.begin(), objectType);

        // Try match as member function with no auto-reference/auto-dereference
        function = overload->try_match(args);

        if(function != nullptr) break;

        // Attempt to auto reference
        if(isStruct) args[0] = PointerType::get(*args[0], 1);
        // Attempt to auto dereference
        else args[0] = PointerType::to_pointer(args[0])->get_pointed_type();

        // Try match as member function with auto-reference/auto-dereference
        function = overload->try_match(args);
      } while(false);

      // Rematch with arguments (possibly with self argument) to try as static
      function = overload->try_match(args);

      if(function == nullptr) {
        this->error_at(
          ctx,
          ctx->func->getStart(),
          format(
            "No instance of overloaded function '{}' matches the given arguments ({}):\nAvailable overloads:\n{}",
            overload->get_full_qualified_id(),
            args
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
    if(not ArrayType::is_array(arrayType) or ArrayType::to_array(arrayType)->get_element_type() == Type::get_void_type()) {
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

    if(indexType != Type::get_int_type()) {
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

    string memberName = ctx->member->getText();
    Value object = $(ctx->object).value;

    auto always = [](ISymbol* symbol) { (void)symbol; return true; };

    auto is_value = [](Value const& value) {
      return (value.is(ValueCategory::RVALUE) or value.is(ValueCategory::LVALUE)) and (
        value.type()->is_aggregate_type() or (
          PointerType::is_pointer(value.type()) and 
          PointerType::to_pointer(value.type())->get_pointed_type()->is_aggregate_type()
        )
      );
    };

    bool ok = object.holds(Value::Kind::STRUCT) 
    or object.holds(Value::Kind::NAMESPACE)
    or is_value(object);

    if(not ok) {
      this->error_at(
        ctx,
        ctx->object->getStart(),
        format(
          "The underlined expression '{}' of type '{}' is not an instance of a struct or a struct or a namespace",
          ctx->object->getText(),
          object.type()->get_name()
        )
      );
    } 

    if(is_value(object)) {
      auto asStruct = Struct::to_struct_type(object.type());
      // attempt auto dereference
      if(not asStruct) {
        asStruct = Struct::to_struct_type(PointerType::to_pointer(object.type())->get_pointed_type());
      }

      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else {
        ISymbol* member = asStruct->retrieve(memberName);
        if(auto field = Variable::to_variable(member)) {
          $(ctx).value = Value::from_field(field, object.category());
        } else $(ctx).value = Value::from_symbol(asStruct->retrieve(memberName));
      }
    }

    if(object.holds(Value::Kind::STRUCT)) {
      auto asStruct = *object.unwrap<Struct*>();
      ISymbol* member = asStruct->retrieve(memberName);
      if(member == nullptr) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Struct '{}' has no field or method called '{}'", asStruct->get_name(), memberName)
        );
      } else if(Variable::is_variable(member)) {
        this->error_at(
          ctx,
          ctx->IDENTIFIER()->getSymbol(),
          format("Field '{}' of struct '{}' cannot be accessed in a static way", memberName, asStruct->get_name())
        );
      } else $(ctx).value = Value::from_symbol(member);
    }

    if(object.holds(Value::Kind::NAMESPACE)) {
      auto asNamespace = *object.unwrap<Namespace*>();
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

    auto castInfo = valueType->is_convertible_to(targetType);
    if(not castInfo) {
      this->error_at(
        ctx,
        ctx->AS()->getSymbol(),
        format(
          "Invalid explicit conversion: cannot convert an expression of type '{}' into an expression of type '{}'",
          lhsType->get_name(),
          rhsType->get_name()
        )
      );
    } else {
      $(ctx).value = Value::from_rvalue(rhsType, nullptr);
      $(ctx).castOp = castInfo.value();
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
      } else {
        resultType = function->get_return_type();
        $(ctx)._operator = function;
      }
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