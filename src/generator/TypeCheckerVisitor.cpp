#include <fridayc.hpp>


namespace friday::inline api {

  TypeCheckerVisitor::TypeCheckerVisitor(CompilationContext& ctx) noexcept
    : StaticAnalyzer { ctx }
  {}

  auto TypeCheckerVisitor::push(ISymbolTable* scope) -> void {
    if(scope == nullptr) throw InvalidArgumentError{};
    this->M_symbolTables.push(scope);
  }

  auto TypeCheckerVisitor::pop() -> ISymbolTable* {
    if(this->M_symbolTables.empty()) throw OperationNotSupportedError{};
    ISymbolTable* x = this->top();
    this->M_symbolTables.pop();
    return x;
  }

  auto TypeCheckerVisitor::top() -> ISymbolTable* {
    if(this->M_symbolTables.empty()) throw OperationNotSupportedError{};
    return this->M_symbolTables.top();
  }

  auto TypeCheckerVisitor::BYTE() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("byte"));
  }

  auto TypeCheckerVisitor::INT() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("int"));
  }

  auto TypeCheckerVisitor::BOOL() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("bool"));
  }

  auto TypeCheckerVisitor::VOID() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("void"));
  }

  auto TypeCheckerVisitor::VOIDPTR() -> Type* {
    return PointerType::get(*this->VOID(), 1);
  }

  auto TypeCheckerVisitor::FLOAT() -> Type* {
    return dynamic_cast<Type*>(Namespace::get_global_namespace()->find_struct("float"));
  }

  auto TypeCheckerVisitor::find_binary_operator(string_view name, Type* lhsType, Type* rhsType) -> Function* {

    auto unit = this->get_current_unit();

    auto try_match = [lhsType, rhsType](Overload* ref) { 
      auto obj = ref->try_match(vector{ lhsType, rhsType });
      return obj != nullptr ? optional{ obj } : nullopt;
    };

    auto search_within_global_scope = [unit, name]() {
      auto obj = unit->look_up_if(
        name, 
        dynamic_cast<ISymbolTable*>(unit->get_owned_namespace()), 
        &Overload::is_overload, 
        {}
      );
      return obj != nullptr ? optional{ obj } : nullopt;
    };

    auto search_within_left_struct = [lhsType, name]() -> optional<ISymbol*> {
      if(auto lhsAsStruct = dynamic_cast<Struct*>(lhsType); lhsAsStruct != nullptr) {
        auto obj = lhsAsStruct->find_method(name);
        return obj != nullptr ? optional{ obj } : nullopt;
      } else return nullopt;
    };

    return search_within_left_struct()
    .or_else(search_within_global_scope)
    .transform(&Overload::to_overload)
    .and_then(try_match)
    .value_or({});
  }

  auto TypeCheckerVisitor::find_unary_operator(string_view name, Type* type) -> Function* {
    
    auto unit = this->get_current_unit();

    auto search_within_global_scope = [unit, name]() {
      auto obj = unit->look_up_if(
        name, 
        dynamic_cast<ISymbolTable*>(unit->get_owned_namespace()), 
        &Overload::is_overload, 
        {}
      );
      return obj != nullptr ? optional{ obj } : nullopt;
    };

    auto try_match = [type](Overload* ref) { 
      auto obj = ref->try_match(vector{ type });
      return obj != nullptr ? optional{ obj } : nullopt;
    };

    auto search_within_left_struct = [type, name]() -> optional<ISymbol*> {
      if(auto lhsAsStruct = dynamic_cast<Struct*>(type); lhsAsStruct != nullptr) {
        auto obj = lhsAsStruct->find_method(name);
        return obj != nullptr ? optional{ obj } : nullopt;
      } else return nullopt;
    };

    return search_within_left_struct()
    .or_else(search_within_global_scope)
    .transform(&Overload::to_overload)
    .and_then(try_match)
    .value_or({});
  }

  auto TypeCheckerVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    this->push(unit.get_owned_namespace());
  }

  auto TypeCheckerVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
    this->pop();
  }

}