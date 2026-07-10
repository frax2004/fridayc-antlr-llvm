#pragma once
#include <Symbol.hpp>
#include <Function.hpp>
#include <SymbolTable.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Overload final : ISymbol, TypedEntity, Type {
    private:
    Pointer<ISymbolTable> M_declaringSymbolTable { nullptr };
    string M_name;
    unordered_map<vector<Pointer<Type>>, rc<Function>> M_overloads;

    public:
    Overload(ISymbolTable& parent, string name);
    ~Overload() override = default;

    auto getFunctions() const -> vector<weak<Function>>;
    auto add(vector<Pointer<Type>> argsTypes, rc<Function> function) -> void;
    auto tryMatch(vector<Pointer<Type>> const& argsTypes) -> weak<Function>;
    auto hasMatch(vector<Pointer<Type>> const& argsTypes) const -> bool;

    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> Pointer<ISymbolTable> override;
    auto getAttributes() const -> Attributes override;
    auto getType() const -> Pointer<Type> override;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

    static auto isOverload(Pointer<ISymbol> symbol) -> bool;
    static auto toOverload(Pointer<ISymbol> symbol) -> Pointer<Overload>;
  };
}

template<>
struct FRIDAY_API json::stringify<friday::Overload> {
  auto operator()(friday::Overload const& self) -> string {
    return format("{{\"kind\": \"overload\", \"name\": \"{}\", \"signatures\": [{}]}}", 
      self.getQualifiedId(),
      self.getFunctions()
      | views::filter([](weak<friday::Function> ref) { return not ref.expired(); })
      | views::transform([](weak<friday::Function> ref) { return ref.lock().get(); })
      | views::transform([](Pointer<friday::Function> func) {
        return format(
          "\"{}\"", 
          func->getType()->getName()
        );
      })
      | views::join_with(", "s)
      | ranges::to<string>()
    );
  }
};
