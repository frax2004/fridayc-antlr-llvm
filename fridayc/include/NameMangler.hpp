#pragma once

#include <Common.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline typesystem {

  struct Type;

  struct FRIDAY_API NameMangler final : Builder<string> {
    private:
    vector<string>        M_names     { };
    vector<Type*> M_argsTypes { };

    public:
    NameMangler(string name);
    NameMangler(NameMangler &&) = default;
    NameMangler(NameMangler const&) = default;
    ~NameMangler() override = default;
    auto operator=(NameMangler &&) -> NameMangler& = default;
    auto operator=(NameMangler const&) -> NameMangler& = default;

    auto dot(string name) -> NameMangler&;
    auto param(Type* type) -> NameMangler&;
    auto build() -> string override;
  };
}