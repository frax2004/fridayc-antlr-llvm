#pragma once
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {
  
  struct FRIDAY_API Primitive final : Struct {
    public:
    Primitive(Namespace& global, string name, Pointer<llvm::Type> T);
    ~Primitive() override = default;

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> override;

    private:
    string M_name;
    Pointer<llvm::Type> M_type { nullptr };
  };
}