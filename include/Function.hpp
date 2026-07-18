#pragma once

#include <TypedEntity.hpp>
#include <FunctionType.hpp>
#include <SymbolTable.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Overload;

  struct FRIDAY_API Function final : TypedEntity, ISymbol {
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
    auto get_qualified_id() const -> string override;
    auto get_declaring_symbol_table() const -> Pointer<ISymbolTable> override;
    auto get_attributes() const -> Attributes override;
    auto get_mangled_name_builder() const -> MangledNameBuilder override;
    
    auto is_nonstatic_method() const -> bool;
    auto is_static_method() const -> bool;

  };
}

