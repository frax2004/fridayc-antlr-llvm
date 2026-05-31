#pragma once

#include <Error.hpp>

namespace friday::inline core {


  struct InvalidArgumentError final : public Error<> {

    constexpr inline InvalidArgumentError(string info) noexcept;
    constexpr inline auto what() const noexcept -> string override;

    private:
    string M_info { "" };
  };
}


#include <InvalidArgumentError.inl>