#pragma once

#include "Config.hpp"
#include "Parser.hpp"
#include "Token.hpp"
#include "UnknownArgumentError.hpp"


namespace friday::inline api::inline cmd {

  /// @brief Parse command line arguments
  /// @param args the command line arguments
  /// @return the configuration or `std::nullopt` if any error was encountered
  auto parse(Vector<StringRef> args) noexcept -> Opt<Config>;

}