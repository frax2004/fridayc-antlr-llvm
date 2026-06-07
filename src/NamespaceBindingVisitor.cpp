#include <NamespaceBindingVisitor.hpp>

namespace friday::inline api::inline pipeline {

  static constexpr auto USE_OF_UNDECLARED_NAMESPACE = "Use of undeclared namespace '{}'."_f;

  NamespaceBindingVisitor::NamespaceBindingVisitor(CompilationContext& ctx)
    : context { &ctx }
  {}

  auto NamespaceBindingVisitor::bind() -> NamespaceBindingVisitor& {
    for(auto& unit : this->context->units) {
      this->setCurrentUnit(unit.get());
      this->visit(unit->ast);
      this->setCurrentUnit(nullptr);
    }
    return *this;
  }

  auto NamespaceBindingVisitor::visitUsingStatement(FridayParser::UsingStatementContext* ctx) -> any {

    auto token = ctx->IDENTIFIER()->getSymbol();
    auto name = token->getText();

    auto it = this->context->namespaces.find(name);
    if(it == this->context->namespaces.end()) {
      this->errorAt(
        token,
        USE_OF_UNDECLARED_NAMESPACE.format(name)
      );
      return {};
    }

    this->getCurrentUnit()->usedNamespaces.try_emplace(name, it->second.get());
    
    return {};
  }
}
