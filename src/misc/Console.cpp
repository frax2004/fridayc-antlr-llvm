#include <Console.hpp>


namespace friday::inline core::inline IO {

  bool Console::S_debugEnabled = true;

  const string Console::Color::RED = Console::Color::rgb(227, 61, 61);
  const string Console::Color::GREEN = Console::Color::rgb(121, 237, 121);
  const string Console::Color::BLUE = Console::Color::rgb(21, 163, 224);
  const string Console::Color::PURPLE = Console::Color::rgb(220, 11, 199);
  const string Console::Color::YELLOW = Console::Color::rgb(255, 215, 0);
  const string Console::Color::ORANGE = Console::Color::rgb(253, 160, 40);
  const string Console::Color::WHITE = Console::Color::rgb(255, 255, 255);
  const string Console::Color::RESET = "\033[0m";
  const string Console::Color::BOLD = "\033[1m";

  auto Console::set_debug_enabled(bool enabled) noexcept -> void {
    Console::S_debugEnabled = enabled;
  }

  auto Console::log(string message) noexcept -> void {
    println(
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
  
  auto Console::note(string message) noexcept -> void {
    println(
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

  auto Console::warning(string message) noexcept -> void {
    println(
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

  auto Console::error(string message) noexcept -> void {
    println(
      stderr,
      "{}fridayc{}: {}{}error{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::RED,
      Color::BOLD,
      Color::RESET,
      message
    );
    fflush(stderr);
  }

  auto Console::debug(string message) noexcept -> void {
    if(not Console::S_debugEnabled) return;
    println(
      stderr,
      "{}fridayc{}: {}{}debug{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::PURPLE,
      Color::BOLD,
      Color::RESET,
      message
    );
    fflush(stderr);
  }
}

