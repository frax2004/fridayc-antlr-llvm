#ifdef __INTELLISENSE__
#include "factory.hpp"
#endif

namespace cpp {

  template<class T>
  Factory<T>::container_type Factory<T>::S_products { };

  template<class T>
  template<class... Args>
  requires (std::constructible_from<T, Args...>)
  auto Factory<T>::create(Args&& ...args) -> T* {
    Factory<T>::S_products.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    return Factory<T>::S_products.back().get();
  }

  template<class T>
  auto Factory<T>::products() -> decltype(auto) {
    return Factory<T>::S_products
    | std::views::transform(&std::unique_ptr<T>::get);
  }
}