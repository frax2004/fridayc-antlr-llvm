#include <LLVMObjectEmitterVisitor.hpp>
#include <llvm/Support/raw_os_ostream.h>

namespace friday::inline api::inline pipeline {
  LLVMObjectEmitterVisitor::LLVMObjectEmitterVisitor(CompilationContext& ctx)
    : StaticAnalyzer { ctx }
    , M_builder { make_shared<llvm::IRBuilder<>>(ctx.get_llvm_context()) }
  {}

  auto LLVMObjectEmitterVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    this->M_currentModule = unit.get_llvm_module();
  }

  auto LLVMObjectEmitterVisitor::on_unit_end(TranslationUnit& unit) -> void {
    auto path = filesystem::path{ unit.get_path() }
    .replace_extension("ll");

    ofstream ostream { path };
    llvm::raw_os_ostream stream{ ostream };

    this->M_currentModule.lock()->print(stream, nullptr);
    stream.flush();
    ostream.close();

    this->M_currentModule = {};
  }

  auto LLVMObjectEmitterVisitor::current() const -> rc<llvm::Module> {
    return this->M_currentModule.lock();
  }

}
