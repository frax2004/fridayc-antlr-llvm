#include "TypeCheckerVisitor.hpp"
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline pipeline {

  TypeCheckerVisitor::TypeCheckerVisitor(CompilationContext& ctx) noexcept
    : StaticAnalyzer { ctx }
  {}

  auto TypeCheckerVisitor::push(weak<ISymbolTable> scope) -> void {
    this->M_symbolTables.push(scope);
  }

  auto TypeCheckerVisitor::pop() -> weak<ISymbolTable> {
    if(this->M_symbolTables.empty()) return {};
    weak<ISymbolTable> x = this->top();
    this->M_symbolTables.pop();
    return x;
  }

  auto TypeCheckerVisitor::top() -> weak<ISymbolTable> {
    return not this->M_symbolTables.empty() ? this->M_symbolTables.top() : weak<ISymbolTable>{};
  }

  auto TypeCheckerVisitor::BYTE() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("byte").lock().get());
  }

  auto TypeCheckerVisitor::INT() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("int").lock().get());
  }

  auto TypeCheckerVisitor::BOOL() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("bool").lock().get());
  }

  auto TypeCheckerVisitor::VOID() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("void").lock().get());
  }

  auto TypeCheckerVisitor::FLOAT() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("float").lock().get());
  }

  auto TypeCheckerVisitor::find_binary_operator(string_view name, Pointer<Type> lhsType, Pointer<Type> rhsType) -> weak<Function> {

    weak<ISymbol> candidate = this->get_current_unit()->look_up_if(name, &Overload::is_overload, {});

    auto try_match = [lhsType, rhsType](Overload* ref) { 
      return ref->try_match({lhsType, rhsType}).to_optional();
    };

    auto search_within_left_struct = [lhsType, candidate, name]() -> optional<weak<ISymbol>> {
      if(auto lhsAsStruct = rtti::cast<Struct>(lhsType); candidate.expired() and lhsAsStruct != nullptr) {
        return lhsAsStruct->find_method(name).to_optional();
      } else return nullopt;
    };

    return candidate
    .to_optional()
    .or_else(search_within_left_struct)
    .transform(&weak<ISymbol>::lock)
    .transform(&rc<ISymbol>::get)
    .transform(&Overload::to_overload)
    .and_then(try_match)
    .value_or({});
  }
  
  auto TypeCheckerVisitor::on_unit_begin(TranslationUnit& _) -> void {
    (void)_;
  }

  auto TypeCheckerVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
  }

}