#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  static auto to_member_access_expr(Pointer<FridayParser::ExpressionContext> expr) {
    return rtti::cast<FridayParser::MemberAccessExpressionContext>(expr);
  }

  auto TypeCheckerVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    const auto candidate = ctx->func->value
    .to_overload()
    .value_or({});

    if(candidate.expired()) {
      this->error_at(
        ctx->getStart(),
        "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
          ctx->func->getText(),
          ctx->func->value.get_type()->get_name()
        )
      );
      return {};
    }

    const rc<Overload> overload = candidate.lock();
    weak<Function> function = {};

    if(auto memberAccess = to_member_access_expr(ctx->func); memberAccess != nullptr) {
      auto params_with_this = [memberAccess, ctx] -> generator<Pointer<Type>> {
        co_yield PointerType::get(*memberAccess->object->value.get_type(), 1);
        for(auto arg : ctx->args) co_yield arg->value.get_type();
      };
      
      function = overload->try_match(params_with_this() | ranges::to<vector>());
    }
    
    auto try_static = [ctx, &overload]() {
      return overload
      ->try_match(
        ctx->args 
        | views::transform(&FridayParser::ExpressionContext::value)
        | views::transform(&Value::get_type)
        | ranges::to<vector>()
      )
      .to_optional();
    };

    function = function
    .to_optional()
    .or_else(try_static)
    .value_or({});

    if(function.expired()) {
      function = overload->try_match(
        ctx->args
        | views::transform(&FridayParser::ExpressionContext::value)
        | views::transform(&Value::get_type)
        | ranges::to<vector>()
      );
    }

    if(function.expired()) {
      this->error_at(
        ctx->func->getStart(),
        "No overload of function '{}' matches the given arguments ({}):\nAvailable overloads:\n{}"_f.format(
          overload->get_qualified_id(),
          ctx->args
          | views::transform(&FridayParser::ExpressionContext::value)
          | views::transform(&Value::get_type)
          | views::transform(&Type::get_name)
          | views::join_with(", "s)
          | ranges::to<string>(),
          overload->get_functions()
          | views::transform(&weak<Function>::lock)
          | views::transform(&rc<Function>::get)
          | views::transform(&Function::get_type)
          | views::transform(&Type::get_name)
          | views::join_with("\n"s)
          | ranges::to<string>()
        )
      );
      return {};
    }

    auto funcType = rtti::cast<FunctionType>(function.lock()->get_type());
    ctx->value = Value::from_value(funcType->get_return_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    this->visitChildren(ctx);
    ctx->value = Value::from_value(ctx->expression()->value.get_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Pointer<Type> arrayType = ctx->array->value.get_type();
    Pointer<Type> indexType = ctx->index->value.get_type();

    bool ok = true;
    if(not ArrayType::is_array(arrayType) or ArrayType::to_array(arrayType)->get_element_type() == this->VOID()) {
      ok = false;
      this->error_at(
        ctx->array->getStart(),
        "Array expression '{}' of type '{}' is not a valid array or pointer that can be dereferenced."_f.format(
          ctx->array->getText(),
          arrayType->get_name()
        )
      );
    }

    if(indexType != this->INT()) {
      ok = false;
      this->error_at(
        ctx->index->getStart(),
        "Array subcript index expression '{}' of type '{}' is not convertible to int. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f.format(
          ctx->index->getText(),
          indexType->get_name()
        )
      );
    }

    if(not ok) return {};

    ctx->value = Value::from_unknown_value(
      ArrayType::to_array(arrayType)->get_element_type(),
      ctx->array->value.get_category(),
      nullptr
    );
    
    return {};
  }

  auto TypeCheckerVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Pointer<Type> lhsType = ctx->left->value.get_type();
    Pointer<Type> rhsType = ctx->right->value.get_type();

    string operatorName = "operator{}"_f.format(ctx->binaryOperator->getText());
    weak<Function> function = this->find_binary_operator(operatorName, lhsType, rhsType);

    string suggestion = "";

    if(function.expired()) {
      if(lhsType != rhsType) {
        suggestion = " Implicit casts are not permitted so, if this is a cast problem, try adding an explicit cast.";
      }
      this->error_at(
        ctx->binaryOperator,
        "No matching function for call to '{}' with operands of types '{}' and '{}'.{}"_f.format(
          operatorName,
          lhsType->get_name(),
          rhsType->get_name(),
          suggestion
        )
      );
    } else ctx->value = Value::from_value(function.lock()->get_return_type(), nullptr);

    return {};
  }

  auto TypeCheckerVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    auto memberName = ctx->member->getText();
    auto always = [](Pointer<ISymbol> symbol) { (void)symbol; return true; };
    auto is_value = [](Value const& value) {
      return value.is_llvm_value() and (
        rtti::instance_of<Struct>(value.get_type()) or (
          PointerType::is_pointer(value.get_type())
          and rtti::instance_of<Struct>(PointerType::to_pointer(value.get_type())->get_pointed_type())
        )
      );
    };

    bool ok = ctx->object->value.is_struct() 
    or ctx->object->value.is_namespace() 
    or ctx->object->value.is_llvm_value();

    if(not ok) {
      this->error_at(
        ctx->object->getStart(),
        "The underlined expression '{}' of type '{}' is not an instance of a struct or a struct or a namespace"_f.format(
          ctx->object->getText(),
          ctx->object->value.get_type()->get_name()
        )
      );
    } 

    if(is_value(ctx->object->value)) {
      auto asStruct = rtti::cast<Struct>(ctx->object->value.get_type());
      if(not asStruct) asStruct = rtti::cast<Struct>(PointerType::to_pointer(ctx->object->value.get_type())->get_pointed_type());

      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx->IDENTIFIER()->getSymbol(),
          "Struct '{}' has no field or method called '{}'"_f.format(asStruct->get_name(), memberName)
        );
      } else ctx->value = Value::from_symbol(asStruct->look_up(memberName, {}));
    }

    if(ctx->object->value.is_struct()) {
      auto asStruct = ctx->object->value.to_struct().value().lock();
      if(not asStruct->is_defined(memberName, always)) {
        this->error_at(
          ctx->IDENTIFIER()->getSymbol(),
          "Struct '{}' has no field or method called '{}'"_f.format(asStruct->get_name(), memberName)
        );
      } else ctx->value = Value::from_symbol(asStruct->look_up(memberName, {}));
    }

    if(ctx->object->value.is_namespace()) {
      auto asNamespace = ctx->object->value.to_struct().value().lock();
      if(not asNamespace->is_defined(memberName, always)) {
        this->error_at(
          ctx->IDENTIFIER()->getSymbol(),
          "Namespace '{}' has no variable or function or struct called '{}'"_f.format(asNamespace->get_qualified_id(), memberName)
        );
      } else ctx->value = Value::from_symbol(asNamespace->look_up(memberName, {}));
    }


    return {};
  }

  auto TypeCheckerVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    this->visitChildren(ctx);

    Pointer<Type> type = ctx->type()->typeId;

    
    if(auto asStruct = rtti::cast<Struct>(type)) {
      auto fieldsNames = ctx->fields 
      | views::transform(&ant::Token::getText);
      
      auto initializers = ctx->initializers 
      | views::transform(&FridayParser::ExpressionContext::value)
      | views::transform(&Value::get_type);
      
      bool ok = true;
      for(auto [i, field_and_type] : views::zip(fieldsNames, initializers) | views::enumerate) {
        auto [name, actual] = field_and_type;

        auto field = asStruct->find_field(name, {});
        if(field.expired()) {
          ok = false;
          this->error_at(
            ctx->fields[i],
            "In new expression (#{}-th field), struct '{}' has no field named '{}'"_f.format(
              i, 
              asStruct->get_name(), 
              name
            )
          );
          continue;
        }

        Pointer<Type> expected = field.lock()->get_type();
        if(expected != actual) {
          ok = false;
          this->error_at(
            ctx->initializers[i]->getStart(),
            "In new expression, in the assignment of field '{}' requires an expression of type '{}' but got a value of type '{}'"_f.format(
              name,
              expected->get_name(),
              actual->get_name()
            )
          );
        }
      }

      if(not ok) return {};

      ctx->value = Value::from_value(type, nullptr);

    } else {
      this->error_at(
        ctx->type()->getStart(),
        "In new expression '{}', cannot create instance of type '{}'"_f.format(
          ctx->getText(),
          type->get_name()
        )
      );
    }
    
    return {};
  }

}