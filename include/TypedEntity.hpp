#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct TypedEntity : public NonCopyable {
    constexpr TypedEntity() = default;
    constexpr virtual ~TypedEntity() = default;

    virtual auto getType() const -> Type* = 0;
  };
}