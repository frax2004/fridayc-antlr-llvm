#ifdef __INTELLISENSE__
#include "OperationNotSupportedError.hpp"
#endif

namespace friday::inline core {
  constexpr inline OperationNotSupportedError::OperationNotSupportedError(string info) noexcept
    : Error<> { }
    , M_info { info }
  {}

  constexpr inline auto OperationNotSupportedError::what() const noexcept -> string {
    return this->M_info;
  }
}