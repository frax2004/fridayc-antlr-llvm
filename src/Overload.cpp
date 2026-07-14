#include <Overload.hpp>
#include <NotImplementedError.hpp>
#include <OperationNotSupportedError.hpp>
#include <UnresolvedOverloadType.hpp>


namespace friday::inline api::inline typesystem {

  Overload::Overload(ISymbolTable& parent, string name)
    : M_declaringSymbolTable { &parent }
    , M_name { move(name) }
  {}

  auto Overload::get_functions() const -> vector<weak<Function>> {
    auto toWeak = [](rc<Function> ref) -> weak<Function> { return ref; };

    return this->M_overloads 
    | views::values 
    | views::transform(toWeak)
    | ranges::to<vector>();
  }

  auto Overload::add(rc<Function> function) -> void {
    this->M_overloads.try_emplace(
      FunctionType::to_function(function->get_type()), 
      function
    );
  }

  auto Overload::try_match(vector<Pointer<Type>> const& argsTypes) -> weak<Function> {
    if(auto it = this->M_overloads.find(argsTypes); it != this->M_overloads.end()) {
      return it->second;
    } else return {};
  }

  auto Overload::has_match(vector<Pointer<Type>> const& argsTypes) const -> bool {
    return this->M_overloads.contains(argsTypes);
  }

  auto Overload::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Overload::get_full_qualified_id() const -> string {
    return "{}.{}"_f.format(
      rtti::cast<ISymbol>(this->M_declaringSymbolTable)->get_full_qualified_id(), 
      this->M_name
    );
  }

  auto Overload::get_mangled_id() const -> string {
    throw OperationNotSupportedError{"Overload::get_mangled_id()"};
  }

  auto Overload::get_declaring_symbol_table() -> Pointer<ISymbolTable> {
    return this->M_declaringSymbolTable;
  }

  auto Overload::get_attributes() const -> Attributes {
    throw NotImplementedError{"Overload::get_attributes()"};
  }
  
  auto Overload::get_type() const -> Pointer<Type> {
    return UnresolvedOverloadType::get();
  }

  auto Overload::is_overload(Pointer<ISymbol> symbol) -> bool {
    return rtti::instance_of<Overload>(symbol);
  }

  auto Overload::to_overload(Pointer<ISymbol> symbol) -> Pointer<Overload> {
    return rtti::cast<Overload>(symbol);
  }

  auto Overload::get_name() const noexcept -> string_view {
    static constexpr string_view S_name = "<unresolved-overload-type>"sv;
    return S_name;
  }

}