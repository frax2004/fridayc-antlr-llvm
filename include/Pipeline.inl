#ifdef __INTELLISENSE__
#include <Pipeline.hpp>
#endif


namespace friday::inline api::inline pipeline {

  template<derived_from<StaticAnalyzer> T>
  auto Pipeline::and_then() -> Pipeline& {

    this->M_context = M_context
    .and_then([](Pointer<CompilationContext> ctx) -> optional<Pointer<CompilationContext>> {      
      auto analyzer = T{*ctx};
      analyzer.analyze();
      auto errors = analyzer.errors();

      if(not errors.empty()) {
        ranges::for_each(errors, &SemanticError::report);
        return nullopt;
      } else return optional{ctx};
    });

    return *this;
  }
  
  template<invocable<Pointer<CompilationContext>> Fn>
  auto Pipeline::peek(Fn&& fn) -> Pipeline& {
    if(this->M_context.has_value()) invoke(fn, this->M_context.value());
    return *this;
  }

}