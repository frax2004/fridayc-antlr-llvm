#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>
#include <Json.hpp>

using namespace friday;



template<class Func>
auto measure(Func&& func, string label) -> string {
  auto begin = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  return format("{{ \"label\": \"{}\", \"time\": \"{}\"}}", label, chrono::duration_cast<chrono::milliseconds>(end - begin));
}



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

  auto toJSONString = views::values 
  | views::transform(box<Namespace>::operator*)
  | views::transform(json::stringify<Namespace>{});

  auto namespaces = vector<string>{};
  namespaces.push_back(json::stringify<Namespace>{}(*context->global));
  namespaces.append_range(context->namespaces | toJSONString);

  auto namespaceBindingErrors = NamespaceBindingVisitor{*context}.bind().errors();

  if(not namespaceBindingErrors.empty()) {
    ranges::for_each(namespaceBindingErrors, SemanticError::report);
    return;
  }

  auto typeSolverErrors = TypeSolverVisitor{*context}.solve().errors();

  if(not typeSolverErrors.empty()) {
    ranges::for_each(namespaceBindingErrors, SemanticError::report);
    return;
  }


  // auto tcv = TypeCheckerVisitor{*context};
  // LLVMObjectEmitterVisitor{*context}.emit();
  // LinkerVisitor{*context}.link();

}
