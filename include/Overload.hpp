#pragma once
#include <Symbol.hpp>
#include <Function.hpp>
#include <SymbolTable.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Overload final : ISymbol, TypedEntity, Type {
    private:
    Pointer<ISymbolTable>                              M_declaringSymbolTable { nullptr };
    string                                             M_name                 { "" };
    unordered_map<vector<Pointer<Type>>, rc<Function>> M_overloads            { };

    public:
    Overload(ISymbolTable& parent, string name);
    ~Overload() override = default;

    auto get_functions() const -> vector<weak<Function>>;
    auto add(vector<Pointer<Type>> argsTypes, rc<Function> function) -> void;
    auto try_match(vector<Pointer<Type>> const& argsTypes) -> weak<Function>;
    auto has_match(vector<Pointer<Type>> const& argsTypes) const -> bool;

    auto get_qualified_id() const -> string override;
    auto get_full_qualified_id() const -> string override;
    auto get_mangled_id() const -> string override;
    auto get_declaring_symbol_table() -> Pointer<ISymbolTable> override;
    auto get_attributes() const -> Attributes override;
    auto get_type() const -> Pointer<Type> override;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

    static auto is_overload(Pointer<ISymbol> symbol) -> bool;
    static auto to_overload(Pointer<ISymbol> symbol) -> Pointer<Overload>;
  };
}

template<>
struct FRIDAY_API json::stringify<friday::Overload> {
  auto operator()(friday::Overload const& self) -> string {
    return format("{{\"kind\": \"overload\", \"name\": \"{}\", \"signatures\": [{}]}}", 
      self.get_qualified_id(),
      self.get_functions()
      | views::filter([](weak<friday::Function> ref) { return not ref.expired(); })
      | views::transform([](weak<friday::Function> ref) { return ref.lock().get(); })
      | views::transform([](Pointer<friday::Function> func) {
        return format(
          "\"{}\"", 
          func->get_type()->get_name()
        );
      })
      | views::join_with(", "s)
      | ranges::to<string>()
    );
  }
};
