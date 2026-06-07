#pragma once
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct ArrayType final : Type {
    private:
    Type* M_elementType { nullptr };
    u64 M_length;
    string M_name;

    private:
    ArrayType(Type& elementType, u64 length) noexcept;

    public:
    static auto get(Type& elementType, u64 length) noexcept -> Type*;

    auto getElementType() const noexcept -> Type*;
    auto getLength() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  };
}

