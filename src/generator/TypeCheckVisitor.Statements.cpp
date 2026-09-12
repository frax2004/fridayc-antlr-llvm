#include <fridayc.hpp>


namespace friday::inline api {
  constexpr static auto RETURN_TYPE_MISMATCH       = "Expression of type '{}' does not match the function return type '{}'. Implicit casts are not permitted, if this is the problem, try adding an explicit cast."sv;
  constexpr static auto EXPRESSION_NOT_CONVERTIBLE = "Expression of type '{}' is not convertible to {}. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."sv;
  constexpr static auto ENTITY_REDECLARATION       = "Redeclaration of name '{}' previously already defined as a different entity."sv;
  constexpr static auto PARAM_REDECLARATION        = "In function declaration, redeclaration of parameter #{} named '{}' of type '{}' previously already defined."sv;
  constexpr static auto INVALID_PARAM_TYPE         = "In function declaration, parameter #{} named '{}' has an invalid type '{}'."sv;

  auto TypeCheckerVisitor::visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any {
    Console::debug(format("ScopeStatementContext: {}", ctx->getText()));
    this->prepare_scope(ctx->syntacticalScope(), {});
    this->check_scope(ctx->syntacticalScope());

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
    Type* actual = $(ctx->expression()).value.type();

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

    Type* inferred = $(ctx->initializer).value.type();

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
  
    static set<Type*> proibitedTypes = {
      ErrorType::get(),
      Type::get_void_type(),
      UnresolvedOverloadType::get()
    };

    if(proibitedTypes.contains(inferred)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->ASSIGN()->getSymbol(),
        format(
          "In declaration of variable '{}', cannot declare a variable with an invalid type '{}'",
          name,
          inferred->get_name()
        )
      );
    }

    if(not ok) return {};
    Variable* var = Variable::Factory::create(*scope, name, *inferred);
    $(ctx).variable = var;
    scope->define(var);

    return {};
  }

  auto TypeCheckerVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    Console::debug(format("IfStatementContext: {}", ctx->getText()));

    for(auto [condition, statement] : views::zip(ctx->conditions, ctx->scopes)) {
      this->visit(condition);

      if($(condition).value.type() != Type::get_bool_type()) {
        this->error_at(
          ctx,
          condition->getStart(),
          format(
            "Condition expression expected to be of type '{}' but got an expression of type '{}'",
            Type::get_bool_type()->get_name(),
            $(condition).value.type()->get_name()
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

    vector<pair<string, Type*>> locals {};

    if(ctx->varname != nullptr) {
      // Indexed for loop
      string varname = ctx->varname->getText();
      ISymbolTable* scope = this->top();

      bool ok = true;
      if(scope->is_defined(varname, &Variable::is_variable)) {
        ok = false;
        this->error_at(
          ctx,
          ctx->varname,
          format(ENTITY_REDECLARATION, varname)
        );
      }

      this->visit(ctx->from);
      this->visit(ctx->to);

      Type* fromType = $(ctx->from).value.type();
      Type* toType = $(ctx->to).value.type();
      if(fromType != Type::get_int_type()) {
        this->error_at(
          ctx->from,
          ctx->from->getStart(),
          format(
            "The underlined lower bound expression of indexed for loop must be of type {}, got an expression of type {}",
            Type::get_int_type()->get_name(),
            fromType->get_name()
          )
        );
      }

      if(toType != Type::get_int_type()) {
        this->error_at(
          ctx->to,
          ctx->to->getStart(),
          format(
            "The underlined upper bound expression of indexed for loop must be of type {}, got an expression of type {}",
            Type::get_int_type()->get_name(),
            toType->get_name()
          )
        );
      }

      if(ok) {
        locals.push_back(pair{ varname, Type::get_int_type() });
      }
    } else {
      // (filtered) Slice for loop
      // assert ctx.enumerator was not defined in the current scope
      // assert ctx.itername was not defined in the current scope
      // assert ctx.slice is a slice
      // assert (if present) ctx.filterExpr is boolean
      ISymbolTable* scope = this->top();

      
      string itername = ctx->itername->getText();

      bool enumeratorWasDefined = ctx->enumerator != nullptr and scope->is_defined(
        ctx->enumerator->getText(), 
        &Variable::is_variable
      );
      
      bool iternameWasDefined = scope->is_defined(itername, &Variable::is_variable);

      if(enumeratorWasDefined) {
        this->error_at(
          ctx,
          ctx->enumerator,
          format(ENTITY_REDECLARATION, ctx->enumerator->getText())
        );
      }

      if(iternameWasDefined) {
        this->error_at(
          ctx,
          ctx->itername,
          format(ENTITY_REDECLARATION, itername)
        );
      }

      this->visit(ctx->slice);
      Type* sliceType = $(ctx->slice).value.type();

      if(not sliceType->is_slice_type()) {
        this->error_at(
          ctx->slice,
          ctx->slice->getStart(),
          format(
            "In range based for loop, the underlined range expression must be a slice but got an expression of type {}",
            sliceType->get_name()
          )
        );
      }

      if(ctx->enumerator != nullptr and not enumeratorWasDefined) {
        locals.push_back(pair{ ctx->enumerator->getText(), Type::get_int_type() });
      }
      
      if(not iternameWasDefined) {
        Type* iterType = PointerType::get(*ArrayType::to_array(sliceType)->get_element_type(), 1);
        locals.push_back(pair{ itername, iterType });
      }

    }

    this->prepare_scope(ctx->scope, locals);

    if(ctx->WHERE() != nullptr) {
      this->visit(ctx->filterExpr);

      Type* filterExprType = $(ctx->filterExpr).value.type();
      if(filterExprType != Type::get_bool_type()) {
        this->error_at(
          ctx->filterExpr,
          ctx->filterExpr->getStart(),
          format(
            "In range based for loop, the underlined filter expression must be of type {}, got an expresson of type {}",
            Type::get_bool_type()->get_name(),
            filterExprType->get_name()
          )
        );
      }
    }

    this->check_scope(ctx->scope);

    return {};
  }

  auto TypeCheckerVisitor::visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any {
    Console::debug(format("WhileStatementContext: {}", ctx->getText()));

    this->visit(ctx->condition);
    if($(ctx->condition).value.type() != Type::get_bool_type()) {
      this->error_at(
        ctx,
        ctx->condition->getStart(),
        format(
          "Condition expression expected to be of type '{}' but got an expression of type '{}'",
          Type::get_bool_type()->get_name(),
          $(ctx->condition).value.type()->get_name()
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
    if(dynamic_cast<FridayParser::DeferStatementContext*>(ctx->statement()) != nullptr) {
      this->error_at(
        ctx,
        ctx->statement()->getStart(),
        "The underlined statement is not a valid deferreable statement"
      );
    }
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
    Type* actual = $(ctx->expression()).value.type();

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

    static map<Type*, string> S_allowedTypes = {
      { Type::get_byteptr_type(), "%s"},
      { Type::get_int_type(), "%lld"},
      { Type::get_float_type(), "%lf"},
      { Type::get_byte_type(), "%c"},
      { Type::get_bool_type(), "%d"},
      { Type::get_voidptr_type(), "%p"}
    };

    static string hint = S_allowedTypes
    | views::keys
    | views::transform(&Type::get_name)
    | views::join_with(format("{}' or '{}{}", Console::Color::RESET, Console::Color::BOLD, Console::Color::YELLOW))
    | ranges::to<string>();

    Type* actual = $(ctx->expression()).value.type();

    if(not S_allowedTypes.contains(actual)) {
      this->error_at(
        ctx,
        ctx->expression()->getStart(),
        format(
          "Expression must either of type '{}{}{}{}' but got an expression of type '{}'",
          Console::Color::BOLD, 
          Console::Color::YELLOW,
          hint,
          Console::Color::RESET,
          actual->get_name()
        )
      );
    } else $(ctx).fmt = S_allowedTypes.at(actual);

    return {};
  }

}