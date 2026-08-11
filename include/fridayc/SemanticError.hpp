#pragma once
#include "SourceLocation.hpp"


namespace friday::inline api {

  struct SemanticError final {
  public:
    SemanticError(SourceLocation location, string message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> string;
    auto where() const noexcept -> SourceLocation;

  private:
    SourceLocation M_location { };
    string         M_message  { "" };
  };
}