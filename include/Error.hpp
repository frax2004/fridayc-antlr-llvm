#pragma once

#include <Core.hpp>

namespace friday::inline core {

  template<class MessageType = string>
  struct FRIDAY_API Error {
    protected:
    constexpr inline Error() noexcept;

    public:
    constexpr Error(Error &&) = default;
    constexpr Error(Error const&) = default;
    constexpr auto operator=(Error &&) -> Error& = default;
    constexpr auto operator=(Error const&) -> Error& = default;
    constexpr virtual ~Error() noexcept = default;
    
    constexpr inline virtual auto what() const noexcept -> MessageType = 0;
    virtual constexpr inline auto trace() const noexcept -> string final;

    private:
    stacktrace M_trace;
  };
}


#include <Error.inl>