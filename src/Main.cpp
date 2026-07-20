#include <Pipeline.hpp>
#include <NullPointerError.hpp>

using namespace friday;

auto Main(vector<string> paths) -> void {

  Console::set_debug_enabled(false);

  CompilationContext context{ paths };

  Pipeline(context)
  .and_then<DiscoveryVisitor>()
  .and_then<NamespaceBindingVisitor>()
  .and_then<TypeSolverVisitor>()
  .and_then<OverloadSolverVisitor>()
  .peek(&CompilationContext::print)
  .and_then<TypeCheckerVisitor>()
  .and_then<LLVMObjectEmitterVisitor>()
  ;

}
