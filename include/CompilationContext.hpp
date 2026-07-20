#pragma once

#include <Common.hpp>
#include <Namespace.hpp>
#include <TranslationUnit.hpp>

namespace friday::inline api::inline pipeline {
  
  struct FRIDAY_API CompilationContext final : NonCopyable {
    private:
    using namespace_map_type = unordered_map<string, rc<Namespace>, transparent_string_hash, equal_to<>>; 

    llvm::LLVMContext           M_llvmContext { };
    rc<Namespace>               M_global      { nullptr };
    vector<rc<TranslationUnit>> M_units       { };
    namespace_map_type          M_namespaces  { };

    public:
    CompilationContext(vector<string> const& paths);
    ~CompilationContext() override = default;

    public:
    auto get_global() const -> rc<Namespace>;
    auto get_llvm_context() -> llvm::LLVMContext&;
    auto get_or_emplace_namespace(string_view name) -> weak<Namespace>;
    auto find_namespace(string_view name) -> weak<Namespace>;

    auto get_units() const -> ranges::ref_view<const vector<rc<TranslationUnit>>>;
    auto add_unit(rc<TranslationUnit> unit) -> void;

    auto print() -> void;
  };
}