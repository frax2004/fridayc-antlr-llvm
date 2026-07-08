#pragma once

#include <SymbolTable.hpp>
#include <Variable.hpp>

namespace friday::inline api::inline typesystem {

  struct Scope final : SymbolTable<Variable> {
    ISymbolTable* M_parent { nullptr };

    public:
    Scope(ISymbolTable& parent);

    auto getVariable(string const& id, weak<Variable> defaultValue = {}) -> weak<Variable>;
    auto getParent() -> ISymbolTable* override;
  };
}