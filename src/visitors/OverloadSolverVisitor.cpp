#include <OverloadSolverVisitor.hpp>
#include <OperationNotSupportedError.hpp>


namespace friday::inline api::inline pipeline {

  OverloadSolverVisitor::OverloadSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto OverloadSolverVisitor::on_unit_begin(TranslationUnit& _) -> void {
    (void)_;
  }

  auto OverloadSolverVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
  }

  auto OverloadSolverVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {

    auto tup2pair = [](tuple<string, Pointer<Type>> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayParser::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };

    (void)toVisibility;
    
    string overloadName = ctx->name->getText();

    auto paramsTypes = ctx->paramsTypes
    | views::transform(&FridayParser::TypeContext::typeId)
    | ranges::to<vector>();

    auto retType = ctx->returnType->typeId;
    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(&ErrorType::is_error_type) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx,
        ctx->paramsTypes[i]->getStart(),
        "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\""_f.format(
          i,
          ctx->paramsNames[i]->getText(),
          ctx->paramsTypes[i]->getText()
        )
      );
    }

    if(ErrorType::is_error_type(retType)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->returnType->getStart(),
        "In function declaration, the return type is of an invalid error type \"{}\""_f.format(
          ctx->returnType->getText()
        )
      );
    }

    if(ctx->overloadDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Overload> asOverload = ctx->overloadDecl.lock();

    if(asOverload->has_match(paramsTypes)) {
      ok = false;
      this->error_at(
        ctx,
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

    rc<Function> function = make_shared<Function>(*asOverload, *retType, parameters);
    asOverload->add(function);

    rc<Scope> scope = make_shared<Scope>(*asOverload->get_declaring_symbol_table());
    for(auto [paramName, paramType] : parameters) {
      scope->define(make_shared<Variable>(*scope, paramName, *paramType));
    }

    ctx->functionDecl = function;
    ctx->block->scope = scope;

    return {};
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {

    auto tup2pair = [](tuple<string, Pointer<Type>> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayParser::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };

    (void)toVisibility;

    string overloadName = ctx->name->getText();

    auto paramsTypes = ctx->paramsTypes
    | views::transform(&FridayParser::TypeContext::typeId)
    | ranges::to<vector>();

    auto retType = ctx->returnType->typeId;
    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(&ErrorType::is_error_type) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx,
        ctx->paramsTypes[i]->getStart(),
        "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\""_f.format(
          i,
          ctx->paramsNames[i]->getText(),
          ctx->paramsTypes[i]->getText()
        )
      );
    }

    if(ErrorType::is_error_type(retType)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->returnType->getStart(),
        "In function declaration, the return type is of an invalid error type \"{}\""_f.format(
          ctx->returnType->getText()
        )
      );
    }

    if(ctx->overloadDecl.expired()) throw OperationNotSupportedError("Internal error.");
    rc<Overload> asOverload = ctx->overloadDecl.lock();

    if(asOverload->has_match(paramsTypes)) {
      ok = false;
      this->error_at(
        ctx,
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

    rc<Function> function = make_shared<Function>(*asOverload, *retType, parameters);
    asOverload->add(function);

    ctx->functionDecl = function;

    return {};
  }

}