#include <Variable.hpp>
#include <Type.hpp>

namespace friday::inline api::inline typesystem {
  Variable::Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept
    : M_declaringScope { &declaringScope }
    , M_name { move(name) }
    , M_type { &type }
  {}

  auto Variable::getQualifiedId() const -> string {

  }

  auto Variable::getFullQualifiedId() const -> string {

  }

  auto Variable::getMangledId() const -> string {

  }

  auto Variable::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_declaringScope;
  }

  auto Variable::getAttributes() const -> Attributes {
    return {};
  }

  auto Variable::getType() -> Type* {
    return this->M_type;
  }


}