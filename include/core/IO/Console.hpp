#pragma once

#include "core/Common.hpp"

namespace friday::inline core::inline IO {

  /// @brief Console singleton instance
  struct Console {
    private:
    /// @brief Default empty constructor
    constexpr Console() noexcept = default;

    public:
    /// @brief Represents a display color in the console
    struct Color {

      private:
      /// @brief Default empty constructor
      constexpr inline Color() noexcept = default;

      public:
      /// @brief Get a color escape sequence
      /// @param r the red channel
      /// @param g the green channel
      /// @param b the blue channel
      /// @return the rgb formatted string escape sequence
      constexpr static auto rgb(u8 r, u8 g, u8 b) noexcept -> String;

      /// @brief Sets the text to bold
      static const String BOLD;
      /// @brief Resets any text modifier
      static const String RESET;
      /// @brief Sets the text color to white
      static const String WHITE;
      /// @brief Sets the text color to red
      static const String RED;
      /// @brief Sets the text color to green
      static const String GREEN;
      /// @brief Sets the text color to blue
      static const String BLUE;
      /// @brief Sets the text color to purple
      static const String PURPLE;
      /// @brief Sets the text color to yellow
      static const String YELLOW;
      /// @brief Sets the text color to orange
      static const String ORANGE;
    }; // struct Color

    public:
    /// @brief Enable or disable the debug mode
    /// @param enabled the state 
    static auto setDebugEnabled(bool enabled) noexcept -> void;

    /// @brief Print a log to the console to the standard output channel
    /// @param message the message
    static auto log(String message) noexcept -> void;
    /// @brief Print a note to the console to the standard output channel
    /// @param message the message
    static auto note(String message) noexcept -> void;
    /// @brief Print a debug message to the console standard error channel
    /// @param message the message
    static auto debug(String message) noexcept -> void;

    /// @brief Print a warning to the console to the standard error channel
    /// @param message the message
    static auto warning(String message) noexcept -> void;
    /// @brief Print an error to the standard error channel
    /// @param message the message
    static auto error(String message) noexcept -> void;

    private:
    /// @brief Debug mode flag
    static bool S_debugEnabled;
  }; // struct Console
} // namespace friday::core::IO

#include "Console.inl"