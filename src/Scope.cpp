#include <Scope.hpp>

namespace friday::inline api::inline typesystem {
  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::getVariable(string const& id, Variable* defaultValue) -> Variable* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    return (Variable*)lookUpIf(id, isVariable, defaultValue);
  }

  auto Scope::getParent() -> ISymbolTable* {
    return this->M_parent;
  }

}
