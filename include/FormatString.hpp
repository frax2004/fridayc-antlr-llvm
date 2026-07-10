#pragma once

#include <Core.hpp>

namespace friday::inline core {
  struct FormatString final {
    const i8* fmt { nullptr };

    template<class ... Args>
    constexpr auto format(Args &&... args) const noexcept -> string;
  };

  constexpr auto operator""_f(const i8* s, u64 length) noexcept -> FormatString;
}

#include <FormatString.inl>