#include <Variable.hpp>
#include <Type.hpp>
#include <NotImplementedError.hpp>

namespace friday::inline api::inline typesystem {
  Variable::Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept {
    this->M_declaringScope = &declaringScope;
    this->M_name = name;
    this->M_type = &type;
  }

  auto Variable::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Variable::getFullQualifiedId() const -> string {
    throw NotImplementedError{"Variable::getFullQualifiedId()"};
  }

  auto Variable::getMangledId() const -> string {
    throw NotImplementedError{"Variable::getMangledId()"};
  }

  auto Variable::getDeclaringSymbolTable() -> Pointer<ISymbolTable> {
    return this->M_declaringScope;
  }

  auto Variable::getAttributes() const -> Attributes {
    throw NotImplementedError{"Variable::getAttributes()"};
  }

  auto Variable::getType() const -> Pointer<Type> {
    return this->M_type;
  }

  auto Variable::isVariable(Pointer<ISymbol> symbol) -> bool {
    return rtti::instanceOf<Variable>(symbol);
  }

  auto Variable::toVariable(Pointer<ISymbol> symbol) -> Pointer<Variable> {
    return rtti::cast<Variable>(symbol);
  }

}