#pragma once

#include "TypedSymbol.hpp"
#include "FunctionType.hpp"

namespace friday::inline api::inline typesystem {
  struct SymbolTable;

  /// @brief Represents a function symbol
  struct Function : public TypedSymbol {
    private:
    /// @brief the function name
    String M_name;
    /// @brief The function return type
    FunctionType* M_signature;
    /// @brief The parameters names
    Vector<String> M_parameters;
    /// @brief The symbol table in which the function was defined
    SymbolTable* M_declaringSymbolTable;

    public:
    /// @brief Constructs a function
    /// @param name the name
    /// @param parameters the parameters
    /// @param visibility the visibility modifier
    Function(
      SymbolTable* parent,
      String name,
      Type* returnType,
      Vector<std::pair<String, Type*>> parameters
    );

    /// @brief Get the `nth` parameter name
    /// @param index the index of the parameter
    /// @return the parameter name
    /// @throws `std::out_of_bounds` error if the index is out of bounds
    auto getParameterName(u64 index) const -> String const&;

    /// @brief Gets the `nth` parameter
    /// @param index the index of the parameter
    /// @return the parameter
    /// @throws `std::out_of_bounds` error if the index is out of bounds
    auto getParameter(u64 index) const -> std::pair<String, Type*>;

  }; // struct Function
} // namespace friday::api::typesystem

