#pragma once

#include <bits/stdc++.h>
#include <antlr4-runtime.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

using namespace std;
namespace ant = antlr4;

using namespace string_literals;
using namespace string_view_literals;

template<class T>
struct hash<vector<T*>> {
  auto operator()(vector<T*> const& vec) const noexcept -> size_t {    
    size_t seed = vec.size();
    for(auto ptr : vec) {
      seed ^= hash<T*>{}(ptr) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

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
using Predicate = function<bool(T)>;

template<class T>
using box = unique_ptr<T>;

using string_ref = string_view;


namespace friday::inline core {
  struct Formatstring final {
    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> string {
      return vformat(M_fmt, make_format_args(args...));
    }

    const i8* M_fmt  { nullptr };
  };

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> Formatstring {
    return Formatstring{s};
  }

  inline namespace rtti {
    auto demangle(const char* name) noexcept -> string;

    auto nameOf(type_info const& info) noexcept -> string;
    
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
