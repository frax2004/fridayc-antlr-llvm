#pragma once
#include <string>
#include <vector>
#include "primitives.hpp"


namespace cpp {

  template<class T>
  struct pointer_vector_hash {
    auto operator()(std::vector<T*> const& vec) const noexcept -> std::size_t {
      std::size_t seed = vec.size();
      for(auto ptr : vec) {
        seed ^= std::hash<T*>{}(ptr) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
      }
      return seed;
    }
  };

  struct transparent_string_hash {
    auto operator()(std::string_view s) const -> u64;
    auto operator()(std::string const& s) const -> u64;
    auto operator()(const i8* s) const -> u64;
  
    struct is_transparent {};
  };
}

