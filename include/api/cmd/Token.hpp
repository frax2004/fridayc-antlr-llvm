#pragma once

#include "core/Common.hpp"


namespace friday::inline api::inline cmd {
  
  /// @brief Token struct for command line arguments parsing
  struct Token {

    // Unknown argument
    static const Token UNKNOWN_ARG;

    // Subcommmands
    static const Token SUB_RUN;
    static const Token SUB_BUILD;
    static const Token SUB_UNKNOWN;

    // Options
    static const Token OPT_HELP;
    static const Token OPT_VERSION;
    static const Token OPT_OUTPUT;
    static const Token OPT_WALL;
    static const Token OPT_WRESTRICTED;
    static const Token OPT_WNONE;
    static const Token OPT_UNKNOWN;

    // Path
    static const Token PATH;

    private:
    /// @brief Default constructor for default tokens
    Token() noexcept;

    public:
    /// @brief Default copy constructor
    /// @param other the other instance
    Token(Token const& other) noexcept;

    /// @brief Default move constructor
    /// @param other the other instance
    Token(Token && other) noexcept;

    /// @brief Construct a token from an identifier
    /// @param identifier the identifier
    Token(String identifier) noexcept;

    /// @brief Copy assignment operrator
    /// @param other the other instance
    /// @return `*this`
    auto operator=(Token const& other) noexcept -> Token&;

    /// @brief Move assignment operrator
    /// @param other the other instance
    /// @return `*this`
    auto operator=(Token && other) noexcept -> Token&;

    /// @brief Equality operator for the token struct
    /// @param other the other instance to compare
    /// @return `true` if the tokens have the same kind and the same lexeme
    constexpr auto operator==(Token const& other) const noexcept -> bool = default;

    /// @brief Inequality operator for the token struct
    /// @param other the other instance to compare
    /// @return `true` if the tokens have not the same kind and not the same lexeme
    constexpr auto operator!=(Token const& other) const noexcept -> bool = default;

    /// @brief Get the token's kind
    /// @return the token's kind
    auto kind() const noexcept -> i32;
    
    /// @brief Get the token's lexeme
    /// @return the token's lexeme
    auto lexeme() const noexcept -> String;

    private:
    /// @brief The kind
    i32 M_kind { 0 };
    /// @brief The lexeme
    String M_lexeme { };
  }; // struct Token
} // namespace friday::api::cmd

