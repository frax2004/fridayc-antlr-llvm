#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API BinaryOperatorBuilder final : Builder<rc<Overload>> {
    private:
    string M_name;
    weak<Type> M_lhs;
    weak<Type> M_rhs;
    weak<Type> M_ret;
    Pointer<ISymbolTable> M_parent;


    public:
    BinaryOperatorBuilder(string name);
    BinaryOperatorBuilder(BinaryOperatorBuilder const&) = default;
    BinaryOperatorBuilder(BinaryOperatorBuilder &&) = default;
    auto operator=(BinaryOperatorBuilder const&) -> BinaryOperatorBuilder& = default;
    auto operator=(BinaryOperatorBuilder &&) -> BinaryOperatorBuilder& = default;
    ~BinaryOperatorBuilder() override = default;

    auto inside(ISymbolTable& parent) -> BinaryOperatorBuilder&;
    auto left(weak<Type> type) -> BinaryOperatorBuilder&;
    auto right(weak<Type> type) -> BinaryOperatorBuilder&;
    auto returns(weak<Type> type) -> BinaryOperatorBuilder&;

    auto build() -> rc<Overload> override;
  };
}