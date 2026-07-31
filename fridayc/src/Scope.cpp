#include <Scope.hpp>

namespace friday::inline api::inline typesystem {
  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::find_variable(string_view id) -> Variable* {
    ISymbol* candidate = this->retrieve_if(id, &Variable::is_variable);
    return not candidate.expired() ? Variable*{ dynamic_pointer_cast<Variable>(candidate.lock()) } : Variable*{};
  }

  auto Scope::get_parent() const -> ISymbolTable* {
    return this->M_parent;
  }

}
