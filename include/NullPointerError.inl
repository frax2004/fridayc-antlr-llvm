#ifdef __INTELLISENSE__
#include "NullPointerError.hpp"
#endif

namespace friday::inline core {
  constexpr inline auto NullPointerError::what() const noexcept -> String {
    return "Cannot dereference a null pointer instance\n";
  }
}