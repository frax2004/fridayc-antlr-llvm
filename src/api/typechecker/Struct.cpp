#include "api/typechecker/Struct.hpp"

namespace friday::inline api::inline typechecker {

  struct ErrorType : public Struct {
    ErrorType() noexcept
      : Struct { "<error-type>" }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override {
      return nullptr;
    }

    auto getType() const noexcept -> Type* override {
      // TODO return the "type of types"
      return nullptr;
    }
  };


  struct Primitive : public Struct {

    Primitive(String name, llvm::Type* T)
      : Struct { std::move(name) }
      , M_type { T }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override {
      return this->M_type;
    }

    private:
    llvm::Type* M_type;
  };

  Struct::Struct(String name, Map<String, Variable> fields, Map<String, Function> methods, VisibilityModifier visibility) noexcept
    : Symbol { }
    , M_fields { std::move(fields) }
    , M_methods { std::move(methods) }
    , M_visibility { visibility }
  {
    this->M_signature = (StructType*)StructType::get(
      this->M_fields
      | std::views::values
      | std::views::transform(Variable::getType)
      | std::ranges::to<std::vector>()
    );
  }

  auto Struct::getVisibility() const noexcept -> VisibilityModifier {
    return this->M_visibility;
  }

  auto Struct::getField(String const& name, const Variable* defaultValue) const noexcept -> const Variable* {
    auto it = this->M_fields.find(name);
    return it != this->M_fields.end() ? &it->second : defaultValue;
  }

  auto Struct::getMethod(String const& name, const Function* defaultValue) const noexcept -> const Function* {
    auto it = this->M_methods.find(name);
    return it != this->M_methods.end() ? &it->second : defaultValue;
  }

  auto Struct::addMethod(Function method) noexcept -> bool {
    return this->M_methods.try_emplace(method.getName(), method).second;
  }

  auto Struct::getType() const noexcept -> Type* {
    return this->M_signature;
  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    return this->getType()->getLLVMType(ctx);
  }

  auto Struct::getIntType(llvm::LLVMContext& ctx) -> Struct* {
    return new Primitive { "int", llvm::Type::getInt64Ty(ctx) };
  }

  auto Struct::getFloatType(llvm::LLVMContext& ctx) -> Struct* {
    return new Primitive { "float", llvm::Type::getDoubleTy(ctx) };
  }

  auto Struct::getByteType(llvm::LLVMContext& ctx) -> Struct* {
    return new Primitive { "byte", llvm::Type::getInt8Ty(ctx) };
  }

  auto Struct::getBoolType(llvm::LLVMContext& ctx) -> Struct* {
    return new Primitive { "bool", llvm::Type::getInt1Ty(ctx) };
  }

  auto Struct::getVoidType(llvm::LLVMContext& ctx) -> Struct* {
    return new Primitive { "void", llvm::Type::getVoidTy(ctx) };
  }

  auto Struct::getErrorType() -> Struct* {
    static ErrorType S_errorTyppe {};
    return &S_errorTyppe;
  }
}
