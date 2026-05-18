#include "api/typesystem/Namespace.hpp"


namespace friday::inline api::inline typesystem {
  Namespace::Namespace(Map<String, Variable> variables, Map<String, Function> functions, Map<String, Struct> structs)
    : M_variables { std::move(variables) }
    , M_functions { std::move(functions) }
    , M_structs { std::move(structs) }
  {}

  auto Namespace::getGlobal() -> Namespace* {
    static Namespace GLOBAL{ };
    return &GLOBAL;
  }

  auto Namespace::getFunction(String const& id, Function* defaultValue) -> Function* {

  }

  auto Namespace::getStruct(String const& id, Struct* defaultValue) -> Struct* {

  }

  auto Namespace::getVariable(String const& id, Variable* defaultValue) -> Variable* {

  }

  auto Namespace::getQualifiedId() const -> String {

  }

  auto Namespace::getFullQualifiedId() const -> String {

  }

  auto Namespace::getMangledId() const -> String {

  }

  auto Namespace::getDeclaringSymbolTable() -> SymbolTable* {

  }

  auto Namespace::getAttributes() const -> Attributes const& {

  }

  auto Namespace::lookUp(String const& id, Symbol* defaultValue) -> Symbol* {

  }

  auto Namespace::lookUpIf(String const& id, SymbolPredicate predicate, Symbol* defaultValue) -> Symbol* {

  }

  auto Namespace::define(Symbol* symbol) -> bool {

  }

  auto Namespace::isDefined(String const& id) -> bool {

  }

  auto Namespace::getParent() -> SymbolTable* {

  }

  auto Namespace::mostSimilar(String const& name, u64 maxEditDistance, SymbolPredicate filter) noexcept -> Opt<Symbol*> {

  }
  
}