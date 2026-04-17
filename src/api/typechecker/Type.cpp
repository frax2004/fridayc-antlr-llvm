#include "api/typechecker/Type.hpp"


namespace friday::inline api::inline typechecker {

  Type::Type(VisibilityModifier visibility) noexcept
    : M_visibility { visibility }
  {}

  auto Type::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }

}