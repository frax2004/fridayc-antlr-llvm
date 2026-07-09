#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>

namespace friday::inline api::inline pipeline {

  TranslationUnit::TranslationUnit(CompilationContext& ctx, string path)
    : path { string(path) }
    , globalContext { &ctx }
    , inputStream { this->path }
    , input { this->inputStream }
    , lexer { &this->input }
    , tokens { &this->lexer }
    , parser { &this->tokens }
    , ast { this->parser.translationUnit() }
  {}

  auto TranslationUnit::parse(CompilationContext& ctx, string path) -> rc<TranslationUnit> {
    return make_shared<TranslationUnit>(ctx, path);
  }

  auto TranslationUnit::lookUp(string const& name, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    auto global = this->globalContext->global.get();
    auto owned = this->ownedNamespace;

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    if(auto candidate = global->lookUp(name, defaultValue); not candidate.expired()) {
      return candidate;
    } else if(not owned.expired()) {
      return owned.lock()->lookUp(name, defaultValue);
    } else for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->lookUp(name, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    return defaultValue;
  }

  auto TranslationUnit::lookUpIf(string const& name, Predicate<ISymbol*> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    auto global = this->globalContext->global.get();
    auto owned = this->ownedNamespace;

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    if(auto candidate = global->lookUpIf(name, predicate, defaultValue); not candidate.expired()) {
      return candidate;
    } else if(not owned.expired()) {
      return owned.lock()->lookUpIf(name, predicate, defaultValue);
    } else for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->lookUpIf(name, predicate, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    return defaultValue;
  }

  auto TranslationUnit::getPath() const -> string {
    return this->path;
  }

  auto TranslationUnit::getParseTree() const -> ant::tree::ParseTree* {
    return this->ast;
  }

  auto TranslationUnit::use(rc<Namespace> nsp) -> void {
    this->usedNamespaces.try_emplace(nsp->getQualifiedId(), nsp);
  }

  auto TranslationUnit::getOwnedNamespace() const -> weak<Namespace> {
    return this->ownedNamespace;
  }

  auto TranslationUnit::setOwnedNamespace(rc<Namespace> nsp) -> void {
    this->ownedNamespace = nsp;
  }
  
}
