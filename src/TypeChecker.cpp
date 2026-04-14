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



  auto TypeChecker::visitProgram(FridayParser::ProgramContext *ctx) -> std::any {
    Console::debug("ProgramContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any {
    Console::debug("TopLevelStatementContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any {
    Console::debug("ReturnStatementContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any {
    Console::debug("PrintStatementContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitStatement(FridayParser::StatementContext *ctx) -> std::any {
    Console::debug("StatementContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitBlock(FridayParser::BlockContext *ctx) -> std::any {
    Console::debug("BlockContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitInlineBlock(FridayParser::InlineBlockContext *ctx) -> std::any {
    Console::debug("InlineBlockContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any {
    Console::debug("FunctionStatementContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitCall(FridayParser::CallContext *ctx) -> std::any {
    Console::debug("CallContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitIdentifier(FridayParser::IdentifierContext *ctx) -> std::any {
    Console::debug("IdentifierContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitCharLiteral(FridayParser::CharLiteralContext *ctx) -> std::any {
    Console::debug("CharLiteralContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitStringLiteral(FridayParser::StringLiteralContext *ctx) -> std::any {
    Console::debug("StringLiteralContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitBoolLiteral(FridayParser::BoolLiteralContext *ctx) -> std::any {
    Console::debug("BoolLiteralContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitFloatLiteral(FridayParser::FloatLiteralContext *ctx) -> std::any {
    Console::debug("FloatLiteralContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitIntLiteral(FridayParser::IntLiteralContext *ctx) -> std::any {
    Console::debug("IntLiteralContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitGrouping(FridayParser::GroupingContext *ctx) -> std::any {
    Console::debug("GroupingContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any {
    Console::debug("SubscriptContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitBinary(FridayParser::BinaryContext *ctx) -> std::any {
    Console::debug("BinaryContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitUnary(FridayParser::UnaryContext *ctx) -> std::any {
    Console::debug("UnaryContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any {
    Console::debug("SimpleTypeContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any {
    Console::debug("FunctionTypeContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any {
    Console::debug("PointerTypeContext: {}"_f.format(ctx->getText()));
  }

  auto TypeChecker::visitType(FridayParser::TypeContext *ctx) -> std::any {
    Console::debug("TypeContext: {}"_f.format(ctx->getText()));
  }

}