#pragma once
#include <fridayc.hpp>


namespace friday::inline api {
  // will link the object files and produce the executable
  struct LinkerVisitor final : StaticAnalyzer {
  public:
    LinkerVisitor(CompilationContext& ctx);
    ~LinkerVisitor() override = default;
  };
}
