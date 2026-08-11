#include <fridayc.hpp>


namespace friday::inline api {
  SemanticError::SemanticError(SourceLocation location, string message)
    : M_location { move(location) }
    , M_message { move(message) }
  {}

  auto SemanticError::what() const noexcept -> string {
    return this->M_message;
  }

  auto SemanticError::where() const noexcept -> SourceLocation {
    return this->M_location;
  }

  auto SemanticError::report() const noexcept -> void {
    Console::error(
      format(
        "in file {}{}{}:{}:{}{} :\n{}{}{}{}\n",
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