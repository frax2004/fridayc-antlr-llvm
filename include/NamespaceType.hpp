#pragma once

#include <Type.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API NamespaceType final : Type {
    private:
    constexpr NamespaceType() = default;

    public:
    constexpr ~NamespaceType() override = default;

    auto get_name() const noexcept -> string_view override;
    auto to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;
    
    static auto get() -> Pointer<Type>;

    private:
    string M_name { "<type-of-namespaces>" };
  };

}