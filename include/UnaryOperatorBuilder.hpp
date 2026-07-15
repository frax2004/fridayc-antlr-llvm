#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API UnaryOperatorBuilder final : Builder<rc<Overload>> {
    private:
    string                M_name   { "" };
    weak<Type>            M_type   { };
    weak<Type>            M_ret    { };
    Pointer<ISymbolTable> M_parent { nullptr };

    public:
    UnaryOperatorBuilder(string name);
    UnaryOperatorBuilder(UnaryOperatorBuilder const&) = default;
    UnaryOperatorBuilder(UnaryOperatorBuilder &&) = default;
    ~UnaryOperatorBuilder() override = default;
    auto operator=(UnaryOperatorBuilder const&) -> UnaryOperatorBuilder& = default;
    auto operator=(UnaryOperatorBuilder &&) -> UnaryOperatorBuilder& = default;

    auto within(ISymbolTable& parent) -> UnaryOperatorBuilder&;
    auto takes(weak<Type> type) -> UnaryOperatorBuilder&;
    auto returns(weak<Type> type) -> UnaryOperatorBuilder&;

    auto build() -> rc<Overload> override;
  };
}