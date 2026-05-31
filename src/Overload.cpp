#include <Overload.hpp>


namespace friday::inline api::inline typesystem {

  auto Overload::getFunctions() const -> Vector<Function*> {
    return this->M_overloads 
    | std::views::values 
    | std::ranges::to<std::vector>();
  }

  auto Overload::add(Vector<Type*> argsTypes, Function* function) -> void {
    this->M_overloads.try_emplace(std::move(argsTypes), function);
  }

  auto Overload::tryMatch(Vector<Type*> argsTypes) -> Function* {
    if(auto it = this->M_overloads.find(argsTypes); it != this->M_overloads.end()) {
      return it->second;
    } else return nullptr;
  }

  auto Overload::hasMatch(Vector<Type*> argsTypes) -> bool {
    return this->M_overloads.contains(argsTypes);
  }

  auto Overload::getQualifiedId() const -> String {
    return this->M_name;
  }

  auto Overload::getFullQualifiedId() const -> String {
    return "{}.{}"_f.format(
      dynamic_cast<ISymbol*>(this->M_declaringSymbolTable)->getFullQualifiedId(), 
      this->M_name
    );
  }

  auto Overload::getMangledId() const -> String {

  }

  auto Overload::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_declaringSymbolTable;
  }

  auto Overload::getAttributes() const -> Attributes {
    return {};
  }

}