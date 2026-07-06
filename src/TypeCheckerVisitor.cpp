#include "TypeCheckerVisitor.hpp"
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  auto TypeChecker::push(ISymbolTable& scope) -> void {
    this->M_symbolTables.push(&scope);
  }

  auto TypeChecker::pop() -> ISymbolTable* {
    ISymbolTable* x = this->M_symbolTables.top();
    this->M_symbolTables.pop();
    return x;
  }

  auto TypeChecker::top() -> ISymbolTable* {
    return this->M_symbolTables.top();
  }

  auto TypeChecker::BYTE() -> Type* {
    return this->getCurrentUnit()->globalContext->global->getStruct("byte");
  }

  auto TypeChecker::INT() -> Type* {
    return this->getCurrentUnit()->globalContext->global->getStruct("int");
  }

  auto TypeChecker::BOOL() -> Type* {
    return this->getCurrentUnit()->globalContext->global->getStruct("bool");
  }

  auto TypeChecker::VOID() -> Type* {
    return this->getCurrentUnit()->globalContext->global->getStruct("void");
  }

  auto TypeChecker::FLOAT() -> Type* {
    return this->getCurrentUnit()->globalContext->global->getStruct("float");
  }

}