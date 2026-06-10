#include <Variable.hpp>
#include <Type.hpp>
#include <NotImplementedError.hpp>

namespace friday::inline api::inline typesystem {
  Variable::Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept
    : M_declaringScope { &declaringScope }
    , M_name { move(name) }
    , M_type { &type }
  {}

  auto Variable::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Variable::getFullQualifiedId() const -> string {
    throw NotImplementedError{"Variable::getFullQualifiedId()"};
  }

  auto Variable::getMangledId() const -> string {
    throw NotImplementedError{"Variable::getMangledId()"};
  }

  auto Variable::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_declaringScope;
  }

  auto Variable::getAttributes() const -> Attributes {
    throw NotImplementedError{"Variable::getAttributes()"};
  }

  auto Variable::getType() const -> Type* {
    return this->M_type;
  }


}