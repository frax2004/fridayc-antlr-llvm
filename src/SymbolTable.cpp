#include "api/typechecker/SymbolTable.hpp"

namespace friday::inline api::inline typechecker {

  SymbolTable::SymbolTable(SymbolTable* parent)
    : M_parent { parent }
  {}

  auto SymbolTable::define(String name, Symbol* value) noexcept -> bool {
    if(this->isDefined(name)) return false;
    return this->M_symbols.emplace(std::move(name), value).second;
  }

  auto SymbolTable::isDefined(String const& name) noexcept -> bool {
    auto it = this->M_symbols.find(name);
    return it != this->M_symbols.end()
    or (this->M_parent != nullptr and this->M_parent->isDefined(name));
  }

  auto SymbolTable::resolve(String const& name, Symbol* defaultValue) noexcept -> Symbol* {
    auto it = this->M_symbols.find(name);
    return it != this->M_symbols.end() ?
      it->second.get() : this->M_parent ? 
        this->M_parent->resolve(name, defaultValue) : defaultValue;
  }

  auto SymbolTable::getParent() const noexcept -> SymbolTable* {
    return this->M_parent;
  }

  auto SymbolTable::mostSimilar(String const& name, u64 maxEditDistance, std::function<bool (Symbol*)> filter) noexcept -> Opt<String> {

    const auto byFilter = [&filter](auto const& entry) -> bool {
      return filter(entry.second.get());
    };

    constexpr const auto toStringRef = [](String const& s) -> llvm::StringRef {
      return llvm::StringRef{ s };
    };

    const auto withEditDistance = [&name, maxEditDistance](String const& target) {
      llvm::StringRef source = target;
      return std::make_pair(source, source.edit_distance_insensitive(name, true, maxEditDistance));
    };

    constexpr const auto byEditDistance = [](std::pair<llvm::StringRef, u32> const& pair) {
      return pair.second;
    };

    const auto byMaxEditDistance = [maxEditDistance](std::pair<llvm::StringRef, u32> const& pair) {
      return pair.second <= maxEditDistance;
    };

    auto mostSimilars = this->M_symbols
    | std::views::filter(byFilter)
    | std::views::keys
    | std::views::transform(withEditDistance)
    | std::views::filter(byMaxEditDistance);

    auto it = std::ranges::min_element(mostSimilars, std::less<>{}, byEditDistance);
    return it != mostSimilars.end() ? 
      std::make_optional((*it).first.str()) : this->M_parent != nullptr ?
        this->M_parent->mostSimilar(name, maxEditDistance) : std::nullopt;
  }

  auto SymbolTable::builtins(llvm::Module& mod) noexcept -> SymbolTable {
    SymbolTable scope { nullptr };
    llvm::LLVMContext& ctx = mod.getContext();

    return std::move(scope);
  }
}