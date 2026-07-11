#pragma once

#include <SourceLocation.hpp>
#include <VisibilityModifier.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Attributes final {
    VisibilityModifier visibility { VisibilityModifier::PUBLIC };
    bool               isStatic   { false };
    bool               isConst    { false };
    bool               isUnused   { false };
  };

}
