#pragma once
#include <Symbol.hpp>
#include <Function.hpp>
#include <SymbolTable.hpp>


namespace friday::inline api::inline typesystem {


  struct Overload final : ISymbol {
    private:
    ISymbolTable* M_declaringSymbolTable;
    String M_name;
    UnorderedMap<Vector<Type*>, Function*> M_overloads;

    public:
    Overload(ISymbolTable& parent, String name, FunctionType& firstSignature);

    auto getFunctions() const -> Vector<Function*>;
    auto add(Vector<Type*> argsTypes, Function* function) -> void;
    auto tryMatch(Vector<Type*> argsTypes) -> Function*;
    auto hasMatch(Vector<Type*> argsTypes) -> bool;

    auto getQualifiedId() const -> String override;
    auto getFullQualifiedId() const -> String override;
    auto getMangledId() const -> String override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;
    auto getAttributes() const -> Attributes override;
  };
}