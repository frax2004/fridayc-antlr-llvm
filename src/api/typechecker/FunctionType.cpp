#include "api/typechecker/FunctionType.hpp"

namespace friday::inline api::inline typechecker {
  FunctionType::FunctionType(Type* returnType, Vector<Type*> paramsTypes) noexcept
    : Type{ 
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
    , M_parameters { std::move(paramsTypes) }
  {}
  
  auto FunctionType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    auto toLLVMType = [&ctx](Type* T) -> llvm::Type* {
      return T->getLLVMType(ctx);
    };

    auto paramsTypes = this->M_parameters
    | std::views::transform(toLLVMType)
    | std::ranges::to<std::vector>();

    return llvm::FunctionType::get(this->M_returnType->getLLVMType(ctx), paramsTypes, false);
  }

  auto FunctionType::getType() const noexcept -> Type* {
    // TODO return the "type of types"
    return nullptr;
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