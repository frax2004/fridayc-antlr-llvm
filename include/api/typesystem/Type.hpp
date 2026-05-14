#pragma once


#include "core/Common.hpp"

namespace friday::inline api::inline typesystem {

  /// @brief Common type interface
  struct Type {
    /// @brief Get the name of the type
    /// @return the name of the type
    virtual auto getName() const noexcept -> String const& = 0;
    /// @brief Get the associated llvm type
    /// @param ctx the context
    /// @return the associated llvm type
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* = 0;

    /// @brief Get the int type
    /// @param ctx the context
    /// @return the int type
    static auto getIntType(llvm::LLVMContext& ctx) -> Type*;
    /// @brief Get the float type
    /// @param ctx the context
    /// @return the float type
    static auto getFloatType(llvm::LLVMContext& ctx) -> Type*;
    /// @brief Get the byte type
    /// @param ctx the context
    /// @return the byte type
    static auto getByteType(llvm::LLVMContext& ctx) -> Type*;
    /// @brief Get the bool type
    /// @param ctx the context
    /// @return the bool type
    static auto getBoolType(llvm::LLVMContext& ctx) -> Type*;
    /// @brief Get the void type
    /// @param ctx the context
    /// @return the void type
    static auto getVoidType(llvm::LLVMContext& ctx) -> Type*;
    /// @brief Get the error type
    /// @param ctx the context
    /// @return the error type
    static auto getErrorType() -> Type*;
  }; // struct Type
} // namespace friday::api::typesystem
