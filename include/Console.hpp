#pragma once

#include <Common.hpp>

namespace friday::inline core::inline IO {

  struct Console final {
    private:
    constexpr Console() noexcept = default;

    public:
    struct Color final {

      private:
      constexpr inline Color() noexcept = default;

      public:
      constexpr static auto rgb(u8 r, u8 g, u8 b) noexcept -> String;

      static const String BOLD;
      static const String RESET;
      static const String WHITE;
      static const String RED;
      static const String GREEN;
      static const String BLUE;
      static const String PURPLE;
      static const String YELLOW;
      static const String ORANGE;
    };

    public:
    static auto setDebugEnabled(bool enabled) noexcept -> void;

    static auto log(String message) noexcept -> void;
    static auto note(String message) noexcept -> void;
    static auto debug(String message) noexcept -> void;
    static auto warning(String message) noexcept -> void;
    static auto error(String message) noexcept -> void;

    private:
    static bool S_debugEnabled;
  };
}

#include <Console.inl>