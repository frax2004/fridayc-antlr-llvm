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

    if(unit->ownedNamespace != nullptr) {
      this->errorAt(
        token, 
        NAMESPACE_REDECLARATION.format(unit->ownedNamespace->getQualifiedId())
      );
      return {};
    }

    string identifier = token->getText();
    auto& namespaces = this->getCompilationContext().namespaces;
    
    if(auto it = namespaces.find(identifier); it != namespaces.end()) {
      unit->ownedNamespace = it->second.get();
    } else unit->ownedNamespace = namespaces.emplace(
      identifier, 
      make_unique<Namespace>(identifier)
    ).first->second.get();

    this->M_currentSymbolTable = unit->ownedNamespace;

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
    
    auto name = ctx->structName->getText();
    auto isStruct = (bool(*)(ISymbol*))&rtti::instanceOf<Struct>;
    if(auto existing = this->current().lookUpIf(name, isStruct)) {
      this->errorAt(
        ctx->structName,
        STRUCT_REDECLARATION.format(name)
      );
      return {};
    }

    Struct* strct = new Struct(*(Namespace*)this->M_currentSymbolTable, name);
    this->current().define(strct);
    ctx->definigScope = this->M_currentSymbolTable;

    auto previous = this->M_currentSymbolTable;
    this->M_currentSymbolTable = strct;

    this->visitChildren(ctx);

    this->M_currentSymbolTable = previous;
    return {};
  }

  auto DiscoveryVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->current().isDefined(name)) {
      this->current().define(new Overload(*this->M_currentSymbolTable, name));
    }

    ctx->definingScope = this->M_currentSymbolTable;

    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->current().isDefined(name)) {
      this->current().define(new Overload(*this->M_currentSymbolTable, name));
    }

    ctx->definingScope = this->M_currentSymbolTable;

    return {};
  }
}
