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

  auto TranslationUnit::lookUp(string const& name, ISymbol* defaultValue) -> ISymbol* {
    auto global = this->globalContext->global.get();
    auto owned = this->ownedNamespace;


    if(auto candidate = global->lookUp(name, defaultValue); candidate != defaultValue) {
      return candidate;
    } else if(auto candidate = owned->lookUp(name, defaultValue); candidate != defaultValue) {
      return candidate;
    } else for(auto nsp : this->usedNamespaces | views::values) {
      if(auto candidate = nsp->lookUp(name, defaultValue); candidate != defaultValue) {
        return candidate;
      }
    }

    return defaultValue;
  }

  auto TranslationUnit::lookUpIf(string const& name, Predicate<ISymbol*> predicate, ISymbol* defaultValue) -> ISymbol* {
    auto global = this->globalContext->global.get();
    auto owned = this->ownedNamespace;


    if(auto candidate = global->lookUpIf(name, predicate, defaultValue); candidate != defaultValue) {
      return candidate;
    } else if(auto candidate = owned->lookUpIf(name, predicate, defaultValue); candidate != defaultValue) {
      return candidate;
    } else for(auto nsp : this->usedNamespaces | views::values) {
      if(auto candidate = nsp->lookUpIf(name, predicate, defaultValue); candidate != defaultValue) {
        return candidate;
      }
    }

    return defaultValue;
  }

}