#pragma once
#include <Type.hpp>


namespace friday::inline api::inline typesystem {

  struct FRIDAY_API FunctionType final : Type {
    private:
    vector<Pointer<Type>> M_parameters { };
    string                M_name       { "" };
    Pointer<Type>         M_returnType { nullptr };

    private:
    FunctionType(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept;

    public:
    ~FunctionType() override = default;

    public:
    static auto get(Type& returnType, vector<Pointer<Type>> paramsTypes) noexcept -> Pointer<Type>;

    auto get_param_type(u64 index) const -> Pointer<Type>;
    auto get_params_types() const noexcept -> vector<Pointer<Type>> const&;
    auto params_size() const noexcept -> u64;
    auto get_return_type() const noexcept -> Pointer<Type>;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    auto get_name() const noexcept -> string_view override;
  };
}