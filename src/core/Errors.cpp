#include <fridayc.hpp>



namespace friday::inline core {
  
  auto Error::trace() const noexcept -> string {
    constexpr auto traceCallExpressionTostring = [](stacktrace_entry const& trace) noexcept -> string {
      return format("from {}{}{}:{}{}\n ↳ in function : {}{}{}{}",
        Console::Color::BOLD,
        Console::Color::rgb(150, 150, 150),
        trace.source_file(),
        trace.source_line(),
        Console::Color::RESET,
        Console::Color::BOLD,
        Console::Color::RED,
        trace.description()
        | views::split("::"s)
        | views::join_with("."s)
        | ranges::to<string>(),
        Console::Color::RESET
      );
    };

    constexpr auto traceCallExpressionFilter = [](stacktrace_entry const& trace) noexcept -> bool {
      return trace.source_file() != "" and trace.source_line() != 0;
    };

    return this->M_trace
    | views::filter(traceCallExpressionFilter)
    | views::take(this->M_trace.size()-4)
    | views::drop(2)
    | views::transform(traceCallExpressionTostring)
    | views::join_with("\n"s)
    | ranges::to<string>();
    
  }

  auto InvalidArgumentError::what() const noexcept -> string {
    return "Invalid argument passed to function call";
  }

  auto NotImplementedError::what() const noexcept -> string {
    return "Function is not yet implemented or it may not be supposed to";
  }

  auto NullPointerError::what() const noexcept -> string {
    return "Illegal memory access";
  }

  auto OperationNotSupportedError::what() const noexcept -> string {
    return "Attempted to call an operation that is not supported";
  }


  RuntimeError::RuntimeError(string message) noexcept
    : M_info { message }
  {}

  auto RuntimeError::what() const noexcept -> string {
    return this->M_info;
  }
}