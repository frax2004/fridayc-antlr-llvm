#include "core/IO/Console.hpp"


namespace friday::inline core::inline IO {

  bool Console::S_debugEnabled = true;

  const String Console::Color::RED = Console::Color::rgb(227, 61, 61);
  const String Console::Color::GREEN = Console::Color::rgb(121, 237, 121);
  const String Console::Color::BLUE = Console::Color::rgb(21, 163, 224);
  const String Console::Color::PURPLE = Console::Color::rgb(220, 11, 199);
  const String Console::Color::YELLOW = Console::Color::rgb(255, 215, 0);
  const String Console::Color::ORANGE = Console::Color::rgb(253, 160, 40);
  const String Console::Color::WHITE = Console::Color::rgb(255, 255, 255);
  const String Console::Color::RESET = "\033[0m";
  const String Console::Color::BOLD = "\033[1m";

  auto Console::setDebugEnabled(bool enabled) noexcept -> void {
    Console::S_debugEnabled = enabled;
  }

  auto Console::log(String message) noexcept -> void {
    std::println(
      stdout,
      "{}fridayc{}: {}{}log{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::GREEN,
      Color::BOLD,
      Color::RESET,
      message
    );
  }
  
  auto Console::note(String message) noexcept -> void {
    std::println(
      stdout,
      "{}fridayc{}: {}{}note{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::BLUE,
      Color::BOLD,
      Color::RESET,
      message
    );
  }

  auto Console::warning(String message) noexcept -> void {
    std::println(
      stdout,
      "{}fridayc{}: {}{}warning{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::ORANGE,
      Color::BOLD,
      Color::RESET,
      message
    );
  }

  auto Console::error(String message) noexcept -> void {
    std::println(
      stderr,
      "{}fridayc{}: {}{}error{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::RED,
      Color::BOLD,
      Color::RESET,
      message
    );
    std::fflush(stderr);
  }

  auto Console::debug(String message) noexcept -> void {
    if(not Console::S_debugEnabled) return;
    std::println(
      stderr,
      "{}fridayc{}: {}{}debug{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::PURPLE,
      Color::BOLD,
      Color::RESET,
      message
    );
    std::fflush(stderr);
  }
}

