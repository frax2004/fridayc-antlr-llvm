#pragma once

#include "Error.hpp"

namespace friday::inline core {

  /// @brief Attempt to call a function that is not supported for a struct
  struct OperationNotSupportedError final : public Error<> {
    /// @brief Default empty constructor
    constexpr inline OperationNotSupportedError(String info) noexcept;

    /// @brief Get the error description
    /// @return the error message
    constexpr inline auto what() const noexcept -> String override;

    private:
    /// @brief description message
    String M_info { "" };
  }; // struct OperationNotSupportedError
} // namespace friday::core


#include "OperationNotSupportedError.inl"