#include <PointerType.hpp>

namespace friday::inline api::inline typesystem {

  PointerType::PointerType(Type& pointedType, u64 dimensions) noexcept
    : M_name { format("{:*>{}}{}", "", dimensions, pointedType.getName()) }
    , M_pointedType { &pointedType }
    , M_dimensions { dimensions }
  {}

  auto PointerType::getName() const noexcept -> string const& {
    return this->M_name;
  }

  auto PointerType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return llvm::PointerType::get(ctx, 0);
  }

  auto PointerType::getPointedType() const noexcept -> Type* {
    return this->M_pointedType;
  }

  auto PointerType::getDimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto PointerType::get(Type& elementType, u64 dimensions) noexcept -> Type* {
    static map<string, PointerType> S_PointerTypes = {};

    Type* elementTypeRef = &elementType;

    if(auto asPointer = dynamic_cast<PointerType*>(elementTypeRef)) {
      elementTypeRef = asPointer->getPointedType();
      dimensions += asPointer->getDimensions();
    }

    PointerType type { *elementTypeRef, dimensions };
    return &S_PointerTypes.try_emplace(type.getName(), type).first->second;
  }

}