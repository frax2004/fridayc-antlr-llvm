#include <iolib/console.hpp>


namespace iolib {

  bool Console::S_debugEnabled = true;
  std::FILE* Console::S_stderr = stderr;
  std::FILE* Console::S_stddbg = stderr;
  std::FILE* Console::S_stdlog = stdout;
  std::FILE* Console::S_stdnte = stdout;
  std::FILE* Console::S_stdwrn = stderr;

  const std::string Console::Color::RED = Console::Color::rgb(227, 61, 61);
  const std::string Console::Color::GREEN = Console::Color::rgb(121, 237, 121);
  const std::string Console::Color::BLUE = Console::Color::rgb(21, 163, 224);
  const std::string Console::Color::PURPLE = Console::Color::rgb(220, 11, 199);
  const std::string Console::Color::YELLOW = Console::Color::rgb(255, 215, 0);
  const std::string Console::Color::ORANGE = Console::Color::rgb(253, 160, 40);
  const std::string Console::Color::WHITE = Console::Color::rgb(255, 255, 255);
  const std::string Console::Color::RESET = "\033[0m";
  const std::string Console::Color::BOLD = "\033[1m";

  auto Console::set_debug_enabled(bool enabled) noexcept -> void {
    Console::S_debugEnabled = enabled;
  }
  
  auto Console::set_channel(Channel channel, std::FILE* stream) noexcept -> void {
    switch(channel) {
      case Channel::LOG: {
        Console::S_stdlog = stream;
        break;
      } case Channel::DEBUG: {
        Console::S_stddbg = stream;
        break;
      } case Channel::NOTE: {
        Console::S_stdnte = stream;
        break;
      } case Channel::WARNING: {
        Console::S_stdwrn = stream;
        break;
      } case Channel::ERROR: {
        Console::S_stderr = stream;
        break;
      }
    }
  }

  auto Console::log(std::string message) noexcept -> void {
    if(Console::S_stdlog == nullptr) return;
    std::println(
      Console::S_stdlog,
      "{}fridayc{}: {}{}log{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::GREEN,
      Color::BOLD,
      Color::RESET,
      message
    );
  }
  
  auto Console::note(std::string message) noexcept -> void {
    if(Console::S_stdnte == nullptr) return;
    std::println(
      Console::S_stdnte,
      "{}fridayc{}: {}{}note{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::BLUE,
      Color::BOLD,
      Color::RESET,
      message
    );
  }

  auto Console::warning(std::string message) noexcept -> void {
    if(Console::S_stdwrn == nullptr) return;
    std::println(
      Console::S_stdwrn,
      "{}fridayc{}: {}{}warning{}: {}", 
      Color::BOLD,
      Color::RESET,
      Color::ORANGE,
      Color::BOLD,
      Color::RESET,
      message
    );
  }

  auto Console::error(std::string message) noexcept -> void {
    if(Console::S_stderr == nullptr) return;
    std::println(
      Console::S_stderr,
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

  auto Console::debug(std::string message) noexcept -> void {
    if(not (Console::S_debugEnabled and Console::S_stddbg != nullptr)) return;
    std::println(
      Console::S_stddbg,
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

