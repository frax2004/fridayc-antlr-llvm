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
    string             M_name            { "" };

    public:
    Namespace(string name);
    Namespace(Namespace& parent, string name);
    ~Namespace() override = default;

    auto find_function(string_view id) -> weak<Overload>;
    auto find_struct(string_view id) -> weak<Struct>;
    auto find_variable(string_view id) -> weak<Variable>;

    auto get_qualified_id() const -> string override;
    auto get_full_qualified_id() const -> string override;
    auto get_mangled_id() const -> string override;
    auto get_declaring_symbol_table() -> Pointer<ISymbolTable> override;
    auto get_parent() -> Pointer<ISymbolTable> override;
    auto get_attributes() const -> Attributes override;

    static auto to_namespace(Pointer<ISymbol> symbol) -> Pointer<Namespace>;
    static auto is_namespace(Pointer<ISymbol> symbol) -> bool;
  };
}


template<>
struct FRIDAY_API json::stringify<friday::Namespace> {
  auto operator()(friday::Namespace const& self) -> string {
    auto name = self.get_qualified_id();
    auto symbols = self.get_symbols();

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
