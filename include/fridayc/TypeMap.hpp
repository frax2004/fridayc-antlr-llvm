#pragma once
#include "Core.hpp"


namespace friday::inline core {
  template<class Key, class Value>
  struct TypeMapEntry {
    using key_type = Key;
    using value_type = Value;
    consteval auto lookup(type_identity<Key>) const -> type_identity<Value> {};
  };

  template<class T>
  concept type_map_entry = requires(T e) {
    typename T::key_type;
    typename T::value_type;
    { e.lookup(type_identity<typename T::key_type>{}) } -> same_as<type_identity<typename T::value_type>>;
  };

  template<class Map, class Key>
  concept type_map_contains = requires(Map m) {
    m.lookup(type_identity<Key>{});
  };

  template<type_map_entry... Entries>
  struct TypeMap : Entries... {
    using Entries::lookup...;

    template<class Key>
    using at = typename decltype(declval<TypeMap>().lookup(type_identity<Key>{}))::type;

    template<class Key>
    static constexpr auto contains = type_map_contains<TypeMap, Key>;
  };

}