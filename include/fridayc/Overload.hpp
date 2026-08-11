#pragma once
#include "Symbol.hpp"
#include "SignatureLess.hpp"



namespace friday::inline api {

  struct Type;
  struct FunctionType;
  struct Function;
  struct ISymbolTable;

  /// @brief Represents a function overload
  struct Overload final : ISymbol {

  public:
    struct Factory {
      static auto create(ISymbolTable& parent, string name) -> Overload*;
    };

    using signature_map_type = map<FunctionType*, Function*, less_by_signature>;

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
    auto add(Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes = { }) -> Function*;

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