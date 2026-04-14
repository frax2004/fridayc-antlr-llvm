#pragma once

#include "core/Common.hpp"
#include "SyntaxError.hpp"
#include "FridayParserBaseListener.h"

namespace friday::inline api::inline parser {


  /// @brief Error listener structure used to listen for syntax errors during scanner and parser phases
  struct ErrorListener final : public ant::BaseErrorListener {

    /// @brief Construct an error listener
    /// @param filePath the source file path
    ErrorListener(String filePath) noexcept;
    
    /// @brief Report a syntax error during parsing phase
    /// @param recognizer the parser
    /// @param offendingSymbol the token mismatched
    /// @param line the line of the token
    /// @param charPositionInLine the column of the token
    /// @param msg the error message
    /// @param e the exception thrown
    auto syntaxError(
      ant::Parser::Recognizer* recognizer, 
      ant::Token* offendingSymbol, 
      u64 line, 
      u64 charPositionInLine, 
      const String& msg, 
      std::exception_ptr e
    ) -> void override;

    /// @brief Get the parse errors
    /// @return the parse errors if any error was encountered or an empty vector
    auto errors() -> Vector<SyntaxError> const&;

    private:
    /// @brief The source file path
    String M_filePath;
    /// @brief The parse errors
    Vector<SyntaxError> M_errors;
  }; // struct ErrorListener
} // namespace friday::api::parser