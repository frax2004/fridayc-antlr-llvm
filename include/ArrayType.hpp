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

    auto getElementType() const noexcept -> Pointer<Type>;
    auto getLength() const noexcept -> u64;
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
  };
}

