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
    this->module = make_shared<llvm::Module>(path, globalContext->get_llvm_context());
  }

  auto TranslationUnit::parse(CompilationContext& ctx, string path) -> rc<TranslationUnit> {
    return make_shared<TranslationUnit>(ctx, path);
  }

  auto TranslationUnit::look_up(string_view name, Pointer<ISymbolTable> current, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    if(current == nullptr) return defaultValue;

    // If current is the global namespace
    if(current == rtti::cast<ISymbolTable>(this->comp_context().get_global().get())) {
      // Search the symbol as a used namespace
      if(auto it = this->usedNamespaces.find(name); it != this->usedNamespaces.end() and not it->second.expired()) {
        return it->second;
      }

      // If not, search the symbol inside the global scope
      if(auto candidate = current->retrieve(name); not candidate.expired()) 
        return candidate;

      // The symbol is not defined
      return defaultValue;
    }


    // If not, do standard recursive search
    weak<ISymbol> candidate = current->retrieve(name);
    return not candidate.expired() ? candidate : this->look_up(
      name, 
      current->get_parent(), 
      defaultValue
    );
  }

  auto TranslationUnit::look_up_if(string_view name, Pointer<ISymbolTable> current, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    if(current == nullptr) return defaultValue;

    // If current is the global namespace
    if(current == rtti::cast<ISymbolTable>(this->comp_context().get_global().get())) {
      // Search the symbol as a used namespace
      if(
        auto it = this->usedNamespaces.find(name); 
        it != this->usedNamespaces.end() 
        and not it->second.expired()
        and predicate(it->second.lock().get())
      ) return it->second;

      // If not, search the symbol inside the global scope
      if(auto candidate = current->retrieve(name); not candidate.expired() and predicate(candidate.lock().get())) 
        return candidate;

      // The symbol is not defined
      return defaultValue;
    }


    // If not, do standard recursive search
    weak<ISymbol> candidate = current->retrieve(name);
    return not candidate.expired() and predicate(candidate.lock().get()) ? candidate : this->look_up_if(
      name, 
      current->get_parent(), 
      predicate,
      defaultValue
    );
  }

  auto TranslationUnit::get_path() const -> string {
    return this->path;
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

  auto TranslationUnit::get_llvm_module() const -> weak<llvm::Module> {
    return this->module;
  }

}
