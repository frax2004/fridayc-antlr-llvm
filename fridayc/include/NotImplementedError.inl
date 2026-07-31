#ifdef __INTELLISENSE__
#include "NotImplementedError.hpp"
#endif

namespace friday::inline core {
  constexpr inline NotImplementedError::NotImplementedError(string info) noexcept
    : Error<> { }
    , M_info { info }
  {}

  constexpr inline auto NotImplementedError::what() const noexcept -> string {
    return this->M_info;
  }
}