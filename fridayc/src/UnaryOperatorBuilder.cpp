#include <UnaryOperatorBuilder.hpp>

namespace friday::inline api::inline pipeline {
  UnaryOperatorBuilder::UnaryOperatorBuilder(string name)
    : M_name { name }
  {}

  auto UnaryOperatorBuilder::within(ISymbolTable& parent) -> UnaryOperatorBuilder& {
    this->M_parent = &parent;
    return *this;
  }

  auto UnaryOperatorBuilder::takes(Type* type) -> UnaryOperatorBuilder& {
    this->M_type = type;
    return *this;
  }

  auto UnaryOperatorBuilder::returns(Type* type) -> UnaryOperatorBuilder& {
    this->M_ret = type;
    return *this;
  }

  auto UnaryOperatorBuilder::build() -> Overload* {
    Overload* overload = make_shared<Overload>(*this->M_parent, this->M_name);
    overload->add(
      make_shared<Function>(
        *overload, 
        *this->M_ret, 
        vector{ pair{"rhs"s, this->M_type} }
      )
    );

    return overload;
  }

}