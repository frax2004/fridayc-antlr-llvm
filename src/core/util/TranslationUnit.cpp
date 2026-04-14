#include "core/util/TranslationUnit.hpp"

namespace friday::inline core::inline util {
  TranslationUnit::TranslationUnit(std::filesystem::path path, llvm::LLVMContext& ctx) noexcept
    : M_sourcePath { path }
    , M_module { std::make_unique<llvm::Module>(M_sourcePath.generic_string(), ctx) }
  {}

  auto TranslationUnit::getPath() const noexcept -> std::filesystem::path const& {
    return this->M_sourcePath;
  }

  auto TranslationUnit::setParseTree(FridayParser::ProgramContext* tree) noexcept -> void {
    this->M_parseTree = tree;
  }

  auto TranslationUnit::getParseTree() const noexcept -> FridayParser::ProgramContext* {
    return this->M_parseTree;
  }

  auto TranslationUnit::getModule() const noexcept -> llvm::Module* {
    return this->M_module.get();
  }
}