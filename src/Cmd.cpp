#include "api/cmd/Cmd.hpp"

#include "core/IO/Console.hpp"
#include "Version.hpp"




namespace friday::inline api::inline cmd {
  auto parse(Vector<StringRef> args) noexcept -> Opt<Config> {
    auto [config, errors] = cmd::Parser::parse(args);

    if(config.help) Console::log(getHelpPage());
    if(config.version) Console::log(getVersionPage());

    if(not errors.empty()) {
      std::ranges::for_each(
        errors | std::views::transform(Error<>::what),
        Console::error
      );

      return std::nullopt;
    }

    return config;
  }

}