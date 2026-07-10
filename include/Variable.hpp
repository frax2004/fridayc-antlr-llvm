#pragma once
#include <TypedEntity.hpp>
#include <Symbol.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Variable final : TypedEntity, ISymbol {
    private:
    string M_name;
    Pointer<Type> M_type { nullptr };
    Pointer<ISymbolTable> M_declaringScope { nullptr };

    public:
    Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept;
    constexpr ~Variable() override = default;

    
    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> Pointer<ISymbolTable> override;

    auto getAttributes() const -> Attributes override;
    auto getType() const -> Pointer<Type> override;

    static auto isVariable(Pointer<ISymbol> symbol) -> bool;
    static auto toVariable(Pointer<ISymbol> symbol) -> Pointer<Variable>;
  };
}

template<>
struct FRIDAY_API json::stringify<friday::Variable> {
  auto operator()(friday::Variable const& self) -> string {
    return format(
      "{{\"kind\": \"variable\", \"name\": \"{}\", \"type\": \"{}\"}}",
      self.getQualifiedId(),
      self.getType()->getName()
    );
  }
};
