#include "api/typesystem/Field.hpp"


namespace friday::inline api::inline typesystem {
  Field::Field(Struct& parent, String name, Type* type, VisibilityModifier visibility)
    : Variable{ (SymbolTable&)parent, name, type }
    , M_visibility { visibility }
  {}

  auto Field::getVisibility() const -> VisibilityModifier {
    return this->M_visibility;
  }

}