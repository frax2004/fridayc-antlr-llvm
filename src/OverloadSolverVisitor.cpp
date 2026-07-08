#include <OverloadSolverVisitor.hpp>
#include <ErrorType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  OverloadSolverVisitor::OverloadSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto OverloadSolverVisitor::beginUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::endUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {
    auto isOverload = [](ISymbol* symbol) { 
      return rtti::instanceOf<Overload>(symbol); 
    };

    auto isErrorType = [](Type* other) { 
      return other == ErrorType::get(); 
    };

    auto toMetadata = [this](FridayParser::TypeContext* ctx) {
      return ctx->typeId != nullptr ? ctx->typeId : ErrorType::get();
    };

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayScanner::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayScanner::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };
    
    string overloadName = ctx->name->getText();
    TranslationUnit* unit = this->getCurrentUnit();
 
    Overload* asOverload = rtti::cast<Overload>(ctx->definingScope->lookUpIf(overloadName, isOverload));

    if(asOverload == nullptr) throw OperationNotSupportedError("Internal error.");

    auto paramsTypes = ctx->paramsTypes
    | views::transform(toMetadata)
    | ranges::to<vector>();

    auto retType = toMetadata(ctx->returnType);
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
      | views::transform(ant::Token::getText), 
      paramsTypes
    )
    | views::transform(tup2pair)
    | ranges::to<vector>();

    auto function = new Function(*asOverload, overloadName, *retType, parameters);
    asOverload->add(paramsTypes, function);

    ctx->typeId = function->getType();
    ctx->visibility = toVisibility(ctx->accessModifier->getType());
    ctx->isStatic = true;
    ctx->initialBlock = ctx->block;

    return {};
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    auto isOverload = [](ISymbol* symbol) { 
      return rtti::instanceOf<Overload>(symbol); 
    };

    auto isErrorType = [](Type* other) { 
      return other == ErrorType::get(); 
    };

    auto toMetadata = [this](FridayParser::TypeContext* ctx) {
      return ctx->typeId != nullptr ? ctx->typeId : ErrorType::get();
    };

    auto tup2pair = [](tuple<string, Type*> const& tup) {
      return make_pair(get<0>(tup), get<1>(tup));
    };

    auto toVisibility = [](u64 vis) {
      switch(vis) {
        case FridayScanner::PUBLIC: return VisibilityModifier::PUBLIC;
        case FridayScanner::PRIVATE: return VisibilityModifier::PRIVATE;
        default: throw InvalidArgumentError{"Invalid visibility modifier"};
      }
    };
    
    string overloadName = ctx->name->getText();
    TranslationUnit* unit = this->getCurrentUnit();
 
    Overload* asOverload = rtti::cast<Overload>(ctx->definingScope->lookUpIf(overloadName, isOverload));

    if(asOverload == nullptr) throw OperationNotSupportedError("Internal error.");

    auto paramsTypes = ctx->paramsTypes
    | views::transform(toMetadata)
    | ranges::to<vector>();

    auto retType = toMetadata(ctx->returnType);
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
      | views::transform(ant::Token::getText), 
      paramsTypes
    )
    | views::transform(tup2pair)
    | ranges::to<vector>();

    auto function = new Function(*asOverload, overloadName, *retType, parameters);
    asOverload->add(paramsTypes, function);
    
    ctx->typeId = function->getType();
    ctx->visibility = toVisibility(ctx->accessModifier->getType());
    ctx->isStatic = true;
    ctx->initialBlock = nullptr;

    return {};

  }

}