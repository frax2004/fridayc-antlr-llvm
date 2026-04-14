#include "api/parser/SyntaxError.hpp"

#include "core/IO/Console.hpp"

namespace friday::inline api::inline parser {
  SyntaxError::SyntaxError(SourceLocation location, String message)
    : Error<> { }
    , M_location { std::move(location) }
    , M_message { std::move(message) }
  {}

  auto SyntaxError::what() const noexcept -> String {
    return this->M_message;
  }

  auto SyntaxError::where() const noexcept -> SourceLocation {
    return this->M_location;
  }

  auto SyntaxError::report() const noexcept -> void {
    Console::error(
      "in file {}{}{}:{}:{}{} : {}{}{}{}"_f.format(
        Console::Color::rgb(150, 150, 150),
        Console::Color::BOLD,
        this->M_location.path(), 
        this->M_location.line(), 
        this->M_location.column(), 
        Console::Color::RESET,
        Console::Color::RED,
        Console::Color::BOLD,
        this->M_message,
        Console::Color::RESET
      )
    );
  }

}