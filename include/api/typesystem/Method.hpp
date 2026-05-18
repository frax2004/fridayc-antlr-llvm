#pragma once

#include "Function.hpp"
#include "VisibilityModifier.hpp"

namespace friday::inline api::inline typesystem {

  struct Struct;

  /// @brief Represents a struct method
  struct Method : public Function {

    private:
    /// @brief The visibility
    VisibilityModifier M_visibility;

    public:
    /// @brief Creates a method
    /// @param parent the struct where the method was defined
    /// @param name the name of the method
    /// @param returnType the return type of the method
    /// @param parameters a list of parameters, that is, a list of pairs (name, type) representing the method's parameters
    /// @param visiblity the visibility
    Method(Struct& parent, String name, Type* returnType, Vector<std::pair<String, Type*>> parameters, VisibilityModifier visibility = VisibilityModifier::PUBLIC);

    /// @brief Get the visibility
    /// @return the visibility
    auto getVisibility() const -> VisibilityModifier;
  }; // struct Method
} // namespace friday::api::typesystem