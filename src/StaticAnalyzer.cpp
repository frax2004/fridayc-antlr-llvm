#include <StaticAnalyzer.hpp>
#include <NullPointerError.hpp>



namespace friday::inline api::inline pipeline {
  StaticAnalyzer::StaticAnalyzer(CompilationContext& ctx)
    : M_context { &ctx }
  {}

  auto StaticAnalyzer::errors() -> vector<SemanticError> {
    return this->M_errors;
  }

  auto StaticAnalyzer::comp_context() -> CompilationContext& {
    return *this->M_context;
  }

  auto StaticAnalyzer::analyze() -> StaticAnalyzer& {
    for(auto unit: this->M_context->get_units()) {
      this->set_current_unit(unit.get());
      this->on_unit_begin(*unit);
      this->visit(unit->get_parse_tree());
      this->on_unit_end(*unit);
      this->set_current_unit(nullptr);
    }

    return *this;
  }

  auto StaticAnalyzer::error_at(Pointer<ant::Token> token, string message) -> void {
    if(not this->M_currentUnit) {
      throw NullPointerError{};
    }

    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_currentUnit->get_path(),
          token->getLine(),
          token->getCharPositionInLine()+1
        },
        message
      }
    );
  }

  auto StaticAnalyzer::set_current_unit(Pointer<TranslationUnit> unit) -> void {
    this->M_currentUnit = unit;
  }

  auto StaticAnalyzer::get_current_unit() -> Pointer<TranslationUnit> {
    return this->M_currentUnit;
  }

}