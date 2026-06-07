#include <StaticAnalyzer.hpp>
#include <NullPointerError.hpp>

namespace friday::inline api::inline pipeline {
  auto StaticAnalyzer::errors() -> vector<SemanticError> {
    return this->M_errors;
  }

  auto StaticAnalyzer::errorAt(ant::Token* token, string message) -> void {
    if(not this->M_currentUnit) {
      throw NullPointerError{};
    }

    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_currentUnit->path,
          token->getLine(),
          token->getCharPositionInLine()+1
        },
        message
      }
    );
  }

  auto StaticAnalyzer::setCurrentUnit(TranslationUnit* unit) -> void {
    this->M_currentUnit = unit;
  }

  auto StaticAnalyzer::getCurrentUnit() -> TranslationUnit* {
    return this->M_currentUnit;
  }

}