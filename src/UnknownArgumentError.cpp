#include "api/cmd/UnknownArgumentError.hpp"

namespace friday::inline api::inline cmd {
  
  UnknownArgumentError::UnknownArgumentError(String message) noexcept
    : M_message { std::move(message) }
  {}

  auto UnknownArgumentError::what() const noexcept -> String {
    return this->M_message;
  }
}