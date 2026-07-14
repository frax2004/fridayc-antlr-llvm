#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>
#include <Scope.hpp>


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
    this->visitChildren(ctx);
    this->pop();

    return {};
  }



  auto TypeCheckerVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    Console::debug("DeclarationStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    // TODO FIX THIS (INCOMPLETE)
    Pointer<ISymbolTable> scope = this->top();
    // TODO FOR NOW THE TYPE IS INFERRED AND THE REAL ONE IS IGNORED
    scope->define(make_shared<Variable>(*scope, ctx->id->getText(), *ctx->initializer->value.get_type()));

    return {};
  }

  auto TypeCheckerVisitor::visitIfStatement(FridayParser::IfStatementContext *ctx) -> any {
    Console::debug("IfStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitForStatement(FridayParser::ForStatementContext *ctx) -> any {
    Console::debug("ForStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    return {};
  }

  auto TypeCheckerVisitor::visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any {
    Console::debug("WhileStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

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
    this->visitChildren(ctx);
    // Pointer<Type> actual = any_cast<Pointer<Type>>(this->visit(ctx->expression()));
    // if(actual == ErrorType::get() or actual != this->M_currentFunctionReturnType) {
    //   this->error_at(
    //     ctx->expression()->getStart(),
    //     RETURN_TYPE_MISMATCH.format(actual->get_name(), this->M_currentFunctionReturnType->get_name())
    //   );
    //   return (Pointer<Type>)ErrorType::get();
    // } else return (Pointer<Type>)this->M_currentScope->resolve("void")->as<Struct>();
    return {};
  }

  auto TypeCheckerVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    Console::debug("PrintStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    // Pointer<Type> expected = PointerType::get((Pointer<Type>)this->M_currentScope->resolve("byte")->as<Struct>(), 1);
    // Pointer<Type> actual = any_cast<Pointer<Type>>(this->visit(ctx->expr()));

    // if(expected != actual) {
    //   this->error_at(
    //     ctx->expr()->getStart(),
    //     EXPRESSION_NOT_CONVERTIBLE.format(actual->get_name(), expected->get_name())
    //   );
    //   return (Pointer<Type>)ErrorType::get();
    // } else return (Pointer<Type>)this->M_currentScope->resolve("void")->as<Struct>();
    return {};
  }

}