#pragma once

#include "SymbolTable.hpp"
#include "Type.hpp"
#include "Field.hpp"
#include "Method.hpp"

namespace friday::inline api::inline typesystem {

  struct Namespace;

  /// @brief Represents a struct
  struct Struct : public Symbol, public Type, public SymbolTable {
    private:
    /// @brief The name
    String M_name;
    /// @brief The fields
    Map<String, Field> M_fields;
    /// @brief The methods
    Map<String, Method> M_methods;

    public:
    /// @brief Creates a struct
    /// @param parent the namespace where the struct was defined
    /// @param name the name of the struct
    /// @param fields the fields of the struct
    /// @param methods the methods of the struct
    Struct(
      Namespace* parent,
      String name, 
      Map<String, Field> fields = {}, 
      Map<String, Method> methods = {}
    ) noexcept;

    /// @brief Adds a method to the struct
    /// @param method the method
    /// @return true if the method is added
    auto addMethod(Method method) noexcept -> bool; 
    /// @brief Get a field
    /// @param name the name of the field
    /// @param defaultValue a default fallback field
    /// @return the field or default value if not present
    auto getField(String const& name, const Field* defaultValue = nullptr) const noexcept -> const Field*;
    /// @brief Get a method
    /// @param name the name of the method
    /// @param defaultValue a default fallback method
    /// @return the method or default value if not present
    auto getMethod(String const& name, const Method* defaultValue = nullptr) const noexcept -> const Method*;

    /// @brief Get the name of the type
    /// @return the name of the type
    auto getName() const noexcept -> String const& override;
    /// @brief Get the associated llvm type
    /// @param ctx the context
    /// @return the associated llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

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

  }; // struct Struct
} // namespace friday::api::typechecker

