#include "api/typesystem/Type.hpp"
#include "api/parser/FridayScanner.h"
#include "api/typesystem/Struct.hpp"
#include "api/typesystem/Namespace.hpp"

namespace friday::inline api::inline typechecker {

  struct ErrorType : public Struct {
    ErrorType() noexcept
      : Struct { Namespace::getGlobal(), "<error-type>" }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override {
      return nullptr;
    }
  };


  struct Primitive : public Struct {

    Primitive(String name, llvm::Type* T)
      : Struct { Namespace::getGlobal(), std::move(name) }
      , M_type { T }
    {}

    auto getLLVMType(llvm::LLVMContext& ctx) const noexcept -> llvm::Type* override {
      return this->M_type;
    }

    private:
    llvm::Type* M_type;
  };

  auto Type::getIntType(llvm::LLVMContext& ctx) -> Type* {
    static Primitive T { "int", llvm::Type::getInt64Ty(ctx) };
    return &T;
  }

  auto Type::getFloatType(llvm::LLVMContext& ctx) -> Type* {
    static Primitive T { "float", llvm::Type::getDoubleTy(ctx) };
    return &T;
  }

  auto Type::getByteType(llvm::LLVMContext& ctx) -> Type* {
    static Primitive T { "byte", llvm::Type::getInt8Ty(ctx) };
    return &T;
  }

  auto Type::getBoolType(llvm::LLVMContext& ctx) -> Type* {
    static Primitive T { "bool", llvm::Type::getInt1Ty(ctx) };
    return &T;
  }

  auto Type::getVoidType(llvm::LLVMContext& ctx) -> Type* {
    static Primitive T { "void", llvm::Type::getVoidTy(ctx) };
    return &T;
  }

  auto Type::getErrorType() -> Type* {
    static ErrorType S_errorTyppe {};
    return &S_errorTyppe;
  }

}