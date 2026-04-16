#include "api/typechecker/StructType.hpp"

namespace friday::inline api::inline typechecker {
  StructType::StructType(Vector<Type*> fieldsTypes) noexcept
    : Type{ 
        std::format(
          "{{{}}}", 
          fieldsTypes
          | std::views::transform(Type::getName)
          | std::views::join_with(", "s)
          | std::ranges::to<std::string>()
        )
      }
    , M_fields { fieldsTypes }
  {}
  
  auto StructType::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    auto toLLVMType = [&ctx](Type* T) -> llvm::Type* {
      return T->getLLVMType(ctx);
    };

    auto fieldsTypes = this->M_fields
    | std::views::transform(toLLVMType)
    | std::ranges::to<std::vector>();

    return llvm::StructType::get(ctx, fieldsTypes, false);
  }

  auto StructType::getType() const noexcept -> Type* {
    // TODO return the "type of types"
    return nullptr;
  }

  auto StructType::get(Vector<Type*> fieldsTypes) noexcept -> Type* {
    static Map<String, StructType> S_structTypes = {};

    StructType structType { std::move(fieldsTypes) };
    return &S_structTypes.try_emplace(structType.getName(), structType).first->second;
  }

  auto StructType::getFieldType(u64 index) const -> Type* {
    return this->M_fields.at(index);
  }

}