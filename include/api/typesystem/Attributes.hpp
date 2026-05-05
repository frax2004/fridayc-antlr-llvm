#pragma once

#include "core/util/SourceLocation.hpp"
#include "VisibilityModifier.hpp"

namespace friday::inline api::inline typesystem {
  struct Attributes final {
    auto getVisibility() const -> VisibilityModifier;
    auto getSourceLocation() const -> SourceLocation;
    auto getModifiers() const -> u32;
  }; // struct Attributes
} // namespace friday::api::typesystem