#ifdef __INTELLISENSE__
#include "SourceLocation.hpp"
#endif

namespace friday::inline core::inline util {

  constexpr SourceLocation::SourceLocation(String filePath, u64 line, u64 column) noexcept
    : M_filePath { std::move(filePath) }
    , M_line { line }
    , M_column { column }
  {}

  consteval inline auto SourceLocation::invalid() noexcept -> SourceLocation {
    return SourceLocation{
      "<invalid>", 0, 0
    };
  }

  constexpr auto SourceLocation::line() const noexcept -> u64 {
    return this->M_line;
  }

  constexpr auto SourceLocation::column() const noexcept -> u64 {
    return this->M_column;
  }

  constexpr auto SourceLocation::path() const noexcept -> StringRef {
    return this->M_filePath;
  }

}