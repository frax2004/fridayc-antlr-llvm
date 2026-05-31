#pragma once

#include <SymbolTable.hpp>
#include <Variable.hpp>

namespace friday::inline api::inline typesystem {

  struct Scope final : SymbolTable<Variable> {
    ISymbolTable* M_parent;

    public:
    Scope(ISymbolTable& parent);

    auto getVariable(string const& id, Variable* defaultValue = nullptr) -> Variable*;
    auto getParent() -> ISymbolTable* override;
  };
}