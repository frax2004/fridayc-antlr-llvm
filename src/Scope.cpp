#include <Scope.hpp>

namespace friday::inline api::inline typesystem {
  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::getVariable(string const& id, weak<Variable> defaultValue) -> weak<Variable> {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(id, isVariable, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Variable>(candidate.lock()) : defaultValue;
  }

  auto Scope::getParent() -> ISymbolTable* {
    return this->M_parent;
  }

}
