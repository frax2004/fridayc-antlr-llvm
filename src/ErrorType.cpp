#include <ErrorType.hpp>

namespace friday::inline api::inline typesystem {

  auto ErrorType::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto ErrorType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return nullptr;
  }

}