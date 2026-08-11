#pragma once
#include "SymbolTable.hpp"


namespace friday::inline api {

  struct Variable;

  struct Scope final : ISymbolTable {
  public:
    struct Factory {
      static auto create(ISymbolTable& parent) -> Scope*;
    };

  private:
    ISymbolTable* M_parent { nullptr };
    
  public:
    Scope(ISymbolTable& parent);
    ~Scope() override = default;

    auto find_variable(string_view id) -> Variable*;
    auto get_parent() const -> ISymbolTable* override;
  };
}