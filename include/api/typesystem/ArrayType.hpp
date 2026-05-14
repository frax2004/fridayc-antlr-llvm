#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typesystem {
  /// @brief The array type struct
  struct ArrayType : public Type {
    private:
    /// @brief The element type
    Type* M_elementType;
    /// @brief The lenght of the array
    u64 M_length;
    /// @brief The name of the type (cached)
    String M_name;

    private:
    /// @brief Create an array type
    /// @param elementType the element type
    /// @param length the length of the array
    ArrayType(Type* elementType, u64 length) noexcept;

    public:
    /// @brief Get the array type
    /// @param elementType the element type
    /// @param length the length of the array
    /// @return the array type
    static auto get(Type* elementType, u64 length) noexcept -> Type*;

    /// @brief Get the element type
    /// @return the element type
    auto getElementType() const noexcept -> Type*;
    /// @brief Get the length of the array
    /// @return the length of the array
    auto getLength() const noexcept -> u64;
    /// @brief Get the name of the type
    /// @return the name of the type
    auto getName() const noexcept -> String const& override;
    /// @brief Get the associated llvm type
    /// @param ctx the context
    /// @return the associated llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  }; // struct ArrayType
} // namespace friday::api::typesystem