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
    string M_name;
    Pointer<Namespace> M_declaryingNamespace { nullptr };

    public:
    Struct(Namespace& parent, string name) noexcept;
    ~Struct() override = default;

    auto getField(string const& name, weak<Variable> defaultValue = {}) noexcept -> weak<Variable>;
    auto getMethod(string const& name, weak<Overload> defaultValue = {}) noexcept -> weak<Overload>;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getAttributes() const -> Attributes override;
    auto getParent() -> Pointer<ISymbolTable> override;
    auto getDeclaringSymbolTable() -> Pointer<ISymbolTable> override;

    static auto isStruct(Pointer<ISymbol> symbol) -> bool;
    static auto toStruct(Pointer<ISymbol> symbol) -> Pointer<Struct>;

  };
}

template<>
struct FRIDAY_API json::stringify<friday::Struct> {
  auto operator()(friday::Struct const& self) -> string {
    auto name = self.getQualifiedId();
    auto symbols = self.getSymbols();

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

