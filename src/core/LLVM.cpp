#include <fridayc.hpp>

namespace friday::inline core {
  
  auto LLVMWrapper::context() -> llvm::LLVMContext& {
    return this->M_context;
  }

  auto LLVMWrapper::module() const -> llvm::Module& {
    return *this->M_module;
  }

  auto LLVMWrapper::builder() const -> llvm::IRBuilder<>& {
    return *this->M_builder;
  }

  LLVMWrapper::LLVMWrapper()
    : M_context { }
    , M_builder { make_unique<llvm::IRBuilder<>>(this->M_context) }
    , M_module { make_unique<llvm::Module>("out", this->M_context) }
  {}

  auto LLVMWrapper::instance() -> LLVMWrapper& {
    static LLVMWrapper S_wrapper { };
    return S_wrapper;
  }

  auto LLVMWrapper::get_int_type(unsigned bits) -> llvm::Type* {
    return llvm::Type::getIntNTy(LLVMWrapper::instance().context(), bits);
  }

  auto LLVMWrapper::get_float_type() -> llvm::Type* {
    return llvm::Type::getFloatTy(LLVMWrapper::instance().context());
  }

  auto LLVMWrapper::get_double_type() -> llvm::Type* {
    return llvm::Type::getDoubleTy(LLVMWrapper::instance().context());
  }

  auto LLVMWrapper::get_void_type() -> llvm::Type* {
    return llvm::Type::getVoidTy(LLVMWrapper::instance().context());
  }

  auto LLVMWrapper::get_struct_type(string name, span<llvm::Type*> fields) -> llvm::Type* {
    return llvm::StructType::create(LLVMWrapper::instance().context(), fields, name, false);
  }

  auto LLVMWrapper::get_function_type(llvm::Type* ret, span<llvm::Type*> args) -> llvm::Type* {
    return llvm::FunctionType::get(ret, args, false);
  }

  auto LLVMWrapper::get_pointer_type(llvm::Type* pointed) -> llvm::Type* {
    return llvm::PointerType::get(pointed, 0);
  }
}