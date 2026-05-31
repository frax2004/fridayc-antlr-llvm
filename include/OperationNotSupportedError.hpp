#pragma once

#include <Error.hpp>

namespace friday::inline core {


  struct OperationNotSupportedError final : public Error<> {

    constexpr inline OperationNotSupportedError(String info) noexcept;
    constexpr inline auto what() const noexcept -> String override;

    private:
    String M_info { "" };
  };
}


#include <OperationNotSupportedError.inl>