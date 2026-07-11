#pragma once

#include <Common.hpp>

namespace friday::inline core::inline IO {

  struct FRIDAY_API Console final {
    private:
    constexpr Console() noexcept = default;

    public:
    struct FRIDAY_API Color final {

      private:
      constexpr inline Color() noexcept = default;

      public:
      constexpr static auto rgb(u8 r, u8 g, u8 b) noexcept -> string;

      static const string BOLD;
      static const string RESET;
      static const string WHITE;
      static const string RED;
      static const string GREEN;
      static const string BLUE;
      static const string PURPLE;
      static const string YELLOW;
      static const string ORANGE;
    };

    public:
    static auto set_debug_enabled(bool enabled) noexcept -> void;

    static auto log(string message) noexcept -> void;
    static auto note(string message) noexcept -> void;
    static auto debug(string message) noexcept -> void;
    static auto warning(string message) noexcept -> void;
    static auto error(string message) noexcept -> void;

    private:
    static bool S_debugEnabled;
  };
}

#include <Console.inl>