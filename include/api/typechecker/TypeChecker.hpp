#pragma once

#include "Symbol.hpp"
#include "Type.hpp"
#include "Pointer.hpp"
#include "FunctionType.hpp"
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

    /// @brief visit a ReturnStatement
    /// @param ctx the ReturnStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any override; 

    /// @brief visit a PrintStatement
    /// @param ctx the PrintStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any override;

    /// @brief visit a Scope
    /// @param ctx the Scope context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitScope(FridayParser::ScopeContext *ctx) -> std::any override;

    /// @brief visit a InlineScope
    /// @param ctx the InlineScope context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitInlineScope(FridayParser::InlineScopeContext *ctx) -> std::any override;

    /// @brief visit a FunctionStatement
    /// @param ctx the FunctionStatement context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any override;

    /// @brief visit a CallExpression
    /// @param ctx the CallExpression context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> std::any override;

    /// @brief visit a IdentifierExpressionContext
    /// @param ctx the IdentifierExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> std::any override;

    /// @brief visit a CharLiteralExpressionContext
    /// @param ctx the CharLiteralExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> std::any override;

    /// @brief visit a StringLiteralExpressionContext
    /// @param ctx the StringLiteralExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> std::any override;

    /// @brief visit a BoolLiteralExpressionContext
    /// @param ctx the BoolLiteralExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> std::any override;

    /// @brief visit a FloatLiteralExpressionContext
    /// @param ctx the FloatLiteralExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> std::any override;

    /// @brief visit a IntLiteralExpressionContext
    /// @param ctx the IntLiteralExpressionContext context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> std::any override;
    
    /// @brief visit a GroupingExpression
    /// @param ctx the GroupingExpression context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> std::any override;

    /// @brief visit a SubscriptExpression
    /// @param ctx the SubscriptExpression context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> std::any override;

    /// @brief visit a BinaryExpression
    /// @param ctx the BinaryExpression context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> std::any override;

    /// @brief visit a UnaryPrefixExpression
    /// @param ctx the UnaryPrefixExpression context
    /// @return a Struct type or Struct::getErrorType() if any error has occurred during semantic checks
    auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> std::any override;

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

    /// @brief Gets the bound visitor to this instance
    /// @tparam T the context type
    /// @return The bound visitor
    template<class T>
    auto byVisiting() const noexcept -> std::function<std::any (T*)>;

    private:
    /// @brief the errors
    Vector<SemanticError> M_errors { };
    /// @brief the translation unit
    TranslationUnit* M_unit { nullptr };
    /// @brief The current function return type
    Type* M_currentFunctionReturnType { nullptr };
    /// @brief the current scope (used as a stack of scopes)
    SymbolTable* M_currentScope { nullptr };
  
  }; // struct TypeChecker
} // namespace friday::api::typechecker


#include "TypeChecker.inl"