#pragma once
#include "Common.hpp"


namespace friday::inline api {

  struct Type  {
    constexpr Type() = default;
    constexpr virtual ~Type() = default;

    virtual auto get_name() const noexcept -> string_view = 0;
    virtual auto to_llvm_type() const noexcept -> llvm::Type* = 0;
  };
}
