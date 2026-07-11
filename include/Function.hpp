#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct FRIDAY_API Function final : TypedEntity {
    private:
    vector<string>        M_parameters { };
    Pointer<Overload>     M_owner      { nullptr };
    Pointer<FunctionType> M_signature  { nullptr };

    public:
    Function(Overload& owner, Type& returnType, vector<pair<string, Pointer<Type>>> parameters = {});
    ~Function() override = default;

    auto get_param_name(u64 index) const -> string_view;
    auto get_param(u64 index) const -> pair<string_view, Pointer<Type>>;
    auto get_return_type() const -> Pointer<Type>;

    auto get_type() const -> Pointer<Type> override;
  };
}

