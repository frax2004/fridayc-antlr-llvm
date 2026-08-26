#pragma once

#include "Core.hpp"

#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_os_ostream.h>


namespace friday::inline core {
  struct LLVMWrapper final {
  private:
    llvm::LLVMContext             M_context { };
    unique_ptr<llvm::IRBuilder<>> M_builder { nullptr };
    unique_ptr<llvm::Module>      M_module  { nullptr };

  private:
    LLVMWrapper();

  public:
    ~LLVMWrapper() = default;

  public:
    static auto get_instance() -> LLVMWrapper&;

  public:
    auto context() -> llvm::LLVMContext&;
    auto module() const -> llvm::Module&;
    auto builder() const -> llvm::IRBuilder<>&;
    auto size_of(llvm::Type* type) const -> size_t;
    auto alignment_of(llvm::Type* type) const -> size_t;

    auto get_int_type(unsigned bits) -> llvm::Type*;
    auto get_float_type() -> llvm::Type*;
    auto get_double_type() -> llvm::Type*;
    auto get_void_type() -> llvm::Type*;
    auto get_struct_type(string name, span<llvm::Type*> fields) -> llvm::Type*;
    auto get_function_type(llvm::Type* ret, span<llvm::Type*> args) -> llvm::Type*;
    auto get_pointer_type() -> llvm::Type*;
  };

  extern LLVMWrapper& LLVM;
}