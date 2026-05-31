#pragma once

#include <Error.hpp>
#include <SourceLocation.hpp>

namespace friday::inline api::inline parser {

  struct SemanticError : public Error<> {
    SemanticError(SourceLocation location, string message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> string override;
    auto where() const noexcept -> SourceLocation;

    private:
    SourceLocation M_location;
    string M_message;
  };
}