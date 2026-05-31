#pragma once

#include <Error.hpp>

namespace friday::inline core {

  struct NullPointerError final : public Error<> {
    constexpr inline NullPointerError() noexcept = default;
    constexpr inline auto what() const noexcept -> String override;
  };
}

#include <NullPointerError.inl>