#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct FRIDAY_API Function final : TypedEntity {
    private:
    vector<string> M_parameters;
    Pointer<Overload> M_owner { nullptr };
    Pointer<FunctionType> M_signature { nullptr };

    public:
    Function(Overload& owner, Type& returnType, vector<pair<string, Pointer<Type>>> parameters = {});
    ~Function() override = default;

    auto getParameterName(u64 index) const -> string const&;
    auto getParameter(u64 index) const -> pair<string, Pointer<Type>>;
    auto getReturnType() const -> Pointer<Type>;

    auto getType() const -> Pointer<Type> override;
  };
}

