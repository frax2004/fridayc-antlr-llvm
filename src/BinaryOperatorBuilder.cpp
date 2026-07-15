#include <BinaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {
  BinaryOperatorBuilder::BinaryOperatorBuilder(string name)
    : M_name { name }
  {}

  auto BinaryOperatorBuilder::within(ISymbolTable& parent) -> BinaryOperatorBuilder& {
    this->M_parent = &parent;
    return *this;
  }

  auto BinaryOperatorBuilder::left(Pointer<Type> type) -> BinaryOperatorBuilder& {
    this->M_lhs = type;
    return *this;
  }

  auto BinaryOperatorBuilder::right(Pointer<Type> type) -> BinaryOperatorBuilder& {
    this->M_rhs = type;
    return *this;
  }

  auto BinaryOperatorBuilder::returns(Pointer<Type> type) -> BinaryOperatorBuilder& {
    this->M_ret = type;
    return *this;
  }

  auto BinaryOperatorBuilder::build() -> rc<Overload> {
    rc<Overload> overload = make_shared<Overload>(*this->M_parent, this->M_name);
    overload->add(
      make_shared<Function>(
        *overload, 
        *this->M_ret, 
        vector{
          pair{"lhs"s, this->M_lhs}, 
          pair{"rhs"s, this->M_rhs}
        }
      )
    );

    return overload;
  }

}