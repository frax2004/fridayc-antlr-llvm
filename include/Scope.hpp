#pragma once

#include <SymbolTable.hpp>
#include <Variable.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Scope final : SymbolTable<Variable> {
    Pointer<ISymbolTable> M_parent { nullptr };

    public:
    Scope(ISymbolTable& parent);
    ~Scope() override = default;

    auto getVariable(string const& id, weak<Variable> defaultValue = {}) -> weak<Variable>;
    auto getParent() -> Pointer<ISymbolTable> override;
  };
}