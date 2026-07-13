#include <BinaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {
  BinaryOperatorBuilder::BinaryOperatorBuilder(string name)
    : M_name { name }
  {}

  auto BinaryOperatorBuilder::within(ISymbolTable& parent) -> BinaryOperatorBuilder& {
    this->M_parent = &parent;
    return *this;
  }

  auto BinaryOperatorBuilder::left(weak<Type> type) -> BinaryOperatorBuilder& {
    this->M_lhs = type;
    return *this;
  }

  auto BinaryOperatorBuilder::right(weak<Type> type) -> BinaryOperatorBuilder& {
    this->M_rhs = type;
    return *this;
  }

  auto BinaryOperatorBuilder::returns(weak<Type> type) -> BinaryOperatorBuilder& {
    this->M_ret = type;
    return *this;
  }

  auto BinaryOperatorBuilder::build() -> rc<Overload> {
    rc<Overload> overload = make_shared<Overload>(*this->M_parent, this->M_name);
    overload->add(
      make_shared<Function>(
        *overload, 
        *this->M_ret.lock(), 
        vector{
          pair{"lhs"s, this->M_lhs.lock().get()}, 
          pair{"rhs"s, this->M_rhs.lock().get()}
        }
      )
    );

    return overload;
  }

}