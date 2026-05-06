#include "api/typesystem/Struct.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typesystem {


  Struct::Struct(Namespace* parent, String name, Map<String, Field> fields, Map<String, Method> methods) noexcept
    : M_name { std::move(name) }
    , M_fields { std::move(fields) }
    , M_methods { std::move(methods) }
  {}

  auto Struct::getField(String const& name, const Field* defaultValue) const noexcept -> const Field* {
    auto it = this->M_fields.find(name);
    return it != this->M_fields.end() ? &it->second : defaultValue;
  }

  auto Struct::getMethod(String const& name, const Method* defaultValue) const noexcept -> const Method* {
    auto it = this->M_methods.find(name);
    return it != this->M_methods.end() ? &it->second : defaultValue;
  }

  auto Struct::addMethod(Method method) noexcept -> bool {
    return this->M_methods.try_emplace(method.getName(), method).second;
  }

}
