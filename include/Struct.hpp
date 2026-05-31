#pragma once

#include <SymbolTable.hpp>
#include <Type.hpp>
#include <Variable.hpp>
#include <Overload.hpp>

namespace friday::inline api::inline typesystem {

  struct Namespace;

  struct Struct : ISymbol, Type, SymbolTable<Variable, Overload> {
    private:
    string M_name;
    Namespace* M_declaryingNamespace;

    public:
    Struct(Namespace& parent, string name) noexcept;

    auto getField(string const& name, Variable* defaultValue = nullptr) noexcept -> Variable*;
    auto getMethod(string const& name, Overload* defaultValue = nullptr) noexcept -> Overload*;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getAttributes() const -> Attributes override;
    auto getParent() -> ISymbolTable* override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;
  };
}

