#pragma once

#include <SymbolTable.hpp>
#include <Type.hpp>
#include <Variable.hpp>
#include <Overload.hpp>

namespace friday::inline api::inline typesystem {

  struct Namespace;

  struct Struct : ISymbol, Type, SymbolTable<Variable, Overload> {
    private:
    String M_name;
    Namespace* M_declaryingNamespace;

    public:
    Struct(Namespace& parent, String name) noexcept;

    auto getField(String const& name, Variable* defaultValue = nullptr) noexcept -> Variable*;
    auto getMethod(String const& name, Overload* defaultValue = nullptr) noexcept -> Overload*;
    auto getName() const noexcept -> String const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    auto getQualifiedId() const -> String override;
    auto getFullQualifiedId() const -> String override;
    auto getMangledId() const -> String override;
    auto getAttributes() const -> Attributes override;
    auto getParent() -> ISymbolTable* override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;
  };
}

