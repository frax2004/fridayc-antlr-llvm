#pragma once

#include "Symbol.hpp"
#include "Variable.hpp"
#include "FunctionType.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a function symbol
  struct Function : public Symbol {
    private:
    /// @brief the function name
    String M_name;
    /// @brief The function return type
    FunctionType* M_signature;
    /// @brief the function visibility
    VisibilityModifier M_visibility;
    /// @brief The parameters names
    Vector<String> M_parameters;

    public:
    /// @brief Constructs a function
    /// @param name the name
    /// @param parameters the parameters
    /// @param visibility the visibility modifier
    Function(
      String name,
      Type* returnType,
      Vector<std::pair<String, Type*>> parameters,
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
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

    /// @brief Gets the visibility modifier for this function
    /// @return the visibility
    auto getVisibility() const noexcept -> VisibilityModifier override;

    /// @brief Get the function type
    /// @return the function signature
    auto getType() const noexcept -> Type* override;

    /// @brief Get the name of the function
    /// @return the name of the function
    auto getName() const noexcept -> String const& override;

    /// @brief Get the mangled function name
    /// @param name the name of the function
    /// @param paramsTypes the types of the parameters
    /// @return the mangled name
    auto getMangledName() const noexcept -> String;

    /// @brief Get the mangled function name
    /// @param name the name of the function
    /// @param paramsTypes the types of the parameters
    /// @return the mangled name
    static auto mangle(String const& name, Vector<Type*> const& paramsTypes) noexcept -> String;
  }; // struct Function
} // namespace friday::api::typechecker

