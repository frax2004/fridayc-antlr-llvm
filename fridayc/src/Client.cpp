#include <Compiler.hpp>

using namespace friday;

auto Main(vector<string> paths) -> void {

  auto settings = CompilationSettings::builder()
  .enable_debug(false)
  .redirect_notes_to(stdout)
  .redirect_logs_to(stdout)
  .redirect_debugs_to(stderr)
  .redirect_errors_to(stderr)
  .redirect_warnings_to(stderr)
  .build();

  auto context = CompilationContext::create(paths);
  auto compiler = Compiler::create(*context, settings);
  compiler->compile();
}
