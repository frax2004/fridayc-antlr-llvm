#include <OverloadSolverVisitor.hpp>
#include <OperationNotSupportedError.hpp>


namespace friday::inline api::inline pipeline {

  OverloadSolverVisitor::OverloadSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto OverloadSolverVisitor::beginUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::endUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {

    auto isErrorType = [](Type* other) { 
      return other == ErrorType::get(); 
    };

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayParser::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };
    
    string overloadName = ctx->name->getText();

    auto paramsTypes = ctx->paramsTypes
    | views::transform(&FridayParser::TypeContext::typeId)
    | ranges::to<vector>();

    auto retType = ctx->returnType->typeId;
    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(isErrorType) | views::enumerate) {
      ok = false;
      this->errorAt(
        ctx->paramsTypes[i]->getStart(),
        "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\""_f.format(
          i,
          ctx->paramsNames[i]->getText(),
          ctx->paramsTypes[i]->getText()
        )
      );
    }

    if(retType == ErrorType::get()) {
      ok = false;
      this->errorAt(
        ctx->returnType->getStart(),
        "In function declaration, the return type is of an invalid error type \"{}\""_f.format(
          ctx->returnType->getText()
        )
      );
    }

    if(ctx->overloadDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Overload> asOverload = ctx->overloadDecl.lock();

    if(asOverload->hasMatch(paramsTypes)) {
      ok = false;
      this->errorAt(
        ctx->name,
        "Redeclaration of function \"{}\" with the same parameters (two functions with the same type cannot be distinguished by the return type alone)"_f.format(
          ctx->name->getText()
        )
      );
    }

    if(not ok) return {};

    auto parameters = views::zip(
      ctx->paramsNames 
      | views::transform(&ant::Token::getText), 
      paramsTypes
    )
    | views::transform(tup2pair)
    | ranges::to<vector>();

    rc<Function> function = make_shared<Function>(*asOverload, overloadName, *retType, parameters);
    asOverload->add(paramsTypes, function);

    rc<Scope> scope = make_shared<Scope>(*asOverload->getDeclaringSymbolTable());
    for(auto [paramName, paramType] : parameters) {
      scope->define(make_shared<Variable>(*scope, paramName, *paramType));
    }

    ctx->functionDecl = function;
    ctx->block->scope = scope;

    return {};
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    auto isErrorType = [](Type* other) { 
      return other == ErrorType::get(); 
    };

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayParser::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };

    string overloadName = ctx->name->getText();

    auto paramsTypes = ctx->paramsTypes
    | views::transform(&FridayParser::TypeContext::typeId)
    | ranges::to<vector>();

    auto retType = ctx->returnType->typeId;
    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(isErrorType) | views::enumerate) {
      ok = false;
      this->errorAt(
        ctx->paramsTypes[i]->getStart(),
        "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\""_f.format(
          i,
          ctx->paramsNames[i]->getText(),
          ctx->paramsTypes[i]->getText()
        )
      );
    }

    if(retType == ErrorType::get()) {
      ok = false;
      this->errorAt(
        ctx->returnType->getStart(),
        "In function declaration, the return type is of an invalid error type \"{}\""_f.format(
          ctx->returnType->getText()
        )
      );
    }

    if(ctx->overloadDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Overload> asOverload = ctx->overloadDecl.lock();

    if(asOverload->hasMatch(paramsTypes)) {
      ok = false;
      this->errorAt(
        ctx->name,
        "Redeclaration of function \"{}\" with the same parameters (two functions with the same type cannot be distinguished by the return type alone)"_f.format(
          ctx->name->getText()
        )
      );
    }

    if(not ok) return {};

    auto parameters = views::zip(
      ctx->paramsNames 
      | views::transform(&ant::Token::getText), 
      paramsTypes
    )
    | views::transform(tup2pair)
    | ranges::to<vector>();

    rc<Function> function = make_shared<Function>(*asOverload, overloadName, *retType, parameters);
    asOverload->add(paramsTypes, function);

    ctx->functionDecl = function;

    return {};
  }

}