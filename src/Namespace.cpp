#include <Namespace.hpp>
#include <NotImplementedError.hpp>

namespace friday::inline api::inline typesystem {
  Namespace::Namespace(string name)
    : M_name { name }
  {}

  Namespace::Namespace(Namespace& parent, string name)
    : M_parentNamespace{ &parent }
    , M_name { name }
  {}

  auto Namespace::find_function(string_view id) -> weak<Overload> {
    weak<ISymbol> candidate = this->retrieve_if(id, &Overload::is_overload);
    return not candidate.expired() ? weak<Overload>{ dynamic_pointer_cast<Overload>(candidate.lock()) } : weak<Overload>{};
  }

  auto Namespace::find_struct(string_view id) -> weak<Struct> {
    weak<ISymbol> candidate = this->retrieve_if(id, &Struct::is_struct);
    return not candidate.expired() ? weak<Struct>{ dynamic_pointer_cast<Struct>(candidate.lock()) } : weak<Struct>{};
  }

  auto Namespace::find_variable(string_view id) -> weak<Variable> {
    weak<ISymbol> candidate = this->retrieve_if(id, &Variable::is_variable);
    return not candidate.expired() ? weak<Variable>{ dynamic_pointer_cast<Variable>(candidate.lock()) } : weak<Variable>{};
  }

  auto Namespace::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Namespace::get_mangled_name_builder() const -> MangledNameBuilder {
    return MangledNameBuilder { this->get_qualified_id() };
  }


  auto Namespace::get_declaring_symbol_table() const -> Pointer<ISymbolTable> {
    return this->M_parentNamespace;
  }

  auto Namespace::get_attributes() const -> Attributes {
    throw NotImplementedError{"Namespace::get_attributes()"};
  }

  auto Namespace::get_parent() const -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_parentNamespace);
  }
  
  auto Namespace::to_namespace(Pointer<ISymbol> symbol) -> Pointer<Namespace> {
    return rtti::cast<Namespace>(symbol);
  }

  auto Namespace::is_namespace(Pointer<ISymbol> symbol) -> bool {
    return rtti::instance_of<Namespace>(symbol);
  }

}