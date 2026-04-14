#pragma once

#include "core/Common.hpp"

#define FRIDAYC_VERSION "0.0.1"
#define FRIDAY_BUILD_AUTHOR "Francesco Pollarà"

namespace friday {
  /// @brief Get the help page
  /// @return the help information string
  auto getHelpPage() noexcept -> String;

  /// @brief Get the version page
  /// @pre the version information string
  auto getVersionPage() noexcept -> String;
}