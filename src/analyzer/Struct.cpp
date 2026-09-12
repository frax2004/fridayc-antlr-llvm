#include <fridayc.hpp>

namespace friday::inline api {

  auto Struct::Factory::create(Namespace& parent, string name) -> Struct* {
    static vector<unique_ptr<Struct>> S_structs { };
    S_structs.push_back(unique_ptr<Struct>(new Struct(parent, name)));
    return S_structs.back().get();
  }

  Struct::Struct(Namespace& parent, string name) noexcept {
    this->M_declaryingNamespace = &parent;
    this->M_name = name;
  }

  auto Struct::find_field(string_view name) const noexcept -> Variable* {
    ISymbol* candidate = this->retrieve_if(name, &Variable::is_variable);
    return candidate != nullptr ? Variable::to_variable(candidate) : nullptr;
  }

  auto Struct::get_type() const -> Type* {
    return TypeType::get();
  }

  auto Struct::find_method(string_view name) const noexcept -> Overload* {
    ISymbol* candidate = this->retrieve_if(name, &Overload::is_overload);
    return candidate != nullptr ? Overload::to_overload(candidate) : nullptr;
  }

  auto Struct::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto Struct::get_field_index(string const& name) const -> u64 {
    if(auto iter = this->M_fields.find(name); iter != this->M_fields.end()) {
      return iter->second;
    } else return Struct::FIELD_NPOS;
  }

  auto Struct::to_llvm_type() const noexcept -> llvm::Type* {
    string mangled_name = this->get_mangled_id();
    if(auto type = llvm::StructType::getTypeByName(LLVM.context(), mangled_name); type != nullptr) {
      return type;
    }
    auto fields = this->get_symbols()
    | views::filter(&Variable::is_variable)
    | views::transform(&Variable::to_variable)
    | views::transform(&Variable::get_type)
    | views::transform(&Type::to_llvm_type)
    | ranges::to<vector>();

    return LLVM.get_struct_type(this->get_mangled_id(), span{ fields.data(), fields.size() });
  }

  auto Struct::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Struct::get_fields() const -> vector<Variable*> {
    auto name2field = [this](string const& name) { return this->find_field(name); };

    return this->M_fields
    | views::keys
    | views::transform(name2field)
    | ranges::to<vector>();
  }

  auto Struct::add_field(Variable* field) -> void {
    u64 fieldCount = this->M_fields.size();
    this->M_fields.emplace(field->get_qualified_id(), fieldCount);
    this->define(dynamic_cast<ISymbol*>(field));
  }

  auto Struct::get_mangled_name_builder() const -> NameMangler {
    auto parent = this->get_declaring_symbol_table();
    ISymbol* symbol = dynamic_cast<ISymbol*>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->get_qualified_id());

    return builder;
  }

  auto Struct::get_declaring_symbol_table() const -> ISymbolTable* {
    return dynamic_cast<ISymbolTable*>(this->M_declaryingNamespace);
  }

  auto Struct::get_attributes() const -> Attributes {
    throw NotImplementedError{};
  }

  auto Struct::get_parent() const -> ISymbolTable* {
    return dynamic_cast<ISymbolTable*>(this->M_declaryingNamespace);
  }

  auto Struct::is_struct(ISymbol* symbol) -> bool {
    return dynamic_cast<Struct*>(symbol) != nullptr;
  }

  auto Struct::to_struct(ISymbol* symbol) -> Struct* {
    return dynamic_cast<Struct*>(symbol);
  }

  auto Struct::to_struct_type(Type* type) -> Struct* {
    return dynamic_cast<Struct*>(type);
  }

  auto Struct::is_struct_type(Type* type) -> bool {
    return dynamic_cast<Struct*>(type) != nullptr;
  }

}
