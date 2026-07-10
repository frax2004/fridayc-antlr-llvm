#ifdef __INTELLISENSE__
#include <Rtti.hpp>
#endif

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