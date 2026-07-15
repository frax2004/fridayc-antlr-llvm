#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API UnaryOperatorBuilder final : Builder<rc<Overload>> {
    private:
    string                M_name   { "" };
    Pointer<Type>         M_type   { nullptr };
    Pointer<Type>         M_ret    { nullptr };
    Pointer<ISymbolTable> M_parent { nullptr };

    public:
    UnaryOperatorBuilder(string name);
    UnaryOperatorBuilder(UnaryOperatorBuilder const&) = default;
    UnaryOperatorBuilder(UnaryOperatorBuilder &&) = default;
    ~UnaryOperatorBuilder() override = default;
    auto operator=(UnaryOperatorBuilder const&) -> UnaryOperatorBuilder& = default;
    auto operator=(UnaryOperatorBuilder &&) -> UnaryOperatorBuilder& = default;

    auto within(ISymbolTable& parent) -> UnaryOperatorBuilder&;
    auto takes(Pointer<Type> type) -> UnaryOperatorBuilder&;
    auto returns(Pointer<Type> type) -> UnaryOperatorBuilder&;

    auto build() -> rc<Overload> override;
  };
}