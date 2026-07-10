#ifdef __INTELLISENSE__
#include <Rtti.hpp>
#endif

namespace friday::inline core::inline rtti {

  template<class To, class From>
  auto cast(Pointer<From> from) -> Pointer<To> {
    return dynamic_cast<Pointer<To>>(from);
  }

  template<class Other, class This>
  auto instanceOf(Pointer<This> object) -> bool {
    return cast<Other>(object) != nullptr;
  }
}