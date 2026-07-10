#pragma once
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will bind namespaces with their used namespaces
  struct FRIDAY_API NamespaceBindingVisitor final : StaticAnalyzer {
    public:
    NamespaceBindingVisitor(CompilationContext& ctx);
    ~NamespaceBindingVisitor() override = default;
  
    auto beginUnit(TranslationUnit& unit) -> void override;
    auto endUnit(TranslationUnit& unit) -> void override;

    auto visitUsingStatement(FridayParser::UsingStatementContext *ctx) -> any override;
  };
}
