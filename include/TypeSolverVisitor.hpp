#pragma once
#include <StaticAnalyzer.hpp>
#include <PointerGraph.hpp>

namespace friday::inline api::inline pipeline {
  // will fill structs with fields and build the dependency graph
  struct TypeSolverVisitor final : StaticAnalyzer {

    private:
    PointerGraph<Struct*> M_dependencyGraph { };
    map<Struct*, ant::ParserRuleContext*> M_properties { };

    public:
    TypeSolverVisitor(CompilationContext& ctx);
    ~TypeSolverVisitor() override = default;

    auto beginUnit(TranslationUnit& unit) -> void override;
    auto endUnit(TranslationUnit& unit) -> void override;

    auto visitStructStatement(FridayParser::StructStatementContext* ctx) -> any override;
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any override;
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any override;
    auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> any override;
    auto visitArrayType(FridayParser::ArrayTypeContext* ctx) -> any override;
  
    private:
    auto toType(FridayParser::TypeContext* type) { this->visit(type); return type->typeId; };
  };
}
