#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>
#include <Json.hpp>


using namespace friday;

template<>
struct json::stringify<Variable> {
  auto operator()(Variable const& self) -> string {
    return "{}";
  }
};

template<>
struct json::stringify<Overload> {
  auto operator()(Overload const& self) -> string {
    return "{{\"type\": \"overload\", \"name\": \"{}\"}}"_f.format(
      self.getQualifiedId()
    );
  }
};

template<>
struct json::stringify<Struct> {
  auto operator()(Struct const& self) -> string {
    auto name = self.getQualifiedId();
    auto symbols = self.getSymbols();

    // TODO grammar must implement global variables
    auto var2str = stringify<Variable>{};
    auto ovl2str = stringify<Overload>{};

    auto sym2str = [&](ISymbol* symbol) {
      if(auto asVar = rtti::cast<Variable>(symbol)) 
        return var2str(*asVar);
      else if(auto asOverload = rtti::cast<Overload>(symbol)) 
        return ovl2str(*asOverload);
      else return "null"s;
    };

    return "{{\"type\": \"struct\", \"name\": \"{}\", \"symbols\": [{}]}}"_f.format(
      name,
      symbols 
      | views::transform(sym2str)
      | views::join_with(", "sv)
      | ranges::to<string>()
    );
  }
};



template<>
struct json::stringify<Namespace> {
  auto operator()(Namespace const& self) -> string {
    auto name = self.getQualifiedId();
    auto symbols = self.getSymbols();

    // TODO grammar must implement global variables
    auto var2str = stringify<Variable>{};
    auto sct2str = stringify<Struct>{};
    auto ovl2str = stringify<Overload>{};

    auto sym2str = [&](ISymbol* symbol) {
      if(auto asVar = rtti::cast<Variable>(symbol)) 
        return var2str(*asVar);
      else if(auto asStruct = rtti::cast<Struct>(symbol)) 
        return sct2str(*asStruct);
      else if(auto asOverload = rtti::cast<Overload>(symbol)) 
        return ovl2str(*asOverload);
      else return "null"s;
    };

    return "{{\"type\": \"namespace\", \"name\": \"{}\", \"symbols\": [{}]}}"_f.format(
      name,
      symbols 
      | views::transform(sym2str)
      | views::join_with(", "sv)
      | ranges::to<string>()
    );
  }
};




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
  | views::transform(box<Namespace>::get);

  for(auto nsp : context->namespaces | toJSONString) {
    println("{}", json::stringify<Namespace>{}(*nsp));
  }

  println("{}", json::stringify<Namespace>{}(*context->global));

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
