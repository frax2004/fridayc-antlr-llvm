#pragma once
#include <Common.hpp>
#include <Namespace.hpp>
#include <FridayScanner.h>
#include <FridayParser.h>

namespace friday::inline api::inline pipeline {

  struct CompilationContext;

  struct FRIDAY_API TranslationUnit final : ISymbolTable {
    private:
    weak<Namespace>              ownedNamespace { };
    map<string, weak<Namespace>> usedNamespaces { };
    Pointer<CompilationContext>          globalContext { nullptr };
    string                       path = "";
    ifstream                     inputStream;
    ant::ANTLRInputStream        input;
    FridayScanner                lexer;
    ant::CommonTokenStream       tokens;
    FridayParser                 parser;
    Pointer<ant::tree::ParseTree>        ast { nullptr };

    public:
    TranslationUnit(CompilationContext& ctx, string path);
    ~TranslationUnit() override = default;

    public:
    auto getPath() const -> string;
    auto getParseTree() const -> Pointer<ant::tree::ParseTree>;
    auto use(rc<Namespace> nsp) -> void;
    auto getOwnedNamespace() const -> weak<Namespace>;
    auto setOwnedNamespace(rc<Namespace> nsp) -> void;
    auto getContext() -> Pointer<CompilationContext>;

    auto define(rc<ISymbol> symbol) -> bool override;
    auto isDefined(string const& id) -> bool override;
    auto mostSimilar(string const& name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance = 0) noexcept -> weak<ISymbol> override;
    auto getSymbols() const -> vector<weak<ISymbol>> override;
    auto getParent() -> Pointer<ISymbolTable> override;
    auto lookUp(string const& name, weak<ISymbol> defaultValue) -> weak<ISymbol> override;
    auto lookUpIf(string const& name, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> override;

    static auto parse(CompilationContext& ctx, string path) -> rc<TranslationUnit>;
  };

}