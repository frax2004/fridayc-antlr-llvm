#ifdef __INTELLISENSE__
#include "Console.hpp"
#endif

namespace friday::inline core::inline IO {

  constexpr auto Console::Color::rgb(u8 r, u8 g, u8 b) noexcept -> String {
    return "\033[38;2;{};{};{}m"_f.format(r, g, b);
  }

}