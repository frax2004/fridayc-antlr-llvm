#pragma once

#include <Symbol.hpp>
#include <SymbolTable.hpp>
#include <Struct.hpp>
#include <Variable.hpp>
#include <Overload.hpp>
#include <Json.hpp>
#include <ErrorType.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Namespace final : ISymbol, SymbolTable<Variable, Struct, Overload> {
    private:
    Pointer<Namespace> M_parentNamespace { nullptr };
    string M_name;

    public:
    Namespace(string name);
    Namespace(Namespace& parent, string name);
    ~Namespace() override = default;

    auto getFunction(string const& id, weak<Overload> defaultValue = {}) -> weak<Overload>;
    auto getStruct(string const& id, weak<Struct> defaultValue = {}) -> weak<Struct>;
    auto getVariable(string const& id, weak<Variable> defaultValue = {}) -> weak<Variable>;

    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> Pointer<ISymbolTable> override;
    auto getParent() -> Pointer<ISymbolTable> override;
    auto getAttributes() const -> Attributes override;
  };
}


template<>
struct FRIDAY_API json::stringify<friday::Namespace> {
  auto operator()(friday::Namespace const& self) -> string {
    auto name = self.getQualifiedId();
    auto symbols = self.getSymbols();

    // TODO grammar must implement global variables
    auto var2str = json::stringify<friday::Variable>{};
    auto sct2str = json::stringify<friday::Struct>{};
    auto ovl2str = json::stringify<friday::Overload>{};

    auto sym2str = [&](Pointer<friday::ISymbol> symbol) {
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
      | views::filter([](weak<friday::ISymbol> ref) { return not ref.expired(); })
      | views::transform([](weak<friday::ISymbol> ref) { return ref.lock().get(); })
      | views::transform(sym2str)
      | views::join_with(", "sv)
      | ranges::to<string>()
    );
  }
};
