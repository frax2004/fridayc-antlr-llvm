#include "api/parser/ErrorListener.hpp"

#include "core/memory/Pointer.hpp"

namespace friday::inline api::inline parser {
  ErrorListener::ErrorListener(String filePath) noexcept
    : M_filePath { std::move(filePath) }
  {}
  
  auto ErrorListener::syntaxError(
    ant::Parser::Recognizer* recognizer, 
    ant::Token* offendingSymbol, 
    u64 line, 
    u64 charPositionInLine, 
    const String& msg, 
    std::exception_ptr e
  ) -> void {
    this->M_errors.push_back(
      SyntaxError{
        SourceLocation{this->M_filePath, line, charPositionInLine+1}, 
        msg
      }
    );
  }
  
  auto ErrorListener::errors() -> Vector<SyntaxError> const& {
    return this->M_errors;
  }
}