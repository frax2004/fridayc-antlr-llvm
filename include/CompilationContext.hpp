#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct FRIDAY_API CompilationContext final : NonCopyable {
    llvm::LLVMContext           llvmContext { };
    rc<Namespace>               global      { nullptr };
    map<string, rc<Namespace>>  namespaces  { };
    vector<rc<TranslationUnit>> units       { };

    public:
    CompilationContext(vector<string> const& paths);
    ~CompilationContext() = default;

    public:
    auto print() -> void;
  };
}