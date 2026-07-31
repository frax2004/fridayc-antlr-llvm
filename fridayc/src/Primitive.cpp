#include <Primitive.hpp>

namespace friday::inline api::inline typesystem {
  PrimitiveType::PrimitiveType(Namespace& global, string name, Pointer<llvm::Type> T)
    : Struct { global, move(name) }
    , M_type { T }
  {}

  auto PrimitiveType::to_llvm_type(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return this->M_type;
  }
}