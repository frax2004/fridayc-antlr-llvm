#pragma once

#include <SourceLocation.hpp>
#include <VisibilityModifier.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Attributes final {
    VisibilityModifier visibility;
    bool isStatic;
    bool isConst;
    bool isUnused;
  };

}
