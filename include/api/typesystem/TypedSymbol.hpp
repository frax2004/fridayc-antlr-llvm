#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline typesystem {
  struct Type;

  struct TypedSymbol : public Symbol {
    virtual auto getType() -> Type* = 0;
  };
}