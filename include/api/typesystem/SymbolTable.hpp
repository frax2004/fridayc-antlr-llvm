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

    /// @brief Finds the most similar symbol in the symbol table
    /// @param name the target name
    /// @param maxEditDistance the maximium distance used by the edit distance algorithm
    /// @param filter a filter predicate
    /// @return the most similar symbol (if there is one)
    auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      std::function<bool (Symbol*)> filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<Symbol*>;

  }; // struct SymbolTable
} // namespace friday::api::typechecker



