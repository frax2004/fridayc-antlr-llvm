#ifdef __INTELLISENSE__
#include "Type.hpp"
#endif

namespace friday::inline api::inline typechecker {

  template<std::derived_from<Type> T>
  auto Type::is() const noexcept -> bool {
    return dynamic_cast<const T*>(this) != nullptr;
  }

  template<std::derived_from<Type> T>
  auto Type::as() noexcept -> T* {
    return dynamic_cast<T*>(this);
  }
}