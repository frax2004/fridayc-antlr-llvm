#pragma once

#include "core/Common.hpp"

namespace friday::inline api::inline typesystem {
  
  struct Type {
    virtual auto getName() const noexcept -> String const& = 0;
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* = 0;

    static auto getIntType(llvm::LLVMContext& ctx) -> Type*;
    static auto getFloatType(llvm::LLVMContext& ctx) -> Type*;
    static auto getByteType(llvm::LLVMContext& ctx) -> Type*;
    static auto getBoolType(llvm::LLVMContext& ctx) -> Type*;
    static auto getVoidType(llvm::LLVMContext& ctx) -> Type*;
    static auto getErrorType() -> Type*;
  }; // struct Type
} // namespace friday::api::typesystem
