#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <PointerType.hpp>
#include <ArrayType.hpp>

namespace friday::inline api::inline pipeline {
  auto TypeCheckerVisitor::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any {
    Console::debug("CallExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    auto candidate = ctx->func->typeId;

    if(candidate == ErrorType::get() or not rtti::instance_of<Overload>(candidate)) {
      this->error_at(
        ctx->getStart(),
        "The underlined expression '{}' of type '{}' is not a function and cannot be called."_f.format(
          ctx->func->getText(),
          candidate->get_name()
        )
      );
      return {};
    }

    auto overload = rtti::cast<Overload>(candidate);

    auto argsTypes = ctx->args
    | views::transform(&FridayParser::ExpressionContext::typeId)
    | ranges::to<vector>();

    if(auto memberAccess = rtti::cast<FridayParser::MemberAccessExpressionContext>(ctx->func)) {
      argsTypes.insert(argsTypes.begin(), memberAccess->object->typeId);
    }

    auto function = overload->try_match(argsTypes);

    if(function.expired()) {
      this->error_at(
        ctx->func->getStart(),
        "No overload of function '{}' matches the given arguments ({}):\nAvailable overloads:\n{}"_f.format(
          overload->get_qualified_id(),
          argsTypes 
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

    bool ok = true;
    if(funcType->params_size() != argsTypes.size()) {
      ok = false;
      this->error_at(
        ctx->getStart(),
        "In function call '{}' of type '{}' : the function expects {} arguments but {} were given."_f.format(
          ctx->func->getText(),
          funcType->get_name(),
          funcType->params_size(),
          argsTypes.size()
        )
      );
    }

    for(u64 i = 0; i < min(argsTypes.size(), funcType->params_size()); i++) {
      Pointer<Type> T = argsTypes[i];

      if(T != funcType->get_param_type(i)) {
        ok = false;
        this->error_at(
          ctx->args[i]->getStart(),
          "In function call '{}' of type '{}' : argument type mismatch. Expected '{}', got '{}'"_f.format(
            ctx->getText(),
            funcType->get_name(),
            funcType->get_param_type(i)->get_name(),
            T->get_name()
          )
        );
      }
    }

    if(ok) ctx->typeId = funcType->get_return_type();

    return {};
  }

  auto TypeCheckerVisitor::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any {
    Console::debug("IdentifierExpressionContext: {}"_f.format(ctx->getText()));
    
    string id = ctx->IDENTIFIER()->getText();
    weak<ISymbolTable> scope = this->top();
    if(scope.expired()) throw OperationNotSupportedError("Internal error.");

    weak<ISymbol> symbol = scope.lock()->look_up(id, {});

    if(symbol.expired()) {
      // auto toSuggestion = [](string const& message) {
      //   return format(" Did you mean '{}'?", message);
      // };

      // string suggestion = this->top()->most_similar(id, isVariableOrFunction, 3);
      // .transform(toSuggestion)
      string suggestion = "";

      this->error_at(
        ctx->getStart(),
        "There is no object named '{}' in the current scope.{}"_f.format(
          id,
          suggestion
        )
      );
    } else {
      rc<ISymbol> ref = symbol.lock();
      if(rtti::instance_of<Variable>(ref.get())) ctx->typeId = dynamic_pointer_cast<Variable>(ref)->get_type();
      else if(rtti::instance_of<Struct>(ref.get())) ctx->typeId = dynamic_pointer_cast<Type>(ref).get();
      else if(rtti::instance_of<Overload>(ref.get())) ctx->typeId = dynamic_pointer_cast<Type>(ref).get();
      else throw InvalidArgumentError{"Invalid symbol kind in identifier expression"};
    }
    
    return {};
  }

  auto TypeCheckerVisitor::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any {
    Console::debug("CharLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->BYTE();
    return {};
  }

  auto TypeCheckerVisitor::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any {
    Console::debug("stringLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = PointerType::get(*this->BYTE(), 1);
    return {};
  }

  auto TypeCheckerVisitor::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any {
    Console::debug("BoolLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->BOOL();
    return {};
  }

  auto TypeCheckerVisitor::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any {
    Console::debug("FloatLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->FLOAT();
    return {};
  }

  auto TypeCheckerVisitor::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any {
    Console::debug("IntLiteralExpressionContext: {}"_f.format(ctx->getText()));
    ctx->typeId = this->INT();
    return {};
  }

  auto TypeCheckerVisitor::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any {
    Console::debug("GroupingExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    ctx->typeId = ctx->expression()->typeId;
    return {};
  }

  auto TypeCheckerVisitor::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any {
    Console::debug("SubscriptExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Pointer<Type> arrayType = ctx->array->typeId;
    Pointer<Type> indexType = ctx->index->typeId;

    Pointer<ArrayType> asArrayType = rtti::cast<ArrayType>(arrayType);

    bool ok = true;
    if(
      asArrayType == nullptr
      or rtti::cast<Type>(asArrayType) == ErrorType::get()  
      or asArrayType->get_element_type() == this->VOID()
    ) {
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

    if(ok) ctx->typeId = asArrayType->get_element_type();
    return {};
  }

  auto TypeCheckerVisitor::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any {
    Console::debug("BinaryExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Pointer<Type> lhsType = ctx->left->typeId;
    Pointer<Type> rhsType = ctx->right->typeId;

    string operatorName = "operator{}"_f.format(ctx->binaryOperator->getText());
    weak<Function> function = this->find_binary_operator(operatorName, lhsType, rhsType);

    string suggestion = "";

    if(function.expired()) {
      if(lhsType == rhsType) {
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
    } else ctx->typeId = function.lock()->get_return_type();

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any {
    Console::debug("UnaryPrefixExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    
    // Pointer<Type> type = any_cast<Pointer<Type>>(this->visit(ctx->expression()));
    // u64 oper = ctx->unaryOperator->get_type();
    // string unaryOperatorName = Type::getUnaryPrefixExpressionOperatorName(oper, type);


    // if(Pointer<Struct> asStruct = type->as<Struct>()) {
    //   if(const Pointer<Function> unaryOperator = asStruct->find_method(unaryOperatorName)) {
    //     ctx->typeId = unaryOperator->get_type()->as<const FunctionType>()->get_return_type();
    //   }
    // }

    // this->error_at(
    //   ctx->unaryOperator,
    //   "No matching function for call to '{}' with operand of type '{}'"_f.format(
    //     unaryOperatorName,
    //     type->getName()
    //   )
    // );
    
    return {};
  }

  auto TypeCheckerVisitor::visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any {
    Console::debug("MemberAccessExpressionContext: {}"_f.format(ctx->getText()));

    this->visit(ctx->object);
    auto memberName = ctx->member->getText();

    Pointer<Struct> asStruct = rtti::cast<Struct>(ctx->object->typeId);
    if(asStruct == nullptr) {
      this->error_at(
        ctx->object->getStart(),
        "Expression of type '{}' is not a struct"_f.format(ctx->object->typeId->get_name())
      );
    } else if(not asStruct->is_defined(memberName)) {
      this->error_at(
        ctx->IDENTIFIER()->getSymbol(),
        "Struct '{}' has no field or method called '{}'"_f.format(asStruct->get_name(), memberName)
      );
    } else {
      auto member = asStruct->look_up(memberName, {}).lock().get();
      if(rtti::instance_of<Variable>(member)) {
        ctx->typeId = rtti::cast<Variable>(member)->get_type();
      } else if(rtti::instance_of<Overload>(member)) {
        ctx->typeId = rtti::cast<Type>(member);
      }
    } 

    return {};
  }

  auto TypeCheckerVisitor::visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any {
    Console::debug("ArrayLiteralExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any {
    Console::debug("ExplicitCastExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any {
    Console::debug("NewExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any {
    Console::debug("UnaryPostfixExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any {
    Console::debug("NullLiteralExpressionContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }
}