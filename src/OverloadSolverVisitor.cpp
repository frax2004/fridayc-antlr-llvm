#include <OverloadSolverVisitor.hpp>
#include <ErrorType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  OverloadSolverVisitor::OverloadSolverVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto OverloadSolverVisitor::beginUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::endUnit(TranslationUnit& unit) -> void {}

  auto OverloadSolverVisitor::visitFunction(
    ant::Token* nameToken, 
    ant::Token* funcToken, 
    vector<FridayParser::TypeContext*> const& paramsTypes, 
    FridayParser::TypeContext* returnType, 
    vector<ant::Token*> const& paramsNames, 
    u64 accessModifier, 
    bool isNative
  ) -> any {

    auto isOverload = [](ISymbol* symbol) { 
      return rtti::instanceOf<Overload>(symbol); 
    };

    auto isErrorType = [](Type* other) { 
      return other == ErrorType::get(); 
    };

    auto toMetadata = [this](FridayParser::TypeContext* type) {
      return this->getCompilationContext()
      .annotations
      .getMetadata<TypeAnnotation>(type->getStart())
      .transform([](TypeAnnotation const& metadata) -> Type* { return metadata.type; })
      .value_or(ErrorType::get());
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

    auto getScope = [](FuncAnnotation const& metadata) -> ISymbolTable* {
      return metadata.scope;
    };


    string overloadName = nameToken->getText();
    TranslationUnit* unit = this->getCurrentUnit();

    ISymbolTable* owner = this->getCompilationContext()
    .annotations
    .getMetadata<FuncAnnotation>(funcToken)
    .transform(getScope)
    .value_or(this->getCompilationContext().global.get());
 
    Overload* asOverload = rtti::cast<Overload>(owner->lookUpIf(overloadName, isOverload));

    if(asOverload == nullptr) throw OperationNotSupportedError("Internal error.");

    auto params = paramsTypes
    | views::transform(toMetadata)
    | ranges::to<vector>();

    auto retType = toMetadata(returnType);
    bool ok = true;

    for(auto [i, type] : params | views::filter(isErrorType) | views::enumerate) {
      ok = false;
      this->errorAt(
        paramsTypes[i]->getStart(),
        "In function declaration, #{} parameter named \"{}\" is of an invalid error type \"{}\""_f.format(
          i,
          paramsNames[i]->getText(),
          paramsTypes[i]->getText()
        )
      );
    }

    if(retType == ErrorType::get()) {
      ok = false;
      this->errorAt(
        returnType->getStart(),
        "In function declaration, the return type is of an invalid error type \"{}\""_f.format(
          returnType->getText()
        )
      );
    }

    if(asOverload->hasMatch(params)) {
      ok = false;
      this->errorAt(
        nameToken,
        "Redeclaration of function \"{}\" with the same parameters (two functions with the same type cannot be distinguished by the return type alone)"_f.format(
          nameToken->getText()
        )
      );
    }

    if(not ok) return {};

    auto function = new Function(
      *asOverload, 
      overloadName, 
      *retType, 
      views::zip(
        paramsNames 
        | views::transform(ant::Token::getText), 
        params
      )
      | views::transform(tup2pair)
      | ranges::to<vector>()
    );
    
    asOverload->add(params, function);

    this->getCompilationContext().annotations.setMetadata(
      funcToken, 
      FuncAnnotation{
        .type = function->getType(),
        .visibility = toVisibility(accessModifier),
        .isStatic = true,
        .isNative = isNative,
      }
    );

    return {};
  }


  auto OverloadSolverVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {
    return this->visitFunction(
      ctx->name,
      ctx->getStart(),
      ctx->paramsTypes,
      ctx->returnType,
      ctx->paramsNames,
      ctx->accessModifier->getType(),
      false
    );
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    return this->visitFunction(
      ctx->name,
      ctx->getStart(),
      ctx->paramsTypes,
      ctx->returnType,
      ctx->paramsNames,
      ctx->accessModifier->getType(),
      true
    );
  }

}