#include <fridayc.hpp>


namespace friday::inline api {
  static vector<unique_ptr<Function>> S_functions { };

  auto Function::instances() -> vector<Function*> {
    return S_functions
    | views::transform(&unique_ptr<Function>::get)
    | ranges::to<vector>();
  }

  auto Function::Factory::create(Overload& parent, Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes) -> Function* {
    S_functions.push_back(unique_ptr<Function>(new Function(parent, returnType, parameters, attributes)));
    return S_functions.back().get();
  }

  Function::Function(Overload& parent, Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes) {
    this->M_owner = &parent;
    
    this->M_attributes = attributes;

    this->M_parameters = parameters 
    | views::transform(&pair<string, Type*>::first) 
    | ranges::to<vector>();

    this->M_signature = (FunctionType*)FunctionType::get(
      returnType,
      parameters
      | views::transform(&pair<string, Type*>::second)
      | ranges::to<vector>()
    );
  }

  auto Function::get_param_name(u64 index) const -> string_view {
    return this->M_parameters.at(index);
  }

  auto Function::get_param(u64 index) const -> pair<string_view, Type*> {
    return make_pair(
      this->M_parameters.at(index),
      this->M_signature->get_param_type(index)
    );
  }

  auto Function::get_type() const -> Type* {
    return dynamic_cast<Type*>(this->M_signature);
  }

  auto Function::get_return_type() const -> Type* {
    return this->M_signature->get_return_type();
  }

  auto Function::is_nonstatic_method() const -> bool {
    auto as_struct = dynamic_cast<Struct*>(this->M_owner->get_declaring_symbol_table());
    auto as_type = dynamic_cast<Type*>(as_struct);

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

  auto Function::get_mangled_name_builder() const -> NameMangler {
    auto parent = this->M_owner->get_declaring_symbol_table();
    ISymbol* symbol = dynamic_cast<ISymbol*>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->M_owner->get_qualified_id());

    auto first = this->M_signature->param_begin();
    auto last = this->M_signature->param_end();

    for(auto T : ranges::subrange(first, last)) {
      builder.param(T);
    }

    return builder;
  }

  auto Function::is_static_method() const -> bool {
    return dynamic_cast<Struct*>(this->M_owner->get_declaring_symbol_table()) != nullptr 
    and not this->is_nonstatic_method();
  }

  auto Function::get_qualified_id() const -> string {
    return this->M_owner->get_qualified_id();
  }

  auto Function::get_declaring_symbol_table() const -> ISymbolTable* {
    return this->M_owner->get_declaring_symbol_table();
  }

  auto Function::get_attributes() const -> Attributes {
    return this->M_attributes;
  }


  
}