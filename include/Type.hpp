#pragma once
#include <Common.hpp>

namespace friday::inline api::inline typesystem {

  struct Type {
    virtual auto getName() const noexcept -> String const& = 0;
    virtual auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* = 0;
  };
}
