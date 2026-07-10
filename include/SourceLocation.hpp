#pragma once

#include <Common.hpp>



namespace friday::inline core::inline util {
  

  struct FRIDAY_API SourceLocation final {
    constexpr SourceLocation() noexcept = default;
    constexpr SourceLocation(SourceLocation const& other) noexcept = default;
    constexpr SourceLocation(SourceLocation && other) noexcept = default;
    constexpr ~SourceLocation() noexcept = default;
    constexpr SourceLocation(string filePath, u64 line, u64 column) noexcept;

    constexpr auto operator==(SourceLocation const& other) const noexcept -> bool = default;
    constexpr auto operator!=(SourceLocation const& other) const noexcept -> bool = default;
    
    consteval static inline auto invalid() noexcept -> SourceLocation;
    
    constexpr auto line() const noexcept -> u64;
    constexpr auto column() const noexcept -> u64;
    constexpr auto path() const noexcept -> string_ref;

    private:
    u64 M_line { 0 };
    u64 M_column { 0 };
    string M_filePath { "" };
  };
}

#include <SourceLocation.inl>