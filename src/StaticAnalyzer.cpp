#include <StaticAnalyzer.hpp>
#include <NullPointerError.hpp>

namespace friday::inline api::inline pipeline {
  auto StaticAnalyzer::errors() -> vector<SemanticError> {
    return this->M_errors;
  }

  auto StaticAnalyzer::errorAt(ant::Token* token, string message) -> void {
    println("heree");
    if(not this->M_currentUnit) {
    println("here324536");
      throw NullPointerError{};
    }

    println("here");
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
    println("here2");
  }

  auto StaticAnalyzer::setCurrentUnit(TranslationUnit* unit) -> void {
    this->M_currentUnit = unit;
  }

  auto StaticAnalyzer::getCurrentUnit() -> TranslationUnit* {
    return this->M_currentUnit;
  }

}