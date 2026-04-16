#pragma once


#include "Symbol.hpp"


namespace friday::inline api::inline typechecker {
  
  /// @brief Represents a type in the type system
  struct Type : public Symbol {
    private:
    /// @brief the struct name
    String M_name;
    /// @brief the struct visibility modifier
    VisibilityModifier M_visibility;

    public:
    /// @brief Constructs a struct
    /// @param name the name
    /// @param visibility the visibility modifier
    Type(
      String name, 
      VisibilityModifier visibility = VisibilityModifier::PUBLIC
    ) noexcept;

    /// @brief Gets the name of the struct
    /// @return the name of the struct
    auto getName() const noexcept -> String const&;
    
    /// @brief Gets the visibility modifier of the struct
    /// @return the visibility modifier
    auto getVisibility() const noexcept -> VisibilityModifier override;

    /// @brief Get the default error type
    /// @return the error type instance
    static auto getErrorType() -> Type*;

  }; // struct Type
} // namespace friday::api::typechecker