#include <UnresolvedOverloadType.hpp>

namespace friday::inline api::inline typesystem {

  auto UnresolvedOverloadType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto UnresolvedOverloadType::to_llvm_type(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto UnresolvedOverloadType::get() -> Pointer<Type> {
    static UnresolvedOverloadType UNRESOLVED_OVERLOAD;
    return rtti::cast<Type>(&UNRESOLVED_OVERLOAD);
  }

}