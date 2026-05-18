#pragma once

#include "SymbolTable.hpp"
#include "Variable.hpp"

namespace friday::inline api::inline typesystem {

  /// @brief Function scope struct
  struct Scope final : public SymbolTable {
    private:
    /// @brief The parent symbol table
    SymbolTable* M_parent;
    /// @brief The defined variables
    Map<String, Variable> M_variables;

    public:
    /// @brief Creates a scope 
    /// @param parent the parent symbol table
    /// @param variables the initial variables
    Scope(SymbolTable& parent, Map<String, Variable> variables = {});

    /// @brief Get a defined variable
    /// @param id the mangled identifier
    /// @param defaultValue the default fallback value
    /// @return the variable or the default value if not present
    auto getVariable(String const& id, Variable* defaultValue) -> Variable*;
    
    /// @brief Look up for a name in the symbol table
    /// @param id the mangled identifier of the symbol
    /// @param defaultValue default fallback symbol
    /// @return the symbol if present, defaultValue otherwise
    auto lookUp(String const& id, Symbol* defaultValue) -> Symbol* override;
    /// @brief Look up for a name in the symbol table
    /// @param id the mangled identifier of the symbol
    /// @param predicate a filter for the symbol
    /// @param defaultValue default fallback symbol
    /// @return the symbol if present and is true for the filter, defaultValue otherwise
    auto lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* override;
    /// @brief Attempts to define a symbol by its name
    /// @param symbol the symbol
    /// @return `true` if the symbol is defined (false if another symbol with the same name was already defined)
    auto define(Symbol* symbol) -> bool override;
    /// @brief Checks if a symbol is defined
    /// @param id the symbol mangled identifier
    /// @return `true` if the symbol is defined
    auto isDefined(String const& id) -> bool override;
    /// @brief Get the parent symbol table
    /// @return the parent symbol table
    auto getParent() -> SymbolTable* override;

    /// @brief Finds the most similar symbol by minimum edit distance
    /// @param name the target name
    /// @param maxEditDistance maximum edit distance permitted
    /// @param filter a symbol filter
    /// @return an optional containing the most similar symbol by name and by filter if there is one, or an empty optional otherwise
    auto mostSimilar(
      String const& name, 
      u64 maxEditDistance = 0, 
      SymbolPredicate filter = [](Symbol*) { return true; }
    ) noexcept -> Opt<Symbol*> override;

  }; // struct Scope
} // namespace friday::api::typesystem