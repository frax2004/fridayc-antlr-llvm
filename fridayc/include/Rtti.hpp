#pragma once

#include <Core.hpp>
#include <Pointer.hpp>

namespace friday::inline core::inline rtti {
  auto demangle(const char* name) noexcept -> string;
  auto name_of(type_info const& info) noexcept -> string;

  template<class To, class From>
  auto cast(From* from) -> To*;

  template<class Other, class This>
  auto instance_of(This* object) -> bool;
}

#include <Rtti.inl>