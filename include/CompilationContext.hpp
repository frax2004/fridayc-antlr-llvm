#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct FRIDAY_API CompilationContext final : NonCopyable {
    private:
    llvm::LLVMContext                                                         M_llvmContext { };
    rc<Namespace>                                                             M_global      { nullptr };
    vector<rc<TranslationUnit>>                                               M_units       { };
    unordered_map<string, rc<Namespace>, transparent_string_hash, equal_to<>> M_namespaces  { };

    public:
    CompilationContext(vector<string> const& paths);
    ~CompilationContext() = default;

    public:
    auto print() -> void;
    auto get_units() const -> ranges::ref_view<const vector<rc<TranslationUnit>>>;
    auto add_unit(rc<TranslationUnit> unit) -> void;
    auto get_or_emplace_namespace(string_view name) -> weak<Namespace>;
    auto get_llvm_context() -> llvm::LLVMContext&;
    auto get_global() const -> rc<Namespace>;
    auto find_namespace(string_view name) -> weak<Namespace>;
  };
}