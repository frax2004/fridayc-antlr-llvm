#pragma once

#include <Common.hpp>
#include <FridayParser.h>

namespace friday::inline core::inline util {

  struct CompilationContext final {
    ant::tree::ParseTree* ast;
    llvm::Module* mod;
    llvm::LLVMContext* ctx;
    string path;
  };
}