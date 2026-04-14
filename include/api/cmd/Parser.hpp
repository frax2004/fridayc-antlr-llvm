#pragma once

#include "Token.hpp"
#include "Config.hpp"
#include "UnknownArgumentError.hpp"




namespace friday::inline api::inline cmd {
  
  /// @brief Command line argument parser struct
  struct Parser final {

    private:
    /// @brief Default empty constructor
    constexpr Parser() noexcept = default;

    public:
    /// @brief Parse command line arguments
    /// @param args the command line arguments
    /// @return list of tokens parsed
    static auto parse(Vector<StringRef> args) noexcept -> std::tuple<Config, Vector<UnknownArgumentError>>;

    private:
    /// @brief Tokenize the input arguments
    /// @param args the args
    /// @return list of tokens
    static auto tokenize(Vector<StringRef> args) noexcept -> Vector<Token>;

  }; // struct Parser
} // namespace friday::api::cmd