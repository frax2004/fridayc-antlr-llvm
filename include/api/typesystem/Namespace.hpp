#pragma once

#include "Symbol.hpp"
#include "SymbolTable.hpp"
#include "Struct.hpp"
#include "Variable.hpp"
#include "Function.hpp"


namespace friday::inline api::inline typesystem {

  /// @brief Represents a namespace
  struct Namespace : public Symbol, public SymbolTable {
    private:
    /// @brief The declared structs
    Map<String, Struct> M_structs;
    /// @brief The declared variables
    Map<String, Variable> M_variables;
    /// @brief The declared functions
    Map<String, Function> M_functions;
    
    public:
    /// @brief Creates a namespace
    /// @param variables the initial variables
    /// @param functions the initial functions
    /// @param structs the initial structs
    Namespace(
      Map<String, Variable> variables = {},
      Map<String, Function> functions = {},
      Map<String, Struct> structs = {}
    );

    /// @brief Get the global namespace
    /// @return the global namespace
    static auto getGlobal() -> Namespace*;
    /// @brief Get a function
    /// @param id the mangled identifier of the function
    /// @param defaultValue a default fallback function
    /// @return the function or defaultValue if not present
    auto getFunction(String const& id, Function* defaultValue) -> Function*;
    /// @brief Get a struct
    /// @param id the mangled identifier of the struct
    /// @param defaultValue a default fallback struct
    /// @return the struct or defaultValue if not present
    auto getStruct(String const& id, Struct* defaultValue) -> Struct*;
    /// @brief Get a variable
    /// @param id the mangled identifier of the variable
    /// @param defaultValue a default fallback variable
    /// @return the variable or defaultValue if not present
    auto getVariable(String const& id, Variable* defaultValue) -> Variable*;

    /// @brief Get the qualified id
    /// @return the qualified id
    auto getQualifiedId() const -> String override;
    /// @brief Get the full qualified id
    /// @return the full qualified id
    auto getFullQualifiedId() const -> String override;
    /// @brief Get the mangled id
    /// @return the mangled id
    auto getMangledId() const -> String override;
    /// @brief Get the declaring symbol table
    /// @return the declaring symbol table
    auto getDeclaringSymbolTable() -> SymbolTable* override;
    /// @brief Get the attributes for this symbol
    /// @return the attributes for this symbol
    auto getAttributes() const -> Attributes const& override;

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
  }; // struct Namespace
} // namespace friday::api::typesystem
