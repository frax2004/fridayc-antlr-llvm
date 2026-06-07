#include <TypeSolverVisitor.hpp>

namespace friday::inline api::inline pipeline {
  TypeSolverVisitor::TypeSolverVisitor(CompilationContext& ctx)
    : context { &ctx }
  {}

  auto TypeSolverVisitor::solve() -> TypeSolverVisitor& {
    for(auto& unit : this->context->units) {
      this->setCurrentUnit(unit.get());
      this->visit(unit->ast);
      this->setCurrentUnit(nullptr);
    }

    return *this;
  }

  auto TypeSolverVisitor::visitStructStatement(FridayParser::StructStatementContext* ctx) -> any {
  }

}
