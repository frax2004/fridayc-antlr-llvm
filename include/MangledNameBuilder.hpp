#pragma once

#include <Common.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline typesystem {

  struct Type;

  struct FRIDAY_API MangledNameBuilder final : Builder<string> {
    private:
    vector<string>        M_names     { };
    vector<Pointer<Type>> M_argsTypes { };

    public:
    MangledNameBuilder(string name);
    MangledNameBuilder(MangledNameBuilder &&) = default;
    MangledNameBuilder(MangledNameBuilder const&) = default;
    ~MangledNameBuilder() override = default;
    auto operator=(MangledNameBuilder &&) -> MangledNameBuilder& = default;
    auto operator=(MangledNameBuilder const&) -> MangledNameBuilder& = default;

    auto dot(string name) -> MangledNameBuilder&;
    auto param(Pointer<Type> type) -> MangledNameBuilder&;
    auto build() -> string override;
  };
}