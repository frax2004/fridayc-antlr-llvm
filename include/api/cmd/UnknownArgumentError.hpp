#pragma once

#include "core/errors/Error.hpp"

namespace friday::inline api::inline cmd {

  /// @brief Command line argument error
  struct UnknownArgumentError : public Error<> {
    /// @brief Constructs a command line error from a message
    /// @param message the message
    UnknownArgumentError(String message) noexcept;

    /// @brief Get the error description
    /// @return the error message
    auto what() const noexcept -> String override;
    
    private:
    /// @brief the message
    String M_message;
  }; // struct UnknownArgumentError
} // namespace friday::api::cmd