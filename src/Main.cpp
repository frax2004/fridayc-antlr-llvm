#include <Pipeline.hpp>

using namespace friday;


auto Main(vector<string> paths) -> void {
  // signal(SIGSEGV, [](int) {
  //   throw NullPointerError{};
  // });

  Console::setDebugEnabled(false);

  CompilationContext context{ paths };

  Pipeline(context)
  .andThen<DiscoveryVisitor>()
  .andThen<NamespaceBindingVisitor>()
  .andThen<TypeSolverVisitor>()
  .andThen<OverloadSolverVisitor>()
  .andThen<TypeCheckerVisitor>()
  .peek(CompilationContext::print)
  ;

}
