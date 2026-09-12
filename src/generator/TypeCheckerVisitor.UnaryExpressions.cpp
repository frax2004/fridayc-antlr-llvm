#include <fridayc.hpp>


namespace friday::inline api {
  
  auto TypeCheckerVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitNewExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* type = $(ctx->type()).type;
    if(PrimitiveType::is_primitive(type)) {
      this->error_at(
        ctx,
        ctx->type()->getStart(),
        format(
          "In new expression '{}', cannot create instance of primitive type '{}'",
          ctx->getText(),
          type->get_name()
        )
      );
    } else if(auto asStruct = Struct::to_struct_type(type)) {
      auto actualFields = views::zip(
        ctx->fields 
        | views::transform(&ant::Token::getText),
        ctx->initializers
        | views::transform([](FridayParser::ExpressionContext* expr) { return &$(expr).value; })
        | views::transform(&Value::type)
        | views::enumerate
      )
      | ranges::to<map<string, tuple<size_t, Type*>>>();

      bool ok = true;
      for(auto field : asStruct->get_fields()) {
        // Field has no initializer value
        auto fieldIter = actualFields.find(field->get_qualified_id()); 
        u64 fieldIndex = asStruct->get_field_index(field->get_qualified_id());

        if(fieldIter == actualFields.end()) {
          ok = false;
          this->error_at(
            ctx,
            ctx->getStop(),
            format(
              "In new expression, required #{}-th field '{}' is missing an initializer value.",
              fieldIndex+1,
              field->get_qualified_id()
            )
          );
          continue;
        }

        Type* actual = get<1>(fieldIter->second);
        Type* expected = field->get_type();
        actualFields.erase(fieldIter);

        // Field has different type
        if(expected != actual) {
          ok = false;
          this->error_at(
            ctx,
            ctx->initializers[fieldIndex]->getStart(),
            format(
              "In new expression, in the assignment of field '{}' requires an expression of type '{}' but got a value of type '{}'",
              field->get_qualified_id(),
              expected->get_name(),
              actual->get_name()
            )
          );
        }
      }

      // Struct has no such fields
      for(auto [name, indexed_type] : actualFields) {
        ok = false;
        auto [i, type] = indexed_type;

        this->error_at(
          ctx,
          ctx->fields[i],
          format(
            "In new expression, struct '{}' has no field named '{}' of type '{}'",
            asStruct->get_name(), 
            name,
            type->get_name()
          )
        );
      }

      if(not ok) return {};

      $(ctx).value = Value::from_rvalue(type, nullptr);

    } else {
      this->error_at(
        ctx,
        ctx->type()->getStart(),
        format(
          "In new expression '{}', cannot create instance of non-structural type '{}'",
          ctx->getText(),
          type->get_name()
        )
      );
    }
    
    return {};
  }

  auto TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitCompTimeUnaryPrefixExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    switch(ctx->unaryOperator->getType()) {
      case FridayParser::SIZEOF: {
        i64 size = static_cast<i64>($(ctx->target).type->size());
        $(ctx).value = Value::from_constant(Type::get_int_type(), Constant::from_int(size));
        break;
      } case FridayParser::ALIGNOF: {
        i64 alignment = static_cast<i64>($(ctx->target).type->alignment());
        $(ctx).value = Value::from_constant(Type::get_int_type(), Constant::from_int(alignment));
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
        if($(ctx->operand).value.category() != ValueCategory::LVALUE) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            "Operand of a reference expression must be an lvalue (cannot take the address of a temporary)"
          );
        }

        if(ErrorType::is_error_type($(ctx->operand).value.type())) {
          ok = false;
          this->error_at(
            ctx,
            ctx->unaryOperator,
            format("Cannot take the address of an expression with invalid type '{}'", ErrorType::get()->get_name())
          );
        }

        if(not ok) break;

        $(ctx).value = Value::from_rvalue(
          PointerType::get(*$(ctx->operand).value.type(), 1), 
          nullptr
        );

        break;
      } case FridayParser::STAR: {

        auto pointer = PointerType::to_pointer($(ctx->operand).value.type());
        if(not pointer or pointer->get_pointed_type() == Type::get_void_type()) {
          this->error_at(
            ctx,
            ctx->unaryOperator,
            format("Cannot dereference an expression of type '{}'", $(ctx->operand).value.type()->get_name())
          );
        } else $(ctx).value = Value::from_lvalue(pointer->get_pointed_type(), nullptr, nullptr);

        break;
      } default: {
        Type* type = $(ctx->expression()).value.type();
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
        } else {
          $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);
          $(ctx)._operator = function;
        }

        break;
      }
    }

    return {};
  }


  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug(format("TypeCheckerVisitor::visitUnaryPostfixExpression({})", ctx->getText()));
    this->visitChildren(ctx);

    Type* type = $(ctx->expression()).value.type();

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
    } else {
      $(ctx).value = Value::from_rvalue(function->get_return_type(), nullptr);
      $(ctx)._operator = function;
    }

    return {};
  }

}