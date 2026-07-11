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
    return rtti::cast<Type>(this->get_current_unit()->comp_context()->get_global()->find_struct("byte").lock().get());
  }

  auto TypeCheckerVisitor::INT() -> Pointer<Type> {
    return rtti::cast<Type>(this->get_current_unit()->comp_context()->get_global()->find_struct("int").lock().get());
  }

  auto TypeCheckerVisitor::BOOL() -> Pointer<Type> {
    return rtti::cast<Type>(this->get_current_unit()->comp_context()->get_global()->find_struct("bool").lock().get());
  }

  auto TypeCheckerVisitor::VOID() -> Pointer<Type> {
    return rtti::cast<Type>(this->get_current_unit()->comp_context()->get_global()->find_struct("void").lock().get());
  }

  auto TypeCheckerVisitor::FLOAT() -> Pointer<Type> {
    return rtti::cast<Type>(this->get_current_unit()->comp_context()->get_global()->find_struct("float").lock().get());
  }

  auto TypeCheckerVisitor::find_binary_operator(string_view name, Pointer<Type> lhsType, Pointer<Type> rhsType) -> weak<Function> {
    auto toOptional = []<typename T>(weak<T> ref) { 
      return not ref.expired() ? make_optional(ref) : nullopt; 
    };

    auto is_overload = [](Pointer<ISymbol> symbol) { 
      return rtti::instance_of<Overload>(symbol); 
    };

    auto to_overload = [](rc<ISymbol> ref) { 
      return dynamic_pointer_cast<Overload>(ref); 
    };

    auto try_match = [lhsType, rhsType, toOptional](rc<Overload> ref) { 
      return toOptional(ref->try_match({lhsType, rhsType})); 
    };

    weak<ISymbol> candidate = this->get_current_unit()->look_up_if(name, is_overload, {});

    auto searchInStruct = [lhsType, candidate, name, toOptional]() -> optional<weak<ISymbol>> {
      if(auto lhsAsStruct = rtti::cast<Struct>(lhsType); candidate.expired() and lhsAsStruct != nullptr) {
        return toOptional(lhsAsStruct->find_method(name));
      } else return nullopt;
    };

    // Attempt to find a matching operator within the current namespace
    return toOptional(candidate)
    // Attempt to find a matching operator within lhs' struct
    .or_else(searchInStruct)
    .transform(&weak<ISymbol>::lock)
    .transform(to_overload)
    // Attempt to match the operator with the operands
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