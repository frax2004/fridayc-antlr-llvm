#pragma once

#include <Core.hpp>

namespace friday::inline core::inline rtti {
  auto demangle(const char* name) noexcept -> string;
  auto name_of(type_info const& info) noexcept -> string;

  template<class To, class From>
  auto cast(Pointer<From> from) -> Pointer<To>;

  template<class Other, class This>
  auto instance_of(Pointer<This> object) -> bool;
}

#include <Rtti.inl>