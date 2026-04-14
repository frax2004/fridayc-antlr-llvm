#ifdef __INTELLISENSE__
#include "Symbol.hpp"
#endif

namespace friday::inline api::inline typechecker {
  
  template<std::derived_from<Symbol> T>
  auto Symbol::is() const noexcept -> bool {
    return dynamic_cast<const T*>(this) != nullptr;
  }

  template<std::derived_from<Symbol> T>
  auto Symbol::as() noexcept -> T* {
    return dynamic_cast<T*>(this);
  }
}