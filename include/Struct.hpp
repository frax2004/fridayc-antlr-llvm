#pragma once

#include <SymbolTable.hpp>
#include <Type.hpp>
#include <Variable.hpp>
#include <Overload.hpp>
#include <Json.hpp>

namespace friday::inline api::inline typesystem {

  struct Namespace;

  struct FRIDAY_API Struct : ISymbol, Type, SymbolTable<Variable, Overload> {
    private:
    string             M_name                { "" };
    Pointer<Namespace> M_declaryingNamespace { nullptr };

    public:
    Struct(Namespace& parent, string name) noexcept;
    ~Struct() override = default;

    auto find_field(string_view name) const noexcept -> weak<Variable>;
    auto find_method(string_view name) const noexcept -> weak<Overload>;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    auto get_qualified_id() const -> string override;
    auto get_attributes() const -> Attributes override;
    auto get_parent() const -> Pointer<ISymbolTable> override;
    auto get_declaring_symbol_table() const -> Pointer<ISymbolTable> override;
    auto get_mangled_name_builder() const -> MangledNameBuilder override;

    static auto is_struct(Pointer<ISymbol> symbol) -> bool;
    static auto to_struct(Pointer<ISymbol> symbol) -> Pointer<Struct>;

  };
}

template<>
struct FRIDAY_API json::stringify<friday::Struct> {
  auto operator()(friday::Struct const& self) -> string {
    auto name = self.get_mangled_id();
    auto symbols = self.get_symbols();

    // TODO grammar must implement global variables
    auto var2str = json::stringify<friday::Variable>{};
    auto ovl2str = json::stringify<friday::Overload>{};

    auto sym2str = [&](Pointer<friday::ISymbol> symbol) {
      if(auto asVar = friday::rtti::cast<friday::Variable>(symbol)) 
        return var2str(*asVar);
      else if(auto asOverload = friday::rtti::cast<friday::Overload>(symbol)) 
        return ovl2str(*asOverload);
      else return "null"s;
    };

    return format(
      "{{\"kind\": \"struct\", \"name\": \"{}\", \"symbols\": [{}]}}",
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

