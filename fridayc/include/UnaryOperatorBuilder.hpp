#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API UnaryOperatorBuilder final : Builder<Overload*> {
    private:
    string                M_name   { "" };
    Type*         M_type   { nullptr };
    Type*         M_ret    { nullptr };
    ISymbolTable* M_parent { nullptr };

    public:
    UnaryOperatorBuilder(string name);
    UnaryOperatorBuilder(UnaryOperatorBuilder const&) = default;
    UnaryOperatorBuilder(UnaryOperatorBuilder &&) = default;
    ~UnaryOperatorBuilder() override = default;
    auto operator=(UnaryOperatorBuilder const&) -> UnaryOperatorBuilder& = default;
    auto operator=(UnaryOperatorBuilder &&) -> UnaryOperatorBuilder& = default;

    auto within(ISymbolTable& parent) -> UnaryOperatorBuilder&;
    auto takes(Type* type) -> UnaryOperatorBuilder&;
    auto returns(Type* type) -> UnaryOperatorBuilder&;

    auto build() -> Overload* override;
  };
}