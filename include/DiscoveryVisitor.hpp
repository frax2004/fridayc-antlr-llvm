#pragma once
#include <StaticAnalyzer.hpp>


namespace friday::inline api::inline pipeline {
  // will forward declare namespaces, structs and functions
  struct FRIDAY_API DiscoveryVisitor final : StaticAnalyzer {
    private:
    Pointer<ISymbolTable> M_currentSymbolTable { nullptr };

    public:
    DiscoveryVisitor(CompilationContext& ctx);
    ~DiscoveryVisitor() override = default;

    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;

    auto visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any override;
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;

    private:
    auto current() -> Pointer<ISymbolTable>;
  };
}