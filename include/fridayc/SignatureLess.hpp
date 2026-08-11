#pragma once

#include "Common.hpp"

namespace friday::inline api {

  struct FunctionType;
  struct Type;

  struct less_by_signature {
    typedef __is_transparent is_transparent;

    auto operator()(FunctionType* const& self, vector<Type*> const& rhs) const -> bool;
    auto operator()(vector<Type*> const& rhs, FunctionType* const& self) const -> bool;
    auto operator()(FunctionType* const& lhs, FunctionType* const& rhs) const -> bool;
  };
}