#ifdef __INTELLISENSE__
#include "TypeChecker.hpp"
#endif


namespace friday::inline api::inline typechecker {
  template<class T>
  auto TypeChecker::byVisiting() const noexcept -> std::function<std::any (T*)> {
    return [this](T* ctx) -> std::any {
      return this->visit(ctx);
    };
  }

}