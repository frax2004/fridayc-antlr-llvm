#pragma once

#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <OverloadSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>

namespace friday::inline api::inline pipeline {

  struct Pipeline final {
    private:
    optional<CompilationContext*> M_context;

    public:
    Pipeline(CompilationContext& context);

    template<derived_from<StaticAnalyzer> T>
    auto andThen() -> Pipeline&;

  template<invocable<CompilationContext*> Fn>
    auto peek(Fn&& fn) -> Pipeline&;
  };

}

#include <Pipeline.inl>
