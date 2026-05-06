#pragma once

#include "Variable.hpp"
#include "VisibilityModifier.hpp"

namespace friday::inline api::inline typesystem {
  struct Field : public Variable {

    private:
    VisibilityModifier M_visibility;

    public:
    Field(String name, Type* type, VisibilityModifier visiblity = VisibilityModifier::PUBLIC);

    auto getVisibility() const -> VisibilityModifier;
  };
}