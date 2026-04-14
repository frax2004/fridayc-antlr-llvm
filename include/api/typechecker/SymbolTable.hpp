#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typechecker {

  struct SymbolTable {

    static auto builtins(llvm::Module& ctx) noexcept -> SymbolTable;

    SymbolTable(SymbolTable* parent);

    auto define(String name, Symbol* type) noexcept -> bool;
    auto isDefined(String const& name) noexcept -> bool;
    auto resolve(String const& name, Symbol* defaultValue = nullptr) noexcept -> Symbol*;
    auto getParent() const noexcept -> SymbolTable*;
    auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      std::function<bool (Symbol*)> filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<String>;

    private:
    SymbolTable* M_parent;
    Map<String, Box<Symbol>> M_symbols;
  };
}



