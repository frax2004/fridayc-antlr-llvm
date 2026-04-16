#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a pointer type
  struct PointerType : public Type {
    private:
    /// @brief The pointed type
    Type* M_pointedType;

    /// @brief The pointed type dimensions
    u64 M_dimensions;

    private:
    /// @brief Constructs a pointer type
    /// @param pointedType the pointed type
    /// @param dimensions the dimensions
    PointerType(Type* pointedType, u64 dimensions) noexcept;

    public:
    /// @brief Get the pointed type
    /// @return the pointed type
    auto getPointedType() const noexcept -> Type*;

    /// @brief Get the pointer type dimensions
    /// @return the dimensions
    auto getDimensions() const noexcept -> u64;

    /// @brief Get the internal llvm type
    /// @param ctx the llvm context
    /// @return the internal llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    /// @brief Get the type
    /// @return the type
    auto getType() const noexcept -> Type* override;

    /// @brief Get the `nth` dimensional pointer to a type
    /// @param pointedType the element type
    /// @param dimensions the dimensions
    /// @return the pointer type
    static auto get(Type* pointedType, u64 dimensions) noexcept -> Type*;
  };
}