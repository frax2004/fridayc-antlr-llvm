#pragma once

#include <Error.hpp>
#include <SourceLocation.hpp>

namespace friday::inline api::inline parser {

  struct FRIDAY_API SemanticError final {
    SemanticError(SourceLocation location, string message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> string;
    auto where() const noexcept -> SourceLocation;

    private:
    SourceLocation M_location { };
    string         M_message  { "" };
  };
}