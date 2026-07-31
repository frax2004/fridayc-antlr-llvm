#pragma once

#include <SymbolTable.hpp>
#include <Type.hpp>
#include <Variable.hpp>
#include <Overload.hpp>
#include <PolymorphicFactory.hpp>
#include <Json.hpp>

namespace friday::inline api::inline typesystem {
  struct Namespace;

  /// @brief Represents a set of fields and member functions
  struct FRIDAY_API Struct : ISymbol, Type, SymbolTable<Variable, Overload> {
    public:
    friend struct PolymorphicFactory<Struct>;
    using Factory = PolymorphicFactory<Struct>;

    private:
    /// @brief The name of the struct
    string M_name { "" };

    /// @brief The namespace where the struct was defined
    Namespace* M_declaryingNamespace { nullptr };

    private:
    /// @brief Construct a struct
    /// @param parent the parent namespace
    /// @param name the name of the struct
    Struct(Namespace& parent, string name) noexcept;
    
    public:
    /// @brief Default destructor
    ~Struct() override = default;

    public:
    auto find_field(string_view name) const noexcept -> Variable*;
    auto find_method(string_view name) const noexcept -> Overload*;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    auto get_qualified_id() const -> string override;
    auto get_attributes() const -> Attributes override;
    auto get_parent() const -> ISymbolTable* override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_mangled_name_builder() const -> NameMangler override;

    static auto is_struct(ISymbol* symbol) -> bool;
    static auto to_struct(ISymbol* symbol) -> Struct*;

  };
}
