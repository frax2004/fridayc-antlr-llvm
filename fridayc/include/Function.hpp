#pragma once

#include <SymbolTable.hpp>
#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {

  struct Overload;

  /// @brief Represents a function
  struct FRIDAY_API Function final : ISymbol {
    public:
    friend struct Overload;

    private:
    /// @brief The parameters names
    vector<string> M_parameters { };

    /// @brief The overload owner
    Overload* M_owner { nullptr };

    /// @brief The function signature type
    FunctionType* M_signature { nullptr };

    private:
    /// @brief Constructs a function
    /// @param owner the overload owner
    /// @param returnType the return type
    /// @param parameters the parameters pairs
    Function(Overload& owner, Type& returnType, vector<pair<string, Type*>> parameters);

    public:
    /// @brief Default destructor
    ~Function() override = default;

    public:
    auto get_param_name(u64 index) const -> string_view;
    auto get_param(u64 index) const -> pair<string_view, Type*>;
    auto get_return_type() const -> Type*;
    auto get_qualified_id() const -> string override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_attributes() const -> Attributes override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_type() const -> Type* override;
    
    auto is_nonstatic_method() const -> bool;
    auto is_static_method() const -> bool;

  };
}

