#include "api/typechecker/TypeChecker.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {

  TypeChecker::TypeChecker(TranslationUnit& unit) noexcept
    : M_unit { &unit }
    , M_currentScope { nullptr }
  {
    llvm::LLVMContext& ctx = unit.getModule()->getContext();
    llvm::Module& mod = *unit.getModule();
  }

  auto TypeChecker::check() -> Vector<SemanticError> {
    auto result = this->visit(this->M_unit->getParseTree());
    /// TODO: do something with 'result'

    return this->M_errors;
  }
  
  auto TypeChecker::errorAt(ant::Token* token, String message) -> void {

    this->M_errors.push_back(
      SemanticError{
        SourceLocation {
          this->M_unit->getPath().generic_string(),
          token->getLine(),
          token->getCharPositionInLine()+1
        },
        std::move(message) 
      }
    );
  }

  auto TypeChecker::beginScope(SymbolTable& scope) noexcept -> void {
    this->M_currentScope = &scope;
  }

  auto TypeChecker::endScope() noexcept -> void {
    this->M_currentScope = this->M_currentScope->getParent();
  }

}