#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ErrorType final : Type {
    private:
    constexpr ErrorType() = default;

    public:
    constexpr ~ErrorType() override = default;

    public:
    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
    static auto get() -> Pointer<Type>;

    private:
    string M_name = "<error-type>"s;
  };

}