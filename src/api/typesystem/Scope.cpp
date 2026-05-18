#include "api/typesystem/Scope.hpp"

namespace friday::inline api::inline typesystem {
  Scope::Scope(SymbolTable& parent, Map<String, Variable> variables)
    : M_parent { &parent }
    , M_variables { std::move(variables) }
  {}

  auto Scope::getVariable(String const& id, Variable* defaultValue) -> Variable* {

  }

  auto Scope::lookUp(String const& id, Symbol* defaultValue) -> Symbol* {

  }

  auto Scope::lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* {

  }

  auto Scope::define(Symbol* symbol) -> bool {

  }

  auto Scope::isDefined(String const& id) -> bool {

  }

  auto Scope::getParent() -> SymbolTable* {

  }

  auto Scope::mostSimilar(String const& name, u64 maxEditDistance, SymbolPredicate filter) noexcept -> Opt<Symbol*> {

  }
}
