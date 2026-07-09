#pragma once
#include <StaticAnalyzer.hpp>


namespace friday::inline api::inline pipeline {
  // will forward declare namespaces, structs and functions
  struct DiscoveryVisitor : StaticAnalyzer {
    private:
    ISymbolTable* M_currentSymbolTable { nullptr };

    public:
    DiscoveryVisitor(CompilationContext& ctx);
    auto beginUnit(TranslationUnit& unit) -> void override;
    auto endUnit(TranslationUnit& unit) -> void override;

    auto visitNamespaceStatement(FridayParser::NamespaceStatementContext* ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext* ctx) -> any override;
    auto visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any override;

    private:
    auto current() -> ISymbolTable*;
  };
}