#pragma once
#include <SemanticError.hpp>
#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>
#include <FridayParserBaseVisitor.h>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API StaticAnalyzer : public FridayParserBaseVisitor, NonCopyable {
    private:
    Pointer<CompilationContext> context { nullptr };
    vector<SemanticError> M_errors { };
    Pointer<TranslationUnit> M_currentUnit { nullptr };

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
    auto setCurrentUnit(Pointer<TranslationUnit> unit) -> void;
    auto getCurrentUnit() -> Pointer<TranslationUnit>;
    auto errorAt(Pointer<ant::Token> token, string message) -> void;

  };
}