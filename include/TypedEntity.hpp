#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API TypedEntity : public NonCopyable {
    constexpr TypedEntity() = default;
    constexpr virtual ~TypedEntity() = default;

    virtual auto getType() const -> Pointer<Type> = 0;
  };
}