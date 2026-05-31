#pragma once

#include <bits/stdc++.h>
#include <antlr4-runtime.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

namespace ant = antlr4;

using namespace std::string_literals;
using namespace std::string_view_literals;

template<class T>
struct std::hash<std::vector<T*>> {
  auto operator()(std::vector<T*> const& vec) const noexcept -> std::size_t {    
    std::size_t seed = vec.size();
    for(auto ptr : vec) {
      seed ^= std::hash<T*>{}(ptr) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

namespace friday::inline core {

  using byte = char;
  using ubyte = unsigned char;
  using bit = bool;
  using i8 = char;
  using i16 = short;
  using i32 = int;
  using i64 = long long;
  using u8 = unsigned char;
  using u16 = unsigned short;
  using u32 = unsigned int;
  using u64 = unsigned long long;
  using f32 = float;
  using f64 = double;

  template<class T>
  using Predicate = std::function<bool(T)>;

  template<class T>
  using Stack = std::stack<T>;

  template<class T>
  using Vector = std::vector<T>;

  template<class K, class V, class Comp = std::less<K>>
  using Map = std::map<K, V, Comp>;

  template<class K, class V>
  using UnorderedMap = std::unordered_map<K, V>;

  template<class K, class Comp = std::less<K>>
  using Set = std::set<K, Comp>;

  template<class K>
  using UnorderedSet = std::unordered_set<K>;

  template<class T>
  using Box = std::unique_ptr<T>;

  using String = std::string;

  using StringRef = std::string_view;

  template<class T>
  using Opt = std::optional<T>;


  struct FormatString final {
    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> String {
      return std::vformat(M_fmt, std::make_format_args(args...));
    }

    const i8* M_fmt;
  };

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString {
    return FormatString{s};
  }

  namespace rtti {
    auto demangle(const char* name) noexcept -> String;

    auto nameOf(std::type_info const& info) noexcept -> String;
    
    template<class To>
    auto cast(auto* from) -> To* {
      return dynamic_cast<To*>(from);
    }

    template<class Other>
    auto instanceOf(auto* object) -> bool {
      return dynamic_cast<Other*>(object) != nullptr;
    }
  }
}
