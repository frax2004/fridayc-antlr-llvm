#pragma once

#include "core/Common.hpp"


namespace friday::inline api::inline cmd {

  /// @brief Warning levels
  enum class WarningLevel {
    /// @brief All warnings
    ALL, 
    /// @brief Limited warnings
    RESTRICTED, 
    /// @brief Warnings disabled
    NONE,
  };

  /// @brief Compiler execution mode
  enum class Mode {
    /// @brief Compile and output the executable
    BUILD,
    /// @brief Interpret an input file
    RUN,
  };

  /// @brief Configuration information struct
  struct Config {
    /// @brief input files
    Opt<std::filesystem::path> input;
    /// @brief [Optional] output path
    Opt<std::filesystem::path> output;
    /// @brief Warning level
    Opt<WarningLevel> warning;
    /// @brief Execution mode
    Opt<Mode> mode;
    /// @brief Shows the help page
    bool help;
    /// @brief Shows the version page
    bool version;

    /// @brief Get the default configuration information
    /// @return The default configuration informations
    static auto defaults() noexcept -> Config;
  }; // struct Config
} // namespace friday::api::cmd
