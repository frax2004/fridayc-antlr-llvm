#include "api/typechecker/Struct.hpp"

namespace friday::inline api::inline typechecker {

  Struct::Struct(String name, Map<String, Variable> fields, Map<String, Function> methods, VisibilityModifier visibility) noexcept
    : Symbol { }
    , M_fields { std::move(fields) }
    , M_methods { std::move(methods) }
  {
    this->M_signature = (StructType*)StructType::get(
      this->M_fields
      | std::views::values
      | std::views::transform(Variable::getType)
      | std::ranges::to<std::vector>()
    );
  }

  auto Struct::getField(String const& name, const Variable* defaultValue) const noexcept -> const Variable* {
    auto it = this->M_fields.find(name);
    return it != this->M_fields.end() ? &it->second : defaultValue;
  }

  auto Struct::getMethod(String const& name, const Function* defaultValue) const noexcept -> const Function* {
    auto it = this->M_methods.find(name);
    return it != this->M_methods.end() ? &it->second : defaultValue;
  }

  auto Struct::getType() const noexcept -> Type* {
    return this->M_signature;
  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return this->getType()->getLLVMType(ctx);
  }

}
