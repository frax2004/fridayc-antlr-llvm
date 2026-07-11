#include <StaticAnalyzer.hpp>
#include <NullPointerError.hpp>



namespace friday::inline api::inline pipeline {
  StaticAnalyzer::StaticAnalyzer(CompilationContext& ctx)
    : context { &ctx }
  {}

  auto StaticAnalyzer::errors() -> vector<SemanticError> {
    return this->M_errors;
  }

  auto StaticAnalyzer::getCompilationContext() -> CompilationContext& {
    return *this->context;
  }

  auto StaticAnalyzer::analyze() -> StaticAnalyzer& {
    for(auto& unit: this->context->units) {
      this->setCurrentUnit(unit.get());
      this->beginUnit(*unit);
      this->visit(unit->getParseTree());
      this->endUnit(*unit);
      this->setCurrentUnit(nullptr);
    }

    return *this;
  }

  auto StaticAnalyzer::errorAt(Pointer<ant::Token> token, string message) -> void {
    if(not this->M_currentUnit) {
      throw NullPointerError{};
    }

    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_currentUnit->getPath(),
          token->getLine(),
          token->getCharPositionInLine()+1
        },
        message
      }
    );
  }

  auto StaticAnalyzer::setCurrentUnit(Pointer<TranslationUnit> unit) -> void {
    this->M_currentUnit = unit;
  }

  auto StaticAnalyzer::getCurrentUnit() -> Pointer<TranslationUnit> {
    return this->M_currentUnit;
  }

}