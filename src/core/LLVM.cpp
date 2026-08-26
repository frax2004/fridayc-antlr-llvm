#include <fridayc.hpp>

namespace friday::inline core {

  auto LLVMWrapper::get_instance() -> LLVMWrapper& {
    static LLVMWrapper S_instance { };
    return S_instance;
  }

  LLVMWrapper& LLVM = LLVMWrapper::get_instance();

  LLVMWrapper::LLVMWrapper()
    : M_context { }
    , M_builder { make_unique<llvm::IRBuilder<>>(this->M_context) }
    , M_module { make_unique<llvm::Module>("out", this->M_context) }
  {}

  auto LLVMWrapper::size_of(llvm::Type* type) const -> size_t {
    return this->M_module->getDataLayout().getTypeAllocSize(type).getFixedValue();
  }

  auto LLVMWrapper::alignment_of(llvm::Type* type) const -> size_t {
    return this->M_module->getDataLayout().getABITypeAlign(type).value();
  }

  auto LLVMWrapper::context() -> llvm::LLVMContext& {
    return this->M_context;
  }

  auto LLVMWrapper::module() const -> llvm::Module& {
    return *this->M_module;
  }

  auto LLVMWrapper::builder() const -> llvm::IRBuilder<>& {
    return *this->M_builder;
  }

  auto LLVMWrapper::get_int_type(unsigned bits) -> llvm::Type* {
    return llvm::Type::getIntNTy(LLVM.context(), bits);
  }

  auto LLVMWrapper::get_float_type() -> llvm::Type* {
    return llvm::Type::getFloatTy(LLVM.context());
  }

  auto LLVMWrapper::get_double_type() -> llvm::Type* {
    return llvm::Type::getDoubleTy(LLVM.context());
  }

  auto LLVMWrapper::get_void_type() -> llvm::Type* {
    return llvm::Type::getVoidTy(LLVM.context());
  }

  auto LLVMWrapper::get_struct_type(string name, span<llvm::Type*> fields) -> llvm::Type* {
    return llvm::StructType::create(LLVM.context(), fields, name, false);
  }

  auto LLVMWrapper::get_function_type(llvm::Type* ret, span<llvm::Type*> args) -> llvm::Type* {
    return llvm::FunctionType::get(ret, args, false);
  }

  auto LLVMWrapper::get_pointer_type() -> llvm::Type* {
    return llvm::PointerType::get(LLVM.context(), 0);
  }
}