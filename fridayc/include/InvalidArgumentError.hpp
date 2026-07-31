#pragma once

#include <Error.hpp>

namespace friday::inline core {
  
  struct FRIDAY_API InvalidArgumentError final : public Error<> {
    
    constexpr inline InvalidArgumentError(string info) noexcept;
    constexpr ~InvalidArgumentError() override = default;
    constexpr inline auto what() const noexcept -> string override;

    private:
    string M_info { "" };
  };
}


#include <InvalidArgumentError.inl>