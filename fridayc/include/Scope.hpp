#pragma once

#include <SymbolTable.hpp>
#include <Variable.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Scope final : SymbolTable<Variable> {
    ISymbolTable* M_parent { nullptr };

    public:
    Scope(ISymbolTable& parent);
    ~Scope() override = default;

    auto find_variable(string_view id) -> Variable*;
    auto get_parent() const -> ISymbolTable* override;
  };
}