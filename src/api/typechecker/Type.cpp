#include "api/typechecker/Type.hpp"


namespace friday::inline api::inline typechecker {


  Type::Type(String name, VisibilityModifier visibility) noexcept
    : M_name { std::move(name) }
    , M_visibility { visibility }
  {}

  auto Type::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Type::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }


}