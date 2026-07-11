#pragma once

namespace friday::inline traits {
  struct FRIDAY_API NonCopyable {
    constexpr NonCopyable() = default;
    constexpr NonCopyable(NonCopyable const&) = delete;
    constexpr auto operator=(NonCopyable const&) = delete;
    constexpr virtual ~NonCopyable() = default;
  };

  struct FRIDAY_API NonMovable {
    constexpr NonMovable() = default;
    constexpr NonMovable(NonMovable &&) = delete;
    constexpr auto operator=(NonMovable &&) = delete;
    constexpr virtual ~NonMovable() = default;
  };

}