#pragma once
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will emit the llvm object files
  struct LLVMObjectEmitterVisitor final : StaticAnalyzer {
  
    public:
    LLVMObjectEmitterVisitor(CompilationContext& ctx);
    ~LLVMObjectEmitterVisitor() override = default;
  };
}
