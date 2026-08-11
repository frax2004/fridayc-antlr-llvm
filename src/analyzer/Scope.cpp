#include <fridayc.hpp>

namespace friday::inline api {

  auto Scope::Factory::create(ISymbolTable& parent) -> Scope* {
    static vector<unique_ptr<Scope>> S_scopes { };
    S_scopes.push_back(unique_ptr<Scope>(new Scope(parent)));
    return S_scopes.back().get();

  }

  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::find_variable(string_view id) -> Variable* {
    ISymbol* candidate = this->retrieve_if(id, &Variable::is_variable);
    return candidate != nullptr ? Variable::to_variable(candidate) : nullptr;
  }

  auto Scope::get_parent() const -> ISymbolTable* {
    return this->M_parent;
  }

}
