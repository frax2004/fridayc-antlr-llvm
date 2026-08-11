#include <fridayc.hpp>


namespace friday::inline api {
  static constexpr auto NAMESPACE_REDECLARATION = "Redeclaration of namespace: previously declared as '{}'."sv;
  static constexpr auto STRUCT_REDECLARATION = "Redeclaration of struct '{}', which was previously already defined."sv;

  DiscoveryVisitor::DiscoveryVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto DiscoveryVisitor::current() -> ISymbolTable* {
    return this->M_currentSymbolTable;
  }

  auto DiscoveryVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    (void)unit;
    this->M_currentSymbolTable = dynamic_cast<ISymbolTable*>(Namespace::get_global_namespace());
  }

  auto DiscoveryVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
    this->M_currentSymbolTable = nullptr;
  }

  auto DiscoveryVisitor::visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> any {
    auto unit = this->get_current_unit();
    auto token = ctx->IDENTIFIER()->getSymbol();

    if(unit->owns_namespace()) {
      this->error_at(
        ctx,
        token, 
        format(NAMESPACE_REDECLARATION, unit->get_owned_namespace()->get_qualified_id())
      );
      return {};
    }

    Namespace* nsp = Namespace::find_or_create_namespace(token->getText());
    unit->set_owned_namespace(nsp);
    $(ctx).namespace_ = nsp;

    this->M_currentSymbolTable = dynamic_cast<ISymbolTable*>(nsp);

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    auto name = ctx->structName->getText();

    if(this->current()->is_defined(name, &Struct::is_struct)) {
      this->error_at(
        ctx,
        ctx->structName,
        format(STRUCT_REDECLARATION, name)
      );

      return {};
    }

    Namespace* nsp = dynamic_cast<Namespace*>(this->M_currentSymbolTable);
    Struct* strct = Struct::Factory::create(*nsp, name);
    this->current()->define(strct);
    $(ctx).struct_ = strct;


    auto previous = this->current();
    this->M_currentSymbolTable = dynamic_cast<ISymbolTable*>(strct);

    this->visitChildren(ctx);

    this->M_currentSymbolTable = previous;
    return {};
  }

  auto DiscoveryVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->current()->is_defined(name, &Overload::is_overload)) {
      Overload* overload = Overload::Factory::create(*this->current(), name);
      $(ctx).overload = overload;
      this->current()->define(overload);
    } else $(ctx).overload = dynamic_cast<Overload*>(
      this->current()->retrieve_if(name, &Overload::is_overload)
    );

    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->M_currentSymbolTable->is_defined(name, &Overload::is_overload)) {
      Overload* overload = Overload::Factory::create(*this->current(), name);
      $(ctx).overload = overload;
      this->current()->define(overload);
    } else $(ctx).overload = dynamic_cast<Overload*>(
      this->current()->retrieve_if(name, &Overload::is_overload)
    );

    return {};
  }
}
