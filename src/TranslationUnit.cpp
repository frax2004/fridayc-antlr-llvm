#include <TranslationUnit.hpp>
#include <CompilationContext.hpp>

namespace friday::inline api::inline pipeline {

  TranslationUnit::TranslationUnit(CompilationContext& ctx, string path)
    : globalContext { &ctx }
    , path { string(path) }
    , inputStream { this->path }
    , input { this->inputStream }
    , lexer { &this->input }
    , tokens { &this->lexer }
    , parser { &this->tokens }
    , ast { this->parser.translationUnit() }
  {
    this->ownedNamespace = this->comp_context().get_global();
  }

  auto TranslationUnit::parse(CompilationContext& ctx, string path) -> rc<TranslationUnit> {
    return make_shared<TranslationUnit>(ctx, path);
  }

  auto TranslationUnit::define(rc<ISymbol> symbol) -> bool {
    return this->ownedNamespace.lock()->define(symbol);
  }

  auto TranslationUnit::is_defined(string_view id) -> bool {
    return this->ownedNamespace.lock()->is_defined(id);
  }

  auto TranslationUnit::most_similar(string_view name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance) noexcept -> weak<ISymbol> {
    (void)name;
    (void)filter;
    (void)maxEditDistance;
    return {};
  }

  auto TranslationUnit::get_symbols() const -> vector<weak<ISymbol>> {
    return this->ownedNamespace.lock()->get_symbols();
  }

  auto TranslationUnit::look_up(string_view name, weak<ISymbol> defaultValue) -> weak<ISymbol> {

    if(not this->ownedNamespace.expired()) {
      if(auto candidate = this->ownedNamespace.lock()->look_up(name, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->look_up(name, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    auto global = this->comp_context().get_global().get();
    if(auto candidate = global->look_up(name, defaultValue); not candidate.expired()) {
      return candidate;
    }

    return defaultValue;
  }

  auto TranslationUnit::look_up_if(string_view name, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {

    if(not this->ownedNamespace.expired()) {
      if(auto candidate = this->ownedNamespace.lock()->look_up_if(name, predicate, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    auto notExpired = [](weak<Namespace> wr) { return not wr.expired(); };
    auto toNamespaces = views::values 
    | views::filter(notExpired) 
    | views::transform(&weak<Namespace>::lock);

    for(auto nsp : this->usedNamespaces | toNamespaces) {
      if(auto candidate = nsp->look_up_if(name, predicate, defaultValue); not candidate.expired()) {
        return candidate;
      }
    }

    auto global = this->comp_context().get_global().get();
    if(auto candidate = global->look_up_if(name, predicate, defaultValue); not candidate.expired()) {
      return candidate;
    }

    return defaultValue;
  }

  auto TranslationUnit::get_path() const -> string {
    return this->path;
  }

  auto TranslationUnit::get_parent() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->ownedNamespace.lock().get());
  }

  auto TranslationUnit::get_parse_tree() const -> Pointer<ant::tree::ParseTree> {
    return this->ast;
  }

  auto TranslationUnit::use(rc<Namespace> nsp) -> void {
    this->usedNamespaces.try_emplace(nsp->get_qualified_id(), nsp);
  }

  auto TranslationUnit::get_owned_namespace() const -> weak<Namespace> {
    return this->ownedNamespace;
  }

  auto TranslationUnit::set_owned_namespace(rc<Namespace> nsp) -> void {
    this->ownedNamespace = nsp;
  }

  auto TranslationUnit::comp_context() -> CompilationContext& {
    return *this->globalContext;
  }

  auto TranslationUnit::owns_namespace() -> bool {
    return not this->ownedNamespace.expired() and this->ownedNamespace.lock() != this->comp_context().get_global();
  }

}
