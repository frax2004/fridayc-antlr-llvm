#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>
#include <PointerGraph.hpp>

namespace friday::inline api::inline pipeline {
  // will fill structs with fields and build the dependency graph
  struct TypeSolverVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context { nullptr };
    PointerGraph<Struct*> M_dependencyGraph { };

    public:
    TypeSolverVisitor(CompilationContext& ctx);

    auto solve() -> TypeSolverVisitor&;

    auto visitStructStatement(FridayParser::StructStatementContext* ctx) -> any override;
  };
}
