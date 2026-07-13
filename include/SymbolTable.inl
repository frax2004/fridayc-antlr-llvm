#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::look_up(string_view id, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      return it->second;
    } else if(auto parent = this->get_parent(); parent != nullptr) {
      return parent->look_up(id, defaultValue);
    }

    return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::look_up_if(string_view id, Predicate<Pointer<ISymbol>> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {

    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      rc<ISymbol> candidate = it->second;
      if(predicate(candidate.get())) {
        return candidate;
      } else {
        return defaultValue; // TODO POTENTIAL BUG, IN THIS CASE THE LOOKUP SHOULD BE DONE UPWARDS
      }
    } else if(auto parent = this->get_parent(); parent != nullptr) {
      return parent->look_up_if(id, predicate, defaultValue);
    }

    return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::is_defined(string_view id, Predicate<Pointer<ISymbol>> predicate) -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() 
    and SymbolTable::assert_valid_type<Ts...>(it->second) 
    and predicate(it->second.get());
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::most_similar(string_view name, Predicate<Pointer<ISymbol>> filter, u64 maxEditDistance) noexcept -> weak<ISymbol> {
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

