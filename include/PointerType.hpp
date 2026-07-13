#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {


  struct FRIDAY_API PointerType final : Type {
    private:
    string        M_name        { "" };
    Pointer<Type> M_pointedType { nullptr };
    u64           M_dimensions  { 0 };

    private:
    PointerType(Type& pointedType, u64 dimensions) noexcept;

    public:
    ~PointerType() override = default;

    public:
    static auto get(Type& pointedType, u64 dimensions) noexcept -> Pointer<Type>;

    auto get_pointed_type() const noexcept -> Pointer<Type>;
    auto get_dimensions() const noexcept -> u64;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

    static auto to_pointer(Pointer<Type> type) -> Pointer<PointerType>;
    static auto is_pointer(Pointer<Type> type) -> bool;
  };
}