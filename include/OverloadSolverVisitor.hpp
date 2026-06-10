#pragma once
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will solve the overload signatures
  struct OverloadSolverVisitor : StaticAnalyzer {
    public:
    OverloadSolverVisitor(CompilationContext& ctx);

    auto beginUnit(TranslationUnit& unit) -> void override;
    auto endUnit(TranslationUnit& unit) -> void override;

    
  };
}
