#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typesystem {

  using SymbolPredicate = std::function<bool (Symbol*)>;

  /// @brief Represents a set of symbols mapped with their name
  struct SymbolTable {
    /// @brief Look up for a name in the symbol table
    /// @param id the mangled identifier of the symbol
    /// @param defaultValue default fallback symbol
    /// @return the symbol if present, defaultValue otherwise
    virtual auto lookUp(String const& id, Symbol* defaultValue) -> Symbol* = 0;
    /// @brief Look up for a name in the symbol table
    /// @param id the mangled identifier of the symbol
    /// @param predicate a filter for the symbol
    /// @param defaultValue default fallback symbol
    /// @return the symbol if present and is true for the filter, defaultValue otherwise
    virtual auto lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* = 0;
    /// @brief Attempts to define a symbol by its name
    /// @param symbol the symbol
    /// @return `true` if the symbol is defined (false if another symbol with the same name was already defined)
    virtual auto define(Symbol* symbol) -> bool = 0;
    /// @brief Checks if a symbol is defined
    /// @param id the symbol mangled identifier
    /// @return `true` if the symbol is defined
    virtual auto isDefined(String const& id) -> bool = 0;
    /// @brief Get the parent symbol table
    /// @return the parent symbol table
    virtual auto getParent() -> SymbolTable* = 0;

    /// @brief Finds the most similar symbol by minimum edit distance
    /// @param name the target name
    /// @param maxEditDistance maximum edit distance permitted
    /// @param filter a symbol filter
    /// @return an optional containing the most similar symbol by name and by filter if there is one, or an empty optional otherwise
    virtual auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      SymbolPredicate filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<Symbol*> = 0;
  }; // struct SymbolTable
} // namespace friday::api::typesystem
