#pragma once

#include "Variable.hpp"
#include "VisibilityModifier.hpp"

namespace friday::inline api::inline typesystem {

  struct Struct;

  /// @brief Represents a struct field
  struct Field : public Variable {
    private:
    /// @brief The visibility
    VisibilityModifier M_visibility;

    public:
    /// @brief Create a field
    /// @param parent the struct where the field was defined
    /// @param name the name of the field
    /// @param type the type of the field
    /// @param visiblity the visibility of the field
    Field(Struct& parent, String name, Type* type, VisibilityModifier visibility = VisibilityModifier::PUBLIC);

    /// @brief Get the field visibility
    /// @return the visibility
    auto getVisibility() const -> VisibilityModifier;
  };
}