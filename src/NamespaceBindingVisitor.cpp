#include <NamespaceBindingVisitor.hpp>

namespace friday::inline api::inline pipeline {

  static constexpr auto USE_OF_UNDECLARED_NAMESPACE = "Use of undeclared namespace '{}'."_f;

  NamespaceBindingVisitor::NamespaceBindingVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto NamespaceBindingVisitor::on_unit_begin(TranslationUnit& _) -> void {
    (void)_;
  }

  auto NamespaceBindingVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
  }

  auto NamespaceBindingVisitor::visitUsingStatement(FridayParser::UsingStatementContext *ctx) -> any {
    auto token = ctx->IDENTIFIER()->getSymbol();
    auto name = token->getText();

    auto nsp = this->comp_context().find_namespace(name);
    
    if(nsp.expired()) {
      this->error_at(token, USE_OF_UNDECLARED_NAMESPACE.format(name));
      return {};
    } else this->get_current_unit()->use(nsp.lock());

    return {};
  }
}
