#pragma once

#include "TypedSymbol.hpp"
#include "FunctionType.hpp"

namespace friday::inline api::inline typesystem {
  struct SymbolTable;

  /// @brief Represents a function symbol
  struct Function : public TypedSymbol {
    private:
    /// @brief The name
    String M_name;
    /// @brief The type
    FunctionType* M_signature;
    /// @brief The parameters names
    Vector<String> M_parameters;
    /// @brief The symbol table where the symbol table was defined
    SymbolTable* M_declaringSymbolTable;

    public:
    /// @brief Creates a function
    /// @param parent the scope where the function was defined
    /// @param name the name
    /// @param returnType the return type
    /// @param parameters an array of parameters, that is, an array a pairs: (name, type)
    Function(
      SymbolTable* parent,
      String name,
      Type* returnType,
      Vector<std::pair<String, Type*>> parameters
    );

    /// @brief Get the ith parameter's name
    /// @param index the parameter index
    /// @return the name of the parameter
    auto getParameterName(u64 index) const -> String const&;
    /// @brief Get the ith parameter
    /// @param index the parameter index
    /// @return a pair of (name, type) representing the parameter
    auto getParameter(u64 index) const -> std::pair<String, Type*>;
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

    /// @brief Get the type of the function
    /// @return the type of the function
    auto getType() -> Type* override;

  }; // struct Function
} // namespace friday::api::typesystem

