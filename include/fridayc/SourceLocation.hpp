#pragma once
#include "Common.hpp"


namespace friday::inline core {
  struct SourceLocation final {
  public:
    SourceLocation() noexcept = default;
    SourceLocation(SourceLocation const& other) noexcept = default;
    SourceLocation(SourceLocation && other) noexcept = default;
    SourceLocation(string filePath, u64 line, u64 column) noexcept;
    ~SourceLocation() noexcept = default;

    constexpr auto operator==(SourceLocation const& other) const noexcept -> bool = default;
    constexpr auto operator!=(SourceLocation const& other) const noexcept -> bool = default;

    static auto invalid() noexcept -> SourceLocation;

    auto line() const noexcept -> u64;
    auto column() const noexcept -> u64;
    auto path() const noexcept -> string_view;

  private:
    u64    M_line     { 0 };
    u64    M_column   { 0 };
    string M_filePath { "" };
  };
}