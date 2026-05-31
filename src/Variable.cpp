#include <Variable.hpp>
#include <Type.hpp>

namespace friday::inline api::inline typesystem {
  Variable::Variable(ISymbolTable& declaringScope, String name, Type& type) noexcept
    : M_declaringScope { &declaringScope }
    , M_name { std::move(name) }
    , M_type { &type }
  {}

  auto Variable::getQualifiedId() const -> String {

  }

  auto Variable::getFullQualifiedId() const -> String {

  }

  auto Variable::getMangledId() const -> String {

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