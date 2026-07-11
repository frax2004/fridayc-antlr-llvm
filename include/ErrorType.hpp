#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ErrorType final : Type {
    private:
    constexpr ErrorType() = default;

    public:
    constexpr ~ErrorType() override = default;

    public:
    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
    static auto get() -> Pointer<Type>;
    static auto is_error_type(Pointer<Type> type) -> bool;


    private:
    string M_name { "<error-type>" };
  };

}