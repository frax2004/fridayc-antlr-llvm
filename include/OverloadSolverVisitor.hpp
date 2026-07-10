#pragma once
#include <StaticAnalyzer.hpp>


namespace friday::inline api::inline pipeline {
  // will solve the overload signatures
  struct FRIDAY_API OverloadSolverVisitor final : StaticAnalyzer {
    public:
    OverloadSolverVisitor(CompilationContext& ctx);
    ~OverloadSolverVisitor() override = default;

    auto beginUnit(TranslationUnit& unit) -> void override;
    auto endUnit(TranslationUnit& unit) -> void override;
    
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;

  };
}
