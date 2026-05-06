#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typesystem {

  struct FunctionType : public Type {
    private:
    Type* M_returnType;
    Vector<Type*> M_parameters;
    String M_name;

    private:
    FunctionType(Type* returnType, Vector<Type*> paramsTypes) noexcept;

    public:
    static auto get(Type* returnType, Vector<Type*> paramsTypes) noexcept -> Type*;

    auto getParameterType(u64 index) const -> Type*;
    auto getParametersTypes() const noexcept -> Vector<Type*> const&;
    auto getParametersCount() const noexcept -> u64;
    auto getReturnType() const noexcept -> Type*;

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    auto getName() const noexcept -> String const& override;
  }; // struct FunctionType
} // namespace friday::api::typesystem