#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::retrieve(string_view id) const -> ISymbol* {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() ? ISymbol*{ it->second } : ISymbol*{};
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::retrieve_if(string_view id, symbol_filter_type predicate) const -> ISymbol* {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and predicate(it->second) ? 
      ISymbol*{ it->second } : ISymbol*{};
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::is_defined(string_view id, symbol_filter_type predicate) const -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() 
    and SymbolTable::assert_valid_type<Ts...>(it->second) 
    and predicate(it->second);
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::most_similar(string_view name, symbol_filter_type filter, u64 maxEditDistance) const noexcept -> ISymbol* {
    (void)name;
    (void)filter;
    (void)maxEditDistance;
    return {};
    // TODO: to implement
  }

  template<derived_from<ISymbol>... Ts>
  template<class... Bases>
  auto SymbolTable<Ts...>::assert_valid_type(ISymbol* object) -> bool {
    return not object.expired() and (rtti::instance_of<Bases>(object.lock()) or ...);
  }
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::define(ISymbol* symbol) -> bool {
    if(symbol == nullptr) return false;
    if(not SymbolTable::assert_valid_type<Ts...>(symbol)) {
      throw InvalidArgumentError{"Invalid symbol type"};
    }

    auto [_, ok] = this->M_symbols.try_emplace(symbol->get_qualified_id(), symbol);
    return ok;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::get_symbols() const -> vector<ISymbol*> {
    return this->M_symbols
    | views::values
    | ranges::to<vector>();
  }

}

