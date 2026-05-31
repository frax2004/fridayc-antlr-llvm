#pragma once
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {
  
  struct Primitive : Struct {
    public:
    Primitive(Namespace& global, string name, llvm::Type* T);

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override;

    private:
    string M_name;
    llvm::Type* M_type;
  };
}