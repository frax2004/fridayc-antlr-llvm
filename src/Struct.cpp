#include <Struct.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, String name) noexcept
    : M_declaryingNamespace { &parent }
    , M_name { std::move(name) }
  {}

  auto Struct::getField(String const& name, Variable* defaultValue) noexcept -> Variable* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    return (Variable*)lookUpIf(name, isVariable, defaultValue);
  }

  auto Struct::getMethod(String const& name, Overload* defaultValue) noexcept -> Overload* {
    constexpr auto isMethod = [](ISymbol* symbol) {
      return dynamic_cast<Overload*>(symbol) != nullptr;
    };

    return (Overload*)lookUpIf(name, isMethod, defaultValue);
  }

  auto Struct::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };
    
    constexpr auto toVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol);
    };

    auto toLLVMType = [&ctx](Type* type) {
      return type->getLLVMType(ctx);
    };

    return llvm::StructType::get(
      ctx,
      this->getSymbols()
      | std::views::filter(isVariable)
      | std::views::transform(toVariable)
      | std::views::transform(Variable::getType)
      | std::views::transform(toLLVMType)
      | std::ranges::to<std::vector>()
    );
  }

  auto Struct::getQualifiedId() const -> String {
    return this->M_name;
  }

  auto Struct::getFullQualifiedId() const -> String {

  }

  auto Struct::getMangledId() const -> String {

  }

  auto Struct::getDeclaringSymbolTable() -> ISymbolTable* {
    return (ISymbolTable*)this->M_declaryingNamespace;
  }

  auto Struct::getAttributes() const -> Attributes {
    return {};
  }

  auto Struct::getParent() -> ISymbolTable* {
    return (ISymbolTable*)this->M_declaryingNamespace;
  }
}
