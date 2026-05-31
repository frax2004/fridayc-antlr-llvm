#pragma once

#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct Type;

  struct MangledNameBuilder final {
    private:
    Vector<String> M_names;
    Vector<Type*> M_argsTypes;

    public:
    MangledNameBuilder(String name);
    
    auto dot(String name) -> MangledNameBuilder&;
    auto param(Type* type) -> MangledNameBuilder&;
    auto build() -> String;
  };
}