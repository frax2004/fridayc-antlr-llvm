#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>

namespace friday::inline api::inline pipeline {
  TranslationUnit::TranslationUnit(string_ref path)
    : path { string(path) }
    , inputStream { this->path }
    , input { this->inputStream }
    , lexer { &this->input }
    , tokens { &this->lexer }
    , parser { &this->tokens }
    , ast { this->parser.program() }
  {}

  
  auto TranslationUnit::parse(string_ref path) -> box<TranslationUnit> {
    return make_unique<TranslationUnit>(path);
  }
}