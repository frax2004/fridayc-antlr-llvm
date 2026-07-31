#ifdef __INTELLISENSE__
#include <Factory.hpp>
#endif

namespace friday::inline core {

  template<class T>
  Factory<T>::container_type Factory<T>::S_products { };

  template<class T>
  template<class... Args>
  requires (constructible_from<T, Args...>)
  auto Factory<T>::create(Args&& ...args) -> T* {
    Factory<T>::S_products.push_back(make_unique<T>(forward<Args>(args)...));
    return Factory<T>::S_products.back().get();
  }

  template<class T>
  auto Factory<T>::products() -> decltype(auto) {
    return Factory<T>::S_products
    | views::transform(&unique_ptr<T>::get);
  }
}