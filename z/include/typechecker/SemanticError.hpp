#pragma once

#include "core/errors/Error.hpp"
#include "core/util/SourceLocation.hpp"

namespace friday::inline api::inline parser {

  struct SemanticError : public Error<> {
    SemanticError(SourceLocation location, String message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> String override;
    auto where() const noexcept -> SourceLocation;

    private:
    SourceLocation M_location;
    String M_message;
  }; // struct SyntaxError
} // namespace friday::api::parser