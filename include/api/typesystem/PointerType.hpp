#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typesystem {

  /// @brief Pointer type struct
  struct PointerType : public Type {
    private:
    /// @brief The pointed type
    Type* M_pointedType;
    /// @brief The name of the type (cached)
    String M_name;
    /// @brief The dimensions of the pointer type
    u64 M_dimensions;

    private:
    /// @brief Create a pointer type
    /// @param pointedType the pointed type
    /// @param dimensions the dimensions
    PointerType(Type* pointedType, u64 dimensions) noexcept;

    public:
    /// @brief Get the pointer type
    /// @param pointedType the pointed type
    /// @param dimensions the dimensions
    /// @return the pointer type
    static auto get(Type* pointedType, u64 dimensions) noexcept -> Type*;

    /// @brief Get the pointed type
    /// @return the pointed type
    auto getPointedType() const noexcept -> Type*;
    /// @brief Get the dimensions
    /// @return the dimensions
    auto getDimensions() const noexcept -> u64;

    /// @brief Get the name of the type
    /// @return the name of the type
    auto getName() const noexcept -> String const& override;
    /// @brief Get the associated llvm type
    /// @param ctx the context
    /// @return the associated llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  }; // struct PointerType
} // namespace friday::api::typesystem