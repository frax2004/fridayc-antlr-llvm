#include "TypeCheckerVisitor.hpp"
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  TypeCheckerVisitor::TypeCheckerVisitor(CompilationContext& ctx) noexcept
    : StaticAnalyzer { ctx }
  {}

  auto TypeCheckerVisitor::push(ISymbolTable& scope) -> void {
    this->M_symbolTables.push(&scope);
  }

  auto TypeCheckerVisitor::pop() -> ISymbolTable* {
    ISymbolTable* x = this->M_symbolTables.top();
    this->M_symbolTables.pop();
    return x;
  }

  auto TypeCheckerVisitor::top() -> ISymbolTable* {
    return this->M_symbolTables.top();
  }

  auto TypeCheckerVisitor::BYTE() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("byte").lock().get());
  }

  auto TypeCheckerVisitor::INT() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("int").lock().get());
  }

  auto TypeCheckerVisitor::BOOL() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("bool").lock().get());
  }

  auto TypeCheckerVisitor::VOID() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("void").lock().get());
  }

  auto TypeCheckerVisitor::FLOAT() -> Type* {
    return rtti::cast<Type>(this->getCurrentUnit()->globalContext->global->getStruct("float").lock().get());
  }

  auto TypeCheckerVisitor::findBinaryOperator(string operatorName, Type* lhsType, Type* rhsType) -> weak<Function> {
    auto toOptional = []<typename T>(weak<T> ref) { 
      return not ref.expired() ? make_optional(ref) : nullopt; 
    };

    auto isOverload = [](ISymbol* symbol) { 
      return rtti::instanceOf<Overload>(symbol); 
    };

    auto toOverload = [](rc<ISymbol> ref) { 
      return dynamic_pointer_cast<Overload>(ref); 
    };
    
    auto tryMatch = [lhsType, rhsType, toOptional](rc<Overload> ref) { 
      return toOptional(ref->tryMatch({lhsType, rhsType})); 
    };

    weak<ISymbol> candidate = this->getCurrentUnit()->lookUpIf(operatorName, isOverload, {});

    auto searchInStruct = [lhsType, candidate, operatorName]() -> optional<weak<ISymbol>> {
      if(auto lhsAsStruct = rtti::cast<Struct>(lhsType); candidate.expired() and lhsAsStruct != nullptr) {
        return make_optional(lhsAsStruct->getMethod(operatorName));
      } else return nullopt;
    };

    // Attempt to find a matching operator within the current namespace
    return toOptional(candidate)
    // Attempt to find a matching operator within lhs' struct
    .or_else(searchInStruct)
    .transform(&weak<ISymbol>::lock)
    .transform(toOverload)
    // Attempt to match the operator with the operands
    .and_then(tryMatch)
    .value_or({});
  }
  
  auto TypeCheckerVisitor::beginUnit(TranslationUnit& unit) -> void {

  }

  auto TypeCheckerVisitor::endUnit(TranslationUnit& unit) -> void {
  }

}