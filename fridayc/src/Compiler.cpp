#include <Compiler.hpp>
#include <Pipeline.hpp>

namespace friday::inline api {
  
  Compiler::Compiler(CompilationContext& ctx, CompilationSettings settings)
    : M_ctx { &ctx }
    , M_settings { settings }
  {}
  
  auto Compiler::create(CompilationContext& ctx, CompilationSettings settings) noexcept -> unique_ptr<Compiler> {
    return make_unique<Compiler>(ctx, settings);
  }

  auto Compiler::compile() -> void {
    Pipeline{ *this->M_ctx }
    .and_then<DiscoveryVisitor>()
    .and_then<NamespaceBindingVisitor>()
    .and_then<TypeSolverVisitor>()
    .and_then<OverloadSolverVisitor>()
    .and_then<TypeCheckerVisitor>()
    .and_then<LLVMObjectEmitterVisitor>()
    ;
  }

}