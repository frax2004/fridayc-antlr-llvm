#pragma once
#include "Common.hpp"
#include <FridayScanner.h>
#include <FridayParser.h>


namespace friday::inline api {

  struct CompilationContext;
  struct ISymbolTable;
  struct Namespace;
  struct ISymbol;

  struct TranslationUnit final  {
  private:
    Namespace*                      ownedNamespace { };
    map<string, Namespace*, less<>> usedNamespaces { };
    CompilationContext*             globalContext  { nullptr };
    string                          path           { "" };
    ifstream                        inputStream;
    ant::ANTLRInputStream           input;
    FridayScanner                   lexer;
    ant::CommonTokenStream          tokens;
    FridayParser                    parser;
    ant::tree::ParseTree*           ast            { nullptr };

  private:
    TranslationUnit(CompilationContext& ctx, string path);

  public:
    ~TranslationUnit() = default;

  public:
    auto owns_namespace() -> bool;
    auto get_path() const -> string;
    auto get_parse_tree() const -> ant::tree::ParseTree*;
    auto use(Namespace* nsp) -> void;
    auto get_owned_namespace() const -> Namespace*;
    auto set_owned_namespace(Namespace* nsp) -> void;
    auto comp_context() -> CompilationContext&;

    auto look_up(
      string_view name, 
      ISymbolTable* deepest,
      ISymbol* defaultValue
    ) -> ISymbol*;

    auto look_up_if(
      string_view name, 
      ISymbolTable* deepest,
      function<bool(ISymbol*)> predicate, 
      ISymbol* defaultValue
    ) -> ISymbol*;

    static auto parse(CompilationContext& ctx, string path) -> unique_ptr<TranslationUnit>;
  };

}