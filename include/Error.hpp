#pragma once
#include <Common.hpp>

namespace friday::inline core {

  template<class MessageType = String>
  struct Error {
    protected:
    constexpr inline Error() noexcept;

    public:
    constexpr inline virtual ~Error() noexcept = default;
    
    constexpr inline virtual auto what() const noexcept -> MessageType = 0;
    virtual constexpr inline auto trace() const noexcept -> String final;

    private:
    std::stacktrace M_trace;
  };
}


#include <Error.inl>