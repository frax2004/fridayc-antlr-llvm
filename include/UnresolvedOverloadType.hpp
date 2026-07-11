#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API UnresolvedOverloadType final : Type {
    private:
    constexpr UnresolvedOverloadType() = default;

    public:
    constexpr ~UnresolvedOverloadType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
    static auto get() -> Pointer<Type>;

    private:
    string M_name { "<unresolved-overload-type>" };
  };

}