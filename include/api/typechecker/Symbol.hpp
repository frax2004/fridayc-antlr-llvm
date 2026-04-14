#pragma once

#include "core/Common.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Encode the full typename
  /// @param name the typename
  /// @return the mangled typename
  auto mangle(StringRef name) -> String;

  /// @brief Decode the full typename
  /// @param name the mangled typename
  /// @return the demangled typename
  auto demangle(StringRef name) -> String;

  /// @brief Visibility access modifier
  enum VisibilityModifier {
    PRIVATE = 0,
    PUBLIC = 1,
  };

  /// @brief Represents an abstract symbol in the symbol table
  struct Symbol {

    /// @brief Tells if this symbol is an instance of one of the subtypes allowed
    /// @tparam T a symbol subtype
    /// @return true if `this` instance is a runtime instance of `T`
    template<std::derived_from<Symbol> T>
    auto is() const noexcept -> bool;

    /// @brief Attempts to cast `this` instance into subtype `T`
    /// @tparam T a symbol subtype
    /// @return `this` instance cast as `T`
    template<std::derived_from<Symbol> T>
    auto as() noexcept -> T*;

    /// @brief Get the internal llvm type
    /// @return pointer to the type
    virtual auto getLLVMType() const noexcept -> llvm::Type* = 0;

    /// @brief Get the visibility modifier for this symbol
    /// @return the visibility modifier
    virtual auto getVisibility() const noexcept -> VisibilityModifier = 0;
  }; // struct Symbol
} // namespace friday::api::typesystem

#include "Symbol.inl"

