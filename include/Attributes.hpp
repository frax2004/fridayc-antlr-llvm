#pragma once

#include <SourceLocation.hpp>
#include <VisibilityModifier.hpp>

namespace friday::inline api::inline typesystem {

  struct Attributes final {
    VisibilityModifier visibility;
    SourceLocation definition;
    bool isStatic;
    bool isConst;
    bool isUnused;
  };

}
