#pragma once
#include <TypedEntity.hpp>
#include <Symbol.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {

  struct Variable final : TypedEntity, ISymbol {
    private:
    string M_name;
    Type* M_type { nullptr };
    ISymbolTable* M_declaringScope { nullptr };

    public:
    Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept;
    constexpr ~Variable() override = default;

    
    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;

    auto getAttributes() const -> Attributes override;
    auto getType() const -> Type* override;

    static auto isVariable(ISymbol* symbol) -> bool;
    static auto toVariable(ISymbol* symbol) -> Variable*;
  };
}

template<>
struct json::stringify<friday::Variable> {
  auto operator()(friday::Variable const& self) -> string {
    return format(
      "{{\"kind\": \"variable\", \"name\": \"{}\", \"type\": \"{}\"}}",
      self.getQualifiedId(),
      self.getType()->getName()
    );
  }
};
