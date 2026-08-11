#include <fridayc.hpp>


namespace friday::inline api {
  LinkerVisitor::LinkerVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
  {}
}