#pragma once

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