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

  auto TypeCheckerVisitor::find_binary_operator(string_view name, Type* lhsType, Type* rhsType) -> Function* {

    TranslationUnit* unit = this->get_current_unit();
    Overload* overload = nullptr;

    if(overload == nullptr) {
      ISymbol* candidate = unit->look_up_if(
        name, 
        dynamic_cast<ISymbolTable*>(unit->get_owned_namespace()), 
        &Overload::is_overload, 
        nullptr
      );

      if(candidate != nullptr) {
        overload = Overload::to_overload(candidate);
      }
    }

    if(auto lhsAsStruct = Struct::to_struct_type(lhsType); overload == nullptr and lhsAsStruct != nullptr) {
      overload = lhsAsStruct->find_method(name);
    }

    return overload != nullptr ? overload->try_match({ lhsType, rhsType }) : nullptr;
  }

  auto TypeCheckerVisitor::find_unary_operator(string_view name, Type* type) -> Function* {

    TranslationUnit* unit = this->get_current_unit();
    Overload* overload = nullptr;

    if(overload == nullptr) {
      ISymbol* candidate = unit->look_up_if(
        name, 
        dynamic_cast<ISymbolTable*>(unit->get_owned_namespace()), 
        &Overload::is_overload, 
        nullptr
      );

      if(candidate != nullptr) {
        overload = Overload::to_overload(candidate);
      }
    }


    if(auto lhsAsStruct = Struct::to_struct_type(type); overload == nullptr and lhsAsStruct != nullptr) {
      overload = lhsAsStruct->find_method(name);
    }

    return overload != nullptr ? overload->try_match({ type }) : nullptr;
  }

  auto TypeCheckerVisitor::on_unit_begin(TranslationUnit& unit) -> void {
    this->push(unit.get_owned_namespace());
  }

  auto TypeCheckerVisitor::on_unit_end(TranslationUnit& _) -> void {
    (void)_;
    this->pop();
  }

  auto TypeCheckerVisitor::check_scope(FridayParser::SyntacticalScopeContext* ctx) -> void {
    this->visitChildren(ctx);
    this->pop();
  }
  
  auto TypeCheckerVisitor::prepare_scope(FridayParser::SyntacticalScopeContext* ctx, vector<pair<string, Type*>> locals) -> void {
    ISymbolTable* parent = this->top();
    
    if(not parent) throw OperationNotSupportedError{};
    
    Scope* current = Scope::Factory::create(*parent);
    
    for(auto local : locals) {
      Variable* var = Variable::Factory::create(
        *dynamic_cast<ISymbolTable*>(current), 
        local.first, 
        *local.second
      );
      current->define(var);
    }
    
    $(ctx).scope = current;
    this->push($(ctx).scope);
  }

}