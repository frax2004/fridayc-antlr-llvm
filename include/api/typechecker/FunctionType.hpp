#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a function signature type
  struct FunctionType : public Type {
    private:
    /// @brief The function return type
    Type* M_returnType;
    /// @brief The function parameters
    Vector<Type*> M_parameters;
    /// @brief The function type name
    String M_name;

    private:
    /// @brief Construct a function type
    /// @param returnType the function return type
    /// @param paramsTypes the function parameters types
    FunctionType(Type* returnType, Vector<Type*> paramsTypes) noexcept;

    public:
    /// @brief Get the function type given the return type and the parameters types
    /// @param returnType the return type of the function
    /// @param paramsTypes the parameters types of the function
    /// @return the function type
    static auto get(Type* returnType, Vector<Type*> paramsTypes) noexcept -> Type*;

    /// @brief Get the internal llvm type
    /// @param ctx the llvm context
    /// @return the internal llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    /// @brief Gets a function parameter
    /// @param index the index of the parameter
    /// @return the parameter
    /// @throws `std::out_of_range` error if index is out of bounds
    auto getParameterType(u64 index) const -> Type*;

    /// @brief Gets the parameters types
    /// @return the parameters types
    auto getParametersTypes() const noexcept -> Vector<Type*> const&;

    /// @brief Get the number of parameters
    /// @return the parameters count
    auto getParametersCount() const noexcept -> u64;

    /// @brief Gets the function type name
    /// @return the type name
    auto getName() const noexcept -> String const& override;

    /// @brief Get the function return type
    /// @return the return type
    auto getReturnType() const noexcept -> Type*;
  }; // struct FunctionType
} // namespace friday::api::typechecker