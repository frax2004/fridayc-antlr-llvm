#include <FridayScanner.h>
#include <FridayParserBaseVisitor.h>
#include <PointerGraph.hpp>
#include <Namespace.hpp>


auto measure(auto func, string label) -> string {
  auto begin = chrono::high_resolution_clock::now();
  func();
  auto end = chrono::high_resolution_clock::now();
  return format("{{ \"label\": \"{}\", \"time\": \"{}\"}}", label, chrono::duration_cast<chrono::milliseconds>(end - begin));
}


using namespace friday;


struct TranslationUnit {
  string path;
  ifstream inputStream;
  ant::ANTLRInputStream input;
  FridayScanner lexer;
  ant::CommonTokenStream tokens;
  FridayParser parser;
  ant::tree::ParseTree* ast;

  CompilationContext* globalContext;
  Namespace* ownedNamespace;
  map<string, Namespace*> usedNamespaces;

  TranslationUnit(string_ref path)
    : path { string(path) }
    , inputStream { this->path }
    , input { this->inputStream }
    , lexer { &this->input }
    , tokens { &this->lexer }
    , parser { &this->tokens }
    , ast { this->parser.program() }
  {}
};

struct CompilationContext {
  box<Namespace> global;
  map<string, box<Namespace>> namespaces;
  vector<box<TranslationUnit>> units;
};

auto parse(string_ref path) -> box<TranslationUnit> {
  auto ast = make_unique<TranslationUnit>(path);
  return std::move(ast);
}

// will forward declare namespaces, structs and functions
struct DiscoveryVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  DiscoveryVisitor(CompilationContext& ctx);

  auto discover() -> void;
};

DiscoveryVisitor::DiscoveryVisitor(CompilationContext& ctx)
  : context { &ctx }
{}

auto DiscoveryVisitor::discover() -> void {
  for(auto& unit : this->context->units) {
    this->visit(unit->ast);    
  }
}


// will bind namespaces with their used namespaces
struct NamespaceBindingVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  NamespaceBindingVisitor(CompilationContext& ctx);
};

NamespaceBindingVisitor::NamespaceBindingVisitor(CompilationContext& ctx)
  : context { &ctx }
{}

// will fill structs with fields and build the dependency graph
struct TypeSolverVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  TypeSolverVisitor(CompilationContext& ctx);
};

TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
  : context { &ctx }
{}

// will do static analysys 
struct TypeCheckerVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  TypeCheckerVisitor(CompilationContext& ctx);
};

TypeCheckerVisitor::TypeCheckerVisitor(CompilationContext& ctx)
  : context { &ctx }
{}

// will emit the llvm object files
struct LLVMObjectEmitterVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  LLVMObjectEmitterVisitor(CompilationContext& ctx);
};

LLVMObjectEmitterVisitor::LLVMObjectEmitterVisitor(CompilationContext& ctx)
  : context { &ctx }
{}

// will link the object files and produce the executable
struct LinkerVisitor : FridayParserBaseVisitor {
  private:
  CompilationContext* context;

  public:
  LinkerVisitor(CompilationContext& ctx);
};

LinkerVisitor::LinkerVisitor(CompilationContext& ctx)
  : context { &ctx }
{}


auto Main(vector<string_ref> paths) -> void {
  auto context = make_unique<CompilationContext>();

  auto futures = paths
  | views::transform([](string_ref path) { return async(launch::async, parse, path); })
  | ranges::to<vector>();

  context->units = futures
  | views::transform(future<box<TranslationUnit>>::get)
  | ranges::to<vector>();

  auto dv = DiscoveryVisitor{*context};
  auto nbv = NamespaceBindingVisitor{*context};
  auto tsv = TypeSolverVisitor{*context};
  auto tcv = TypeCheckerVisitor{*context};
  auto ev = LLVMObjectEmitterVisitor{*context};
  auto lv = LinkerVisitor{*context};

}


