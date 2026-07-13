#include <Function.hpp>
#include <SymbolTable.hpp>
#include <Overload.hpp>
#include <Struct.hpp>
#include <PointerType.hpp>

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

  auto Function::is_nonstatic_method() const -> bool {
    auto as_struct = rtti::cast<Struct>(this->M_owner->get_declaring_symbol_table());
    auto as_type = rtti::cast<Type>(as_struct);

    return 
    // parent is a struct
    as_struct != nullptr
    // method has at least 1 param
    and this->M_signature->params_size() > 0
    // first param is a pointer type
    and PointerType::is_pointer(this->M_signature->get_param_type(0))
    // the pointed type is the struct
    and PointerType::to_pointer(this->M_signature->get_param_type(0))->get_pointed_type() == as_type;


  }

  auto Function::is_static_method() const -> bool {
    return rtti::instance_of<Struct>(this->M_owner->get_declaring_symbol_table()) 
    and not this->is_nonstatic_method();
  }

  
}