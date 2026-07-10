#pragma once

#include <Error.hpp>

namespace friday::inline core {

  struct NullPointerError final : public Error<> {
    constexpr inline NullPointerError() noexcept = default;
    constexpr inline NullPointerError(void* ptr) noexcept;
    constexpr ~NullPointerError() override = default;
    constexpr inline auto what() const noexcept -> string override;

    private:
    string M_message = "Illegal Memory Access.\n";
  };
}

#include <NullPointerError.inl>