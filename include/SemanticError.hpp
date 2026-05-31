#pragma once

#include <Error.hpp>
#include <SourceLocation.hpp>

namespace friday::inline api::inline parser {

  struct SemanticError : public Error<> {
    SemanticError(SourceLocation location, String message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> String override;
    auto where() const noexcept -> SourceLocation;

    private:
    SourceLocation M_location;
    String M_message;
  };
}