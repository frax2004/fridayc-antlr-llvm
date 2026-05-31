#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct Function : TypedEntity {
    private:
    Overload* M_owner;
    FunctionType* M_signature;
    vector<string> M_parameters;

    public:
    Function(Overload& owner, string name, Type& returnType, vector<pair<string, Type*>> parameters = {});

    auto getParameterName(u64 index) const -> string const&;
    auto getParameter(u64 index) const -> pair<string, Type*>;

    auto getType() -> Type* override;
  };
}

