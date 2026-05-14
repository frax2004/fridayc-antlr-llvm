#include "api/typesystem/Namespace.hpp"


namespace friday::inline api::inline typesystem {
  Namespace::Namespace(Namespace* parent, Map<String, Variable> variables, Map<String, Function> functions, Map<String, Struct> structs)
    : M_parent { parent }
    , M_variables { std::move(variables) }
    , 

  auto Namespace::getGlobal() -> Namespace*;
  auto Namespace::getFunction(String const& id, Function* defaultValue) -> Function*;
  auto Namespace::getStruct(String const& id, Struct* defaultValue) -> Struct*;
  auto Namespace::getVariable(String const& id, Variable* defaultValue) -> Variable*;
  auto Namespace::getQualifiedId() const -> String override;
  auto Namespace::getFullQualifiedId() const -> String override;
  auto Namespace::getMangledId() const -> String override;
  auto Namespace::getDeclaringSymbolTable() -> SymbolTable* override;
  auto Namespace::getAttributes() const -> Attributes const& override;
  auto Namespace::lookUp(String const& id, Symbol* defaultValue) -> Symbol* override;
  auto Namespace::lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* override;
  auto Namespace::define(Symbol* symbol) -> bool override;
  auto Namespace::isDefined(String const& id) -> bool override;
  auto Namespace::getParent() -> SymbolTable* override;
  auto Namespace::mostSimilar(
    String const& name, 
    u64 maxEditDistance = 0, 
    SymbolPredicate filter = [](Symbol*) { return true; }
  ) noexcept -> Opt<Symbol*> override;
  
}