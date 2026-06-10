#include <LLVMObjectEmitterVisitor.hpp>

namespace friday::inline api::inline pipeline {
  LLVMObjectEmitterVisitor::LLVMObjectEmitterVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
}
