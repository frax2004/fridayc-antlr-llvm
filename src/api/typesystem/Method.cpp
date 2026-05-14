#include "api/typesystem/Method.hpp"


namespace friday::inline api::inline typesystem {
  
  Method::Method(Struct& parent, String name, Type* returnType, Vector<std::pair<String, Type*>> parameters, VisibilityModifier visibility)
    : Function{ parent, std::move(name), returnType, std::move(parameters) }
    , M_visibility { visibility }
  {}


  auto Method::getVisibility() const -> VisibilityModifier {
    return this->M_visibility;
  }

}