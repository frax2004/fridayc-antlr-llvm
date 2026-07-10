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
  
  auto DiscoveryVisitor::beginUnit(TranslationUnit& unit) -> void {
    this->M_currentSymbolTable = &unit;
  }
  
  auto DiscoveryVisitor::endUnit(TranslationUnit& _) -> void {
    (void)_;
    this->M_currentSymbolTable = nullptr;
  }

  auto DiscoveryVisitor::visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> any {
    auto unit = this->getCurrentUnit();
    auto token = ctx->IDENTIFIER()->getSymbol();

    if(auto owned = unit->getOwnedNamespace(); not owned.expired() and owned.lock() != this->getCompilationContext().global) {
      this->errorAt(
        token, 
        NAMESPACE_REDECLARATION.format(unit->getOwnedNamespace().lock()->getQualifiedId())
      );
      return {};
    }

    string identifier = token->getText();
    auto& namespaces = this->getCompilationContext().namespaces;
    
    if(auto it = namespaces.find(identifier); it != namespaces.end()) {
      unit->setOwnedNamespace(it->second);
    } else {
      auto [iter, ok] = namespaces.emplace(
        identifier, 
        make_shared<Namespace>(identifier)
      );

      unit->setOwnedNamespace(iter->second);
      ctx->namespaceDecl = iter->second;
    }

    this->M_currentSymbolTable = unit->getOwnedNamespace().lock().get();

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext *ctx) -> any {
    auto name = ctx->structName->getText();

    if(not this->current()->lookUpIf(name, Struct::isStruct, {}).expired()) {
      this->errorAt(
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

  auto DiscoveryVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    weak<ISymbol> candidate = this->M_currentSymbolTable->lookUpIf(name, Overload::isOverload, {});
    if(candidate.expired()) {
      rc<Overload> overload = make_shared<Overload>(*this->current(), name);
      ctx->overloadDecl = overload;
      this->current()->define(overload);
    } else ctx->overloadDecl = dynamic_pointer_cast<Overload>(candidate.lock());

    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any {
    auto name = ctx->name->getText();

    weak<ISymbol> candidate = this->current()->lookUpIf(name, Overload::isOverload, {});
    if(candidate.expired()) {
      rc<Overload> overload = make_shared<Overload>(*this->current(), name);
      ctx->overloadDecl = overload;
      this->current()->define(overload);
    } else ctx->overloadDecl = dynamic_pointer_cast<Overload>(candidate.lock());

    return {};
  }
}
