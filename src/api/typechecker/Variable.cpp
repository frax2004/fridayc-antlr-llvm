#include "api/typechecker/Variable.hpp"
#include "api/typechecker/Type.hpp"

namespace friday::inline api::inline typechecker {
  Variable::Variable(String name, Type* type, VisibilityModifier visibility) noexcept
    : M_name { std::move(name) }
    , M_type { type }
    , M_visibility { visibility }
  {}

  auto Variable::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Variable::getType() const noexcept -> Type* {
    return this->M_type;
  }

  auto Variable::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }

}