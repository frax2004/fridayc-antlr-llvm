#pragma once
#include "StaticAnalyzer.hpp"


namespace friday::inline api {
  // will fill structs with fields and build the dependency graph
  struct TypeSolverVisitor final : StaticAnalyzer {

  private:
    DirectedGraph                         M_dependencyGraph { };
    map<Struct*, ant::ParserRuleContext*> M_properties      { };

  public:
    TypeSolverVisitor(CompilationContext& ctx);
    ~TypeSolverVisitor() override = default;

    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;

    auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any override;
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any override;
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any override;
    auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> any override;
    auto visitArrayType(FridayParser::ArrayTypeContext *ctx) -> any override;
  };
}
