#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct TypedEntity {
    virtual auto getType() const -> Type* = 0;
  };
}