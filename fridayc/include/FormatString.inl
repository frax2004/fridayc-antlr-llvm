#ifdef __INTELLISENSE__
#include <FormatString.hpp>
#endif

namespace friday::inline core {
  template<class ... Args>
  constexpr auto FormatString::format(Args &&... args) const noexcept -> string {
    return vformat(fmt, make_format_args(args...));
  }

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString {
    return FormatString{s};
  }

}

