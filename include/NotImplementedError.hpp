#pragma once

#include <Error.hpp>

namespace friday::inline core {

  struct NotImplementedError final : public Error<> {
    constexpr inline NotImplementedError(string info) noexcept;
    constexpr ~NotImplementedError() override = default;
    constexpr inline auto what() const noexcept -> string override;

    private:
    string M_info { "" };
  };
}


#include <NotImplementedError.inl>