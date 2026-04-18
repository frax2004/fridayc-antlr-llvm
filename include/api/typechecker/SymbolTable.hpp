#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a set of symbols mapped with their name
  struct SymbolTable {

    /// @brief Gets the builtin symbol table
    /// @param mod the module
    /// @return the builtin symbol table
    static auto builtins(llvm::Module& mod) noexcept -> SymbolTable;

    /// @brief Construct a symbol table
    /// @param parent the parent symbol table
    SymbolTable(SymbolTable* parent = nullptr);

    /// @brief Attempts to define a symbol if it's not already defined
    /// @param name the name of the symbol
    /// @param symbol the symbol
    /// @return `true` if and only if the symbol is succesfully defined
    auto define(String name, Symbol* symbol) noexcept -> bool;

    /// @brief Checks if a symbol is defined
    /// @param name the name of the symbol
    /// @return `true` if and only if the symbol was defined (does not check in parent symbol tables)
    auto isDefinedLocal(String const& name) noexcept -> bool;

    /// @brief Checks if a symbol is defined
    /// @param name the name of the symbol
    /// @return `true` if and only if the symbol was defined
    auto isDefined(String const& name) noexcept -> bool;

    /// @brief Attempts to resolve the name of the symbol
    /// @param name the name of the symbol
    /// @param predicate filter the symbol with this predicate
    /// @param defaultValue backoff value
    /// @return the symbol if one is found, or pass the call to the parent symbol table if it has one, or else the default value given
    auto resolveIf(String const& name, std::function<bool (Symbol*)> predicate, Symbol* defaultValue = nullptr) noexcept -> Symbol*;

    /// @brief Attempts to resolve the name of the symbol
    /// @param name the name of the symbol
    /// @param defaultValue backoff value
    /// @return the symbol if one is found, or pass the call to the parent symbol table if it has one, or else the default value given
    auto resolve(String const& name, Symbol* defaultValue = nullptr) noexcept -> Symbol*;

    /// @brief Gets the parent symbol table
    /// @return the parent symbol table
    auto getParent() const noexcept -> SymbolTable*;

    /// @brief Finds the most similar symbol in the symbol table
    /// @param name the target name
    /// @param maxEditDistance the maximium distance used by the edit distance algorithm
    /// @param filter a filter predicate
    /// @return the most similar symbol (if there is one)
    auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      std::function<bool (Symbol*)> filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<String>;

    private:
    /// @brief the parent symbol table
    SymbolTable* M_parent;
    /// @brief the symbol table
    Map<String, Box<Symbol>> M_symbols;
  }; // struct SymbolTable
} // namespace friday::api::typechecker



