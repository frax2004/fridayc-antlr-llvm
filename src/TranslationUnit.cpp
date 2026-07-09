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
  {
    this->ownedNamespace = this->globalContext->global;
  }

  auto TranslationUnit::parse(CompilationContext& ctx, string path) -> rc<TranslationUnit> {
    return make_shared<TranslationUnit>(ctx, path);
  }

  auto TranslationUnit::define(rc<ISymbol> symbol) -> bool {
    return this->ownedNamespace.lock()->define(symbol);
  }

  auto TranslationUnit::isDefined(string const& id) -> bool {
    return this->ownedNamespace.lock()->isDefined(id);
  }

  auto TranslationUnit::mostSimilar(string const& name, Predicate<ISymbol*> filter, u64 maxEditDistance) noexcept -> weak<ISymbol> {
    return {};
  }

  auto TranslationUnit::getSymbols() const -> vector<weak<ISymbol>> {
    return this->ownedNamespace.lock()->getSymbols();
  }

  auto TranslationUnit::lookUp(string const& name, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    Console::debug("(TranslationUnit) Searching '{}'..."_f.format(name));
    auto global = this->globalContext->global.get();

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    if(not this->ownedNamespace.expired()) {
      if(auto candidate = this->ownedNamespace.lock()->lookUp(name, defaultValue); not candidate.expired()) {
        Console::debug("(Translation Unit) Found");
        return candidate;
      }
    }
    Console::debug("(Translation Unit) Not Found. Looking in used namespaces for '{}'..."_f.format(name));
    for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->lookUp(name, defaultValue); not candidate.expired()) {
        Console::debug("(Translation Unit) Found");
        return candidate;
      }
    }

    Console::debug("(Translation Unit) Not Found. Looking Upwards for '{}'..."_f.format(name));
    if(auto candidate = global->lookUp(name, defaultValue); not candidate.expired()) {
      Console::debug("(Translation Unit) Found");
      return candidate;
    }
    Console::debug("(Translation Unit) Not Found (predicate is false)");

    return defaultValue;
  }

  auto TranslationUnit::lookUpIf(string const& name, Predicate<ISymbol*> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    Console::debug("(TranslationUnit - Predicate) Searching '{}'..."_f.format(name));

    auto global = this->globalContext->global.get();

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    if(not this->ownedNamespace.expired()) {
      if(auto candidate = this->ownedNamespace.lock()->lookUpIf(name, predicate, defaultValue); not candidate.expired()) {
        Console::debug("(Translation Unit - Predicate) Found");
        return candidate;
      }
    }
    Console::debug("(Translation Unit) Not Found. Looking in used namespaces for '{}'..."_f.format(name));
    for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->lookUpIf(name, predicate, defaultValue); not candidate.expired()) {
        Console::debug("(Translation Unit) Found (predicate is true)");
        return candidate;
      }
    }

    Console::debug("(Translation Unit) Not Found. Looking Upwards for '{}'..."_f.format(name));
    if(auto candidate = global->lookUpIf(name, predicate, defaultValue); not candidate.expired()) {
      Console::debug("(Translation Unit) Found (predicate is true)");
      return candidate;
    }
    Console::debug("(Translation Unit) Not Found (predicate is false)");

    return defaultValue;
  }

  auto TranslationUnit::getPath() const -> string {
    return this->path;
  }

  auto TranslationUnit::getParent() -> ISymbolTable* {
    return rtti::cast<ISymbolTable>(this->ownedNamespace.lock().get());
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

  auto TranslationUnit::getContext() -> CompilationContext* {
    return this->globalContext;
  }
  
}
