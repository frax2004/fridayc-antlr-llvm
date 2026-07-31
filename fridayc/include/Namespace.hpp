#pragma once

#include <Symbol.hpp>
#include <SymbolTable.hpp>
#include <Struct.hpp>
#include <Variable.hpp>
#include <Overload.hpp>
#include <ErrorType.hpp>
#include <Factory.hpp>
#include <Json.hpp>

namespace friday::inline api::inline typesystem {

  /// @brief Represents a collection of structs, variables and function overloads
  struct FRIDAY_API Namespace final : ISymbol, SymbolTable<Variable, Struct, Overload> {
    
    public:
    friend struct Factory<Namespace>;
    using Factory = Factory<Namespace>;

    /// @brief The type of the namespace map
    using namespace_map_type = unordered_map<string, Namespace*, transparent_string_hash,equal_to<>>;
    
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

    private:
    /// @brief Construct a namespace 
    /// @param parent the parent namespace
    /// @param name the name of the namespace
    Namespace(Namespace& parent, string name);

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

    static auto to_namespace(ISymbol* symbol) -> Namespace*;
    static auto is_namespace(ISymbol* symbol) -> bool;

    /// @brief Get the global namespace
    /// @return the global namespace instance
    static auto get_global_namespace() noexcept -> Namespace*;

    /// @brief Search a namespace instance by its name
    /// @param name the name of the namespace
    /// @return the instance of the namespace or `nullptr` if not found
    static auto find_namespace(string_view name) -> Namespace*;

  };
}
