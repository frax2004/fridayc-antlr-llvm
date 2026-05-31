#pragma once
#include <TypedEntity.hpp>
#include <Symbol.hpp>


namespace friday::inline api::inline typesystem {

  struct Variable : TypedEntity, ISymbol {
    private:
    string M_name;
    Type* M_type;
    ISymbolTable* M_declaringScope;

    public:
    Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept;
    
    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;

    auto getAttributes() const -> Attributes override;
    auto getType() -> Type* override;
  };
}