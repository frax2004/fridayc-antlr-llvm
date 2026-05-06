#pragma once

#include "TypedSymbol.hpp"
#include "FunctionType.hpp"

namespace friday::inline api::inline typesystem {
  struct SymbolTable;

  struct Function : public TypedSymbol {
    private:
    String M_name;
    FunctionType* M_signature;
    Vector<String> M_parameters;
    SymbolTable* M_declaringSymbolTable;

    public:
    Function(
      SymbolTable* parent,
      String name,
      Type* returnType,
      Vector<std::pair<String, Type*>> parameters
    );

    auto getParameterName(u64 index) const -> String const&;
    auto getParameter(u64 index) const -> std::pair<String, Type*>;
  }; // struct Function
} // namespace friday::api::typesystem

