#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct Function final : TypedEntity {
    private:
    vector<string> M_parameters;
    Overload* M_owner { nullptr };
    FunctionType* M_signature { nullptr };

    public:
    Function(Overload& owner, Type& returnType, vector<pair<string, Type*>> parameters = {});
    ~Function() override = default;

    auto getParameterName(u64 index) const -> string const&;
    auto getParameter(u64 index) const -> pair<string, Type*>;
    auto getReturnType() const -> Type*;

    auto getType() const -> Type* override;
  };
}

