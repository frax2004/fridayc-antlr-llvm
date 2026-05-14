#pragma once

#include "core/util/SourceLocation.hpp"
#include "VisibilityModifier.hpp"

namespace friday::inline api::inline typesystem {
  struct Attributes final {
    VisibilityModifier visibility;
    SourceLocation location;
    u32 modifiers;
  }; // struct Attributes
} // namespace friday::api::typesystem
