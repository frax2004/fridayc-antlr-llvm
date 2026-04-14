#include "core/Common.hpp"
#include "core/IO/Console.hpp"
#include "core/errors/Error.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

using namespace friday;


auto main(i32 argc, const i8** argv) -> i32 {

  extern void Main(Vector<StringRef> args);

  try {
    Main(Vector<StringRef>{ argv + 1, argv + argc});
  } catch(const Error<>& error) {

    Console::error(
      "{}{}{}{}\nMost recent call first:\n{}"_f.format(
        Console::Color::RED,
        Console::Color::BOLD,
        error.what(),
        Console::Color::RESET,
        error.trace()
      )
    );
  } catch(const std::exception& exception) {
    Console::error(
      "{}{}{}{}"_f.format(
        Console::Color::RED,
        Console::Color::BOLD,
        exception.what(),
        Console::Color::RESET
      )
    );  
  }

  return 0;
}
