#include <Overload.hpp>


namespace friday::inline api::inline typesystem {

  auto Overload::getFunctions() const -> vector<Function*> {
    return this->M_overloads 
    | views::values 
    | ranges::to<vector>();
  }

  auto Overload::add(vector<Type*> argsTypes, Function* function) -> void {
    this->M_overloads.try_emplace(move(argsTypes), function);
  }

  auto Overload::tryMatch(vector<Type*> argsTypes) -> Function* {
    if(auto it = this->M_overloads.find(argsTypes); it != this->M_overloads.end()) {
      return it->second;
    } else return nullptr;
  }

  auto Overload::hasMatch(vector<Type*> argsTypes) -> bool {
    return this->M_overloads.contains(argsTypes);
  }

  auto Overload::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Overload::getFullQualifiedId() const -> string {
    return "{}.{}"_f.format(
      dynamic_cast<ISymbol*>(this->M_declaringSymbolTable)->getFullQualifiedId(), 
      this->M_name
    );
  }

  auto Overload::getMangledId() const -> string {

  }

  auto Overload::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_declaringSymbolTable;
  }

  auto Overload::getAttributes() const -> Attributes {
    return {};
  }

}