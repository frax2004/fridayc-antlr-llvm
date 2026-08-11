#include <fridayc.hpp>


namespace friday::inline api {
  static constexpr auto USE_OF_UNDECLARED_NAMESPACE = "Use of undeclared namespace '{}'."sv;

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
    ant::Token* token = ctx->IDENTIFIER()->getSymbol();
    string      name  = token->getText();
    Namespace*  nsp   = Namespace::find_namespace(name);

    if(nsp == nullptr) {
      this->error_at(ctx, token, format(USE_OF_UNDECLARED_NAMESPACE, name));
      return {};
    } else this->get_current_unit()->use(nsp);

    return {};
  }
}
