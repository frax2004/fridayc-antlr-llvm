#pragma once
#include "Symbol.hpp"


namespace friday::inline api {

  struct Overload;
  struct FunctionType;

  /// @brief Represents a function
  struct Function final : ISymbol {
  public:
    struct Factory {
      static auto create(Overload& owner, Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes = {}) -> Function*;
    };
    friend struct Overload;

  private:
    /// @brief The parameters names
    vector<string> M_parameters { };

    /// @brief The overload owner
    Overload* M_owner { nullptr };

    /// @brief The function signature type
    FunctionType* M_signature { nullptr };

    /// @brief The function attributes
    Attributes M_attributes { };

  private:
    /// @brief Constructs a function
    /// @param owner the overload owner
    /// @param returnType the return type
    /// @param parameters the parameters pairs
    Function(Overload& owner, Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes = {});

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

    static auto instances() -> vector<Function*>;
  };
}

