#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typechecker {

  struct Struct;

  /// @brief Represents a variable
  struct Variable : public Symbol {
    private:
    /// @brief the name of the variable
    String name;
    /// @brief the type of the variable
    Struct* type;
    /// @brief the visibility of the variable
    VisibilityModifier visiblity;
    
    public:
    /// @brief Gets the name of the variable
    /// @return the name of the variable
    auto getName() const noexcept -> String const&;

    /// @brief Gets the type of the variable
    /// @return the type of the variable
    auto getType() const noexcept -> Struct*;

    /// @brief Gets the internal llvm type of the variable
    /// @return the llvm type
    auto getLLVMType() const noexcept -> llvm::Type* override;

    /// @brief Gets the visibility modifier of the variable
    /// @return the visibility modifier
    auto getVisibility() const noexcept -> VisibilityModifier override;
  }; // struct Variable
} // namespace friday::api::typechecker