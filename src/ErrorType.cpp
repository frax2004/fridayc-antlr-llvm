#include <ErrorType.hpp>

namespace friday::inline api::inline typesystem {

  auto ErrorType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto ErrorType::to_llvm_type(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto ErrorType::get() -> Pointer<Type> {
    static ErrorType ERROR;
    return rtti::cast<Type>(&ERROR);
  }

}