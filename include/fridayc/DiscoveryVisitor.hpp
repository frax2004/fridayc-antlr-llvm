#pragma once
#include "StaticAnalyzer.hpp"


namespace friday::inline api {

  struct ISymbolTable;

  // will forward declare namespaces, structs and functions
  struct DiscoveryVisitor final : StaticAnalyzer {
  private:
    ISymbolTable* M_currentSymbolTable { nullptr };

  public:
    DiscoveryVisitor(CompilationContext& ctx);
    ~DiscoveryVisitor() override = default;

    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;

    auto visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any override;
    auto visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;

  private:
    auto current() -> ISymbolTable*;
  };
}