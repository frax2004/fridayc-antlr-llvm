#include "api/typechecker/Function.hpp"

namespace friday::inline api::inline typechecker {
  
  Function::Function(String name, Type* returnType, Vector<std::pair<String, Type*>> parameters, VisibilityModifier visibility)
    : M_name { std::move(name) }
    , M_visibility { visibility }
    , M_parameters { 
      parameters 
      | std::views::transform(&std::pair<String, Type*>::first) 
      | std::ranges::to<std::vector>()
    }
  {
    this->M_signature = (FunctionType*)FunctionType::get(
      returnType,
      parameters
      | std::views::transform(&std::pair<String, Type*>::second)
      | std::ranges::to<std::vector>()
    );
  }

  auto Function::getParameterName(u64 index) const -> String const& {
    return this->M_parameters.at(index);
  }

  auto Function::getNativeBody() const noexcept -> const llvm::Function* {
    return this->M_body;
  }

  auto Function::setNativeBody(llvm::Function* body) noexcept -> void {
    this->M_body = body;
  }

  auto Function::getParameter(u64 index) const -> std::pair<String, Type*> {
    return std::make_pair(
      this->M_parameters.at(index),
      this->M_signature->getParameterType(index)
    );
  }

  auto Function::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }

  auto Function::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Function::getType() const noexcept -> Type* {
    return this->M_signature;
  }

}