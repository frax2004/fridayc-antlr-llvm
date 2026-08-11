#pragma once
#include "Symbol.hpp"
#include "SymbolTable.hpp"


namespace friday::inline api {

  struct Struct;
  struct Variable;
  struct Overload;

  /// @brief Represents a collection of structs, variables and function overloads
  struct Namespace final : ISymbol, ISymbolTable {
    
  public:
    struct Factory {
      static auto create(string name) -> Namespace*;
    };

    /// @brief The type of the namespace map
    using namespace_map_type = unordered_map<string, Namespace*, transparent_string_hash, equal_to<>>;
    
  private:
    /// @brief The global namespace
    static Namespace* S_globalNamespace;

    /// @brief Maps a namepsace name with its instance
    static namespace_map_type S_namespaces;

  private:
    /// @brief The parent namespace
    Namespace* M_parentNamespace { nullptr };

  private:
    /// @brief The name of the namespace
    string M_name { "" };

  private:
    /// @brief Construct a namespace 
    /// @param name the name of the namespace
    Namespace(string name);

  public:
    /// @brief Default destructor
    ~Namespace() override = default;

  public:
    /// @brief Search a function overload in this namespace
    /// @param id the id of the function
    /// @return Pointer to the instance of the function overload or `nullptr`
    auto find_function(string_view id) -> Overload*;

    /// @brief Search a struct in this namespace
    /// @param id the id of the struct
    /// @return Pointer to the instance of the struct or `nullptr`
    auto find_struct(string_view id) -> Struct*;

    /// @brief Search a variable in this namespace
    /// @param id the id of the variable
    /// @return Pointer to the instance of the variable or `nullptr`
    auto find_variable(string_view id) -> Variable*;

    auto get_qualified_id() const -> string override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_parent() const -> ISymbolTable* override;
    auto get_attributes() const -> Attributes override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_type() const -> Type* override;

    static auto to_namespace(ISymbol* symbol) -> Namespace*;
    static auto is_namespace(ISymbol* symbol) -> bool;

    /// @brief Get the global namespace
    /// @return the global namespace instance
    static auto get_global_namespace() noexcept -> Namespace*;

    /// @brief Search a namespace instance by its name
    /// @param name the name of the namespace
    /// @return the instance of the namespace or `nullptr` if not found
    static auto find_namespace(string_view name) -> Namespace*;

    /// @brief Search a namespace instance by its name or create a new instance if non existent
    /// @param name the name of the namespace
    /// @return the instance of the namespace or the new instance if not found
    static auto find_or_create_namespace(string_view name) -> Namespace*;

  };
}
