#include <Overload.hpp>
#include <NotImplementedError.hpp>
#include <OperationNotSupportedError.hpp>
#include <UnresolvedOverloadType.hpp>


namespace friday::inline api::inline typesystem {

  Overload::Overload(ISymbolTable& parent, string name)
    : M_declaringSymbolTable { &parent }
    , M_name { move(name) }
  {}

  auto Overload::getFunctions() const -> vector<weak<Function>> {
    auto toWeak = [](rc<Function> ref) -> weak<Function> { return ref; };

    return this->M_overloads 
    | views::values 
    | views::transform(toWeak)
    | ranges::to<vector>();
  }

  auto Overload::add(vector<Type*> argsTypes, rc<Function> function) -> void {
    this->M_overloads.try_emplace(move(argsTypes), function);
  }

  auto Overload::tryMatch(vector<Type*> const& argsTypes) -> weak<Function> {
    if(auto it = this->M_overloads.find(argsTypes); it != this->M_overloads.end()) {
      return it->second;
    } else return {};
  }

  auto Overload::hasMatch(vector<Type*> const& argsTypes) const -> bool {
    return this->M_overloads.contains(argsTypes);
  }

  auto Overload::getQualifiedId() const -> string {
    return this->M_name;
  }

  auto Overload::getFullQualifiedId() const -> string {
    return "{}.{}"_f.format(
      rtti::cast<ISymbol>(this->M_declaringSymbolTable)->getFullQualifiedId(), 
      this->M_name
    );
  }

  auto Overload::getMangledId() const -> string {
    throw OperationNotSupportedError{"Overload::getMangledId()"};
  }

  auto Overload::getDeclaringSymbolTable() -> ISymbolTable* {
    return this->M_declaringSymbolTable;
  }

  auto Overload::getAttributes() const -> Attributes {
    throw NotImplementedError{"Overload::getAttributes()"};
  }
  
  auto Overload::getType() const -> Type* {
    return UnresolvedOverloadType::get();
  }

  auto Overload::isOverload(ISymbol* symbol) -> bool {
    return rtti::instanceOf<Overload>(symbol);
  }

  auto Overload::toOverload(ISymbol* symbol) -> Overload* {
    return rtti::cast<Overload>(symbol);
  }

}