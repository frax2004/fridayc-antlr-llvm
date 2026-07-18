#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::retrieve(string_view id) const -> weak<ISymbol> {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() ? weak<ISymbol>{ it->second } : weak<ISymbol>{};
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::retrieve_if(string_view id, Predicate<Pointer<ISymbol>> predicate) const -> weak<ISymbol> {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and predicate(it->second.get()) ? 
      weak<ISymbol>{ it->second } : weak<ISymbol>{};
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::is_defined(string_view id, Predicate<Pointer<ISymbol>> predicate) const -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() 
    and SymbolTable::assert_valid_type<Ts...>(it->second) 
    and predicate(it->second.get());
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::most_similar(string_view name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance) const noexcept -> weak<ISymbol> {
    (void)name;
    (void)filter;
    (void)maxEditDistance;
    return {};
    // TODO: to implement
  }

  template<derived_from<ISymbol>... Ts>
  template<class... Bases>
  auto SymbolTable<Ts...>::assert_valid_type(weak<ISymbol> object) -> bool {
    return not object.expired() and (rtti::instance_of<Bases>(object.lock().get()) or ...);
  }
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::define(rc<ISymbol> symbol) -> bool {
    if(symbol == nullptr) return false;
    if(not SymbolTable::assert_valid_type<Ts...>(symbol)) {
      throw InvalidArgumentError{"Invalid symbol type"};
    }

    auto [_, ok] = this->M_symbols.try_emplace(symbol->get_qualified_id(), symbol);
    return ok;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::get_symbols() const -> vector<weak<ISymbol>> {
    auto toWeak = [](rc<ISymbol> const& ref) -> weak<ISymbol> { return ref; };

    return this->M_symbols
    | views::values
    | views::transform(toWeak)
    | ranges::to<vector>();
  }

}

