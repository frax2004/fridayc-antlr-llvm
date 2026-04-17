#include "api/typechecker/Struct.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {

  struct ErrorType : public Struct {
    ErrorType() noexcept
      : Struct { "<error-type>" }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override {
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
    , M_name { std::move(name) }
    , M_fields { std::move(fields) }
    , M_methods { std::move(methods) }
    , M_visibility { visibility }
  {}

  auto Struct::getName() const noexcept -> String const& {
    return this->M_name;
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
    // TODO handle this in a better way
    throw OperationNotSupportedError{"Cannot get the type of a struct"};
    return nullptr;
  }

  auto Struct::getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* {
    auto toLLVMType = [&ctx](Type* type) -> llvm::Type* {
      return type->getLLVMType(ctx);
    };

    return llvm::StructType::get(
      ctx,
      this->M_fields
      | std::views::values
      | std::views::transform(Variable::getType)
      | std::views::transform(toLLVMType)
      | std::ranges::to<std::vector>()
    );
  }

  auto Struct::getIntType(llvm::LLVMContext& ctx) -> Type* {
    return new Primitive { "int", llvm::Type::getInt64Ty(ctx) };
  }

  auto Struct::getFloatType(llvm::LLVMContext& ctx) -> Type* {
    return new Primitive { "float", llvm::Type::getDoubleTy(ctx) };
  }

  auto Struct::getByteType(llvm::LLVMContext& ctx) -> Type* {
    return new Primitive { "byte", llvm::Type::getInt8Ty(ctx) };
  }

  auto Struct::getBoolType(llvm::LLVMContext& ctx) -> Type* {
    return new Primitive { "bool", llvm::Type::getInt1Ty(ctx) };
  }

  auto Struct::getVoidType(llvm::LLVMContext& ctx) -> Type* {
    return new Primitive { "void", llvm::Type::getVoidTy(ctx) };
  }

  auto Struct::getErrorType() -> Type* {
    static ErrorType S_errorTyppe {};
    return &S_errorTyppe;
  }
}
