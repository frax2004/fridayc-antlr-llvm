#pragma once
#include "Common.hpp"
#include "SemanticError.hpp"


namespace friday {

  struct CLI final {
    public:
    enum : u32 {
      EMIT    = 1 << 0,
      VERBOSE = 1 << 1,
      VERSION = 1 << 2,
      HELP    = 1 << 3,
      ODP     = 1 << 4,
    };

    enum class WarningLevel : u32 {
      NONE,
      RESTRICTED,
      ALL,
    };

    enum class Subcommand : u32 {
      NONE,
      BUILD,
      NEW,
    };

    enum class ProjectCategory : u32 {
      NONE,
      EXE,
      STATIC_LIB,
      SHARED_LIB,
    };

    public:
    const string          outputPath      = "";
    const string          libs            = "";
    const set<string>     sources         = { };
    const bitset<32>      flags           = { };
    const WarningLevel    warningLevel    = CLI::WarningLevel::RESTRICTED;
    const Subcommand      subcommand      = CLI::Subcommand::NONE;
    const ProjectCategory projectCategory = CLI::ProjectCategory::NONE;

    static auto parse(span<string> args) -> expected<CLI, vector<string>>;
  };
}