#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <OverloadSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>
#include <Json.hpp>
#include <Primitive.hpp>


using namespace friday;


template<class Func>
auto measure(Func&& func, string label) -> string {
  auto begin = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  return format("{{ \"label\": \"{}\", \"time\": \"{}\"}}", label, chrono::duration_cast<chrono::milliseconds>(end - begin));
}



auto Main(vector<string> paths) -> void {
  llvm::LLVMContext ctx;

  auto context = make_shared<CompilationContext>();
  context->global = make_shared<Namespace>("");
  context->global->define(make_shared<Primitive>(*context->global, "int", llvm::Type::getInt64Ty(ctx)));
  context->global->define(make_shared<Primitive>(*context->global, "byte", llvm::Type::getInt8Ty(ctx)));
  context->global->define(make_shared<Primitive>(*context->global, "bool", llvm::Type::getInt1Ty(ctx)));
  context->global->define(make_shared<Primitive>(*context->global, "float", llvm::Type::getDoubleTy(ctx)));
  context->global->define(make_shared<Primitive>(*context->global, "void", llvm::Type::getVoidTy(ctx)));

  auto parse = [&context](string path) {
    return async(launch::async, [&context, path]() {
      return TranslationUnit::parse(*context, path);
    });
  };

  auto futures = paths
  | views::transform(parse)
  | ranges::to<vector>();

  context->units = futures
  | views::transform(&future<rc<TranslationUnit>>::get)
  | ranges::to<vector>();

  auto discoveryErrors = DiscoveryVisitor{*context}.analyze().errors();
  
  if(not discoveryErrors.empty()) {
    ranges::for_each(discoveryErrors, &SemanticError::report);
    return;
  }

  auto toJSONString = views::values 
  | views::transform(&rc<Namespace>::operator*)
  | views::transform(json::stringify<Namespace>{});

  auto namespaces = vector<string>{};
  namespaces.push_back(json::stringify<Namespace>{}(*context->global));
  namespaces.append_range(context->namespaces | toJSONString);

  auto namespaceBindingErrors = NamespaceBindingVisitor{*context}.analyze().errors();
  
  if(not namespaceBindingErrors.empty()) {
    ranges::for_each(namespaceBindingErrors, &SemanticError::report);
    return;
  }

  auto typeSolverErrors = TypeSolverVisitor{*context}.analyze().errors();
  
  if(not typeSolverErrors.empty()) {
    ranges::for_each(typeSolverErrors, &SemanticError::report);
    return;
  }

  auto overloadSolverErrors = OverloadSolverVisitor{*context}.analyze().errors();
  
  if(not overloadSolverErrors.empty()) {
    ranges::for_each(overloadSolverErrors, &SemanticError::report);
    return;
  }


  // auto typeCheckerErrors = TypeCheckerVisitor{*context}.analyze().errors();


  // LLVMObjectEmitterVisitor{*context}.emit();
  // LinkerVisitor{*context}.link();


  auto toString = json::stringify<Namespace>{};

  auto table = "[{}, {}]"_f.format(
    toString(*context->global),
    context->namespaces
    | views::values
    | views::transform(&rc<Namespace>::operator*)
    | views::transform(toString)
    | views::join_with(", "s)
    | ranges::to<string>()
  );


  FILE* output = fopen("table.json", "w+");
  println(output, "{}", table);
  fclose(output);


}
