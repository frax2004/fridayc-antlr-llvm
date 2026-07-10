#include <PointerType.hpp>

namespace friday::inline api::inline typesystem {

  PointerType::PointerType(Type& pointedType, u64 dimensions) noexcept {
    this->M_name = "{:*>{}}{}"_f.format("", dimensions, pointedType.getName());
    this->M_pointedType = &pointedType;
    this->M_dimensions = dimensions;
  }

  auto PointerType::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto PointerType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    return llvm::PointerType::get(ctx, 0);
  }

  auto PointerType::getPointedType() const noexcept -> Pointer<Type> {
    return this->M_pointedType;
  }

  auto PointerType::getDimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto PointerType::get(Type& elementType, u64 dimensions) noexcept -> Pointer<Type> {
    static map<string, rc<PointerType>> S_PointerTypes = {};

    rc<PointerType> type {new PointerType(elementType, dimensions)};
    return rtti::cast<Type>(S_PointerTypes.try_emplace(type->getName(), type).first->second.get());
  }

}