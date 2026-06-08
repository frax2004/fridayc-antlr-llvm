#pragma once
#include <Common.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>
#include <Namespace.hpp>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct TranslationUnit {
    public:
    string path = "";
    ifstream inputStream;
    ant::ANTLRInputStream input;
    FridayScanner lexer;
    ant::CommonTokenStream tokens;
    FridayParser parser;
    ant::tree::ParseTree* ast { nullptr };

    
    CompilationContext* globalContext { nullptr };
    Namespace* ownedNamespace { nullptr };
    map<string, Namespace*> usedNamespaces { };
    
    public:
    TranslationUnit(string_ref path);
    TranslationUnit(TranslationUnit const&) = delete;

    public:
    static auto parse(string_ref path) -> box<TranslationUnit>;

    auto lookUp(string const& name, ISymbol* defaultValue = nullptr) -> ISymbol*;
    auto lookUpIf(string const& name, Predicate<ISymbol*> predicate, ISymbol* defaultValue = nullptr) -> ISymbol*;
  };

}