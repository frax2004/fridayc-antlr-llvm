#include <NamespaceType.hpp>

namespace friday::inline api::inline typesystem {

  auto NamespaceType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto NamespaceType::to_llvm_type(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto NamespaceType::get() -> Pointer<Type> {
    static NamespaceType NAMESPACE_TYPE;
    return rtti::cast<Type>(&NAMESPACE_TYPE);
  }

}