#include <fridayc.hpp>


namespace friday::inline core {
  SourceLocation::SourceLocation(string filePath, u64 line, u64 column) noexcept
    : M_line { line }
    , M_column { column }
    , M_filePath { filePath }
  {}

  auto SourceLocation::invalid() noexcept -> SourceLocation {
    return SourceLocation{
      "<invalid>", 0, 0
    };
  }

  auto SourceLocation::line() const noexcept -> u64 {
    return this->M_line;
  }

  auto SourceLocation::column() const noexcept -> u64 {
    return this->M_column;
  }

  auto SourceLocation::path() const noexcept -> string_view {
    return this->M_filePath;
  }

}