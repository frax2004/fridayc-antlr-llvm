#include <PointerType.hpp>

namespace friday::inline api::inline typesystem {

  PointerType::PointerType(Type& pointedType, u64 dimensions, string name) noexcept {
    this->M_name = name;
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
    static map<string, rc<PointerType>> S_pointerTypes = {};

    if(dimensions > 1) return PointerType::get(*PointerType::get(elementType, dimensions-1), 1);
    
    string name = "{:*>{}}{}"_f.format("", dimensions, elementType.get_name());
    if(S_pointerTypes.contains(name)) return rtti::cast<Type>(S_pointerTypes.at(name).get());
    rc<PointerType> type = S_pointerTypes[name] = rc<PointerType>(new PointerType{elementType, dimensions, name});
    return rtti::cast<Type>(type.get());
  }
  
  auto PointerType::to_pointer(Pointer<Type> type) -> Pointer<PointerType> {
    return rtti::cast<PointerType>(type);
  }

  auto PointerType::is_pointer(Pointer<Type> type) -> bool {
    return rtti::instance_of<PointerType>(type);
  }
}