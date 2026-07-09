#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUp(string const& id, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    // Console::debug("Searching '{}'..."_f.format(id));
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      // Console::debug("Found");
      return it->second;
    } else if(auto parent = this->getParent(); parent != nullptr) {
      // Console::debug("Not Found. Looking Upwards for '{}'..."_f.format(id));
      return parent->lookUp(id, defaultValue);
    }

    // Console::debug("Not Found");
    return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUpIf(string const& id, Predicate<ISymbol*> predicate, weak<ISymbol> defaultValue) -> weak<ISymbol> {
    // Console::debug("(Predicate) Searching '{}'..."_f.format(id));

    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      rc<ISymbol> candidate = it->second;
      if(predicate(candidate.get())) {
        // Console::debug("Found (predicate is true)");
        return candidate;
      }
      else {
        // Console::debug("Not Found (predicate is false)");
        return defaultValue; // TODO POTENTIAL BUG, IN THIS CASE THE LOOKUP SHOULD BE DONE UPWARDS
      }
    } else if(auto parent = this->getParent(); parent != nullptr) {
      // Console::debug("Not Found. Looking Upwards for '{}'..."_f.format(id));
      return parent->lookUpIf(id, predicate, defaultValue);
    }

    // Console::debug("Not Found");
    return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::isDefined(string const& id) -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and SymbolTable::assertInstanceOf<Ts...>(it->second);
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::mostSimilar(string const& name, Predicate<ISymbol*> filter, u64 maxEditDistance) noexcept -> weak<ISymbol> {
    (void)name;
    (void)filter;
    (void)maxEditDistance;
    return {};
    // TODO: to implement
  }

  template<derived_from<ISymbol>... Ts>
  template<class... Bases>
  auto SymbolTable<Ts...>::assertInstanceOf(weak<ISymbol> object) -> bool {
    return not object.expired() and (rtti::instanceOf<Bases>(object.lock().get()) or ...);
  }
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::define(rc<ISymbol> symbol) -> bool {
    if(symbol == nullptr) return false;
    if(not SymbolTable::assertInstanceOf<Ts...>(symbol)) {
      throw InvalidArgumentError{"Invalid symbol type"};
    }

    auto [_, ok] = this->M_symbols.try_emplace(symbol->getQualifiedId(), symbol);
    return ok;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::getSymbols() const -> vector<weak<ISymbol>> {
    auto toWeak = [](rc<ISymbol> const& ref) -> weak<ISymbol> { return ref; };

    return this->M_symbols
    | views::values
    | views::transform(toWeak)
    | ranges::to<vector>();
  }

}

