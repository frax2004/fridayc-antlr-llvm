#include <DiscoveryVisitor.hpp>


namespace friday::inline api::inline pipeline {
  static constexpr auto NAMESPACE_REDECLARATION = "Redeclaration of namespace: previously declared as '{}'."_f;
  static constexpr auto STRUCT_REDECLARATION = "Redeclaration of struct '{}', which was previously already defined."_f;

  DiscoveryVisitor::DiscoveryVisitor(CompilationContext& ctx)
    : context { &ctx }
  {}
  
  auto DiscoveryVisitor::discover() -> DiscoveryVisitor& {
    for(auto& unit : this->context->units) {
      this->setCurrentUnit(unit.get());
      this->M_currentSymbolTable = this->context->global.get();

      this->visit(unit->ast);

      this->M_currentSymbolTable = nullptr;
      this->setCurrentUnit(nullptr);
    }

    return *this;
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
    if(auto it = this->context->namespaces.find(identifier); it != this->context->namespaces.end()) {
      unit->ownedNamespace = it->second.get();
    } else unit->ownedNamespace = this->context->namespaces.emplace(
      identifier, 
      make_unique<Namespace>(identifier)
    ).first->second.get();

    this->M_currentSymbolTable = unit->ownedNamespace;

    return {};
  }

  auto DiscoveryVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
    
    auto name = ctx->structName->getText();
    auto isStruct = (bool(*)(ISymbol*))&rtti::instanceOf<Struct>;
    if(auto existing = this->M_currentSymbolTable->lookUpIf(name, isStruct)) {
      this->errorAt(
        ctx->structName,
        STRUCT_REDECLARATION.format(name)
      );
      return {};
    }

    Struct* strct = new Struct(*(Namespace*)this->M_currentSymbolTable, name);
    this->M_currentSymbolTable->define(strct);
    
    auto previous = this->M_currentSymbolTable;
    this->M_currentSymbolTable = strct;

    this->visitChildren(ctx);

    this->M_currentSymbolTable = previous;
    return {};
  }

  auto DiscoveryVisitor::visitFunctionStatement(FridayParser::FunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->M_currentSymbolTable->isDefined(name)) {
      this->M_currentSymbolTable->define(new Overload(*this->M_currentSymbolTable, name));
    }
    return {};
  }

  auto DiscoveryVisitor::visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext* ctx) -> any {
    auto name = ctx->name->getText();

    if(not this->M_currentSymbolTable->isDefined(name)) {
      this->M_currentSymbolTable->define(new Overload(*this->M_currentSymbolTable, name));
    }
    return {};
  }
}
