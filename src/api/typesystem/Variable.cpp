#include "api/typesystem/Variable.hpp"
#include "api/typesystem/Type.hpp"

namespace friday::inline api::inline typesystem {
  Variable::Variable(SymbolTable& declaringScope, String name, Type* type) noexcept 
    : M_declaringScope { &declaringScope }
    , M_name { std::move(name) }
    , M_type { type }
  {}

  auto Variable::getQualifiedId() const -> String {

  }

  auto Variable::getFullQualifiedId() const -> String {

  }

  auto Variable::getMangledId() const -> String {

  }

  auto Variable::getDeclaringSymbolTable() -> SymbolTable* {

  }

  auto Variable::getAttributes() const -> Attributes const& {

  }

  auto Variable::getType() -> Type* {

  }


}