#ifdef __INTELLISENSE__
#include "Error.hpp"
#endif



#include "Console.hpp"

namespace friday::inline core {

  template<class MessageType>
  constexpr inline Error<MessageType>::Error() noexcept
    : M_trace { stacktrace::current() }
  {}

  template<class MessageType>
  constexpr inline auto Error<MessageType>::trace() const noexcept -> string {
    constexpr auto traceCallExpressionTostring = [](stacktrace_entry const& trace) noexcept -> string {
      return "from {}{}{}:{}{} in function : {}{}{}{}"_f.format(
        Console::Color::BOLD,
        Console::Color::rgb(150, 150, 150),
        trace.source_file(),
        trace.source_line(),
        Console::Color::RESET,
        Console::Color::BOLD,
        Console::Color::RED,
        trace.description(),
        Console::Color::RESET
      );
    };

    constexpr auto traceCallExpressionFilter = [](stacktrace_entry const& trace) noexcept -> bool {
      return trace.source_file() != "" and trace.source_line() != 0;
    };

    return this->M_trace
    | views::filter(traceCallExpressionFilter)
    | views::transform(traceCallExpressionTostring)
    | views::join_with("\n"s)
    | ranges::to<string>();
    
  }

}