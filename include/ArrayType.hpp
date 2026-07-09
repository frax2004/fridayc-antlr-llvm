#pragma once
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct ArrayType final : Type {
    private:
    string M_name        { "" };
    Type*  M_elementType { nullptr };
    u64    M_length      { 0 };

    private:
    ArrayType(Type& elementType, u64 length) noexcept;
    ~ArrayType() override = default;

    public:
    static auto get(Type& elementType, u64 length) noexcept -> Type*;

    auto getElementType() const noexcept -> Type*;
    auto getLength() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  };
}

