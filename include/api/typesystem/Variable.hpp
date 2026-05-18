#pragma once

#include "TypedSymbol.hpp"


namespace friday::inline api::inline typesystem {

  /// @brief Represents a variable symbol
  struct Variable : public TypedSymbol {
    private:
    /// @brief The name
    String M_name;
    /// @brief The type
    Type* M_type;
    /// @brief The scope where the variable was defined
    SymbolTable* M_declaringScope;

    public:
    /// @brief Creates a variable
    /// @param declaringScope the scope where the variable was defined
    /// @param name the name
    /// @param type the type
    Variable(SymbolTable& declaringScope, String name, Type* type) noexcept;

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
    
    /// @brief Get the type of the variable
    /// @return the type of the variable
    auto getType() -> Type* override;
  }; // struct Variable
} // namespace friday::api::typesystem