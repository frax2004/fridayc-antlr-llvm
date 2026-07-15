#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API BinaryOperatorBuilder final : Builder<rc<Overload>> {
    private:
    string                M_name   { "" };
    Pointer<Type>         M_lhs    { nullptr };
    Pointer<Type>         M_rhs    { nullptr };
    Pointer<Type>         M_ret    { nullptr };
    Pointer<ISymbolTable> M_parent { nullptr };


    public:
    BinaryOperatorBuilder(string name);
    BinaryOperatorBuilder(BinaryOperatorBuilder const&) = default;
    BinaryOperatorBuilder(BinaryOperatorBuilder &&) = default;
    ~BinaryOperatorBuilder() override = default;
    auto operator=(BinaryOperatorBuilder const&) -> BinaryOperatorBuilder& = default;
    auto operator=(BinaryOperatorBuilder &&) -> BinaryOperatorBuilder& = default;

    auto within(ISymbolTable& parent) -> BinaryOperatorBuilder&;
    auto left(Pointer<Type> type) -> BinaryOperatorBuilder&;
    auto right(Pointer<Type> type) -> BinaryOperatorBuilder&;
    auto returns(Pointer<Type> type) -> BinaryOperatorBuilder&;

    auto build() -> rc<Overload> override;
  };
}