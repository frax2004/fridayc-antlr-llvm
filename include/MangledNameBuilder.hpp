#pragma once

#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct Type;

  struct FRIDAY_API MangledNameBuilder final {
    private:
    vector<string> M_names;
    vector<Pointer<Type>> M_argsTypes;

    public:
    MangledNameBuilder(string name);
    
    auto dot(string name) -> MangledNameBuilder&;
    auto param(Pointer<Type> type) -> MangledNameBuilder&;
    auto build() -> string;
  };
}