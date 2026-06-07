#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will bind namespaces with their used namespaces
  struct NamespaceBindingVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context { nullptr };

    public:
    NamespaceBindingVisitor(CompilationContext& ctx);
  
    auto bind() -> NamespaceBindingVisitor&;
    auto visitUsingStatement(FridayParser::UsingStatementContext* ctx) -> any override;
  };
}
