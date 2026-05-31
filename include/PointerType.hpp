#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {


  struct PointerType final : public Type {
    private:
    Type* M_pointedType;
    string M_name;
    u64 M_dimensions;

    private:
    PointerType(Type& pointedType, u64 dimensions) noexcept;

    public:
    static auto get(Type& pointedType, u64 dimensions) noexcept -> Type*;

    auto getPointedType() const noexcept -> Type*;
    auto getDimensions() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  };
}