#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typechecker {

  struct Type;

  /// @brief Represents a variable
  struct Variable : public Symbol {
    private:
    /// @brief the name of the variable
    String M_name;
    /// @brief the type of the variable
    Type* M_type;
    /// @brief the visibility of the variable
    VisibilityModifier M_visibility;
    
    public:
    /// @brief Constructs a variable
    /// @param name the name
    /// @param type the type
    /// @param visibility the visibility modifier
    Variable(String name, Type* type, VisibilityModifier visibility) noexcept;

    /// @brief Gets the name of the variable
    /// @return the name of the variable
    auto getName() const noexcept -> String const&;

    /// @brief Gets the type of the variable
    /// @return the type of the variable
    auto getType() const noexcept -> Type* override;

    /// @brief Gets the internal llvm type of the variable
    /// @return the llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    /// @brief Gets the visibility modifier of the variable
    /// @return the visibility modifier
    auto getVisibility() const noexcept -> VisibilityModifier override;
  }; // struct Variable
} // namespace friday::api::typechecker