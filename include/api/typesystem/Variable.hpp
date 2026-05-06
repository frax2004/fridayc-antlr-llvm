#pragma once

#include "TypedSymbol.hpp"


namespace friday::inline api::inline typesystem {

  struct Variable : public TypedSymbol {
    private:
    String M_name;
    Type* M_type;

    public:
    Variable(String name, Type* type) noexcept;
  }; // struct Variable
} // namespace friday::api::typesystem