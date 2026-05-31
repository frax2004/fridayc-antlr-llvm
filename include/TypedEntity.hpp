#pragma once

namespace friday::inline api::inline typesystem {
  struct Type;

  struct TypedEntity {
    virtual auto getType() -> Type* = 0;
  };
}