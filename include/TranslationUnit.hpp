#pragma once
#include <Common.hpp>
#include <Namespace.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct FRIDAY_API TranslationUnit final : NonCopyable {
    private:
    weak<Namespace>                      ownedNamespace { };
    map<string, weak<Namespace>, less<>> usedNamespaces { };
    Pointer<CompilationContext>          globalContext { nullptr };
    string                               path = "";
    ifstream                             inputStream;
    ant::ANTLRInputStream                input;
    FridayScanner                        lexer;
    ant::CommonTokenStream               tokens;
    FridayParser                         parser;
    Pointer<ant::tree::ParseTree>        ast { nullptr };
    rc<llvm::Module>                     module { };

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
    auto comp_context() -> CompilationContext&;
    auto get_llvm_module() const -> weak<llvm::Module>;

    auto look_up(
      string_view name, 
      Pointer<ISymbolTable> deepest,
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol>;

    auto look_up_if(
      string_view name, 
      Pointer<ISymbolTable> deepest,
      Predicate<Pointer<ISymbol>> predicate, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol>;

    static auto parse(CompilationContext& ctx, string path) -> rc<TranslationUnit>;
  };

}