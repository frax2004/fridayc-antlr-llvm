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
    map<Struct*, ant::ParserRuleContext*> M_properties { };

    public:
    TypeSolverVisitor(CompilationContext& ctx);

    auto solve() -> TypeSolverVisitor&;

    auto visitStructStatement(FridayParser::StructStatementContext* ctx) -> any override;
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any override;
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any override;
    auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> any override;
    auto visitArrayType(FridayParser::ArrayTypeContext* ctx) -> any override;
  };
}
