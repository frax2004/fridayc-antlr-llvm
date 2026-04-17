#include "api/typechecker/Pointer.hpp"

namespace friday::inline api::inline typechecker {

  Pointer::Pointer(Type* pointedType, u64 dimensions) noexcept
    : Type { }
    , M_name { std::format("{:*>{}}{}", "", dimensions, pointedType->getName()) }
    , M_pointedType { pointedType }
    , M_dimensions { dimensions }
  {}

  auto Pointer::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Pointer::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return llvm::PointerType::get(ctx, 0);
  }

  auto Pointer::getPointedType() const noexcept -> Type* {
    return this->M_pointedType;
  }

  auto Pointer::getDimensions() const noexcept -> u64 {
    return this->M_dimensions;
  }

  auto Pointer::get(Type* elementType, u64 dimensions) noexcept -> Type* {
    static Map<String, Pointer> S_Pointers = {};

    if(auto pointer = elementType->as<Pointer>()) {
      elementType = pointer->getPointedType();
      dimensions += pointer->getDimensions();
    }
  
    Pointer pointer { elementType, dimensions };
    return &S_Pointers.try_emplace(pointer.getName(), pointer).first->second;
  }

}