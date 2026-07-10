#ifdef __INTELLISENSE__
#include "NullPointerError.hpp"
#endif

namespace friday::inline core {
  constexpr inline NullPointerError::NullPointerError(void* ptr) noexcept
    : M_message { format("Attempting to read from illegal memory address {}.\n", ptr) }
  {}

  constexpr inline auto NullPointerError::what() const noexcept -> string {
    return this->M_message;
  }
}