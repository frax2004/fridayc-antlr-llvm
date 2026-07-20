#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <Scope.hpp>
#include <PointerType.hpp>


namespace friday::inline api::inline pipeline {
  constexpr static auto RETURN_TYPE_MISMATCH       = "Expression of type '{}' does not match the function return type '{}'. Implicit casts are not permitted, if this is the problem, try adding an explicit cast."_f;
  constexpr static auto EXPRESSION_NOT_CONVERTIBLE = "Expression of type '{}' is not convertible to {}. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f;
  constexpr static auto ENTITY_REDECLARATION       = "Redeclaration of name '{}' previously already defined as a different entity."_f;
  constexpr static auto PARAM_REDECLARATION        = "In function declaration, redeclaration of parameter #{} named '{}' of type '{}' previously already defined."_f;
  constexpr static auto INVALID_PARAM_TYPE         = "In function declaration, parameter #{} named '{}' has an invalid type '{}'."_f;

  auto TypeCheckerVisitor::visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any {
    Console::debug("ScopeStatementContext: {}"_f.format(ctx->getText()));

    Pointer<ISymbolTable> parent = this->top();

    if(not parent) throw OperationNotSupportedError("Internal error.");

    rc<Scope> current = make_shared<Scope>(*parent);
    ctx->syntacticalScope()->scope = current;

    this->push(current.get());
    this->visitChildren(ctx);
    this->pop();

    return {};
  }

  auto TypeCheckerVisitor::visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any {
    Console::debug("BlockContext: {}"_f.format(ctx->getText()));

    this->push(ctx->scope.get());
    this->visitChildren(ctx);
    this->pop();

    return {};
  }

  auto TypeCheckerVisitor::visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any {
    Console::debug("TrailingBlockContext: {}"_f.format(ctx->getText()));

    this->push(ctx->scope.get());
    this->visit(ctx->expression());
    auto func = rtti::cast<FridayParser::FreeFunctionStatementContext>(ctx->parent);
    Pointer<Type> expected = func->returnType->typeId;
    Pointer<Type> actual = ctx->expression()->value.get_type();
    

    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        RETURN_TYPE_MISMATCH.format(actual->get_name(), expected->get_name())
      );
    }

    this->pop();

    return {};
  }



  auto TypeCheckerVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    Console::debug("DeclarationStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    Pointer<ISymbolTable> scope = this->top();
    string name = ctx->id->getText();

    bool ok = true;
    if(scope->is_defined(name, &Variable::is_variable)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->id,
        ENTITY_REDECLARATION.format(name)
      );
    }

    Pointer<Type> inferred = ctx->expression()->value.get_type();
    if(auto expected = ctx->type(); expected != nullptr and expected->typeId != inferred) {
      ok = false;
      this->error_at(
        ctx,
        ctx->ASSIGN()->getSymbol(),
        "In declaration of variable '{}', cannot assign an expression of type '{}' to an object of type '{}'"_f.format(
          name,
          inferred->get_name(),
          expected->typeId->get_name()
        )
      );
    }

    if(ErrorType::is_error_type(inferred)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->ASSIGN()->getSymbol(),
        "In declaration of variable '{}', cannot declare a variable with an invalid type '{}'"_f.format(
          name,
          ErrorType::get()->get_name()
        )
      );
    }

    if(not ok) return {};
    scope->define(make_shared<Variable>(*scope, name, *ctx->initializer->value.get_type()));

    return {};
  }

  auto TypeCheckerVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    Console::debug("IfStatementContext: {}"_f.format(ctx->getText()));

    for(auto [condition, statement] : views::zip(ctx->conditions, ctx->scopes)) {
      this->visit(condition);

      if(condition->value.get_type() != this->BOOL()) {
        this->error_at(
          ctx,
          condition->getStart(),
          "Condition expression expected to be of type '{}' but got an expression of type '{}'"_f.format(
            this->BOOL()->get_name(),
            condition->value.get_type()->get_name()
          )
        );
      }

      this->visit(statement);
    }

    if(ctx->elseStatement) this->visit(ctx->elseStatement);

    return {};
  }

  auto TypeCheckerVisitor::visitForStatement(FridayParser::ForStatementContext *ctx) -> any {
    Console::debug("ForStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any {
    Console::debug("WhileStatementContext: {}"_f.format(ctx->getText()));

    this->visit(ctx->condition);
    if(ctx->condition->value.get_type() != this->BOOL()) {
      this->error_at(
        ctx,
        ctx->condition->getStart(),
        "Condition expression expected to be of type '{}' but got an expression of type '{}'"_f.format(
          this->BOOL()->get_name(),
          ctx->condition->value.get_type()->get_name()
        )
      );
    }

    this->visit(ctx->scope);

    return {};
  }

  auto TypeCheckerVisitor::visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any {
    Console::debug("ExpressionStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any {
    Console::debug("DeferStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any {
    Console::debug("ReturnStatementContext: {}"_f.format(ctx->getText()));
    this->visit(ctx->expression());

    Pointer<ant::tree::ParseTree> funcRule = rtti::cast<ant::tree::ParseTree>(ctx);
    while(not rtti::instance_of<FridayParser::FreeFunctionStatementContext>(funcRule)) {
      funcRule = funcRule->parent;
    }
    
    auto asFunc = rtti::cast<FridayParser::FreeFunctionStatementContext>(funcRule);
    Pointer<Type> expected = asFunc->returnType->typeId;
    Pointer<Type> actual = ctx->expression()->value.get_type();

    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        RETURN_TYPE_MISMATCH.format(actual->get_name(), expected->get_name())
      );
    }

    return {};
  }

  auto TypeCheckerVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    Console::debug("PrintStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    auto actual = ctx->expression()->value.get_type();
    auto expected = PointerType::get(*this->BYTE(), 1);

    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        "Expression must be of type '{}' bug got an expression of type '{}'"_f.format(
          expected->get_name(),
          actual->get_name()
        )
      );
    }

    return {};
  }

}