#pragma once
#include <Symbol.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ISymbolTable : NonCopyable {
    public:
    constexpr ISymbolTable() = default;
    virtual ~ISymbolTable() override = default;

    public:
    virtual auto lookUp(string const& id, weak<ISymbol> defaultValue) -> weak<ISymbol> = 0;
    virtual auto lookUpIf(string const& id, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> = 0;
    virtual auto define(rc<ISymbol> symbol) -> bool = 0;
    virtual auto isDefined(string const& id) -> bool = 0;
    virtual auto getParent() -> Pointer<ISymbolTable> = 0;
    virtual auto mostSimilar(string const& name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance = 0) noexcept -> weak<ISymbol> = 0;
    virtual auto getSymbols() const -> vector<weak<ISymbol>> = 0;
  };

  template<derived_from<ISymbol>... Ts>
  struct FRIDAY_API SymbolTable : ISymbolTable {
    private:
    map<string, rc<ISymbol>> M_symbols{};

    private:
    template<class... Bases>
    static auto assertInstanceOf(weak<ISymbol> object) -> bool;

    public:
    constexpr SymbolTable() = default;
    virtual ~SymbolTable() override = default;

    public:
    virtual auto lookUp(string const& id, weak<ISymbol> defaultValue) -> weak<ISymbol> override;
    virtual auto lookUpIf(string const& id, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> override;
    virtual auto define(rc<ISymbol> symbol) -> bool final override;
    virtual auto isDefined(string const& id) -> bool final override;
    virtual auto mostSimilar(string const& name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance = 0) noexcept -> weak<ISymbol> final override;
    virtual auto getSymbols() const -> vector<weak<ISymbol>> final override;
  };
}

#include <SymbolTable.inl>
