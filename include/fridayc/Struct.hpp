#pragma once
#include "SymbolTable.hpp"
#include "Type.hpp"
#include "Symbol.hpp"


namespace friday::inline api {
  struct Namespace;
  struct Overload;
  struct Variable;

  /// @brief Represents a set of fields and member functions
  struct Struct : ISymbol, Type, ISymbolTable {
  public:
    struct Factory {
      static auto create(Namespace& parent, string name) -> Struct*;
    };
  
  public:
    constexpr static u64 FIELD_NPOS = -1ULL;

  private:
    /// @brief The name of the struct
    string M_name { "" };

    /// @brief The namespace where the struct was defined
    Namespace* M_declaryingNamespace { nullptr };

    /// @brief The fields
    map<string, u64> M_fields { };

  protected:
    /// @brief Construct a struct
    /// @param parent the parent namespace
    /// @param name the name of the struct
    Struct(Namespace& parent, string name) noexcept;
    
  public:
    /// @brief Default destructor
    ~Struct() override = default;

  public:
    auto get_field_index(string const& name) const -> u64;
    auto add_field(Variable* field) -> void;
    auto find_field(string_view name) const noexcept -> Variable*;
    auto find_method(string_view name) const noexcept -> Overload*;
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    auto get_fields() const -> vector<Variable*>;
    auto get_name() const noexcept -> string_view override;
    auto get_qualified_id() const -> string override;
    auto get_attributes() const -> Attributes override;
    auto get_parent() const -> ISymbolTable* override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_type() const -> Type* override;

    static auto is_struct(ISymbol* symbol) -> bool;
    static auto is_struct_type(Type* type) -> bool;
    static auto to_struct(ISymbol* symbol) -> Struct*;
    static auto to_struct_type(Type* symbol) -> Struct*;

  };
}
