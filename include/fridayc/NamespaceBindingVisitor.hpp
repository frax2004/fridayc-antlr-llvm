#pragma once
#include "StaticAnalyzer.hpp"


namespace friday::inline api {
  // will bind namespaces with their used namespaces
  struct NamespaceBindingVisitor final : StaticAnalyzer {
  public:
    NamespaceBindingVisitor(CompilationContext& ctx);
    ~NamespaceBindingVisitor() override = default;
  
    auto on_unit_begin(TranslationUnit& unit) -> void override;
    auto on_unit_end(TranslationUnit& unit) -> void override;

    auto visitUsingStatement(FridayParser::UsingStatementContext *ctx) -> any override;
  };
}
