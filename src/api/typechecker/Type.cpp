#include "api/typechecker/Type.hpp"


namespace friday::inline api::inline typechecker {

  struct ErrorType : public Type {
    ErrorType() noexcept
      : Type { "<error-type>", VisibilityModifier::PUBLIC }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
      return nullptr;
    }

    auto getType() const noexcept -> Type* {
      // TODO return the "type of types"
      return nullptr;
    }
  };

  Type::Type(String name, VisibilityModifier visibility) noexcept
    : M_name { std::move(name) }
    , M_visibility { visibility }
  {}

  auto Type::getName() const noexcept -> String const& {
    return this->M_name;
  }

  auto Type::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }

  auto Type::getErrorType() -> Type* {
    static ErrorType S_errorTyppe {};
    return &S_errorTyppe;
  }

}