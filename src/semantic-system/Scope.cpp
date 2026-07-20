#include <Scope.hpp>

namespace friday::inline api::inline typesystem {
  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::find_variable(string_view id) -> weak<Variable> {
    weak<ISymbol> candidate = this->retrieve_if(id, &Variable::is_variable);
    return not candidate.expired() ? weak<Variable>{ dynamic_pointer_cast<Variable>(candidate.lock()) } : weak<Variable>{};
  }

  auto Scope::get_parent() const -> Pointer<ISymbolTable> {
    return this->M_parent;
  }

}
