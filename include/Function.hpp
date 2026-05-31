#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct Function : TypedEntity {
    private:
    Overload* M_owner;
    FunctionType* M_signature;
    Vector<String> M_parameters;

    public:
    Function(Overload& owner, String name, Type& returnType, Vector<std::pair<String, Type*>> parameters = {});

    auto getParameterName(u64 index) const -> String const&;
    auto getParameter(u64 index) const -> std::pair<String, Type*>;

    auto getType() -> Type* override;
  };
}

