#pragma once

#include <Core.hpp>

namespace friday::inline core {

  /**
   * @brief Represents a formattable string
   */
  struct FRIDAY_API FormatString final {

  public:
    /**
     * @brief The format string
     */
    const i8* fmt { "" };

  public:
    /**
     * @brief Apply arguments to the format string
     * @tparam ...Args the type arguments
     * @param args... the arguments
     * @return the formatted string
     */
    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> string;
  };

  /**
   * @brief Convert a string literal into a formattable string
   * @param s the string literal
   * @param length the length of the string literal
   * @return the formattable string
   */
  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString;
}

#include <FormatString.inl>