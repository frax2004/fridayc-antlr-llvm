#include <fridayc.hpp>


namespace friday::inline api {
  auto Variable::Factory::create(ISymbolTable& declaringScope, string name, Type& type) -> Variable* {
    static vector<unique_ptr<Variable>> S_variables { };
    S_variables.push_back(unique_ptr<Variable>(new Variable(declaringScope, name, type)));
    return S_variables.back().get();
  }


  Variable::Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept {
    this->M_declaringScope = &declaringScope;
    this->M_name = name;
    this->M_type = &type;
  }

  auto Variable::get_qualified_id() const -> string {
    return this->M_name;
  }
  
  auto Variable::get_mangled_name_builder() const -> NameMangler {
    auto parent = this->get_declaring_symbol_table();
    ISymbol* symbol = dynamic_cast<ISymbol*>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->get_qualified_id());

    return builder;
  }

  auto Variable::get_declaring_symbol_table() const -> ISymbolTable* {
    return this->M_declaringScope;
  }

  auto Variable::get_attributes() const -> Attributes {
    throw NotImplementedError{};
  }

  auto Variable::get_type() const -> Type* {
    return this->M_type;
  }

  auto Variable::is_variable(ISymbol* symbol) -> bool {
    return dynamic_cast<Variable*>(symbol) != nullptr;
  }

  auto Variable::to_variable(ISymbol* symbol) -> Variable* {
    return dynamic_cast<Variable*>(symbol);
  }

}