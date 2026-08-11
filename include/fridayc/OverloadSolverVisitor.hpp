#pragma once
#include "StaticAnalyzer.hpp"


namespace friday::inline api {
  // will solve the overload signatures
  struct OverloadSolverVisitor final : StaticAnalyzer {
  public:
    OverloadSolverVisitor(CompilationContext& ctx);
    ~OverloadSolverVisitor() override = default;

    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;
    
    auto visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;
  };
}
