#include <Struct.hpp>
#include <NotImplementedError.hpp>
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, string name) noexcept {
    this->M_declaryingNamespace = &parent;
    this->M_name = name;
  }

  auto Struct::getField(string const& name, weak<Variable> defaultValue) noexcept -> weak<Variable> {
    constexpr auto isVariable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(name, isVariable, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Variable>(candidate.lock()) : defaultValue;
  }

  auto Struct::getMethod(string const& name, weak<Overload> defaultValue) noexcept -> weak<Overload> {
    constexpr auto isMethod = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Overload>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = lookUpIf(name, isMethod, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Overload>(candidate.lock()) : defaultValue;
  }

  auto Struct::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    constexpr auto isVariable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol) != nullptr;
    };
    
    constexpr auto toVariable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol);
    };

    auto toLLVMType = [&ctx](Pointer<Type> type) {
      return type->getLLVMType(ctx);
    };

    return llvm::StructType::get(
      ctx,
      this->getSymbols()
      | views::filter([](weak<ISymbol> ref) { return not ref.expired(); })
      | views::transform([](weak<ISymbol> ref) { return ref.lock().get(); })
      | views::filter(isVariable)
      | views::transform(toVariable)
      | views::transform(&Variable::getType)
      | views::transform(toLLVMType)
      | ranges::to<vector>()
    );
  }

  auto Struct::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Struct::getFullQualifiedId() const -> string {
    throw NotImplementedError{"Struct::getFullQualifiedId()"};
  }

  auto Struct::getMangledId() const -> string {
    throw NotImplementedError{"Struct::getMangledId()"};
  }

  auto Struct::getDeclaringSymbolTable() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::getAttributes() const -> Attributes {
    throw NotImplementedError{"Struct::getAttributes()"};
  }

  auto Struct::getParent() -> Pointer<ISymbolTable> {
    return rtti::cast<ISymbolTable>(this->M_declaryingNamespace);
  }

  auto Struct::isStruct(Pointer<ISymbol> symbol) -> bool {
    return rtti::instanceOf<Struct>(symbol);
  }

  auto Struct::toStruct(Pointer<ISymbol> symbol) -> Pointer<Struct> {
    return rtti::cast<Struct>(symbol);
  }

}
