#ifdef __INTELLISENSE__
#include <Annotation.hpp>
#endif

namespace friday::inline api::inline pipeline {
  

  template<class... Properties>
  auto AnnotationTree<Properties...>::setMetadata(key_type key, annotation_type metadata) -> void {
    this->M_properties.insert_or_assign(key, metadata);
  }

  template<class... Properties>
  template<class T>
  requires (same_as<T, Properties> or ...)
  auto AnnotationTree<Properties...>::isAnnotatedWith(key_type key) const -> bool {
    constexpr const auto predicate = &holds_alternative<T, Properties...>;
    auto it = this->M_properties.find(key);
    return it != this->M_properties.end() and predicate(it->second);
  }

  template<class... Properties>
  template<class T>
  requires (same_as<T, Properties> or ...)
  auto AnnotationTree<Properties...>::getMetadata(key_type key) const -> optional<T> {
    constexpr const auto predicate = &holds_alternative<T, Properties...>;
    auto it = this->M_properties.find(key);
    return it != this->M_properties.end() and predicate(it->second) ?
      make_optional<T>(get<T>(it->second)) : nullopt;
  }

  template<class... Properties>
  auto AnnotationTree<Properties...>::operator[](key_type key) -> annotation_type& {
    return this->M_properties[key];
  }


  template<class... Properties>
  template<class T>
  requires (same_as<T, Properties> or ...)
  auto AnnotationTree<Properties...>::getMetadata(key_type key, T fallback) const -> T {
    constexpr const auto predicate = &holds_alternative<T, Properties...>;
    auto it = this->M_properties.find(key);
    return it != this->M_properties.end() and predicate(it->second) ?
      get<T>(it->second) : fallback;
  }
}