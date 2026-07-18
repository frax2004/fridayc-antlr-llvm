#include <Variable.hpp>
#include <Type.hpp>
#include <NotImplementedError.hpp>
#include <SymbolTable.hpp>

namespace friday::inline api::inline typesystem {
  Variable::Variable(ISymbolTable& declaringScope, string name, Type& type) noexcept {
    this->M_declaringScope = &declaringScope;
    this->M_name = name;
    this->M_type = &type;
  }

  auto Variable::get_qualified_id() const -> string {
    return this->M_name;
  }
  
  auto Variable::get_mangled_name_builder() const -> MangledNameBuilder {
    auto parent = this->get_declaring_symbol_table();
    Pointer<ISymbol> symbol = rtti::cast<ISymbol>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->get_qualified_id());

    return builder;
  }

  auto Variable::get_declaring_symbol_table() const -> Pointer<ISymbolTable> {
    return this->M_declaringScope;
  }

  auto Variable::get_attributes() const -> Attributes {
    throw NotImplementedError{"Variable::get_attributes()"};
  }

  auto Variable::get_type() const -> Pointer<Type> {
    return this->M_type;
  }

  auto Variable::is_variable(Pointer<ISymbol> symbol) -> bool {
    return rtti::instance_of<Variable>(symbol);
  }

  auto Variable::to_variable(Pointer<ISymbol> symbol) -> Pointer<Variable> {
    return rtti::cast<Variable>(symbol);
  }

}