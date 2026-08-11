#pragma once

#include "Common.hpp"

namespace friday::inline core {

  struct Error {
  protected:
    Error() noexcept = default;

  public:
    Error(Error &&) = default;
    Error(Error const&) = default;
    auto operator=(Error &&) -> Error& = default;
    auto operator=(Error const&) -> Error& = default;
    virtual ~Error() noexcept = default;

    virtual auto what() const noexcept -> string = 0;
    auto trace() const noexcept -> string;

  private:
    stacktrace M_trace = stacktrace::current();
  };


  struct InvalidArgumentError final : Error {
  public:
    InvalidArgumentError() noexcept = default;
    ~InvalidArgumentError() override = default;
    auto what() const noexcept -> string override;
  };

  struct NotImplementedError : Error {
  public:
    NotImplementedError() noexcept = default;
    ~NotImplementedError() override = default;
    auto what() const noexcept -> string override;
  };

  struct NullPointerError : Error {
  public:
    NullPointerError() noexcept = default;
    ~NullPointerError() override = default;
    auto what() const noexcept -> string override;
  };

  struct OperationNotSupportedError : Error {
  public:
    OperationNotSupportedError() noexcept = default;
    ~OperationNotSupportedError() override = default;
    auto what() const noexcept -> string override;
  };

  struct RuntimeError : Error {
  public:
    RuntimeError(string message) noexcept;
    ~RuntimeError() override = default;
    auto what() const noexcept -> string override;

  private:
    string M_info;
  };

}
