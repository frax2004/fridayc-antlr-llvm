#include <UnaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {
  UnaryOperatorBuilder::UnaryOperatorBuilder(string name)
    : M_name { name }
  {}

  auto UnaryOperatorBuilder::within(ISymbolTable& parent) -> UnaryOperatorBuilder& {
    this->M_parent = &parent;
    return *this;
  }

  auto UnaryOperatorBuilder::takes(weak<Type> type) -> UnaryOperatorBuilder& {
    this->M_type = type;
    return *this;
  }

  auto UnaryOperatorBuilder::returns(weak<Type> type) -> UnaryOperatorBuilder& {
    this->M_ret = type;
    return *this;
  }

  auto UnaryOperatorBuilder::build() -> rc<Overload> {
    rc<Overload> overload = make_shared<Overload>(*this->M_parent, this->M_name);
    overload->add(
      make_shared<Function>(
        *overload, 
        *this->M_ret.lock(), 
        vector{ pair{"rhs"s, this->M_type.lock().get()} }
      )
    );

    return overload;
  }

}