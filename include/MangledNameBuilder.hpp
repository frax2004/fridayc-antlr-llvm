#pragma once

#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct Type;

  struct MangledNameBuilder final {
    private:
    vector<string> M_names;
    vector<Type*> M_argsTypes;

    public:
    MangledNameBuilder(string name);
    
    auto dot(string name) -> MangledNameBuilder&;
    auto param(Type* type) -> MangledNameBuilder&;
    auto build() -> string;
  };
}