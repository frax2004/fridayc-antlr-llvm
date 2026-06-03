#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will forward declare namespaces, structs and functions
  struct DiscoveryVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context { nullptr };
    ISymbolTable* M_currentSymbolTable { nullptr };

    public:
    DiscoveryVisitor(CompilationContext& ctx);

    auto discover() -> DiscoveryVisitor&;
    auto visitNamespaceStatement(FridayParser::NamespaceStatementContext* ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext* ctx) -> any override;
    auto visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any override;
  };
}