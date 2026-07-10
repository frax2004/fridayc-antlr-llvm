#pragma once
#include <Type.hpp>


namespace friday::inline api::inline typesystem {

  struct FunctionType final : Type {
    private:
    vector<Type*> M_parameters;
    string M_name;
    Type* M_returnType { nullptr };

    private:
    FunctionType(Type& returnType, vector<Type*> paramsTypes) noexcept;

    public:
    ~FunctionType() override = default;

    public:
    static auto get(Type& returnType, vector<Type*> paramsTypes) noexcept -> Type*;

    auto getParameterType(u64 index) const -> Type*;
    auto getParametersTypes() const noexcept -> vector<Type*> const&;
    auto getParametersCount() const noexcept -> u64;
    auto getReturnType() const noexcept -> Type*;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    auto getName() const noexcept -> string const& override;
  };
}