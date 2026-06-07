#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUp(string const& id, ISymbol* defaultValue) -> ISymbol* {
    if(defaultValue != nullptr and not SymbolTable::assertInstanceOf<Ts...>(defaultValue)) {
      return defaultValue;
    }
    
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      return it->second.get();
    } else if(auto parent = this->getParent(); parent != nullptr) {
      return parent->lookUp(id, defaultValue);
    } else return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUpIf(string const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue) -> ISymbol* {
    if(defaultValue != nullptr and not SymbolTable::assertInstanceOf<Ts...>(defaultValue)) {
      return defaultValue;
    }
    
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      ISymbol* candidate = it->second.get();
      if(predicate(candidate)) return candidate;
    }
    
    if(auto parent = this->getParent(); parent != nullptr) {
      return parent->lookUpIf(id, predicate, defaultValue);
    }
    
    return defaultValue;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::isDefined(string const& id) -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and SymbolTable::assertInstanceOf(it->second.get());
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::mostSimilar(string const& name, Predicate<ISymbol*> filter, u64 maxEditDistance) noexcept -> optional<ISymbol*> {
    return nullopt;
    /// TODO: to implement
  }

  template<derived_from<ISymbol>... Ts>
  template<class... Bases>
  auto SymbolTable<Ts...>::assertInstanceOf(ISymbol* object) -> bool {
    return (dynamic_cast<Bases*>(object) || ...);
  }
  
  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::define(ISymbol* symbol) -> bool {
    if(symbol == nullptr) return false;
    if(not SymbolTable::assertInstanceOf<Ts...>(symbol)) {
      throw InvalidArgumentError{"Invalid symbol type"};
    }

    return this->M_symbols.try_emplace(symbol->getQualifiedId(), symbol).second;
  }

  template<derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::getSymbols() const -> vector<ISymbol*> {
    return this->M_symbols
    | views::values
    | views::transform(box<ISymbol>::get)
    | ranges::to<vector>();
  }

}

