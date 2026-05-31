#pragma once

#include <Symbol.hpp>
#include <SymbolTable.hpp>
#include <Struct.hpp>
#include <Variable.hpp>
#include <Overload.hpp>

namespace friday::inline api::inline typesystem {

  struct Namespace final : ISymbol, SymbolTable<Variable, Struct, Overload> {
    private:
    Namespace* M_parentNamespace;

    public:
    constexpr Namespace() = default;
    Namespace(Namespace& parent);

    auto getFunction(string const& id, Overload* defaultValue = nullptr) -> Overload*;
    auto getStruct(string const& id, Struct* defaultValue = nullptr) -> Struct*;
    auto getVariable(string const& id, Variable* defaultValue = nullptr) -> Variable*;

    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;
    auto getParent() -> ISymbolTable* override;
    auto getAttributes() const -> Attributes override;
  };
}
