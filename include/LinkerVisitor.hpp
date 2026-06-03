#pragma once
#include <FridayParserBaseVisitor.h>
#include <CompilationContext.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {
  // will link the object files and produce the executable
  struct LinkerVisitor : FridayParserBaseVisitor, StaticAnalyzer {
    private:
    CompilationContext* context;
  
    public:
    LinkerVisitor(CompilationContext& ctx);
  };
}
