#include <Struct.hpp>
#include <NotImplementedError.hpp>
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, string name) noexcept {
    this->M_declaryingNamespace = &parent;
    this->M_name = name;
  }

  auto Struct::find_field(string_view name) const noexcept -> Variable* {
    ISymbol* candidate = this->retrieve_if(name, &Variable::is_variable);
    return not candidate.expired() ? Variable*{ dynamic_pointer_cast<Variable>(candidate.lock()) } : Variable*{};
  }

  auto Struct::find_method(string_view name) const noexcept -> Overload* {
    ISymbol* candidate = this->retrieve_if(name, &Overload::is_overload);
    return not candidate.expired() ? Overload*{ dynamic_pointer_cast<Overload>(candidate.lock()) } : Overload*{};
  }

  auto Struct::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto Struct::to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    constexpr auto is_variable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    constexpr auto to_variable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol);
    };

    auto toLLVMType = [&ctx](Type* type) {
      return type->to_llvm_type(ctx);
    };

    return llvm::StructType::get(
      ctx,
      this->get_symbols()
      | views::filter([](ISymbol* ref) { return not ref.expired(); })
      | views::transform([](ISymbol* ref) { return ref.lock().get(); })
      | views::filter(is_variable)
      | views::transform(to_variable)
      | views::transform(&Variable::get_type)
      | views::transform(toLLVMType)
      | ranges::to<vector>()
    );
  }

  auto Struct::get_qualified_id() const -> string {
    return this->M_name;
  }

  auto Struct::get_mangled_name_builder() const -> NameMangler {
    auto parent = this->get_declaring_symbol_table();
    ISymbol* symbol = rtti::cast<ISymbol>(parent);

    auto builder = symbol->get_mangled_name_builder();
    builder.dot(this->get_qualified_id());

    return builder;
  }

  auto Struct::get_declaring_symbol_table() const -> ISymbolTable* {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::get_attributes() const -> Attributes {
    throw NotImplementedError{"Struct::get_attributes()"};
  }

  auto Struct::get_parent() const -> ISymbolTable* {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::is_struct(ISymbol* symbol) -> bool {
    return rtti::instance_of<Struct>(symbol);
  }

  auto Struct::to_struct(ISymbol* symbol) -> Struct* {
    return rtti::cast<Struct>(symbol);
  }

}
