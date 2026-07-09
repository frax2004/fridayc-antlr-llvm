#pragma once
#include <Common.hpp>
#include <Namespace.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct TranslationUnit {
    private:
    weak<Namespace> ownedNamespace { };
    map<string, weak<Namespace>> usedNamespaces { };

    private:
    CompilationContext* globalContext { nullptr };
    string path = "";
    ifstream inputStream;
    ant::ANTLRInputStream input;
    FridayScanner lexer;
    ant::CommonTokenStream tokens;
    FridayParser parser;
    ant::tree::ParseTree* ast { nullptr };

    public:
    TranslationUnit(CompilationContext& ctx, string path);
    TranslationUnit(TranslationUnit const&) = delete;

    public:
    auto getPath() const -> string;
    auto getParseTree() const -> ant::tree::ParseTree*;
    auto use(rc<Namespace> nsp) -> void;
    auto getOwnedNamespace() const -> weak<Namespace>;
    auto setOwnedNamespace(rc<Namespace> nsp) -> void;

    auto lookUp(string const& name, weak<ISymbol> defaultValue) -> weak<ISymbol>;
    auto lookUpIf(string const& name, Predicate<ISymbol*> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol>;

    static auto parse(CompilationContext& ctx, string path) -> rc<TranslationUnit>;
  };

}