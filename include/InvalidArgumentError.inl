#ifdef __INTELLISENSE__
#include "InvalidArgumentError.hpp"
#endif

namespace friday::inline core {
  constexpr inline InvalidArgumentError::InvalidArgumentError(String info) noexcept
    : Error<> { }
    , M_info { info }
  {}

  constexpr inline auto InvalidArgumentError::what() const noexcept -> String {
    return this->M_info;
  }
}