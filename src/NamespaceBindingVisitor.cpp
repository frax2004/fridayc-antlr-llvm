#include <NamespaceBindingVisitor.hpp>

namespace friday::inline api::inline pipeline {

  static constexpr auto USE_OF_UNDECLARED_NAMESPACE = "Use of undeclared namespace '{}'."_f;

  NamespaceBindingVisitor::NamespaceBindingVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto NamespaceBindingVisitor::beginUnit(TranslationUnit& unit) -> void { }

  auto NamespaceBindingVisitor::endUnit(TranslationUnit& unit) -> void { }

  auto NamespaceBindingVisitor::visitUsingStatement(FridayParser::UsingStatementContext* ctx) -> any {
    auto token = ctx->IDENTIFIER()->getSymbol();
    auto name = token->getText();

    auto& namespaces = this->getCompilationContext().namespaces; 
    auto it = namespaces.find(name);
    
    if(it == namespaces.end()) {
      this->errorAt(
        token,
        USE_OF_UNDECLARED_NAMESPACE.format(name)
      );
      return {};
    }

    this->getCurrentUnit()->usedNamespaces.try_emplace(name, it->second);
    
    return {};
  }
}
