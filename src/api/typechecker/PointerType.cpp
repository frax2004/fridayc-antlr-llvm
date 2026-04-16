#include "api/typechecker/PointerType.hpp"

namespace friday::inline api::inline typechecker {

  PointerType::PointerType(Type* pointedType, u64 dimensions) noexcept
    : Type { std::format("{:*>{}}{}", "", dimensions, pointedType->getName()) }
    , M_pointedType { pointedType }
    , M_dimensions { dimensions }
  {}

  auto PointerType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return llvm::PointerType::get(ctx, 0);
  }

  auto PointerType::getType() const noexcept -> Type* {
    // TODO return the "type of types"
    return nullptr;
  }

  auto PointerType::getPointedType() const noexcept -> Type* {
    return this->M_pointedType;
  }

  auto PointerType::getDimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto PointerType::get(Type* elementType, u64 dimensions) noexcept -> Type* {
    static Map<String, PointerType> S_pointerTypes = {};

    PointerType pointerType { elementType, dimensions };
    return &S_pointerTypes.try_emplace(pointerType.getName(), pointerType).first->second;
  }

}