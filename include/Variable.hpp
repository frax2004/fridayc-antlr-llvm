#pragma once
#include <TypedEntity.hpp>
#include <Symbol.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Variable final : TypedEntity, ISymbol {
    private:
    string                M_name           { "" };
    Pointer<Type>         M_type           { nullptr };
    Pointer<ISymbolTable> M_declaringScope { nullptr };

    public:
    Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept;
    constexpr ~Variable() override = default;

    
    auto get_qualified_id() const -> string override;
    auto get_mangled_name_builder() const -> MangledNameBuilder override;
    auto get_declaring_symbol_table() const -> Pointer<ISymbolTable> override;

    auto get_attributes() const -> Attributes override;
    auto get_type() const -> Pointer<Type> override;

    static auto is_variable(Pointer<ISymbol> symbol) -> bool;
    static auto to_variable(Pointer<ISymbol> symbol) -> Pointer<Variable>;
  };
}

template<>
struct FRIDAY_API json::stringify<friday::Variable> {
  auto operator()(friday::Variable const& self) -> string {
    return format(
      "{{\"kind\": \"variable\", \"name\": \"{}\", \"type\": \"{}\"}}",
      self.get_mangled_id(),
      self.get_type()->get_name()
    );
  }
};
