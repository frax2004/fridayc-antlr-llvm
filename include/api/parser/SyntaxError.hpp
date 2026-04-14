#pragma once

#include "core/errors/Error.hpp"
#include "core/util/SourceLocation.hpp"

#include <bits/stdc++.h>
namespace friday::inline api::inline parser {

  struct SyntaxError : public Error<> {
    SyntaxError(SourceLocation location, String message);

    auto report() const noexcept -> void;
    auto what() const noexcept -> String override;
    auto where() const noexcept -> SourceLocation;

    private:
    SourceLocation M_location;
    String M_message;
  }; // struct SyntaxError
} // namespace friday::api::parser