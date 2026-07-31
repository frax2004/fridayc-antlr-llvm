#include <FunctionType.hpp>

namespace friday::inline api::inline typesystem {
  FunctionType::FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept
    : Type { } 
  {
    this->M_name = "{}({})"_f.format(
      returnType.get_name(), 
      paramsTypes
      | views::transform(&Type::get_name)
      | views::join_with(", "s)
      | ranges::to<string>()
    );

    this->M_returnType = &returnType;
    this->M_parameters = paramsTypes;
  }

  auto FunctionType::get_params_types() const noexcept -> vector<Type*> const& {
    return this->M_parameters;
  }

  auto FunctionType::get_name() const noexcept -> string_view {
    return this->M_name;
  }
  
  auto FunctionType::params_size() const noexcept -> u64 {
    return this->M_parameters.size();
  }

  auto FunctionType::to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    auto toLLVMType = [&ctx](Type* T) -> Pointer<llvm::Type> {
      return T->to_llvm_type(ctx);
    };

    auto paramsTypes = this->M_parameters
    | views::transform(toLLVMType)
    | ranges::to<vector>();

    return llvm::FunctionType::get(this->M_returnType->to_llvm_type(ctx), paramsTypes, false);
  }

  auto FunctionType::get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type* {
    static map<string, FunctionType*> S_functionTypes = {};

    FunctionType* functionType { new FunctionType(returnType, move(paramsTypes)) };
    return rtti::cast<Type>(
      S_functionTypes.try_emplace(
        string{ functionType->get_name() }, 
        functionType
      )
      .first
      ->second
      .get()
    );
  }

  auto FunctionType::get_param_type(u64 index) const -> Type* {
    return this->M_parameters.at(index);
  }

  auto FunctionType::get_return_type() const noexcept -> Type* {
    return this->M_returnType;
  }

  auto FunctionType::param_begin() const -> vector<Type*>::const_iterator {
    return this->M_parameters.begin();
  }

  auto FunctionType::param_end() const -> vector<Type*>::const_iterator {
    return this->M_parameters.end();
  }

  auto FunctionType::to_function(Type* type) -> FunctionType* {
    return rtti::cast<FunctionType>(type);
  }

  auto FunctionType::is_function(Type* type) -> bool {
    return rtti::instance_of<FunctionType>(type);
  }

}