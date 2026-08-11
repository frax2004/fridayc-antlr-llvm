#pragma once
#include "Common.hpp"


namespace friday::inline api {

  enum Visibility {
    PRIVATE = 0,
    PUBLIC = 1,
  };

  enum Linkage {
    INTERNAL,
    EXTERNAL,
  };

  struct Attributes final {
    Visibility visibility { Visibility::PUBLIC };
    Linkage    linkage    { Linkage::INTERNAL };
    bool       isStatic   { false };
    bool       isConst    { false };
  };

}