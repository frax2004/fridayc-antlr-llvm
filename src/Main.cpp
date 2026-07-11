#include <Pipeline.hpp>
#include <NullPointerError.hpp>

using namespace friday;


auto Main(vector<string> paths) -> void {
  if constexpr(FRIDAY_API_ENABLE_SIGSEGV_AS_EXCEPTION) {
    signal(SIGSEGV, [](int signum) {
      (void)signum;
      throw NullPointerError{};
    });
  }

  Console::set_debug_enabled(false);

  CompilationContext context{ paths };


  Pipeline(context)
  .and_then<DiscoveryVisitor>()
  .and_then<NamespaceBindingVisitor>()
  .and_then<TypeSolverVisitor>()
  .and_then<OverloadSolverVisitor>()
  .and_then<TypeCheckerVisitor>()
  .peek(CompilationContext::print)
  ;

}
