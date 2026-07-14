#pragma once
#include <SemanticError.hpp>
#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>
#include <FridayParserBaseVisitor.h>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API StaticAnalyzer : public FridayParserBaseVisitor, NonCopyable {
    private:
    Pointer<CompilationContext> M_context     { nullptr };
    vector<SemanticError>       M_errors      { };
    Pointer<TranslationUnit>    M_currentUnit { nullptr };

    public:
    StaticAnalyzer(CompilationContext& ctx);
    virtual ~StaticAnalyzer() override = default;

    public:
    auto errors() -> vector<SemanticError>;
    auto analyze() -> StaticAnalyzer&;

    virtual auto on_unit_begin(TranslationUnit& unit) -> void = 0;
    virtual auto on_unit_end(TranslationUnit& unit) -> void = 0;
    auto comp_context() -> CompilationContext&;
    
    protected:
    auto set_current_unit(Pointer<TranslationUnit> unit) -> void;
    auto get_current_unit() -> Pointer<TranslationUnit>;
    auto error_at(Pointer<ant::ParserRuleContext> ctx, Pointer<ant::Token> end, string message) -> void;

  };
}