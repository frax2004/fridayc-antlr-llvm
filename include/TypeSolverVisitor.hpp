#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will fill structs with fields and build the dependency graph
  struct TypeSolverVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context;
  
    public:
    TypeSolverVisitor(CompilationContext& ctx);
  };
}
