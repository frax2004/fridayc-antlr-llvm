#pragma once
#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Type : NonCopyable {
    constexpr Type() = default;
    constexpr virtual ~Type() override = default;

    virtual auto get_name() const noexcept -> string_view = 0;
    virtual auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> = 0;
  };
}
