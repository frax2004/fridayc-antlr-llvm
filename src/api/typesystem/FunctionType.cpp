#include "api/typesystem/FunctionType.hpp"

namespace friday::inline api::inline typechecker {
  FunctionType::FunctionType(Type* returnType, Vector<Type*> paramsTypes) noexcept
    : Type { } 
    , M_name { 
        std::format(
          "{}({})", 
          returnType->getName(), 
          paramsTypes
          | std::views::transform(Type::getName)
          | std::views::join_with(", "s)
          | std::ranges::to<std::string>()
        )
      }
    , M_returnType { returnType }
    , M_parameters { paramsTypes }
  {}

  auto FunctionType::getParametersTypes() const noexcept -> Vector<Type*> const& {
    return this->M_parameters;
  }

  auto FunctionType::getName() const noexcept -> String const& {
    return this->M_name;
  }
  
  auto FunctionType::getParametersCount() const noexcept -> u64 {
    return this->M_parameters.size();
  }

  auto FunctionType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    auto toLLVMType = [&ctx](Type* T) -> llvm::Type* {
      return T->getLLVMType(ctx);
    };

    auto paramsTypes = this->M_parameters
    | std::views::transform(toLLVMType)
    | std::ranges::to<std::vector>();

    return llvm::FunctionType::get(this->M_returnType->getLLVMType(ctx), paramsTypes, false);
  }

  auto FunctionType::get(Type* returnType, Vector<Type*> paramsTypes) noexcept -> Type* {
    static Map<String, FunctionType> S_functionTypes = {};

    FunctionType functionType { returnType, std::move(paramsTypes) };
    return &S_functionTypes.try_emplace(functionType.getName(), functionType).first->second;
  }

  auto FunctionType::getParameterType(u64 index) const -> Type* {
    return this->M_parameters.at(index);
  }

  auto FunctionType::getReturnType() const noexcept -> Type* {
    return this->M_returnType;
  }

}