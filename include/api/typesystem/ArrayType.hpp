#pragma once

#include "Type.hpp"

namespace friday::inline api::inline typesystem {

  struct ArrayType : public Type {
    private:
    Type* M_elementType;
    u64 M_length;
    String M_name;

    private:
    ArrayType(Type* elementType, u64 length) noexcept;

    public:
    static auto get(Type* elementType, u64 length) noexcept -> Type*;

    auto getElementType() const noexcept -> Type*;
    auto getLength() const noexcept -> u64;

    auto getName() const noexcept -> String const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  }; // struct ArrayType
} // namespace friday::api::typesystem