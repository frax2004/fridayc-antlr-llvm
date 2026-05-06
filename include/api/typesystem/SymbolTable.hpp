#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typesystem {

  /// @brief Represents a set of symbols mapped with their name
  struct SymbolTable {

    virtual auto lookUp(String const& id, Symbol* defaultValue) -> Symbol* = 0;
    virtual auto lookUpIf(String const& id, std::function<bool (Symbol*)> predicate, Symbol* defaultValue) -> Symbol* = 0;
    virtual auto define(Symbol* symbol) -> bool = 0;
    virtual auto isDefined(String const& id) -> bool = 0;
    virtual auto getParent() -> SymbolTable* = 0;

    virtual auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      std::function<bool (Symbol*)> filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<Symbol*> = 0;

  }; // struct SymbolTable
} // namespace friday::api::typechecker



