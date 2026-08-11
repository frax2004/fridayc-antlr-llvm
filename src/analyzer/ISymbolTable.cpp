#include <fridayc.hpp>

namespace friday::inline api {
  
  auto ISymbolTable::retrieve(string_view id) const -> ISymbol* {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() ? it->second : nullptr;
  }

  auto ISymbolTable::retrieve_if(string_view id, symbol_filter_type predicate) const -> ISymbol* {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and predicate(it->second) ? 
      it->second : nullptr;
  }

  auto ISymbolTable::is_defined(string_view id, symbol_filter_type predicate) const -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end()
    and predicate(it->second);
  }

  auto ISymbolTable::most_similar(string_view name, symbol_filter_type filter, u64 maxEditDistance) const noexcept -> ISymbol* {
    (void)name;
    (void)filter;
    (void)maxEditDistance;
    return {};
    // TODO: to implement
  }
  
  auto ISymbolTable::define(ISymbol* symbol) -> bool {
    if(symbol == nullptr) return false;

    auto [_, ok] = this->M_symbols.try_emplace(symbol->get_qualified_id(), symbol);
    return ok;
  }

  auto ISymbolTable::get_symbols() const -> vector<ISymbol*> {
    return this->M_symbols
    | views::values
    | ranges::to<vector>();
  }
}