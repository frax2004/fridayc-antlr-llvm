#pragma once
#include <Symbol.hpp>

namespace friday::inline api::inline typesystem {

  struct ISymbolTable {
    public:
    virtual auto lookUp(String const& id, ISymbol* defaultValue = nullptr) -> ISymbol* = 0;
    virtual auto lookUpIf(String const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue = nullptr) -> ISymbol* = 0;
    virtual auto define(ISymbol* symbol) -> bool = 0;
    virtual auto isDefined(String const& id) -> bool = 0;
    virtual auto getParent() -> ISymbolTable* = 0;
    virtual auto mostSimilar(String const& name, Predicate<ISymbol*> filter, u64 maxEditDistance = 0) noexcept -> Opt<ISymbol*> = 0;
    virtual auto getSymbols() const -> Vector<ISymbol*> = 0;
  };

  template<std::derived_from<ISymbol>... Ts>
  struct SymbolTable : ISymbolTable {
    private:
    Map<String, Box<ISymbol>> M_symbols{};

    private:
    template<class... Bases>
    static auto assertInstanceOf(ISymbol* object) -> bool;

    public:
    virtual auto lookUp(String const& id, ISymbol* defaultValue = nullptr) -> ISymbol* final override;
    virtual auto lookUpIf(String const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue = nullptr) -> ISymbol* final override;
    virtual auto define(ISymbol* symbol) -> bool final override;
    virtual auto isDefined(String const& id) -> bool final override;
    virtual auto mostSimilar(String const& name, Predicate<ISymbol*> filter, u64 maxEditDistance = 0) noexcept -> Opt<ISymbol*> final override;
    virtual auto getSymbols() const -> Vector<ISymbol*> final override;
  };
}

#include <SymbolTable.inl>
