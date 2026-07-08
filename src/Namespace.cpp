#include <Namespace.hpp>
#include <NotImplementedError.hpp>

namespace friday::inline api::inline typesystem {
  Namespace::Namespace(string name)
    : M_name { name }
  {}

  Namespace::Namespace(Namespace& parent, string name)
    : M_parentNamespace{ &parent }
    , M_name { name }
  {}

  auto Namespace::getFunction(string const& id, weak<Overload> defaultValue) -> weak<Overload> {
    constexpr auto isOverload = [](ISymbol* symbol) {
      return dynamic_cast<Overload*>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(id, isOverload, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Overload>(candidate.lock()) : defaultValue;
  }

  auto Namespace::getStruct(string const& id, weak<Struct> defaultValue) -> weak<Struct> {
    constexpr auto isStruct = [](ISymbol* symbol) {
      return dynamic_cast<Struct*>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(id, isStruct, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Struct>(candidate.lock()) : defaultValue;
  }

  auto Namespace::getVariable(string const& id, weak<Variable> defaultValue) -> weak<Variable> {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(id, isVariable, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Variable>(candidate.lock()) : defaultValue;
  }

  auto Namespace::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Namespace::getFullQualifiedId() const -> string {
    throw NotImplementedError{"Namespace::getFullQualifiedId()"};
  }

  auto Namespace::getMangledId() const -> string {
    throw NotImplementedError{"Namespace::getMangledId()"};
  }

  auto Namespace::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_parentNamespace;
  }

  auto Namespace::getAttributes() const -> Attributes {
    throw NotImplementedError{"Namespace::getAttributes()"};
  }

  auto Namespace::getParent() -> ISymbolTable* {
    return rtti::cast<ISymbolTable>(this->M_parentNamespace);
  }  
}