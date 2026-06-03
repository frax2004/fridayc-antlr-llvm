#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>


template<class Func>
auto measure(Func&& func, string label) -> string {
  auto begin = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  return format("{{ \"label\": \"{}\", \"time\": \"{}\"}}", label, chrono::duration_cast<chrono::milliseconds>(end - begin));
}

using namespace friday;


auto Main(vector<string_ref> paths) -> void {
  auto context = make_unique<CompilationContext>();
  context->global = make_unique<Namespace>("");

  auto parse = [](string_ref path) {
    return async(launch::async, TranslationUnit::parse, path);
  };

  auto futures = paths
  | views::transform(parse)
  | ranges::to<vector>();

  context->units = futures
  | views::transform(future<box<TranslationUnit>>::get)
  | ranges::to<vector>();

  auto discoveryErrors = DiscoveryVisitor{*context}.discover().errors();

  if(not discoveryErrors.empty()) {
    ranges::for_each(discoveryErrors, SemanticError::report);
    return;
  }

  // auto namespaceBindingErrors = NamespaceBindingVisitor{*context}.bind().errors();

  // if(not namespaceBindingErrors.empty()) {
  //   ranges::for_each(namespaceBindingErrors, SemanticError::report);
  //   return;
  // }

  // TypeSolverVisitor{*context}.solve();
  // auto tcv = TypeCheckerVisitor{*context};
  // LLVMObjectEmitterVisitor{*context}.emit();
  // LinkerVisitor{*context}.link();

}
