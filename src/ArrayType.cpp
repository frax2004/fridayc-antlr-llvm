#include <ArrayType.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline typesystem {
  ArrayType::ArrayType(Type& elementType, u64 length) noexcept {
    this->M_elementType = &elementType;
    this->M_length = length;
    this->M_name = "[]{}"_f.format(elementType.get_name());
  }

  auto ArrayType::get(Type& elementType, u64 length) noexcept -> Pointer<Type> {
    static map<string, rc<ArrayType>> S_arrayTypes = {};
    
    rc<ArrayType> T {new ArrayType(elementType, length)};
    return rtti::cast<Type>(
      S_arrayTypes.try_emplace(
        string{ T->get_name() }, 
        T
      )
      .first
      ->second
      .get()
    );
  }

  auto ArrayType::get_element_type() const noexcept -> Pointer<Type> {
    return this->M_elementType;
  }

  auto ArrayType::get_length() const noexcept -> u64 {
    return this->M_length;
  }

  auto ArrayType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto ArrayType::to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    return rtti::cast<llvm::Type>(
      llvm::ArrayType::get(
        this->M_elementType->to_llvm_type(ctx), 
        this->M_length
      )
    );
  }

  auto ArrayType::to_array(Pointer<Type> type) -> Pointer<ArrayType> {
    return rtti::cast<ArrayType>(type);
  }

  auto ArrayType::is_array(Pointer<Type> type) -> bool {
    return rtti::instance_of<ArrayType>(type);
  }

  
}