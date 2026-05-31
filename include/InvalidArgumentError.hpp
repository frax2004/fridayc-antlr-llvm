#pragma once

#include <Error.hpp>

namespace friday::inline core {


  struct InvalidArgumentError final : public Error<> {

    constexpr inline InvalidArgumentError(String info) noexcept;
    constexpr inline auto what() const noexcept -> String override;

    private:
    String M_info { "" };
  };
}


#include <InvalidArgumentError.inl>