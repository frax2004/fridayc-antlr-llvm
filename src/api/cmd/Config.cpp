#include "api/cmd/Config.hpp"

namespace friday::inline api::inline cmd {
  auto Config::defaults() noexcept -> Config {
    return Config {
      .input = std::nullopt,
      .output = std::nullopt,
      .warning = std::nullopt,
      .mode = std::nullopt,
      .help = false,
      .version = false
    };
  }
}