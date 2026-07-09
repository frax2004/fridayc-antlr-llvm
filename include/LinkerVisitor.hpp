#pragma once
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will link the object files and produce the executable
  struct LinkerVisitor final : StaticAnalyzer {
    public:
    LinkerVisitor(CompilationContext& ctx);
    ~LinkerVisitor() override = default;
  };
}
