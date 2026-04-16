#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a struct signature type
  struct StructType : public Type {
    private:
    /// @brief The struct fields
    Vector<Type*> M_fields;

    private:
    /// @brief Construct a struct type
    /// @param fields the struct fields types
    StructType(Vector<Type*> fieldsTypes) noexcept;

    public:
    /// @brief Get the struct type given the return type and the parameters types
    /// @param fieldsTypes the fields types of the struct
    /// @return the struct type
    static auto get(Vector<Type*> fieldsTypes) noexcept -> Type*;

    /// @brief Get the internal llvm type
    /// @param ctx the llvm context
    /// @return the internal llvm type
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    /// @brief Get the type
    /// @return the type
    auto getType() const noexcept -> Type* override;

    /// @brief Gets a struct parameter
    /// @param index the index of the parameter
    /// @return the parameter
    /// @throws `std::out_of_range` error if index is out of bounds
    auto getFieldType(u64 index) const -> Type*;

  }; // struct StructType
} // namespace friday::api::typechecker