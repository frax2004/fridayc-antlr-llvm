#include <fridayc.hpp>


namespace friday::inline api {

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
    this->ownedNamespace = Namespace::get_global_namespace();
  }

  auto TranslationUnit::parse(CompilationContext& ctx, string path) -> unique_ptr<TranslationUnit> {
    return unique_ptr<TranslationUnit>(new TranslationUnit(ctx, path));
  }

  auto TranslationUnit::look_up(string_view name, ISymbolTable* current, ISymbol* defaultValue) -> ISymbol* {
    if(current == nullptr) return defaultValue;

    // If current is the global namespace
    if(current == dynamic_cast<ISymbolTable*>(Namespace::get_global_namespace())) {
      // Search the symbol as a used namespace
      if(auto it = this->usedNamespaces.find(name); it != this->usedNamespaces.end()) {
        return it->second;
      }

      // If not, search the symbol inside the global scope
      if(auto candidate = current->retrieve(name); candidate != nullptr)
        return candidate;

      // The symbol is not defined
      return defaultValue;
    }


    // If not, do standard recursive search
    ISymbol* candidate = current->retrieve(name);
    return candidate != nullptr ? candidate : this->look_up(
      name, 
      current->get_parent(), 
      defaultValue
    );
  }

  auto TranslationUnit::look_up_if(string_view name, ISymbolTable* current, function<bool (ISymbol*)> predicate, ISymbol* defaultValue) -> ISymbol* {
    if(current == nullptr) return defaultValue;

    // If current is the global namespace
    if(current == dynamic_cast<ISymbolTable*>(Namespace::get_global_namespace())) {
      // Search the symbol as a used namespace
      if(
        auto it = this->usedNamespaces.find(name); 
        it != this->usedNamespaces.end() 
        and predicate(it->second)
      ) return it->second;

      // If not, search the symbol inside the global scope
      if(auto candidate = current->retrieve(name); candidate != nullptr and predicate(candidate)) 
        return candidate;

      // The symbol is not defined
      return defaultValue;
    }


    // If not, do standard recursive search
    ISymbol* candidate = current->retrieve(name);
    return candidate != nullptr and predicate(candidate) ? candidate : this->look_up_if(
      name, 
      current->get_parent(), 
      predicate,
      defaultValue
    );
  }

  auto TranslationUnit::get_path() const -> string {
    return this->path;
  }

  auto TranslationUnit::get_parse_tree() const -> ant::tree::ParseTree* {
    return this->ast;
  }

  auto TranslationUnit::use(Namespace* nsp) -> void {
    this->usedNamespaces.try_emplace(nsp->get_qualified_id(), nsp);
  }

  auto TranslationUnit::get_owned_namespace() const -> Namespace* {
    return this->ownedNamespace;
  }

  auto TranslationUnit::set_owned_namespace(Namespace* nsp) -> void {
    this->ownedNamespace = nsp;
  }

  auto TranslationUnit::comp_context() -> CompilationContext& {
    return *this->globalContext;
  }

  auto TranslationUnit::owns_namespace() -> bool {
    return this->ownedNamespace != nullptr and this->ownedNamespace != Namespace::get_global_namespace();
  }

}
