#include "core/Common.hpp"
#include "core/IO/Console.hpp"
#include "core/errors/Error.hpp"
#include "core/errors/OperationNotSupportedError.hpp"





using namespace friday;

extern void Main(Vector<StringRef> args);




auto main(i32 argc, const i8** argv) -> i32 {
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
