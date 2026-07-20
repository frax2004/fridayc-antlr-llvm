#include <LinkerVisitor.hpp>


namespace friday::inline api::inline pipeline {
  LinkerVisitor::LinkerVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
}