#include "api/typesystem/Struct.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, String name, Map<String, Field> fields, Map<String, Method> methods) noexcept
    : M_declaryingNamespace { &parent }
    , M_name { std::move(name) }
    , M_fields { std::move(fields) }
    , M_methods { std::move(methods) }
  {}

  auto Struct::getField(String const& name, const Field* defaultValue) const noexcept -> const Field* {
    auto it = this->M_fields.find(name);
    return it != this->M_fields.end() ? &it->second : defaultValue;
  }

  auto Struct::getMethod(String const& name, const Method* defaultValue) const noexcept -> const Method* {
    auto it = this->M_methods.find(name);
    return it != this->M_methods.end() ? &it->second : defaultValue;
  }

  auto Struct::addMethod(Method method) noexcept -> bool {
    
  }

  auto Struct::getName() const noexcept -> String const& {

  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {

  }

  auto Struct::getQualifiedId() const -> String {

  }

  auto Struct::getFullQualifiedId() const -> String {

  }

  auto Struct::getMangledId() const -> String {

  }

  auto Struct::getDeclaringSymbolTable() -> SymbolTable* {

  }

  auto Struct::getAttributes() const -> Attributes const& {

  }

  auto Struct::lookUp(String const& id, Symbol* defaultValue) -> Symbol* {

  }

  auto Struct::lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* {

  }

  auto Struct::define(Symbol* symbol) -> bool {

  }

  auto Struct::isDefined(String const& id) -> bool {

  }

  auto Struct::getParent() -> SymbolTable* {

  }

  auto Struct::mostSimilar(String const& name, u64 maxEditDistance, SymbolPredicate filter) noexcept -> Opt<Symbol*> {

  }
}
