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

  auto Namespace::find_function(string_view id, weak<Overload> defaultValue) -> weak<Overload> {
    constexpr auto is_overload = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Overload>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = look_up_if(id, is_overload, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Overload>(candidate.lock()) : defaultValue;
  }

  auto Namespace::find_struct(string_view id, weak<Struct> defaultValue) -> weak<Struct> {
    constexpr auto is_struct = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Struct>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = look_up_if(id, is_struct, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Struct>(candidate.lock()) : defaultValue;
  }

  auto Namespace::find_variable(string_view id, weak<Variable> defaultValue) -> weak<Variable> {
    constexpr auto is_variable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = look_up_if(id, is_variable, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Variable>(candidate.lock()) : defaultValue;
  }

  auto Namespace::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Namespace::get_full_qualified_id() const -> string {
    throw NotImplementedError{"Namespace::getFullQualifiedId()"};
  }

  auto Namespace::get_mangled_id() const -> string {
    throw NotImplementedError{"Namespace::get_mangled_id()"};
  }

  auto Namespace::get_declaring_symbol_table() -> Pointer<ISymbolTable> {
    return this->M_parentNamespace;
  }

  auto Namespace::get_attributes() const -> Attributes {
    throw NotImplementedError{"Namespace::get_attributes()"};
  }

  auto Namespace::get_parent() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_parentNamespace);
  }  
}