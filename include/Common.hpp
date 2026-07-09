#pragma once

#include <bits/stdc++.h>
#include <antlr4-runtime.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

namespace ant = antlr4;

using namespace std;
using namespace string_literals;
using namespace string_view_literals;

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
using rc = shared_ptr<T>;

template<class T>
using weak = weak_ptr<T>;

using string_ref = string_view;

template<class T>
struct hash<vector<T*>> {
  auto operator()(vector<T*> const& vec) const noexcept -> size_t;
};


namespace friday::inline traits {
  struct NonCopyable {
    constexpr NonCopyable() = default;
    constexpr NonCopyable(NonCopyable const&) = delete;
    constexpr auto operator=(NonCopyable const&) = delete;
    constexpr virtual ~NonCopyable() = default;
  };

  struct NonMovable {
    constexpr NonMovable() = default;
    constexpr NonMovable(NonMovable &&) = delete;
    constexpr auto operator=(NonMovable &&) = delete;
    constexpr virtual ~NonMovable() = default;
  };

}

namespace friday::inline core {
  struct FormatString final {
    const i8* fmt { nullptr };

    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> string;
  };

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString;
}

namespace friday::inline core::inline rtti {
  auto demangle(const char* name) noexcept -> string;
  auto nameOf(type_info const& info) noexcept -> string;

  template<class To, class From>
  auto cast(From* from) -> To*;

  template<class Other, class This>
  auto instanceOf(This* object) -> bool;
}

#include <Common.inl>