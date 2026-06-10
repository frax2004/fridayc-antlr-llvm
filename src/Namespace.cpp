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

  auto Namespace::getFunction(string const& id, Overload* defaultValue) -> Overload* {
    constexpr auto isOverload = [](ISymbol* symbol) {
      return dynamic_cast<Overload*>(symbol) != nullptr;
    };

    return (Overload*)lookUpIf(id, isOverload, defaultValue);
  }

  auto Namespace::getStruct(string const& id, Struct* defaultValue) -> Struct* {
    constexpr auto isStruct = [](ISymbol* symbol) {
      return dynamic_cast<Struct*>(symbol) != nullptr;
    };

    return (Struct*)lookUpIf(id, isStruct, defaultValue);
  }

  auto Namespace::getVariable(string const& id, Variable* defaultValue) -> Variable* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    return (Variable*)lookUpIf(id, isVariable, defaultValue);
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
    return this->M_parentNamespace;
  }  
}