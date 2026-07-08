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
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("byte").lock().get());
  }

  auto TypeChecker::INT() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("int").lock().get());
  }

  auto TypeChecker::BOOL() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("bool").lock().get());
  }

  auto TypeChecker::VOID() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("void").lock().get());
  }

  auto TypeChecker::FLOAT() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("float").lock().get());
  }

}