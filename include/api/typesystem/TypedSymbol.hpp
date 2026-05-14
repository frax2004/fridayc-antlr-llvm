#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typesystem {
  struct Type;

  /// @brief Represents a typed symbol
  struct TypedSymbol : public Symbol {
    /// @brief Get the type of the symbol
    /// @return the type of the symbol
    virtual auto getType() -> Type* = 0;
  }; // struct TypedSymbol
} // namespace friday::api::typesystem