#pragma once

#include "Error.hpp"

namespace friday::inline core {
  /// @brief Null pointer dereference attempt error
  struct NullPointerError final : public Error<> {
    /// @brief Default empty constructor
    constexpr inline NullPointerError() noexcept = default;

    /// @brief Get the error description
    /// @return the error message
    constexpr inline auto what() const noexcept -> String override;
  }; // struct NullPointerError
} // namespace friday::core

#include "NullPointerError.inl"