#include <ErrorType.hpp>

namespace friday::inline api::inline typesystem {

  auto ErrorType::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto ErrorType::getLLVMType(llvm::LLVMContext& _) const noexcept -> Pointer<llvm::Type> {
    (void)_;
    return nullptr;
  }
  
  auto ErrorType::get() -> Pointer<Type> {
    static ErrorType ERROR;
    return rtti::cast<Type>(&ERROR);
  }

}