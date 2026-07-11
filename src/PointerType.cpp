#include <PointerType.hpp>

namespace friday::inline api::inline typesystem {

  PointerType::PointerType(Type& pointedType, u64 dimensions) noexcept {
    this->M_name = "{:*>{}}{}"_f.format("", dimensions, pointedType.get_name());
    this->M_pointedType = &pointedType;
    this->M_dimensions = dimensions;
  }

  auto PointerType::get_name() const noexcept -> string_view {
    return this->M_name;
  }

  auto PointerType::to_llvm_type(llvm::LLVMContext& ctx) const noexcept -> Pointer<llvm::Type> {
    return llvm::PointerType::get(ctx, 0);
  }

  auto PointerType::get_pointed_type() const noexcept -> Pointer<Type> {
    return this->M_pointedType;
  }

  auto PointerType::get_dimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto PointerType::get(Type& elementType, u64 dimensions) noexcept -> Pointer<Type> {
    static map<string, rc<PointerType>> S_PointerTypes = {};

    rc<PointerType> type {new PointerType(elementType, dimensions)};
    return rtti::cast<Type>(
      S_PointerTypes.try_emplace(
        string{ type->get_name() }, 
        type
      )
      .first
      ->second
      .get()
    );
  }

}