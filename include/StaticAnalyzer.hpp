#pragma once
#include <SemanticError.hpp>
#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>
#include <FridayParserBaseVisitor.h>

namespace friday::inline api::inline pipeline {
  struct StaticAnalyzer : public FridayParserBaseVisitor, NonCopyable {
    private:
    CompilationContext* context { nullptr };
    vector<SemanticError> M_errors { };
    TranslationUnit* M_currentUnit { nullptr };

    public:
    StaticAnalyzer(CompilationContext& ctx);
    virtual ~StaticAnalyzer() override = default;

    public:
    auto errors() -> vector<SemanticError>;
    auto analyze() -> StaticAnalyzer&;
    
    virtual auto beginUnit(TranslationUnit& unit) -> void = 0;
    virtual auto endUnit(TranslationUnit& unit) -> void = 0;
    auto getCompilationContext() -> CompilationContext&;
    
    protected:
    auto setCurrentUnit(TranslationUnit* unit) -> void;
    auto getCurrentUnit() -> TranslationUnit*;
    auto errorAt(ant::Token* token, string message) -> void;

  };
}