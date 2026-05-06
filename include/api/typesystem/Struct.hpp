#pragma once

#include "SymbolTable.hpp"
#include "Type.hpp"
#include "Field.hpp"
#include "Method.hpp"

namespace friday::inline api::inline typesystem {

  struct Namespace;
  
  struct Struct : public Symbol, public Type, public SymbolTable {
    private:
    String M_name;
    Map<String, Field> M_fields;
    Map<String, Method> M_methods;

    public:
    Struct(
      Namespace* parent,
      String name, 
      Map<String, Field> fields = {}, 
      Map<String, Method> methods = {}
    ) noexcept;

    auto addMethod(Method method) noexcept -> bool; 
    auto getField(String const& name, const Field* defaultValue = nullptr) const noexcept -> const Field*;
    auto getMethod(String const& name, const Method* defaultValue = nullptr) const noexcept -> const Method*;
}; // struct Struct
} // namespace friday::api::typechecker

