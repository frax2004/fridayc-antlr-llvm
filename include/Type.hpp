#pragma once
#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API Type : NonCopyable {
    constexpr Type() = default;
    constexpr virtual ~Type() override = default;

    virtual auto getName() const noexcept -> string const& = 0;
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> = 0;
  };
}
