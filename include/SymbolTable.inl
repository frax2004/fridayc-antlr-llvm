#ifdef __INTELLISENSE__
#include <SymbolTable.hpp>
#endif

#include <InvalidArgumentError.hpp>

namespace friday::inline api::inline typesystem {
  
  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUp(String const& id, ISymbol* defaultValue) -> ISymbol* {
    if(not SymbolTable::assertInstanceOf<Ts...>(defaultValue)) {
      return defaultValue;
    }
    
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      return it->second.get();
    } else if(auto parent = this->getParent(); parent != nullptr) {
      return parent->lookUp(id, defaultValue);
    } else return defaultValue;
  }

  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::lookUpIf(String const& id, Predicate<ISymbol*> predicate, ISymbol* defaultValue) -> ISymbol* {
    if(not SymbolTable::assertInstanceOf<Ts...>(defaultValue)) {
      return defaultValue;
    }
    
    if(auto it = this->M_symbols.find(id); it != this->M_symbols.end()) {
      ISymbol* candidate = it->second.get();
      if(predicate(candidate)) return candidate;
    }
    
    if(auto parent = this->getParent(); parent != nullptr) {
      ISymbol* candidate = parent->lookUp(id, defaultValue);
      if(predicate(candidate)) return candidate;
    }
    
    return defaultValue;
  }

  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::isDefined(String const& id) -> bool {
    auto it = this->M_symbols.find(id);
    return it != this->M_symbols.end() and SymbolTable::assertInstanceOf(it->second.get());
  }

  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::mostSimilar(String const& name, Predicate<ISymbol*> filter, u64 maxEditDistance) noexcept -> Opt<ISymbol*> {
    return std::nullopt;
    /// TODO: to implement
  }

  template<std::derived_from<ISymbol>... Ts>
  template<class... Bases>
  auto SymbolTable<Ts...>::assertInstanceOf(ISymbol* object) -> bool {
    return (dynamic_cast<Bases*>(object) || ...);
  }
  
  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::define(ISymbol* symbol) -> bool {
    if(not SymbolTable::assertInstanceOf<Ts...>(symbol)) {
      throw InvalidArgumentError{"Invalid symbol type"};
    }

    return this->M_symbols.try_emplace(symbol->getQualifiedId(), symbol).second;
  }

  template<std::derived_from<ISymbol>... Ts>
  auto SymbolTable<Ts...>::getSymbols() const -> Vector<ISymbol*> {
    return this->M_symbols
    | std::views::values
    | std::views::transform(Box<ISymbol>::get)
    | std::ranges::to<std::vector>();
  }

}

