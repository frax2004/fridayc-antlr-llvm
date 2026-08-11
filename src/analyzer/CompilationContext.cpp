#include <fridayc.hpp>


namespace friday::inline api {
  
  CompilationContext::CompilationContext(vector<string> const& paths) {
    auto futures = paths
    | views::transform([](string const& s) { return filesystem::absolute(s).generic_string(); })
    | views::transform([this](string const& path) { return this->parse(path); })
    | ranges::to<vector>();
    
    this->M_translationUnits = futures
    | views::transform(&future<unique_ptr<TranslationUnit>>::get)
    | ranges::to<vector>();
    
  }

  auto CompilationContext::create(vector<string> const& paths) -> unique_ptr<CompilationContext> {
    return unique_ptr<CompilationContext>(new CompilationContext(paths));
  }

  auto CompilationContext::parse(string path) -> future<unique_ptr<TranslationUnit>> {
    return async(launch::async, [this, path]() {
      Console::log(format("Parsing '{}'", path));
      flush(cout);
      return TranslationUnit::parse(*this, path);
    });
  };

  auto CompilationContext::get_units() const -> vector<TranslationUnit*> {
    return this->M_translationUnits
    | views::transform(&unique_ptr<TranslationUnit>::get)
    | ranges::to<vector>();
  }
}
