#ifdef __INTELLISENSE__
#include <Common.hpp>
#endif

template<class T>
auto hash<vector<T*>>::operator()(vector<T*> const& vec) const noexcept -> size_t {    
  size_t seed = vec.size();
  for(auto ptr : vec) {
    seed ^= hash<T*>{}(ptr) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}

namespace friday::inline core {
  template<class ... Args>
  constexpr auto FormatString::format(Args &&... args) const noexcept -> string {
    return vformat(fmt, make_format_args(args...));
  }

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString {
    return FormatString{s};
  }

}


namespace friday::inline core::inline rtti {

  template<class To, class From>
  auto cast(From* from) -> To* {
    return dynamic_cast<To*>(from);
  }

  template<class Other, class This>
  auto instanceOf(This* object) -> bool {
    return cast<Other>(object) != nullptr;
  }
}