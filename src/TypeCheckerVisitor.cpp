#include "TypeCheckerVisitor.hpp"
#include <OperationNotSupportedError.hpp>
#include <PointerType.hpp>

namespace friday::inline api::inline pipeline {

  TypeCheckerVisitor::TypeCheckerVisitor(CompilationContext& ctx) noexcept
    : StaticAnalyzer { ctx }
  {}

  auto TypeCheckerVisitor::push(Pointer<ISymbolTable> scope) -> void {
    this->M_symbolTables.push(scope);
  }

  auto TypeCheckerVisitor::pop() -> Pointer<ISymbolTable> {
    if(this->M_symbolTables.empty()) return nullptr;
    Pointer<ISymbolTable> x = this->top();
    this->M_symbolTables.pop();
    return x;
  }

  auto TypeCheckerVisitor::top() -> Pointer<ISymbolTable> {
    return not this->M_symbolTables.empty() ? this->M_symbolTables.top() : nullptr;
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

  auto TypeCheckerVisitor::VOIDPTR() -> Pointer<Type> {
    return PointerType::get(*this->VOID(), 1);
  }

  auto TypeCheckerVisitor::FLOAT() -> Pointer<Type> {
    return rtti::cast<Type>(this->comp_context().get_global()->find_struct("float").lock().get());
  }

  auto TypeCheckerVisitor::find_binary_operator(string_view name, Pointer<Type> lhsType, Pointer<Type> rhsType) -> weak<Function> {

    auto unit = this->get_current_unit();

    auto try_match = [lhsType, rhsType](Overload* ref) { 
      return ref->try_match(vector{ lhsType, rhsType }).to_optional();
    };

    auto search_within_global_scope = [unit, name]() {
      return unit->look_up_if(
        name, 
        rtti::cast<ISymbolTable>(unit->get_owned_namespace().lock().get()), 
        &Overload::is_overload, 
        {}
      ).to_optional();
    };

    auto search_within_left_struct = [lhsType, name]() -> optional<weak<ISymbol>> {
      if(auto lhsAsStruct = rtti::cast<Struct>(lhsType); lhsAsStruct != nullptr) {
        return lhsAsStruct->find_method(name).to_optional();
      } else return nullopt;
    };

    return search_within_left_struct()
    .or_else(search_within_global_scope)
    .transform(&weak<ISymbol>::lock)
    .transform(&rc<ISymbol>::get)
    .transform(&Overload::to_overload)
    .and_then(try_match)
    .value_or({});
  }

  auto TypeCheckerVisitor::find_unary_operator(string_view name, Pointer<Type> type) -> weak<Function> {
    
    auto unit = this->get_current_unit();
    weak<ISymbol> candidate = unit->look_up_if(
      name, 
      rtti::cast<ISymbolTable>(unit->get_owned_namespace().lock().get()), 
      &Overload::is_overload, 
      {}
    );

    auto try_match = [type](Overload* ref) { 
      return ref->try_match(vector{ type }).to_optional();
    };

    auto search_within_left_struct = [type, candidate, name]() -> optional<weak<ISymbol>> {
      if(auto lhsAsStruct = rtti::cast<Struct>(type); candidate.expired() and lhsAsStruct != nullptr) {
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

  auto TypeCheckerVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    this->push(unit.get_owned_namespace().lock().get());
  }

  auto TypeCheckerVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
    this->pop();
  }

}