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

  private:
    /// @brief The name of the struct
    string M_name { "" };

    /// @brief The namespace where the struct was defined
    Namespace* M_declaryingNamespace { nullptr };

  protected:
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
    auto to_llvm_type() const noexcept -> llvm::Type* override;
    auto get_qualified_id() const -> string override;
    auto get_attributes() const -> Attributes override;
    auto get_parent() const -> ISymbolTable* override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_type() const -> Type* override;

    static auto is_struct(ISymbol* symbol) -> bool;
    static auto to_struct(ISymbol* symbol) -> Struct*;

  };
}
