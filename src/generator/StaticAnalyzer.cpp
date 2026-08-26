#include <fridayc.hpp>



namespace friday::inline api {

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
    this->setup();
    for(auto unit: this->M_context->get_units()) {
      this->set_current_unit(unit);
      this->on_unit_begin(*unit);
      this->visit(unit->get_parse_tree());
      this->on_unit_end(*unit);
      this->set_current_unit(nullptr);
    }

    return *this;
  }

  auto StaticAnalyzer::setup() -> void {}

  auto StaticAnalyzer::error_at(ant::ParserRuleContext* ctx, ant::Token* token, string message) -> void {
    if(not this->M_currentUnit) {
      throw NullPointerError{};
    }

    auto code = token
    ->getInputStream()
    ->getText(
      ant::misc::Interval{
        ctx->getStart()->getStartIndex(), 
        ctx->getStop()->getStopIndex()
      }
    );

    auto highlight = [i = ctx->getStart()->getLine()](string line) mutable {
      return format(
        " {:>4} | {}\n {:>4} | {}", 
        i++, 
        line, 
        "",
        views::repeat('~', line.length())
        | ranges::to<string>()
      );
    };

    auto highlighted = code 
    | views::split("\n"s)
    | views::transform(ranges::to<string>())
    | views::transform(highlight)
    | views::join_with("\n"s)
    | ranges::to<string>();


    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_currentUnit->get_path(),
          token->getLine(),
          token->getCharPositionInLine()+1
        },


        format(
          "{}\n {:>4} |\n{}Note{}: {}{}{}",
          highlighted,
          "",
          Console::Color::BLUE,
          Console::Color::RESET,
          Console::Color::rgb(171, 171, 171),
          message,
          Console::Color::RESET
        )
      }
    );
  }

  auto StaticAnalyzer::set_current_unit(TranslationUnit* unit) -> void {
    this->M_currentUnit = unit;
  }

  auto StaticAnalyzer::get_current_unit() -> TranslationUnit* {
    return this->M_currentUnit;
  }

}