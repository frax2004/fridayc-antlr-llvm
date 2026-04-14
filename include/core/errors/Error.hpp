#pragma once

#include "core/Common.hpp"


namespace friday::inline core {

  /// @brief Primary error struct
  /// @tparam MessageType the value type of the message
  template<class MessageType = String>
  struct Error {
    protected:
    /// @brief Constructs an error
    constexpr inline Error() noexcept;

    public:
    /// @brief Get the stack trace
    /// @return the call stack back trace
    virtual constexpr inline auto trace() const noexcept -> String final;

    /// @brief Default empty destructor
    constexpr inline virtual ~Error() noexcept = default;

    /// @brief Get the error description message
    /// @return the error message
    constexpr inline virtual auto what() const noexcept -> MessageType = 0;

    private:
    /// @brief Current stack trace
    std::stacktrace M_trace;
  }; // struct Error
} // namespace friday::core


#include "Error.inl"