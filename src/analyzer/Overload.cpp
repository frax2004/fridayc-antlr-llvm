#include <fridayc.hpp>


namespace friday::inline api {

  auto Overload::Factory::create(ISymbolTable& parent, string name) -> Overload* {
    static vector<unique_ptr<Overload>> S_overloads { };
    S_overloads.push_back(unique_ptr<Overload>(new Overload(parent, name)));
    return S_overloads.back().get();
  }

  Overload::Overload(ISymbolTable& parent, string name)
    : M_declaringSymbolTable { &parent }
    , M_name { move(name) }
  {}

  auto Overload::get_instances() const -> vector<Function*> {
    return this->M_overloads 
    | views::values
    | ranges::to<vector>();
  }

  auto Overload::add(Type& returnType, vector<pair<string, Type*>> parameters, Attributes attributes) -> Function* {
    auto signature = dynamic_cast<FunctionType*>(
      FunctionType::get(
        returnType, 
        parameters 
        | views::transform(&pair<string, Type*>::second)
        | ranges::to<vector>()
      )
    );

    if(this->M_overloads.contains(signature)) {
      throw InvalidArgumentError{};
    }

    Function* function = Function::Factory::create(*this, returnType, parameters, attributes);

    this->M_overloads.emplace(signature, function);

    return function;
  }

  auto Overload::try_match(vector<Type*> const& argsTypes) -> Function* {
    if(auto it = this->M_overloads.find(argsTypes); it != this->M_overloads.end()) {
      return it->second;
    } else return {};
  }

  auto Overload::has_match(vector<Type*> const& argsTypes) const -> bool {
    return this->M_overloads.contains(argsTypes);
  }

  auto Overload::get_qualified_id() const -> string {
    return this->M_name;
  }
  
  auto Overload::get_mangled_name_builder() const -> NameMangler {
    auto parent = this->get_declaring_symbol_table();
    ISymbol* symbol = dynamic_cast<ISymbol*>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->get_qualified_id());
    return builder;
  }

  auto Overload::get_declaring_symbol_table() const -> ISymbolTable* {
    return this->M_declaringSymbolTable;
  }

  auto Overload::get_attributes() const -> Attributes {
    throw OperationNotSupportedError{};
  }

  auto Overload::get_type() const -> Type* {
    return UnresolvedOverloadType::get();
  }

  auto Overload::is_overload(ISymbol* symbol) -> bool {
    return dynamic_cast<Overload*>(symbol) != nullptr;
  }

  auto Overload::to_overload(ISymbol* symbol) -> Overload* {
    return dynamic_cast<Overload*>(symbol);
  }

}