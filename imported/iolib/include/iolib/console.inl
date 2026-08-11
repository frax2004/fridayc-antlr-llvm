#ifdef __INTELLISENSE__
#include "console.hpp"
#endif

namespace iolib {

  constexpr auto Console::Color::rgb(unsigned char r, unsigned char g, unsigned char b) noexcept -> std::string {
    return std::format("\033[38;2;{};{};{}m", r, g, b);
  }

}