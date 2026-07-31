#pragma once

#include <Symbol.hpp>
#include <Json.hpp>
#include <Factory.hpp>


namespace friday::inline api::inline typesystem {

  /// @brief Represents a variable
  struct FRIDAY_API Variable final : ISymbol {
    public:
    friend struct Factory<Variable>;
    using Factory = Factory<Variable>;

    private:
    /// @brief The name of the variable
    string M_name { "" };
    /// @brief The type of the variable
    Type* M_type { nullptr };
    /// @brief The scope where the variable is defined
    ISymbolTable* M_declaringScope { nullptr };

    private:
    /// @brief Construct a variable
    /// @param declaringScope the scope where the variable was defined
    /// @param name the name of the variable
    /// @param type the type of the variable
    Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept;
    
    public:
    /// @brief Default destructor
    constexpr ~Variable() override = default;

    auto get_qualified_id() const -> string override;
    auto get_mangled_name_builder() const -> NameMangler override;
    auto get_declaring_symbol_table() const -> ISymbolTable* override;

    auto get_attributes() const -> Attributes override;
    auto get_type() const -> Type* override;

    static auto is_variable(ISymbol* symbol) -> bool;
    static auto to_variable(ISymbol* symbol) -> Variable*;
  };
}
