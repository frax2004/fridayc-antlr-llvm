#include <Namespace.hpp>


namespace friday::inline api::inline typesystem {
  Namespace::Namespace(Namespace& parent)
    : M_parentNamespace{ &parent }
  {}

  auto Namespace::getFunction(String const& id, Overload* defaultValue) -> Overload* {
    constexpr auto isOverload = [](ISymbol* symbol) {
      return dynamic_cast<Overload*>(symbol) != nullptr;
    };

    return (Overload*)lookUpIf(id, isOverload, defaultValue);
  }

  auto Namespace::getStruct(String const& id, Struct* defaultValue) -> Struct* {
    constexpr auto isStruct = [](ISymbol* symbol) {
      return dynamic_cast<Struct*>(symbol) != nullptr;
    };

    return (Struct*)lookUpIf(id, isStruct, defaultValue);
  }

  auto Namespace::getVariable(String const& id, Variable* defaultValue) -> Variable* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    return (Variable*)lookUpIf(id, isVariable, defaultValue);
  }

  auto Namespace::getQualifiedId() const -> String {

  }

  auto Namespace::getFullQualifiedId() const -> String {

  }

  auto Namespace::getMangledId() const -> String {

  }

  auto Namespace::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_parentNamespace;
  }

  auto Namespace::getAttributes() const -> Attributes {
    return {};
  }

  auto Namespace::getParent() -> ISymbolTable* {
    return this->M_parentNamespace;
  }  
}