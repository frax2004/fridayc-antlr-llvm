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

  auto Namespace::find_function(string_view id) -> Overload* {
    ISymbol* candidate = this->retrieve_if(id, &Overload::is_overload);
    return not candidate.expired() ? Overload*{ dynamic_pointer_cast<Overload>(candidate.lock()) } : Overload*{};
  }

  auto Namespace::find_struct(string_view id) -> Struct* {
    ISymbol* candidate = this->retrieve_if(id, &Struct::is_struct);
    return not candidate.expired() ? Struct*{ dynamic_pointer_cast<Struct>(candidate.lock()) } : Struct*{};
  }

  auto Namespace::find_variable(string_view id) -> Variable* {
    ISymbol* candidate = this->retrieve_if(id, &Variable::is_variable);
    return not candidate.expired() ? Variable*{ dynamic_pointer_cast<Variable>(candidate.lock()) } : Variable*{};
  }

  auto Namespace::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Namespace::get_mangled_name_builder() const -> NameMangler {
    return NameMangler { this->get_qualified_id() };
  }


  auto Namespace::get_declaring_symbol_table() const -> ISymbolTable* {
    return this->M_parentNamespace;
  }

  auto Namespace::get_attributes() const -> Attributes {
    throw NotImplementedError{"Namespace::get_attributes()"};
  }

  auto Namespace::get_parent() const -> ISymbolTable* {
    return rtti::cast<ISymbolTable>(this->M_parentNamespace);
  }
  
  auto Namespace::to_namespace(ISymbol* symbol) -> Namespace* {
    return rtti::cast<Namespace>(symbol);
  }

  auto Namespace::is_namespace(ISymbol* symbol) -> bool {
    return rtti::instance_of<Namespace>(symbol);
  }

}