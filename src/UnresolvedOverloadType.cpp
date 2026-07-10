#include <UnresolvedOverloadType.hpp>

namespace friday::inline api::inline typesystem {

  auto UnresolvedOverloadType::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto UnresolvedOverloadType::getLLVMType(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto UnresolvedOverloadType::get() -> Pointer<Type> {
    static UnresolvedOverloadType UNRESOLVED_OVERLOAD;
    return rtti::cast<Type>(&UNRESOLVED_OVERLOAD);
  }

}