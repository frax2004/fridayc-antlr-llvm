#include <DiscoveryVisitor.hpp>


namespace friday::inline api::inline pipeline {
  static constexpr auto NAMESPACE_REDECLARATION = "Redeclaration of namespace: previously declared as '{}'."_f;
  static constexpr auto STRUCT_REDECLARATION = "Redeclaration of struct '{}', which was previously already defined."_f;

  DiscoveryVisitor::DiscoveryVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
  
  auto DiscoveryVisitor::current() -> ISymbolTable& {
    return *this->M_currentSymbolTable;
  }
  
  auto DiscoveryVisitor::beginUnit(TranslationUnit& unit) -> void {
    this->M_currentSymbolTable = this->getCompilationContext().global.get();
  }
  
  auto DiscoveryVisitor::endUnit(TranslationUnit& unit) -> void {
    this->M_currentSymbolTable = nullptr;
  }

  auto DiscoveryVisitor::visitNamespaceStatement(FridayParser::NamespaceStatementContext* ctx) -> any {
    auto unit = this->getCurrentUnit();
    auto token = ctx->IDENTIFIER()->getSymbol();

    if(not unit->ownedNamespace.expired()) {
      this->errorAt(
        token, 
        NAMESPACE_REDECLARATION.format(unit->ownedNamespace.lock()->getQualifiedId())
      );
      return {};
    }

    string identifier = token->getText();
    auto& namespaces = this->getCompilationContext().namespaces;
    
    if(auto it = namespaces.find(identifier); it != namespaces.end()) {
      unit->ownedNamespace = it->second;
    } else {
      auto [iter, ok] = namespaces.emplace(
        identifier, 
        make_shared<Namespace>(identifier)
      );

      unit->ownedNamespace = iter->second;
      ctx->namespaceDecl = iter->second;
    }

    this->M_currentSymbolTable = unit->ownedNamespace.lock().get();

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
    auto name = ctx->structName->getText();
    auto isStruct = static_cast<bool(*)(ISymbol*)>(&rtti::instanceOf<Struct>);

    if(not this->current().lookUpIf(name, isStruct, {}).expired()) {
      this->errorAt(
        ctx->structName,
        STRUCT_REDECLARATION.format(name)
      );
      return {};
    }

    auto nsp = dynamic_cast<Namespace*>(this->M_currentSymbolTable);
    rc<Struct> strct = make_shared<Struct>(*nsp, name);
    this->current().define(strct);
    ctx->structDecl = strct;

    auto previous = &this->current();
    this->M_currentSymbolTable = strct.get();

    this->visitChildren(ctx);

    this->M_currentSymbolTable = previous;
    return {};
  }

  auto DiscoveryVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();
    auto isOverload = static_cast<bool(*)(ISymbol*)>(&rtti::instanceOf<Overload>);

    weak<ISymbol> candidate = this->M_currentSymbolTable->lookUpIf(name, isOverload, {});
    if(candidate.expired()) {
      rc<Overload> overload = make_shared<Overload>(this->current(), name);
      ctx->overload = overload;
      this->current().define(overload);
    } else ctx->overload = dynamic_pointer_cast<Overload>(candidate.lock());

    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();
    auto isOverload = static_cast<bool(*)(ISymbol*)>(&rtti::instanceOf<Overload>);

    weak<ISymbol> candidate = this->current().lookUpIf(name, isOverload, {});
    if(candidate.expired()) {
      rc<Overload> overload = make_shared<Overload>(this->current(), name);
      ctx->overload = overload;
      this->current().define(overload);
    } else ctx->overload = dynamic_pointer_cast<Overload>(candidate.lock());

    return {};
  }
}
