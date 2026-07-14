#include <Struct.hpp>
#include <NotImplementedError.hpp>
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, string name) noexcept {
    this->M_declaryingNamespace = &parent;
    this->M_name = name;
  }

  auto Struct::find_field(string_view name) noexcept -> weak<Variable> {
    weak<ISymbol> candidate = this->retrieve_if(name, &Variable::is_variable);
    return not candidate.expired() ? weak<Variable>{ dynamic_pointer_cast<Variable>(candidate.lock()) } : weak<Variable>{};
  }

  auto Struct::find_method(string_view name) noexcept -> weak<Overload> {
    weak<ISymbol> candidate = this->retrieve_if(name, &Overload::is_overload);
    return not candidate.expired() ? weak<Overload>{ dynamic_pointer_cast<Overload>(candidate.lock()) } : weak<Overload>{};
  }

  auto Struct::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto Struct::to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    constexpr auto is_variable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol) != nullptr;
    };
    
    constexpr auto to_variable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol);
    };

    auto toLLVMType = [&ctx](Pointer<Type> type) {
      return type->to_llvm_type(ctx);
    };

    return llvm::StructType::get(
      ctx,
      this->get_symbols()
      | views::filter([](weak<ISymbol> ref) { return not ref.expired(); })
      | views::transform([](weak<ISymbol> ref) { return ref.lock().get(); })
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

  auto Struct::get_full_qualified_id() const -> string {
    throw NotImplementedError{"Struct::get_full_qualified_id()"};
  }

  auto Struct::get_mangled_id() const -> string {
    throw NotImplementedError{"Struct::get_mangled_id()"};
  }

  auto Struct::get_declaring_symbol_table() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::get_attributes() const -> Attributes {
    throw NotImplementedError{"Struct::get_attributes()"};
  }

  auto Struct::get_parent() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::is_struct(Pointer<ISymbol> symbol) -> bool {
    return rtti::instance_of<Struct>(symbol);
  }

  auto Struct::to_struct(Pointer<ISymbol> symbol) -> Pointer<Struct> {
    return rtti::cast<Struct>(symbol);
  }

}
