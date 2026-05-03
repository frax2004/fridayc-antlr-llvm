#pragma once

#include <bits/stdc++.h>
#include <antlr4-runtime.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>

namespace ant = antlr4;

using namespace std::string_literals;
using namespace std::string_view_literals;

namespace friday::inline core {


  /// @brief `8-bit` signed integer
  using byte = char;

  /// @brief `8-bit` unsigned integer
  using ubyte = unsigned char;

  /// @brief `1-bit` unsigned integer
  using bit = bool;

  /// @brief `8-bit` signed integer
  using i8 = char;
  
  /// @brief `16-bit` signed integer
  using i16 = short;
  
  /// @brief `32-bit` signed integer
  using i32 = int;
  
  /// @brief `64-bit` signed integer
  using i64 = long long;

  /// @brief `8-bit` unsigned integer
  using u8 = unsigned char;
  
  /// @brief `16-bit` unsigned integer
  using u16 = unsigned short;
  
  /// @brief `32-bit` unsigned integer
  using u32 = unsigned int;
  
  /// @brief `64-bit` unsigned integer
  using u64 = unsigned long long;

  /// @brief `32-bit` floating-point
  using f32 = float;

  /// @brief `64-bit` floating-point
  using f64 = double;

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

  /// @brief Formattable string struct
  struct FormatString final {

    /// @brief Formats the string with the given arguments
    /// @tparam ...Args the aruments types
    /// @param ...args the arguments
    /// @return the formatted string
    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> String {
      return std::vformat(M_fmt, std::make_format_args(args...));
    }

    const i8* M_fmt;
  }; // struct FormatString

  /// @brief Converts a compile time known string literal into a format string
  /// @param s the string literal
  /// @param len the length of the string literal
  /// @return the format string
  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString {
    return FormatString{s};
  }


  namespace rtti {
    auto nameOf(std::type_info const& info) noexcept -> String;
    
    template<class From, class To>
    auto cast(From* from) -> To* {
      return dynamic_cast<To*>(from);
    }

    template<class T, class U>
    auto instanceOf(T* object) -> bool {
      return dynamic_cast<U*>(object) != nullptr;
    }
  }
} // namespace friday
