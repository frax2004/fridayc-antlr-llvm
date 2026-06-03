#pragma once
#include <SemanticError.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  struct StaticAnalyzer {
    private:
    vector<SemanticError> M_errors { };
    TranslationUnit* M_currentUnit { nullptr };

    public:
    auto errors() -> vector<SemanticError>;

    protected:
    auto setCurrentUnit(TranslationUnit* unit) -> void;
    auto getCurrentUnit() -> TranslationUnit*;
    auto errorAt(ant::Token* token, string message) -> void;

  };
}