#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct UnresolvedOverloadType final : Type {
    private:
    constexpr UnresolvedOverloadType() = default;

    public:
    constexpr ~UnresolvedOverloadType() override = default;

    auto getName() const noexcept -> string const& override;
    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;
    
    static auto get() -> Type*;

    private:
    string M_name = "<unresolved-overload-type>"s;
  };

}