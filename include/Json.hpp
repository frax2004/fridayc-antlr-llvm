#pragma once
#include <Common.hpp>

namespace json {

  template<class T>
  struct stringify;

  template<class T>
  concept object = requires (T candidate) {
    { candidate.to_json_string() } -> convertible_to<string>;
  } or requires (T candidate) {
    stringify<T>{};
    { stringify<T>{}(candidate) } -> convertible_to<string>;
  };
}
