#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct FRIDAY_API TranslationUnit final : NonCopyable {
    private:
    Namespace*                      ownedNamespace { };
    map<string, Namespace*, less<>> usedNamespaces { };
    CompilationContext*          globalContext { nullptr };
    string                               path = "";
    ifstream                             inputStream;
    ant::ANTLRInputStream                input;
    FridayScanner                        lexer;
    ant::CommonTokenStream               tokens;
    FridayParser                         parser;
    Pointer<ant::tree::ParseTree>        ast { nullptr };
    Pointer<llvm::Module>                     module { };

    public:
    TranslationUnit(CompilationContext& ctx, string path);
    ~TranslationUnit() override = default;

    public:
    auto owns_namespace() -> bool;
    auto get_path() const -> string;
    auto get_parse_tree() const -> Pointer<ant::tree::ParseTree>;
    auto use(Namespace* nsp) -> void;
    auto get_owned_namespace() const -> Namespace*;
    auto set_owned_namespace(Namespace* nsp) -> void;
    auto comp_context() -> CompilationContext&;
    auto get_llvm_module() const -> Pointer<llvm::Module>;

    auto look_up(
      string_view name, 
      ISymbolTable* deepest,
      ISymbol* defaultValue
    ) -> ISymbol*;

    auto look_up_if(
      string_view name, 
      ISymbolTable* deepest,
      Predicate<ISymbol*> predicate, 
      ISymbol* defaultValue
    ) -> ISymbol*;

    static auto parse(CompilationContext& ctx, string path) -> TranslationUnit*;
  };

}