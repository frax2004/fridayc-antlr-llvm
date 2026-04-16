#pragma once

#include "Symbol.hpp"
#include "Type.hpp"
#include "PointerType.hpp"
#include "FunctionType.hpp"
#include "StructType.hpp"
#include "Variable.hpp"
#include "Function.hpp"
#include "Struct.hpp"
#include "SymbolTable.hpp"
#include "SemanticError.hpp"

#include "api/parser/FridayParserBaseVisitor.h"
#include "core/util/TranslationUnit.hpp"

namespace friday::inline api::inline typechecker {

  /// @brief Represents a type checker visitor
  struct TypeChecker : public FridayParserBaseVisitor {

    /// @brief Constructs a type checker
    /// @param unit the translation unit
    TypeChecker(TranslationUnit& unit) noexcept;

    /// @brief Run semantic analysis for this translation unit
    /// @return the errors (if any occurred)
    auto check() -> Vector<SemanticError>;

    /// @brief visit a Program
    /// @param ctx the Program context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitProgram(FridayParser::ProgramContext *ctx) -> std::any override;

    /// @brief visit a TopLevelStatement
    /// @param ctx the TopLevelStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any override;

    /// @brief visit a ReturnStatement
    /// @param ctx the ReturnStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any override; 

    /// @brief visit a PrintStatement
    /// @param ctx the PrintStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any override;

    /// @brief visit a Statement
    /// @param ctx the Statement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitStatement(FridayParser::StatementContext *ctx) -> std::any override;

    /// @brief visit a Block
    /// @param ctx the Block context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitBlock(FridayParser::BlockContext *ctx) -> std::any override;

    /// @brief visit a InlineBlock
    /// @param ctx the InlineBlock context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitInlineBlock(FridayParser::InlineBlockContext *ctx) -> std::any override;

    /// @brief visit a FunctionStatement
    /// @param ctx the FunctionStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any override;

    /// @brief visit a Call
    /// @param ctx the Call context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitCall(FridayParser::CallContext *ctx) -> std::any override;

    /// @brief visit a IdentifierContext
    /// @param ctx the IdentifierContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitIdentifier(FridayParser::IdentifierContext *ctx) -> std::any override;

    /// @brief visit a CharLiteralContext
    /// @param ctx the CharLiteralContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitCharLiteral(FridayParser::CharLiteralContext *ctx) -> std::any override;

    /// @brief visit a StringLiteralContext
    /// @param ctx the StringLiteralContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitStringLiteral(FridayParser::StringLiteralContext *ctx) -> std::any override;

    /// @brief visit a BoolLiteralContext
    /// @param ctx the BoolLiteralContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitBoolLiteral(FridayParser::BoolLiteralContext *ctx) -> std::any override;

    /// @brief visit a FloatLiteralContext
    /// @param ctx the FloatLiteralContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitFloatLiteral(FridayParser::FloatLiteralContext *ctx) -> std::any override;

    /// @brief visit a IntLiteralContext
    /// @param ctx the IntLiteralContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitIntLiteral(FridayParser::IntLiteralContext *ctx) -> std::any override;
    
    /// @brief visit a Grouping
    /// @param ctx the Grouping context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitGrouping(FridayParser::GroupingContext *ctx) -> std::any override;

    /// @brief visit a Subscript
    /// @param ctx the Subscript context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any override;

    /// @brief visit a Binary
    /// @param ctx the Binary context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitBinary(FridayParser::BinaryContext *ctx) -> std::any override;

    /// @brief visit a Unary
    /// @param ctx the Unary context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitUnary(FridayParser::UnaryContext *ctx) -> std::any override;

    /// @brief Visit a SimpleType
    /// @param ctx the SimpleType context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any override;
    
    /// @brief visit a FunctionType
    /// @param ctx the FunctionType context 
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any override;
    
    /// @brief visit a PointerType
    /// @param ctx the PointerType context 
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any override;
    
    /// @brief visit a Type
    /// @param ctx the Type context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks 
    auto visitType(FridayParser::TypeContext *ctx) -> std::any override;

    private:
    /// @brief Raises an error
    /// @param token the token where the error occurred
    /// @param message the error message
    auto errorAt(ant::Token* token, String message) -> void;

    /// @brief Push a scope into the stack of scopes using the call stack
    /// @param scope the new current scope
    auto beginScope(SymbolTable& scope) noexcept -> void;

    /// @brief Pop the current scope out of the stack of scopes in the call stack
    auto endScope() noexcept -> void;

    private:
    /// @brief the errors
    Vector<SemanticError> M_errors { };
    /// @brief the translation unit
    TranslationUnit* M_unit { nullptr };
    /// @brief the current scope (used as a stack of scopes)
    SymbolTable* M_currentScope { nullptr };
  };
}

