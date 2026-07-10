#pragma once
#include <Type.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API FunctionType final : Type {
    private:
    vector<Pointer<Type>> M_parameters;
    string M_name;
    Pointer<Type> M_returnType { nullptr };

    private:
    FunctionType(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept;

    public:
    ~FunctionType() override = default;

    public:
    static auto get(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept -> Pointer<Type>;

    auto getParameterType(u64 index) const -> Pointer<Type>;
    auto getParametersTypes() const noexcept -> vector<Pointer<Type>> const&;
    auto getParametersCount() const noexcept -> u64;
    auto getReturnType() const noexcept -> Pointer<Type>;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    auto getName() const noexcept -> string const& override;
  };
}