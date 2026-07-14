#include <TypeType.hpp>

namespace friday::inline api::inline typesystem {

  auto TypeType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto TypeType::to_llvm_type(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto TypeType::get() -> Pointer<Type> {
    static TypeType TYPE_TYPE;
    return rtti::cast<Type>(&TYPE_TYPE);
  }

}