#pragma once

#include <Symbol.hpp>
#include <SymbolTable.hpp>
#include <SignatureLess.hpp>
#include <Function.hpp>
#include <Factory.hpp>
#include <Json.hpp>

namespace friday::inline api::inline typesystem {

  /// @brief Represents a function overload
  struct FRIDAY_API Overload final : ISymbol {

    public:
    friend struct Factory<Overload>;
    using Factory = Factory<Overload>;
    using signature_map_type = map<FunctionType*, unique_ptr<Function>, less_by_signature>;

    private:
    /// @brief The scope that defined the overload
    ISymbolTable* M_declaringSymbolTable { nullptr };

    /// @brief The name of the overload
    string M_name { "" };

    /// @brief The function overload instances
    signature_map_type M_overloads { };

    private:
    /// @brief Construct a function overload
    /// @param parent the parent scope
    /// @param name the name of the overload
    Overload(ISymbolTable& parent, string name);

    public:
    /// @brief Default destructor
    ~Overload() override = default;

    public:
    /// @brief Add a function instance to the overload
    /// @param returnType the return type
    /// @param parameters a list of (name, type) parameter pairs
    auto add(Type& returnType, vector<pair<string, Type*>> parameters) -> void;

    /// @brief Check if an instance of the function overload with the matching types exists
    /// @param argsTypes the argument types
    /// @return `true` if there is a matching function overload instance
    auto has_match(vector<Type*> const& argsTypes) const -> bool;

    /// @brief Finds an instance of the function overload with the matching types exists
    /// @param argsTypes the argument types
    /// @return The found instance if there is a matching function overload instance or `nullptr`
    auto try_match(vector<Type*> const& argsTypes) -> Function*;
    
    /// @brief Get all the instances of the function overload
    /// @return the function overload instances
    auto get_instances() const -> vector<Function*>;

    auto get_qualified_id() const -> string override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;
    auto get_attributes() const -> Attributes override;
    auto get_type() const -> Type* override;

    static auto is_overload(ISymbol* symbol) -> bool;
    static auto to_overload(ISymbol* symbol) -> Overload*;
  };
}