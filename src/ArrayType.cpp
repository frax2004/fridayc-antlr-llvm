#include <ArrayType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline typesystem {
  ArrayType::ArrayType(Type& elementType, u64 length) noexcept {
    this->M_elementType = &elementType;
    this->M_length = length;
    this->M_name = "[]{}"_f.format(elementType.getName());
  }

  auto ArrayType::get(Type& elementType, u64 length) noexcept -> Pointer<Type> {
    static map<string, rc<ArrayType>> S_arrayTypes = {};
    
    rc<ArrayType> T {new ArrayType(elementType, length)};
    return rtti::cast<Type>(S_arrayTypes.try_emplace(T->getName(), T).first->second.get());
  }

  auto ArrayType::getElementType() const noexcept -> Pointer<Type> {
    return this->M_elementType;
  }

  auto ArrayType::getLength() const noexcept -> u64 {
    return this->M_length;
  }

  auto ArrayType::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto ArrayType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    return rtti::cast<llvm::Type>(
      llvm::ArrayType::get(
        this->M_elementType->getLLVMType(ctx), 
        this->M_length
      )
    );
  }

}