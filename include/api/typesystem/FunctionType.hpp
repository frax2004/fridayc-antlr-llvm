#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typesystem {

  /// @brief Function type struct
  struct FunctionType : public Type {
    private:
    /// @brief The function return type
    Type* M_returnType;
    /// @brief The function parameters types
    Vector<Type*> M_parameters;
    /// @brief The function name (cached)
    String M_name;

    private:
    /// @brief Create a function type
    /// @param returnType the return type
    /// @param paramsTypes the parameters types
    FunctionType(Type* returnType, Vector<Type*> paramsTypes) noexcept;

    public:
    /// @brief Get the function type
    /// @param returnType the return type
    /// @param paramsTypes the parameters types
    /// @return the function type
    static auto get(Type* returnType, Vector<Type*> paramsTypes) noexcept -> Type*;

    /// @brief Get the parameter type
    /// @param index the index of the parameter
    /// @return the type of the parameter
    auto getParameterType(u64 index) const -> Type*;
    /// @brief Get the parameters types
    /// @return the parameters types
    auto getParametersTypes() const noexcept -> Vector<Type*> const&;
    /// @brief Get the parameters count
    /// @return the parameters count
    auto getParametersCount() const noexcept -> u64;
    /// @brief Get the return type
    /// @return the return type
    auto getReturnType() const noexcept -> Type*;

    /// @brief Get the associated llvm type
    /// @param ctx the context
    /// @return the associated llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    /// @brief Get the type name
    /// @return the type name
    auto getName() const noexcept -> String const& override;
  }; // struct FunctionType
} // namespace friday::api::typesystem