#pragma once
#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ArrayType final : Type {
    private:
    string        M_name        { "" };
    Pointer<Type> M_elementType { nullptr };
    u64           M_length      { 0 };

    private:
    ArrayType(Type& elementType, u64 length) noexcept;

    public:
    ~ArrayType() override = default;

    public:
    static auto get(Type& elementType, u64 length) noexcept -> Pointer<Type>;

    auto get_element_type() const noexcept -> Pointer<Type>;
    auto get_length() const noexcept -> u64;
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

    static auto to_array(Pointer<Type> type) -> Pointer<ArrayType>;
    static auto is_array(Pointer<Type> type) -> bool;
  };
}

