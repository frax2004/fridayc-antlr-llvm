#pragma once

#if FRIDAY_API_POINTER_WRAPPER == 1

#if FRIDAY_API_POINTER_WRAPPER_RUNTIME_SUPPORT == 1
#include <csignal>
#include <NullPointerError.hpp>
#endif

template<class T>
struct FRIDAY_API Pointer final {
  using value_type = T;
  using reference_type = T&;
  using pointer_type = T*;

  constexpr Pointer() noexcept = default;
  constexpr Pointer(T* other) noexcept;
  constexpr Pointer(Pointer const&) noexcept = default;
  constexpr Pointer(Pointer &&) noexcept = default;
  constexpr ~Pointer() noexcept = default;

  constexpr operator bool() const noexcept;
  constexpr auto operator<=>(Pointer const&) const -> strong_ordering = default;
  constexpr auto operator*(this auto&& self) -> decltype(auto);
  constexpr auto operator->(this auto&& self) -> decltype(auto);

  private:
  pointer_type M_pointer { nullptr };
};

#include <Pointer.inl>

#else

template<class T>
using Pointer = T*;

#endif

