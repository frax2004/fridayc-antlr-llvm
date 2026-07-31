#include <Common.hpp>
#include <Console.hpp>
#include <Error.hpp>
#include <OperationNotSupportedError.hpp>
#include <NullPointerError.hpp>

using namespace friday;


auto main(i32 argc, const i8** argv) -> i32 {
  if constexpr(FRIDAY_API_ENABLE_SIGSEGV_AS_EXCEPTION) {
    signal(SIGSEGV, [](int signum) {
      (void)signum;
      throw NullPointerError{};
    });
  }

  extern void Main(vector<string> args);

  try {
    Main(vector<string>{ argv + 1, argv + argc});
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
  } catch(const exception& exception) {
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
