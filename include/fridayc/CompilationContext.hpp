#pragma once
#include "Common.hpp"


namespace friday::inline api {

  struct TranslationUnit;


  struct CompilationContext final  {
  private:
    vector<unique_ptr<TranslationUnit>> M_translationUnits { };

  private:
    CompilationContext(vector<string> const& paths);

  public:
    constexpr ~CompilationContext() = default;
  
    auto get_units() const -> vector<TranslationUnit*>;
    
    static auto create(vector<string> const& paths) -> unique_ptr<CompilationContext>;

  private:
    auto parse(string path) -> future<unique_ptr<TranslationUnit>>;
  };
}