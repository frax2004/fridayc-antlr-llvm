#ifdef __INTELLISENSE__
#include <PolymorphicFactory.hpp>
#endif

namespace friday::inline core {

  template<class T>
  PolymorphicFactory<T>::container_type PolymorphicFactory<T>::S_products { };

  template<class T>
  template<derived_from<T> U, class... Args>
  requires (constructible_from<U, Args...>)
  auto PolymorphicFactory<T>::create(Args&& ...args) -> U* {
    PolymorphicFactory<T>::S_products.push_back(make_unique<U>(forward<Args>(args)...));
    return PolymorphicFactory<T>::S_products.back().get();
  }

  template<class T>
  auto PolymorphicFactory<T>::products() -> decltype(auto) {
    return PolymorphicFactory<T>::S_products
    | views::transform(&unique_ptr<T>::get);
  }
}