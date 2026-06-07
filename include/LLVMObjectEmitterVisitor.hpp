#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will emit the llvm object files
  struct LLVMObjectEmitterVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context { nullptr };
  
    public:
    LLVMObjectEmitterVisitor(CompilationContext& ctx);
  };
}
