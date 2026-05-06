#include "api/typesystem/ArrayType.hpp"


namespace friday::inline api::inline typesystem {
  ArrayType::ArrayType(Type* elementType, u64 length) noexcept
    : M_elementType { elementType }
    , M_length { length }
    , M_name { "[]"s + elementType->getName() }
  {}

  auto ArrayType::get(Type* elementType, u64 length) noexcept -> Type* {

  }

  auto ArrayType::getElementType() const noexcept -> Type* {
    return this->M_elementType;
  }

  auto ArrayType::getLength() const noexcept -> u64 {
    return this->M_length;
  }

  auto ArrayType::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto ArrayType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return llvm::ArrayType::get(this->M_elementType->getLLVMType(ctx), this->M_length);
  }

}