#pragma once

#include "core/Common.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Visibility access modifier
  enum VisibilityModifier {
    PRIVATE = 0,
    PUBLIC = 1,
  };

  struct Type;

  /// @brief Represents an abstract symbol in the symbol table
  struct Symbol {

    /// @brief Encode the full typename
    /// @param name the typename
    /// @return the mangled typename
    auto mangle() -> String;

    /// @brief Decode the full typename
    /// @param name the mangled typename
    /// @return the demangled typename
    static auto demangle(StringRef name) -> String;

    /// @brief Get the name of the symbol
    /// @return the name of the symbol
    virtual auto getName() const noexcept -> String const& = 0;

    /// @brief Get the type of the symbol
    /// @return the type
    virtual auto getType() const noexcept -> Type* = 0;

    /// @brief Get the visibility modifier for this symbol
    /// @return the visibility modifier
    virtual auto getVisibility() const noexcept -> VisibilityModifier = 0;

  }; // struct Symbol
} // namespace friday::api::typesystem

#include "Symbol.inl"

