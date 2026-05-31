#pragma once
#include <TypedEntity.hpp>
#include <Symbol.hpp>


namespace friday::inline api::inline typesystem {

  struct Variable : TypedEntity, ISymbol {
    private:
    String M_name;
    Type* M_type;
    ISymbolTable* M_declaringScope;

    public:
    Variable(ISymbolTable& declaringScope, String name, Type& type) noexcept;
    
    auto getQualifiedId() const -> String override;
    auto getFullQualifiedId() const -> String override;
    auto getMangledId() const -> String override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;

    auto getAttributes() const -> Attributes override;
    auto getType() -> Type* override;
  };
}