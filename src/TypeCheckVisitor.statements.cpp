#include <TypeCheckerVisitor.hpp>
#include <OperationNotSupportedError.hpp>
#include <ErrorType.hpp>


namespace friday::inline api::inline pipeline {
  constexpr static auto RETURN_TYPE_MISMATCH = "Expression of type '{}' does not match the function return type '{}'. Implicit casts are not permitted, if this is the problem, try adding an explicit cast."_f;
  constexpr static auto EXPRESSION_NOT_CONVERTIBLE = "Expression of type '{}' is not convertible to {}. Implicit cast are not permitted, if this is the problem, try adding an explicit cast."_f;
  constexpr static auto ENTITY_REDECLARATION = "Redeclaration of name '{}' previously already defined as a different entity."_f;
  constexpr static auto PARAM_REDECLARATION = "In function declaration, redeclaration of parameter #{} named '{}' of type '{}' previously already defined."_f;
  constexpr static auto INVALID_PARAM_TYPE = "In function declaration, parameter #{} named '{}' has an invalid type '{}'."_f;

  auto TypeCheckerVisitor::visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any {
    Console::debug("DeclarationStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    

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
    this->visitChildren(ctx);
    // Type* actual = any_cast<Type*>(this->visit(ctx->expression()));
    // if(actual == ErrorType::get() or actual != this->M_currentFunctionReturnType) {
    //   this->errorAt(
    //     ctx->expression()->getStart(),
    //     RETURN_TYPE_MISMATCH.format(actual->getName(), this->M_currentFunctionReturnType->getName())
    //   );
    //   return (Type*)ErrorType::get();
    // } else return (Type*)this->M_currentScope->resolve("void")->as<Struct>();
    return {};
  }

  auto TypeCheckerVisitor::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any {
    Console::debug("PrintStatementContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    // Type* expected = PointerType::get((Type*)this->M_currentScope->resolve("byte")->as<Struct>(), 1);
    // Type* actual = any_cast<Type*>(this->visit(ctx->expr()));

    // if(expected != actual) {
    //   this->errorAt(
    //     ctx->expr()->getStart(),
    //     EXPRESSION_NOT_CONVERTIBLE.format(actual->getName(), expected->getName())
    //   );
    //   return (Type*)ErrorType::get();
    // } else return (Type*)this->M_currentScope->resolve("void")->as<Struct>();
    return {};
  }

  auto TypeCheckerVisitor::visitScope(FridayParser::ScopeContext *ctx) -> any {
    Console::debug("ScopeContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);

    // auto toType = (Type*(*)(any const&))&any_cast<Type*>;
    // auto byVisiting = [this](FridayParser::StatementContext* ctx) -> any {
    //   return this->visit(ctx);
    // };

    // auto statements = ctx->statement()
    // | views::transform(byVisiting)
    // | views::transform(toType);

    // SymbolTable scope { this->M_currentScope };
    // this->beginScope(scope);

    // bool ok = true;
    // for(auto statement : statements) {
    //   if(statement == ErrorType::get()) {
    //     ok = false;
    //   }
    // }
    // this->endScope();

    // return (Type*)(ok ? (Type*)this->M_currentScope->resolve("void")->as<Struct>() : (Type*)ErrorType::get());
    return {};
  }

  auto TypeCheckerVisitor::visitInlineScope(FridayParser::InlineScopeContext *ctx) -> any {
    Console::debug("InlineScopeContext: {}"_f.format(ctx->getText()));
    this->visitChildren(ctx);
    // Type* T = any_cast<Type*>(this->visit(ctx->expr()));
    // if(T == ErrorType::get() or T != this->M_currentFunctionReturnType) {
    //   this->errorAt(
    //     ctx->expr()->getStart(),
    //     RETURN_TYPE_MISMATCH.format(T->getName(), this->M_currentFunctionReturnType->getName())
    //   );
    //   return (Type*)ErrorType::get();
    // } else return (Type*)this->M_currentScope->resolve("void")->as<Struct>();
    return {};
  }

  // auto TypeChecker::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> any {
  //   Console::debug("FunctionStatementContext: {}"_f.format(ctx->getText()));
  //   this->visitChildren(ctx);

    // auto toType = (Type*(*)(any const&))&any_cast<Type*>;

    // auto byVisiting = [this](FridayParser::TypeContext* ctx) -> any {
    //   return this->visit(ctx);
    // };
    // auto toPair = [](tuple<string, Type*> const& pair) -> pair<string, Type*> {
    //   return make_pair(get<0>(pair), get<1>(pair));
    // };
    // auto isFunctionOrVariable = [](Symbol* symbol) -> bool {
    //   return symbol->is<Function>() or symbol->is<Variable>();
    // };

    // string name = ctx->name->getText();
    // Type* returnType = any_cast<Type*>(this->visit(ctx->returnType));

    // vector<pair<string, Type*>> parameters = views::zip(
    //   ctx->paramsNames
    //   | views::transform(ant::Token::getText),
    //   ctx->paramsTypes
    //   | views::transform(byVisiting)
    //   | views::transform(toType)
    // )
    // | views::transform(toPair)
    // | ranges::to<vector>();

    // bool ok = true;


    // if(auto alreadyExistingFunction = this->M_currentScope->resolveIf(name, isFunctionOrVariable)) {
    //   ok = false;
    //   this->errorAt(ctx->name, ENTITY_REDECLARATION.format(name));
    // }

    // SymbolTable functionScope { this->M_currentScope };
    // this->beginScope(functionScope);

    // for(u64 i = 0; i < parameters.size(); ++i) {
    //   bool paramOk = true;
    //   auto const& [paramName, paramType] = parameters[i];

    //   if(this->M_currentScope->isDefinedLocal(paramName)) {
    //     paramOk = false;
    //     this->errorAt(ctx->name, PARAM_REDECLARATION.format(i+1, paramName, paramType->getName()));
    //   }

    //   if(paramType == (Type*)ErrorType::get()) {
    //     paramOk = false;
    //     this->errorAt(ctx->name, INVALID_PARAM_TYPE.format(i+1, paramName, paramType->getName()));
    //   }

    //   if(paramOk) this->M_currentScope->define(paramName, new Variable(paramName, paramType));
    //   else ok = false;
    // }

    // if(returnType == (Type*)ErrorType::get()) {
    //   ok = false;
    //   this->errorAt(
    //     ctx->returnType->getStart(),
    //     "In function declaration, the function return type is an invalid type '{}'"_f.format(returnType->getName())
    //   );
    // }

    // Type* blockType = ({
    //   Type* tmpRetType = this->M_currentFunctionReturnType;
    //   this->M_currentFunctionReturnType = returnType;
    //   Type* res = any_cast<Type*>(this->visit(ctx->functionScope()));
    //   this->M_currentFunctionReturnType = tmpRetType;
    //   res;
    // });

    // this->endScope();

    // if(blockType == (Type*)ErrorType::get()) {
    //   ok = false;
    // }

    // if(ok) {
    //   this->M_currentScope->define(
    //     name, 
    //     new Function{ 
    //       name, 
    //       returnType, 
    //       parameters 
    //     }
    //   );
    // }

    // return (Type*)(ok ? (Type*)this->M_currentScope->resolve("void")->as<Struct>() : (Type*)ErrorType::get());
  // }

}