#include <Function.hpp>
#include <SymbolTable.hpp>

namespace friday::inline api::inline typesystem {
  
  Function::Function(Overload& parent, Type& returnType, vector<pair<string, Pointer<Type>>> parameters) {
    this->M_owner = &parent;

    this->M_parameters = parameters 
    | views::transform(&pair<string, Pointer<Type>>::first) 
    | ranges::to<vector>();

    this->M_signature = (Pointer<FunctionType>)FunctionType::get(
      returnType,
      parameters
      | views::transform(&pair<string, Pointer<Type>>::second)
      | ranges::to<vector>()
    );
  }

  auto Function::get_param_name(u64 index) const -> string_view {
    return this->M_parameters.at(index);
  }

  auto Function::get_param(u64 index) const -> pair<string_view, Pointer<Type>> {
    return make_pair(
      this->M_parameters.at(index),
      this->M_signature->get_param_type(index)
    );
  }

  auto Function::get_type() const -> Pointer<Type> {
    return rtti::cast<Type>(this->M_signature);
  }

  auto Function::get_return_type() const -> Pointer<Type> {
    return this->M_signature->get_return_type();
  }

}