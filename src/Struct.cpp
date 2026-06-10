#include <Struct.hpp>
#include <NotImplementedError.hpp>

namespace friday::inline api::inline typesystem {

  Struct::Struct(Namespace& parent, string name) noexcept
    : M_declaryingNamespace { &parent }
    , M_name { move(name) }
  {}

  auto Struct::getField(string const& name, Variable* defaultValue) noexcept -> Variable* {
    constexpr auto isVariable = [](ISymbol* symbol) {
      return dynamic_cast<Variable*>(symbol) != nullptr;
    };

    return (Variable*)lookUpIf(name, isVariable, defaultValue);
  }

  auto Struct::getMethod(string const& name, Overload* defaultValue) noexcept -> Overload* {
    constexpr auto isMethod = [](ISymbol* symbol) {
      return dynamic_cast<Overload*>(symbol) != nullptr;
    };

    return (Overload*)lookUpIf(name, isMethod, defaultValue);
  }

  auto Struct::getName() const noexcept -> string const& {
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
      | views::filter(isVariable)
      | views::transform(toVariable)
      | views::transform(Variable::getType)
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

  auto Struct::getDeclaringSymbolTable() -> ISymbolTable* {
    return (ISymbolTable*)this->M_declaryingNamespace;
  }

  auto Struct::getAttributes() const -> Attributes {
    throw NotImplementedError{"Struct::getAttributes()"};
  }

  auto Struct::getParent() -> ISymbolTable* {
    return (ISymbolTable*)this->M_declaryingNamespace;
  }
}
