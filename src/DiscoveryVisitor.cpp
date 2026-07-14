#include <DiscoveryVisitor.hpp>


namespace friday::inline api::inline pipeline {
  static constexpr auto NAMESPACE_REDECLARATION = "Redeclaration of namespace: previously declared as '{}'."_f;
  static constexpr auto STRUCT_REDECLARATION = "Redeclaration of struct '{}', which was previously already defined."_f;

  DiscoveryVisitor::DiscoveryVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}

  auto DiscoveryVisitor::current() -> Pointer<ISymbolTable> {
    return this->M_currentSymbolTable;
  }
  
  auto DiscoveryVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    (void)unit;
    this->M_currentSymbolTable = this->comp_context().get_global().get();
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
        NAMESPACE_REDECLARATION.format(unit->get_owned_namespace().lock()->get_qualified_id())
      );
      return {};
    }

    auto nsp = this->comp_context().get_or_emplace_namespace(token->getText());
    unit->set_owned_namespace(nsp.lock());
    ctx->namespaceDecl = nsp;

    this->M_currentSymbolTable = nsp.lock().get();

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    auto name = ctx->structName->getText();

    if(this->current()->is_defined(name, &Struct::is_struct)) {
      this->error_at(
        ctx,
        ctx->structName,
        STRUCT_REDECLARATION.format(name)
      );

      return {};
    }

    auto nsp = rtti::cast<Namespace>(this->M_currentSymbolTable);
    rc<Struct> strct = make_shared<Struct>(*nsp, name);
    this->current()->define(strct);
    ctx->structDecl = strct;

    auto previous = this->current();
    this->M_currentSymbolTable = strct.get();

    this->visitChildren(ctx);

    this->M_currentSymbolTable = previous;
    return {};
  }

  auto DiscoveryVisitor::visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->current()->is_defined(name, &Overload::is_overload)) {
      rc<Overload> overload = make_shared<Overload>(*this->current(), name);
      ctx->overloadDecl = overload;
      this->current()->define(overload);
    } else ctx->overloadDecl = dynamic_pointer_cast<Overload>(
      this->current()->retrieve_if(name, &Overload::is_overload).lock()
    );

    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->M_currentSymbolTable->is_defined(name, &Overload::is_overload)) {
      rc<Overload> overload = make_shared<Overload>(*this->current(), name);
      ctx->overloadDecl = overload;
      this->current()->define(overload);
    } else ctx->overloadDecl = dynamic_pointer_cast<Overload>(
      this->current()->retrieve_if(name, &Overload::is_overload).lock()
    );

    return {};
  }
}
