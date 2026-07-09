#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {


  struct PointerType final : Type {
    private:
    string M_name;
    Type* M_pointedType { nullptr };
    u64 M_dimensions;

    private:
    PointerType(Type& pointedType, u64 dimensions) noexcept;
    ~PointerType() override = default;

    public:
    static auto get(Type& pointedType, u64 dimensions) noexcept -> Type*;

    auto getPointedType() const noexcept -> Type*;
    auto getDimensions() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
  };
}