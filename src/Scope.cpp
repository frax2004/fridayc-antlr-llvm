#include <Scope.hpp>

namespace friday::inline api::inline typesystem {
  Scope::Scope(ISymbolTable& parent)
    : M_parent { &parent }
  {}

  auto Scope::find_variable(string_view id, weak<Variable> defaultValue) -> weak<Variable> {
    constexpr auto is_variable = [](Pointer<ISymbol> symbol) {
      return dynamic_cast<Pointer<Variable>>(symbol) != nullptr;
    };

    weak<ISymbol> candidate = look_up_if(id, is_variable, defaultValue);
    return not candidate.expired() ? dynamic_pointer_cast<Variable>(candidate.lock()) : defaultValue;
  }

  auto Scope::get_parent() -> Pointer<ISymbolTable> {
    return this->M_parent;
  }

}
