#include <NamespaceBindingVisitor.hpp>

namespace friday::inline api::inline pipeline {
  NamespaceBindingVisitor::NamespaceBindingVisitor(CompilationContext& ctx)
    : context { &ctx }
  {}
  
  auto NamespaceBindingVisitor::bind() -> NamespaceBindingVisitor& {

    return *this;
  }
}
