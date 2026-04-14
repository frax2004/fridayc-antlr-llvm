#ifdef __INTELLISENSE__
#include "Error.hpp"
#endif



#include "core/IO/Console.hpp"

namespace friday::inline core {

  template<class MessageType>
  constexpr inline Error<MessageType>::Error() noexcept
    : M_trace { std::stacktrace::current() }
  {}

  template<class MessageType>
  constexpr inline auto Error<MessageType>::trace() const noexcept -> String {
    constexpr auto traceCallToString = [](std::stacktrace_entry const& trace) noexcept -> String {
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

    constexpr auto traceCallFilter = [](std::stacktrace_entry const& trace) noexcept -> bool {
      return trace.source_file() != "" and trace.source_line() != 0;
    };

    return this->M_trace
    | std::views::filter(traceCallFilter)
    | std::views::transform(traceCallToString)
    | std::views::join_with("\n"s)
    | std::ranges::to<String>();
    
  }

}