#pragma once

#include "Symbol.hpp"
#include "Variable.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a function symbol
  struct Function : public Symbol {
    private:
    /// @brief the function name
    String M_name;
    /// @brief the function type
    llvm::Type* M_type;
    /// @brief the function parameters
    Map<String, Variable> M_parameters;
    /// @brief the function visibility
    VisibilityModifier M_visibility;

    public:
    /// @brief Constructs a function
    /// @param name the name
    /// @param parameters the parameters
    /// @param visibility the visibility modifier
    Function(
      String name,
      Map<String, Variable> parameters = {},
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
    );

    /// @brief Sets the function name
    /// @param name the name
    /// @return reference to `*this` instance
    auto setName(String name) noexcept -> Function&;
    
    /// @brief Sets the function visibility
    /// @param visibility the visibility modifier
    /// @return reference to `*this` instance
    auto setVisibiltiy(VisibilityModifier visibility) noexcept -> Function&;

    /// @brief Adds a function parameter
    /// @param parameter the parameter
    /// @return reference to `*this` instance
    auto addParameter(Variable parameter) noexcept -> Function&;

    /// @brief Gets the function parameter from the name
    /// @param name the name of the parameter
    /// @return the parameter
    auto getParameter(String const& name) const noexcept -> Variable*;

    /// @brief Gets the visibility modifier for this function
    /// @return the visibility
    auto getVisibility() const noexcept -> VisibilityModifier override;
    
    /// @brief Gets the internal llvm type for this function
    /// @return the llvm type
    auto getLLVMType() const noexcept -> llvm::Type* override;
  }; // struct Function
} // namespace friday::api::typechecker

