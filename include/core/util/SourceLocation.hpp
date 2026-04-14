#pragma once

#include "core/Common.hpp"



namespace friday::inline core::inline util {
  
  /// @brief Source Location struct
  struct SourceLocation final {

    /// @brief Default empty constructor
    constexpr SourceLocation() noexcept = default;
    /// @brief Default empty copy constructor
    /// @param other 
    constexpr SourceLocation(SourceLocation const& other) noexcept = default;
    /// @brief Default empty move constructor
    /// @param other 
    constexpr SourceLocation(SourceLocation && other) noexcept = default;
    /// @brief Default empty destructor
    constexpr ~SourceLocation() noexcept = default;

    /// @brief Construct a source location instance
    /// @param filePath the file path
    /// @param line the line in the source file
    /// @param column the column in the source file
    constexpr SourceLocation(String filePath, u64 line, u64 column) noexcept;

    /// @brief Default equality operator
    /// @param other
    /// @return `true` if the source location objects are the same
    constexpr auto operator==(SourceLocation const& other) const noexcept -> bool = default;
    
    /// @brief Default inequality operator
    /// @param other
    /// @return `true` if the source location objects are not the same
    constexpr auto operator!=(SourceLocation const& other) const noexcept -> bool = default;

    /// @brief Get the default invalid source location instance
    /// @return invalid source location
    consteval static inline auto invalid() noexcept -> SourceLocation;

    /// @brief Get the line of the source file
    /// @return the line in the source file
    constexpr auto line() const noexcept -> u64;
    /// @brief Get the column of the source file
    /// @return the column in the source file
    constexpr auto column() const noexcept -> u64;
    /// @brief Get the path of the source file
    /// @return the path of the source file
    constexpr auto path() const noexcept -> StringRef;

    private:
    /// @brief line in the source file
    u64 M_line { 0 };
    /// @brief colum in the source file
    u64 M_column { 0 };
    /// @brief the path of the source file
    String M_filePath { "" };
  }; // struct SourceLocation
} // namespace friday::core::util

#include "SourceLocation.inl"