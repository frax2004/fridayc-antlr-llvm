#pragma once
#include <Symbol.hpp>

namespace friday::inline api::inline typesystem {

  struct ISymbolTable {
    public:
    virtual auto lookUp(string const& id, ISymbol* defaultValue = nullptr) -> ISymbol* = 0;
    virtual auto lookUpIf(string const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue = nullptr) -> ISymbol* = 0;
    virtual auto define(ISymbol* symbol) -> bool = 0;
    virtual auto isDefined(string const& id) -> bool = 0;
    virtual auto getParent() -> ISymbolTable* = 0;
    virtual auto mostSimilar(string const& name, Predicate<ISymbol*> filter, u64 maxEditDistance = 0) noexcept -> optional<ISymbol*> = 0;
    virtual auto getSymbols() const -> vector<ISymbol*> = 0;
  };

  template<derived_from<ISymbol>... Ts>
  struct SymbolTable : ISymbolTable {
    private:
    map<string, box<ISymbol>> M_symbols{};

    private:
    template<class... Bases>
    static auto assertInstanceOf(ISymbol* object) -> bool;

    public:
    virtual auto lookUp(string const& id, ISymbol* defaultValue = nullptr) -> ISymbol* final override;
    virtual auto lookUpIf(string const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue = nullptr) -> ISymbol* final override;
    virtual auto define(ISymbol* symbol) -> bool final override;
    virtual auto isDefined(string const& id) -> bool final override;
    virtual auto mostSimilar(string const& name, Predicate<ISymbol*> filter, u64 maxEditDistance = 0) noexcept -> optional<ISymbol*> final override;
    virtual auto getSymbols() const -> vector<ISymbol*> final override;
  };
}

#include <SymbolTable.inl>
