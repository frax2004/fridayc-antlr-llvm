#include "api/typesystem/SymbolTable.hpp"
#include "api/typesystem/Struct.hpp"
#include "core/IO/Console.hpp"

namespace friday::inline api::inline typechecker {

  // auto SymbolTable::define(String name, Symbol* value) noexcept -> bool {
  //   return this->M_symbols.try_emplace(std::move(name), value).second;
  // }

  // auto SymbolTable::isDefinedLocal(String const& name) noexcept -> bool {
  //   return this->M_symbols.contains(name);
  // }

  // auto SymbolTable::isDefined(String const& name) noexcept -> bool {
  //   return this->M_symbols.contains(name)
  //   or (this->M_parent != nullptr and this->M_parent->isDefined(name));
  // }

  // auto SymbolTable::resolveIf(String const& name, std::function<bool (Symbol*)> predicate, Symbol* defaultValue) noexcept -> Symbol* {
  //   auto symbol = this->resolve(name, defaultValue);
  //   return predicate(symbol) ? symbol : defaultValue;
  // }

  // auto SymbolTable::resolve(String const& name, Symbol* defaultValue) noexcept -> Symbol* {
  //   auto it = this->M_symbols.find(name);
  //   return it != this->M_symbols.end() ?
  //     it->second.get() : this->M_parent ? 
  //       this->M_parent->resolve(name, defaultValue) : defaultValue;
  // }

  // auto SymbolTable::getParent() const noexcept -> SymbolTable* {
  //   return this->M_parent;
  // }

  // auto SymbolTable::mostSimilar(String const& name, u64 maxEditDistance, std::function<bool (Symbol*)> filter) noexcept -> Opt<String> {

  //   const auto byFilter = [&filter](auto const& entry) -> bool {
  //     return filter(entry.second.get());
  //   };

  //   constexpr const auto toStringRef = [](String const& s) -> llvm::StringRef {
  //     return llvm::StringRef{ s };
  //   };

  //   const auto withEditDistance = [&name, maxEditDistance](String const& target) {
  //     llvm::StringRef source = target;
  //     return std::make_pair(source, source.edit_distance_insensitive(name, true, maxEditDistance));
  //   };

  //   constexpr const auto byEditDistance = [](std::pair<llvm::StringRef, u32> const& pair) {
  //     return pair.second;
  //   };

  //   const auto byMaxEditDistance = [maxEditDistance](std::pair<llvm::StringRef, u32> const& pair) {
  //     return pair.second <= maxEditDistance;
  //   };

  //   auto mostSimilars = this->M_symbols
  //   | std::views::filter(byFilter)
  //   | std::views::keys
  //   | std::views::transform(withEditDistance)
  //   | std::views::filter(byMaxEditDistance);

  //   auto it = std::ranges::min_element(mostSimilars, std::less<>{}, byEditDistance);
  //   return it != mostSimilars.end() ? 
  //     std::make_optional((*it).first.str()) : this->M_parent != nullptr ?
  //       this->M_parent->mostSimilar(name, maxEditDistance) : std::nullopt;
  // }

  // auto SymbolTable::builtins(llvm::Module& mod) noexcept -> SymbolTable {
  //   SymbolTable scope { nullptr };
  //   llvm::LLVMContext& ctx = mod.getContext();

  //   Struct* Float = (Struct*)Struct::getFloatType(ctx);

  //   scope.define("float", Float);

  //   Struct* Int = (Struct*)Struct::getIntType(ctx);
  //   scope.define("int", Int);

  //   Struct* Byte = (Struct*)Struct::getByteType(ctx);
  //   scope.define("byte", Byte);

  //   Struct* Bool = (Struct*)Struct::getBoolType(ctx);
  //   scope.define("bool", Bool);

  //   Struct* Void = (Struct*)Struct::getVoidType(ctx);
  //   scope.define("void", Void);


  //   return std::move(scope);
  // }
}