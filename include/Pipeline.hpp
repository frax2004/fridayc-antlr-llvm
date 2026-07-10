#pragma once

#include <DiscoveryVisitor.hpp>
#include <NamespaceBindingVisitor.hpp>
#include <TypeSolverVisitor.hpp>
#include <OverloadSolverVisitor.hpp>
#include <TypeCheckerVisitor.hpp>
#include <LLVMObjectEmitterVisitor.hpp>
#include <LinkerVisitor.hpp>

namespace friday::inline api::inline pipeline {

  struct FRIDAY_API Pipeline final {
    private:
    optional<Pointer<CompilationContext>> M_context;

    public:
    Pipeline(CompilationContext& context);

    template<derived_from<StaticAnalyzer> T>
    auto andThen() -> Pipeline&;

  template<invocable<Pointer<CompilationContext>> Fn>
    auto peek(Fn&& fn) -> Pipeline&;
  };

}

#include <Pipeline.inl>
