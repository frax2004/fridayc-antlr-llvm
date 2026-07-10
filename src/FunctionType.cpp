#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  FunctionType::FunctionType(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept
    : Type { } 
  {
    this->M_name = "{}({})"_f.format(
      returnType.getName(), 
      paramsTypes
      | views::transform(&Type::getName)
      | views::join_with(", "s)
      | ranges::to<string>()
    );

    this->M_returnType = &returnType;

    this->M_parameters = paramsTypes;
  }

  auto FunctionType::getParametersTypes() const noexcept -> vector<Pointer<Type>> const& {
    return this->M_parameters;
  }

  auto FunctionType::getName() const noexcept -> string const& {
    return this->M_name;
  }
  
  auto FunctionType::getParametersCount() const noexcept -> u64 {
    return this->M_parameters.size();
  }

  auto FunctionType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    auto toLLVMType = [&ctx](Pointer<Type> T) -> Pointer<llvm::Type> {
      return T->getLLVMType(ctx);
    };

    auto paramsTypes = this->M_parameters
    | views::transform(toLLVMType)
    | ranges::to<vector>();

    return llvm::FunctionType::get(this->M_returnType->getLLVMType(ctx), paramsTypes, false);
  }

  auto FunctionType::get(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept -> Pointer<Type> {
    static map<string, rc<FunctionType>> S_functionTypes = {};

    rc<FunctionType> functionType { new FunctionType(returnType, move(paramsTypes)) };
    return rtti::cast<Type>(S_functionTypes.try_emplace(functionType->getName(), functionType).first->second.get());
  }

  auto FunctionType::getParameterType(u64 index) const -> Pointer<Type> {
    return this->M_parameters.at(index);
  }

  auto FunctionType::getReturnType() const noexcept -> Pointer<Type> {
    return this->M_returnType;
  }

}