#pragma once
#include <Symbol.hpp>
#include <Function.hpp>
#include <SymbolTable.hpp>
#include <Json.hpp>


namespace friday::inline api::inline typesystem {


  struct Overload final : ISymbol {
    private:
    ISymbolTable* M_declaringSymbolTable { nullptr };
    string M_name;
    unordered_map<vector<Type*>, Function*> M_overloads;

    public:
    Overload(ISymbolTable& parent, string name);

    auto getFunctions() const -> vector<Function*>;
    auto add(vector<Type*> argsTypes, Function* function) -> void;
    auto tryMatch(vector<Type*> const& argsTypes) -> Function*;
    auto hasMatch(vector<Type*> const& argsTypes) const -> bool;

    auto getQualifiedId() const -> string override;
    auto getFullQualifiedId() const -> string override;
    auto getMangledId() const -> string override;
    auto getDeclaringSymbolTable() -> ISymbolTable* override;
    auto getAttributes() const -> Attributes override;
  };
}

template<>
struct json::stringify<friday::Overload> {
  auto operator()(friday::Overload const& self) -> string {
    return format("{{\"kind\": \"overload\", \"name\": \"{}\", \"signatures\": [{}]}}", 
      self.getQualifiedId(),
      self.getFunctions()
      | views::transform([](friday::Function* func) {
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
