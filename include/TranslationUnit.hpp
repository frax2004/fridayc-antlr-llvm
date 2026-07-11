#pragma once
#include <Common.hpp>
#include <Namespace.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct FRIDAY_API TranslationUnit final : ISymbolTable {
    private:
    weak<Namespace>               ownedNamespace { };
    map<string, weak<Namespace>>  usedNamespaces { };
    Pointer<CompilationContext>   globalContext { nullptr };
    string                        path = "";
    ifstream                      inputStream;
    ant::ANTLRInputStream         input;
    FridayScanner                 lexer;
    ant::CommonTokenStream        tokens;
    FridayParser                  parser;
    Pointer<ant::tree::ParseTree> ast { nullptr };

    public:
    TranslationUnit(CompilationContext& ctx, string path);
    ~TranslationUnit() override = default;

    public:
    auto owns_namespace() -> bool;
    auto get_path() const -> string;
    auto get_parse_tree() const -> Pointer<ant::tree::ParseTree>;
    auto use(rc<Namespace> nsp) -> void;
    auto get_owned_namespace() const -> weak<Namespace>;
    auto set_owned_namespace(rc<Namespace> nsp) -> void;
    auto comp_context() -> Pointer<CompilationContext>;

    auto define(rc<ISymbol> symbol) -> bool override;
    auto is_defined(string_view id) -> bool override;
    auto get_symbols() const -> vector<weak<ISymbol>> override;
    auto get_parent() -> Pointer<ISymbolTable> override;

    auto most_similar(
      string_view name, 
      Predicate<Pointer<ISymbol>> filter, 
      u64 maxEditDistance = 0
    ) noexcept -> weak<ISymbol> override;
    
    auto look_up(
      string_view name, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> override;
    
    auto look_up_if(
      string_view name, 
      Predicate<Pointer<ISymbol>> predicate, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> override;

    static auto parse(CompilationContext& ctx, string path) -> rc<TranslationUnit>;
  };

}