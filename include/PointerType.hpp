#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {


  struct FRIDAY_API PointerType final : Type {
    private:
    string M_name;
    Pointer<Type> M_pointedType { nullptr };
    u64 M_dimensions;

    private:
    PointerType(Type& pointedType, u64 dimensions) noexcept;

    public:
    ~PointerType() override = default;

    public:
    static auto get(Type& pointedType, u64 dimensions) noexcept -> Pointer<Type>;

    auto getPointedType() const noexcept -> Pointer<Type>;
    auto getDimensions() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
  };
}