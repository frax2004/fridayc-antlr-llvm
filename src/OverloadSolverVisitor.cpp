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
    constexpr auto isOverload = (bool(*)(ISymbol*))&rtti::instanceOf<Overload>;

    auto isErrorType = [](Type* other) { return other == ErrorType::get(); };
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

    string overloadName = ctx->name->getText();
    TranslationUnit* unit = this->getCurrentUnit();

    ISymbolTable* owner = this->getCompilationContext()
    .annotations
    .getMetadata<FuncAnnotation>(ctx->getStart())
    .transform(getScope)
    .value_or(this->getCompilationContext().global.get());

    Overload* asOverload = rtti::cast<Overload>(owner->lookUpIf(overloadName, isOverload));

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

    if(ok) {
      auto function = new Function(
        *asOverload, 
        overloadName, 
        *retType, 
        views::zip(
          ctx->paramsNames 
          | views::transform(ant::Token::getText), 
          paramsTypes
        )
        | views::transform(tup2pair)
        | ranges::to<vector>()
      );
      
      asOverload->add(paramsTypes, function);

      this->getCompilationContext().annotations.setMetadata(
        ctx->getStart(), 
        FuncAnnotation{
          .type = function->getType(),
          .visibility = toVisibility(ctx->accessModifier->getType()),
          .isStatic = true,
          .isNative = false,
        }
      );
    }

    return {};
  }

  auto OverloadSolverVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    constexpr auto isOverload = (bool(*)(ISymbol*))&rtti::instanceOf<Overload>;

    auto isErrorType = [](Type* other) { return other == ErrorType::get(); };
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

    string overloadName = ctx->name->getText();
    TranslationUnit* unit = this->getCurrentUnit();


    ISymbolTable* owner = this->getCompilationContext()
    .annotations
    .getMetadata<FuncAnnotation>(ctx->getStart())
    .transform(getScope)
    .value_or(this->getCompilationContext().global.get());

    Overload* asOverload = rtti::cast<Overload>(owner->lookUpIf(overloadName, isOverload));

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

    if(ok) {
      auto function = new Function(
        *asOverload, 
        overloadName, 
        *retType, 
        views::zip(
          ctx->paramsNames 
          | views::transform(ant::Token::getText), 
          paramsTypes
        )
        | views::transform(tup2pair)
        | ranges::to<vector>()
      );

      asOverload->add(paramsTypes, function);

      this->getCompilationContext()
      .annotations[ctx->getStart()]
      .visit([&](auto& func) {
        if constexpr(same_as<FuncAnnotation, remove_cvref_t<decltype(func)>>) {
          func.type = function->getType();
          func.visibility = toVisibility(ctx->accessModifier->getType());
          func.isStatic = true;
          func.isNative = true;
        }
      });
    }

    return {};
  }

}