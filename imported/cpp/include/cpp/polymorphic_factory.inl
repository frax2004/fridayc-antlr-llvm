#ifdef __INTELLISENSE__
#include "polymorphic_factory.hpp"
#endif

namespace cpp {

  template<class T>
  PolymorphicFactory<T>::container_type PolymorphicFactory<T>::S_products { };

  template<class T>
  template<derived_from<T> U, class... Args>
  requires (constructible_from<U, Args...>)
  auto PolymorphicFactory<T>::create(Args&& ...args) -> U* {
    PolymorphicFactory<T>::S_products.push_back(std::make_unique<U>(std::forward<Args>(args)...));
    return PolymorphicFactory<T>::S_products.back().get();
  }

  template<class T>
  auto PolymorphicFactory<T>::products() -> decltype(auto) {
    return PolymorphicFactory<T>::S_products
    | std::views::transform(&std::unique_ptr<T>::get);
  }
}