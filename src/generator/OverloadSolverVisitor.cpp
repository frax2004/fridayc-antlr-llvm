#include <fridayc.hpp>


namespace friday::inline api {

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

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return Visibility::PUBLIC;
        case FridayParser::PRIVATE: return Visibility::PRIVATE;
        default: throw InvalidArgumentError{};
      }
    };

    (void)toVisibility;
    
    string overloadName = ctx->name->getText();

    auto paramsTypes = ctx->paramsTypes
    | views::transform([](FridayParser::TypeContext* typeCtx) { return $(typeCtx).type; })
    | ranges::to<vector>();

    Type* retType = $(ctx->returnType).type;
    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(&ErrorType::is_error_type) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx,
        ctx->paramsTypes[i]->getStart(),
        format(
          "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\"",
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
        format(
          "In function declaration, the return type is of an invalid error type \"{}\"",
          ctx->returnType->getText()
        )
      );
    }

    if($(ctx).overload == nullptr) throw InvalidArgumentError{};
    Overload* overload = $(ctx).overload;
    
    if(overload->has_match(paramsTypes)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->name,
        format(
          "Redeclaration of function \"{}\" with the same parameters (two functions with the same type cannot be distinguished by the return type alone)",
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


    Scope* scope = Scope::Factory::create(*overload->get_declaring_symbol_table());
    for(auto [paramName, paramType] : parameters) {
      scope->define(Variable::Factory::create(*scope, paramName, *paramType));
    }

    $(ctx).function = overload->add(*retType, parameters);
    if(auto asTrailingScope = dynamic_cast<FridayParser::TrailingBlockContext*>(ctx->block)) {
      $(asTrailingScope).function = &$(ctx);
      $(asTrailingScope).scope = scope;
    } else if(auto asBasicBlock = dynamic_cast<FridayParser::BasicBlockContext*>(ctx->block)) {
      $(asBasicBlock).function = &$(ctx);
      $(asBasicBlock).scope = scope;
    } else throw InvalidArgumentError{};
    $(ctx).scope = &$(ctx->block);
    

    return {};
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayParser::PUBLIC: return Visibility::PUBLIC;
        case FridayParser::PRIVATE: return Visibility::PRIVATE;
        default: throw InvalidArgumentError{};
      }
    };

    (void)toVisibility;

    string overloadName = ctx->name->getText();

    Type* retType = $(ctx->returnType).type;
    auto paramsTypes = ctx->paramsTypes
    | views::transform([](FridayParser::TypeContext* typeCtx) { return $(typeCtx).type; })
    | ranges::to<vector>();

    bool ok = true;

    for(auto [i, type] : paramsTypes | views::filter(&ErrorType::is_error_type) | views::enumerate) {
      ok = false;
      this->error_at(
        ctx,
        ctx->paramsTypes[i]->getStart(),
        format(
          "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\"",
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
        format(
          "In function declaration, the return type is of an invalid error type \"{}\"",
          ctx->returnType->getText()
        )
      );
    }

    if($(ctx).overload == nullptr) {
      throw InvalidArgumentError{};
    }

    Overload* overload = $(ctx).overload;

    if(overload->has_match(paramsTypes)) {
      ok = false;
      this->error_at(
        ctx,
        ctx->name,
        format(
          "Redeclaration of function \"{}\" with the same parameters (two functions with the same type cannot be distinguished by the return type alone)",
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

    $(ctx).function = overload->add(*retType, parameters);

    return {};
  }

}