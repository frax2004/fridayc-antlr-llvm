#pragma once

#include <Symbol.hpp>
#include <SymbolTable.hpp>
#include <Struct.hpp>
#include <Variable.hpp>
#include <Overload.hpp>
#include <Json.hpp>

namespace friday::inline api::inline typesystem {

  struct Namespace final : ISymbol, SymbolTable<Variable, Struct, Overload> {
    private:
    Namespace* M_parentNamespace { nullptr };
    string M_name;

    public:
    Namespace(string name);
    Namespace(Namespace& parent, string name);

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


template<>
struct json::stringify<friday::Namespace> {
  auto operator()(friday::Namespace const& self) -> string {
    auto name = self.getQualifiedId();
    auto symbols = self.getSymbols();

    // TODO grammar must implement global variables
    auto var2str = json::stringify<friday::Variable>{};
    auto sct2str = json::stringify<friday::Struct>{};
    auto ovl2str = json::stringify<friday::Overload>{};

    auto sym2str = [&](friday::ISymbol* symbol) {
      if(auto asVar = friday::rtti::cast<friday::Variable>(symbol)) 
        return var2str(*asVar);
      else if(auto asStruct = friday::rtti::cast<friday::Struct>(symbol)) 
        return sct2str(*asStruct);
      else if(auto asOverload = friday::rtti::cast<friday::Overload>(symbol)) 
        return ovl2str(*asOverload);
      else return "null"s;
    };

    return format(
      "{{\"kind\": \"namespace\", \"name\": \"{}\", \"symbols\": [{}]}}",
      name,
      symbols 
      | views::transform(sym2str)
      | views::join_with(", "sv)
      | ranges::to<string>()
    );
  }
};
