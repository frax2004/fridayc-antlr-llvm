#pragma once

#include <Error.hpp>

namespace friday::inline core {


  struct FRIDAY_API OperationNotSupportedError final : public Error<> {

    constexpr inline OperationNotSupportedError(string info) noexcept;
    constexpr ~OperationNotSupportedError() override = default;
    constexpr inline auto what() const noexcept -> string override;

    private:
    string M_info { "" };
  };
}


#include <OperationNotSupportedError.inl>