#pragma once

#include "Common.hpp"

namespace friday::inline api {

  struct Type;

  struct NameMangler final : Builder<string> {
  private:
    vector<string> M_names     { };
    vector<Type*>  M_argsTypes { };

  public:
    NameMangler(string name);
    NameMangler(NameMangler &&) = default;
    NameMangler(NameMangler const&) = default;
    ~NameMangler() override = default;
    auto operator=(NameMangler &&) -> NameMangler& = default;
    auto operator=(NameMangler const&) -> NameMangler& = default;

  public:
    auto dot(string name) -> NameMangler&;
    auto param(Type* type) -> NameMangler&;
    auto build() -> string override;
  };
}