#pragma once
#include <Symbol.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ISymbolTable : NonCopyable {
    public:
    constexpr ISymbolTable() = default;
    constexpr virtual ~ISymbolTable() override = default;

    public:
    virtual auto look_up(
      string_view id, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> = 0;

    virtual auto look_up_if(
      string_view id, 
      Predicate<Pointer<ISymbol>> predicate, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> = 0;

    virtual auto most_similar(
      string_view name, 
      Predicate<Pointer<ISymbol>> filter, 
      u64 maxEditDistance = 0
    ) noexcept -> weak<ISymbol> = 0;

    virtual auto define(rc<ISymbol> symbol) -> bool = 0;
    virtual auto is_defined(string_view id) -> bool = 0;
    virtual auto get_parent() -> Pointer<ISymbolTable> = 0;
    virtual auto get_symbols() const -> vector<weak<ISymbol>> = 0;
  };

  template<derived_from<ISymbol>... Ts>
  struct FRIDAY_API SymbolTable : ISymbolTable {
    private:
    unordered_map<string, rc<ISymbol>, transparent_string_hash, equal_to<>> M_symbols{};

    private:
    template<class... Bases>
    static auto assert_valid_type(weak<ISymbol> object) -> bool;

    public:
    constexpr SymbolTable() = default;
    virtual ~SymbolTable() override = default;

    public:
    virtual auto look_up(
      string_view id, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> override;

    virtual auto look_up_if(
      string_view id, 
      Predicate<Pointer<ISymbol>> predicate, 
      weak<ISymbol> defaultValue
    ) -> weak<ISymbol> override;

    virtual auto most_similar(
      string_view id, 
      Predicate<Pointer<ISymbol>> filter, 
      u64 maxEditDistance = 0
    ) noexcept -> weak<ISymbol> final override;

    virtual auto define(rc<ISymbol> symbol) -> bool final override;
    virtual auto is_defined(string_view id) -> bool final override;
    virtual auto get_symbols() const -> vector<weak<ISymbol>> final override;
  };
}

#include <SymbolTable.inl>
