#include <Primitive.hpp>

namespace friday::inline api::inline typesystem {
  Primitive::Primitive(Namespace& global, string name, llvm::Type* T)
    : Struct { global, move(name) }
    , M_type { T }
  {}

  auto Primitive::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return this->M_type;
  }
}