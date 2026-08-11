#include <fridayc.hpp>


namespace friday::inline api {
  constexpr static auto RETURN_TYPE_MISMATCH       = "Expression of type '{}' does not match the function return type '{}'. Implicit casts are not permitted, if this is the problem, try adding an explicit cast."sv;
  constexpr static auto EXPRESSION_NOT_CONVERTIBLE = "Expression of type '{}' is not convertible to {}. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."sv;
  constexpr static auto ENTITY_REDECLARATION       = "Redeclaration of name '{}' previously already defined as a different entity."sv;
  constexpr static auto PARAM_REDECLARATION        = "In function declaration, redeclaration of parameter #{} named '{}' of type '{}' previously already defined."sv;
  constexpr static auto INVALID_PARAM_TYPE         = "In function declaration, parameter #{} named '{}' has an invalid type '{}'."sv;

  auto TypeCheckerVisitor::visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any {
    Console::debug(format("ScopeStatementContext: {}", ctx->getText()));

    ISymbolTable* parent = this->top();

    if(not parent) throw OperationNotSupportedError{};

    Scope* current = Scope::Factory::create(*parent);
    $(ctx->syntacticalScope()).scope = current;

    this->push(current);
    this->visitChildren(ctx);
    this->pop();

    return {};
  }

  auto TypeCheckerVisitor::visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any {
    Console::debug(format("BlockContext: {}", ctx->getText()));

    this->push($(ctx).scope);
    this->visitChildren(ctx);
    this->pop();

    return {};
  }

  auto TypeCheckerVisitor::visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any {
    Console::debug(format("TrailingBlockContext: {}", ctx->getText()));

    this->push($(ctx).scope);
    this->visit(ctx->expression());
    auto func = dynamic_cast<FridayParser::FreeFunctionStatementContext*>(ctx->parent);
    Type* expected = $(func->returnType).type;
    Type* actual = $(ctx->expression()).value.get_type();


    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        format(RETURN_TYPE_MISMATCH, actual->get_name(), expected->get_name())
      );
    }

    this->pop();

    return {};
  }



  auto TypeCheckerVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    Console::debug(format("DeclarationStatementContext: {}", ctx->getText()));
    this->visitChildren(ctx);

    ISymbolTable* scope = this->top();
    string name = ctx->id->getText();

    bool ok = true;
    if(scope->is_defined(name, &Variable::is_variable)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->id,
        format(ENTITY_REDECLARATION, name)
      );
    }

    Type* inferred = $(ctx->expression()).value.get_type();
    if(auto expected = ctx->type(); expected != nullptr and $(expected).type != inferred) {
      ok = false;
      this->error_at(
        ctx,
        ctx->ASSIGN()->getSymbol(),
        format(
          "In declaration of variable '{}', cannot assign an expression of type '{}' to an object of type '{}'",
          name,
          inferred->get_name(),
          $(expected).type->get_name()
        )
      );
    }

    if(ErrorType::is_error_type(inferred)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->ASSIGN()->getSymbol(),
        format(
          "In declaration of variable '{}', cannot declare a variable with an invalid type '{}'",
          name,
          ErrorType::get()->get_name()
        )
      );
    }

    if(not ok) return {};
    scope->define(Variable::Factory::create(*scope, name, *$(ctx->initializer).value.get_type()));

    return {};
  }

  auto TypeCheckerVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    Console::debug(format("IfStatementContext: {}", ctx->getText()));

    for(auto [condition, statement] : views::zip(ctx->conditions, ctx->scopes)) {
      this->visit(condition);

      if($(condition).value.get_type() != this->BOOL()) {
        this->error_at(
          ctx,
          condition->getStart(),
          format(
            "Condition expression expected to be of type '{}' but got an expression of type '{}'",
            this->BOOL()->get_name(),
            $(condition).value.get_type()->get_name()
          )
        );
      }

      this->visit(statement);
    }

    if(ctx->elseStatement) this->visit(ctx->elseStatement);

    return {};
  }

  auto TypeCheckerVisitor::visitForStatement(FridayParser::ForStatementContext *ctx) -> any {
    Console::debug(format("ForStatementContext: {}", ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any {
    Console::debug(format("WhileStatementContext: {}", ctx->getText()));

    this->visit(ctx->condition);
    if($(ctx->condition).value.get_type() != this->BOOL()) {
      this->error_at(
        ctx,
        ctx->condition->getStart(),
        format(
          "Condition expression expected to be of type '{}' but got an expression of type '{}'",
          this->BOOL()->get_name(),
          $(ctx->condition).value.get_type()->get_name()
        )
      );
    }

    this->visit(ctx->scope);

    return {};
  }

  auto TypeCheckerVisitor::visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any {
    Console::debug(format("ExpressionStatementContext: {}", ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any {
    Console::debug(format("DeferStatementContext: {}", ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any {
    Console::debug(format("ReturnStatementContext: {}", ctx->getText()));
    this->visit(ctx->expression());

    ant::tree::ParseTree* funcRule = dynamic_cast<ant::tree::ParseTree*>(ctx);
    while(dynamic_cast<FridayParser::FreeFunctionStatementContext*>(funcRule) == nullptr)  {
      funcRule = funcRule->parent;
    }
    
    auto asFunc = dynamic_cast<FridayParser::FreeFunctionStatementContext*>(funcRule);
    Type* expected = $(asFunc->returnType).type;
    Type* actual = $(ctx->expression()).value.get_type();

    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        format(RETURN_TYPE_MISMATCH, actual->get_name(), expected->get_name())
      );
    }

    return {};
  }

  auto TypeCheckerVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    Console::debug(format("PrintStatementContext: {}", ctx->getText()));
    this->visitChildren(ctx);

    auto actual = $(ctx->expression()).value.get_type();
    auto expected = PointerType::get(*this->BYTE(), 1);

    if(expected != actual) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        format(
          "Expression must be of type '{}' bug got an expression of type '{}'",
          expected->get_name(),
          actual->get_name()
        )
      );
    }

    return {};
  }

}