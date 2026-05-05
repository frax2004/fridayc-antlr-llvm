#pragma once

#include "Symbol.hpp"
#include "SymbolTable.hpp"
#include "Struct.hpp"
#include "Variable.hpp"
#include "Function.hpp"


namespace friday::inline api::inline typesystem {

  struct Namespace : public Symbol, public SymbolTable {
    private:
    Namespace* M_parent;
    Map<String, Box<Struct>> M_structs;
    Map<String, Box<Variable>> M_variables;
    Map<String, Box<Function>> M_functions;
    
    public:
    Namespace(
      Namespace* parent,
      Map<String, Box<Variable>> variables,
      Map<String, Box<Function>> functions,
      Map<String, Box<Struct>> structs
    );

    static auto getGlobal() -> Namespace*;
    auto getFunction(String const& id, Function* defaultValue) -> Function*;
    auto getStruct(String const& id, Struct* defaultValue) -> Struct*;
    auto getVariable(String const& id, Variable* defaultValue) -> Variable*;
  };


}
