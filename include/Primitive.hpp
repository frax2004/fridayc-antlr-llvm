#pragma once
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Primitive final : Struct {
    public:
    Primitive(Namespace& global, string name, llvm::Type* T);
    ~Primitive() override = default;

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    private:
    string M_name;
    llvm::Type* M_type { nullptr };
  };
}