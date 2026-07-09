#pragma once

#include <Error.hpp>

namespace friday::inline core {

  struct NullPointerError final : public Error<> {
    constexpr inline NullPointerError() noexcept = default;
    constexpr ~NullPointerError() override = default;
    constexpr inline auto what() const noexcept -> string override;
  };
}

#include <NullPointerError.inl>