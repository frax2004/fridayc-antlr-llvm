#include "api/cmd/Token.hpp"

namespace friday::inline api::inline cmd {

  const Token Token::UNKNOWN_ARG {}; // 0
  const Token Token::SUB_RUN {}; // 1
  const Token Token::SUB_BUILD {}; // 2
  const Token Token::SUB_UNKNOWN {}; // 3
  const Token Token::OPT_HELP {}; // 4
  const Token Token::OPT_VERSION {}; // 5
  const Token Token::OPT_OUTPUT {}; // 6
  const Token Token::OPT_WALL {}; // 7
  const Token Token::OPT_WRESTRICTED {}; // 8
  const Token Token::OPT_WNONE {}; // 9
  const Token Token::OPT_UNKNOWN {}; // 10
  const Token Token::PATH {}; // 11
  
  static i32 ID = 0;

  Token::Token() noexcept
    : M_kind { ID++ }
    , M_lexeme { }
  {}

  Token::Token(Token const& other) noexcept 
    : M_kind { other.M_kind }
    , M_lexeme { other.M_lexeme }
  {}

  Token::Token(Token && other) noexcept 
    : M_kind { other.M_kind }
    , M_lexeme { std::move(other.M_lexeme) }
  {}
  
  Token::Token(String identifier) noexcept
    : M_kind { Token::PATH.kind() }
    , M_lexeme { std::move(identifier) }
  {}

  auto Token::operator=(Token const& other) noexcept -> Token& {
    this->M_kind = other.M_kind;
    this->M_lexeme = other.M_lexeme;
    return *this;
  }

  auto Token::operator=(Token && other) noexcept -> Token& {
    this->M_kind = other.M_kind;
    this->M_lexeme = std::move(other.M_lexeme);
    return *this;
  }

  auto Token::kind() const noexcept -> i32 {
    return this->M_kind;
  }

  auto Token::lexeme() const noexcept -> String {
    return this->M_lexeme;
  }

}