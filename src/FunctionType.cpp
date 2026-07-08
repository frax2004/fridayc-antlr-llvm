#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  FunctionType::FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept
    : Type { } 
    , M_name { 
        format(
          "{}({})", 
          returnType.getName(), 
          paramsTypes
          | views::transform(&Type::getName)
          | views::join_with(", "s)
          | ranges::to<string>()
        )
      }
    , M_returnType { &returnType }
    , M_parameters { paramsTypes }
  {}

  auto FunctionType::getParametersTypes() const noexcept -> vector<Type*> const& {
    return this->M_parameters;
  }

  auto FunctionType::getName() const noexcept -> string const& {
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
    | views::transform(toLLVMType)
    | ranges::to<vector>();

    return llvm::FunctionType::get(this->M_returnType->getLLVMType(ctx), paramsTypes, false);
  }

  auto FunctionType::get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type* {
    static map<string, FunctionType> S_functionTypes = {};

    FunctionType functionType { returnType, move(paramsTypes) };
    return &S_functionTypes.try_emplace(functionType.getName(), functionType).first->second;
  }

  auto FunctionType::getParameterType(u64 index) const -> Type* {
    return this->M_parameters.at(index);
  }

  auto FunctionType::getReturnType() const noexcept -> Type* {
    return this->M_returnType;
  }

}