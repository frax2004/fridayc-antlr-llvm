
// Generated from FridayParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FridayParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by FridayParser.
 */
class  FridayParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(FridayParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(FridayParser::ProgramContext *ctx) = 0;

  virtual void enterTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) = 0;
  virtual void exitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) = 0;

  virtual void enterNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) = 0;
  virtual void exitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) = 0;

  virtual void enterNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) = 0;
  virtual void exitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) = 0;

  virtual void enterUsingStatement(FridayParser::UsingStatementContext *ctx) = 0;
  virtual void exitUsingStatement(FridayParser::UsingStatementContext *ctx) = 0;

  virtual void enterStructStatement(FridayParser::StructStatementContext *ctx) = 0;
  virtual void exitStructStatement(FridayParser::StructStatementContext *ctx) = 0;

  virtual void enterFunctionStatement(FridayParser::FunctionStatementContext *ctx) = 0;
  virtual void exitFunctionStatement(FridayParser::FunctionStatementContext *ctx) = 0;

  virtual void enterStatement(FridayParser::StatementContext *ctx) = 0;
  virtual void exitStatement(FridayParser::StatementContext *ctx) = 0;

  virtual void enterDeferrableStatement(FridayParser::DeferrableStatementContext *ctx) = 0;
  virtual void exitDeferrableStatement(FridayParser::DeferrableStatementContext *ctx) = 0;

  virtual void enterDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) = 0;
  virtual void exitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) = 0;

  virtual void enterIfStatement(FridayParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(FridayParser::IfStatementContext *ctx) = 0;

  virtual void enterForStatement(FridayParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(FridayParser::ForStatementContext *ctx) = 0;

  virtual void enterWhileStatement(FridayParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(FridayParser::WhileStatementContext *ctx) = 0;

  virtual void enterExpressionStatement(FridayParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterDeferStatement(FridayParser::DeferStatementContext *ctx) = 0;
  virtual void exitDeferStatement(FridayParser::DeferStatementContext *ctx) = 0;

  virtual void enterPrintStatement(FridayParser::PrintStatementContext *ctx) = 0;
  virtual void exitPrintStatement(FridayParser::PrintStatementContext *ctx) = 0;

  virtual void enterScope(FridayParser::ScopeContext *ctx) = 0;
  virtual void exitScope(FridayParser::ScopeContext *ctx) = 0;

  virtual void enterReturnStatement(FridayParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(FridayParser::ReturnStatementContext *ctx) = 0;

  virtual void enterInlineScope(FridayParser::InlineScopeContext *ctx) = 0;
  virtual void exitInlineScope(FridayParser::InlineScopeContext *ctx) = 0;

  virtual void enterFunctionScope(FridayParser::FunctionScopeContext *ctx) = 0;
  virtual void exitFunctionScope(FridayParser::FunctionScopeContext *ctx) = 0;

  virtual void enterMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) = 0;
  virtual void exitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) = 0;

  virtual void enterUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) = 0;
  virtual void exitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) = 0;

  virtual void enterStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) = 0;
  virtual void exitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) = 0;

  virtual void enterFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) = 0;
  virtual void exitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) = 0;

  virtual void enterNewExpression(FridayParser::NewExpressionContext *ctx) = 0;
  virtual void exitNewExpression(FridayParser::NewExpressionContext *ctx) = 0;

  virtual void enterArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) = 0;
  virtual void exitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) = 0;

  virtual void enterExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) = 0;
  virtual void exitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) = 0;

  virtual void enterIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) = 0;
  virtual void exitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) = 0;

  virtual void enterIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) = 0;
  virtual void exitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) = 0;

  virtual void enterBinaryExpression(FridayParser::BinaryExpressionContext *ctx) = 0;
  virtual void exitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) = 0;

  virtual void enterGroupingExpression(FridayParser::GroupingExpressionContext *ctx) = 0;
  virtual void exitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) = 0;

  virtual void enterUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) = 0;
  virtual void exitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) = 0;

  virtual void enterSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) = 0;
  virtual void exitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) = 0;

  virtual void enterBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) = 0;
  virtual void exitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) = 0;

  virtual void enterCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) = 0;
  virtual void exitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) = 0;

  virtual void enterCallExpression(FridayParser::CallExpressionContext *ctx) = 0;
  virtual void exitCallExpression(FridayParser::CallExpressionContext *ctx) = 0;

  virtual void enterNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) = 0;
  virtual void exitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) = 0;

  virtual void enterType(FridayParser::TypeContext *ctx) = 0;
  virtual void exitType(FridayParser::TypeContext *ctx) = 0;

  virtual void enterFunctionType(FridayParser::FunctionTypeContext *ctx) = 0;
  virtual void exitFunctionType(FridayParser::FunctionTypeContext *ctx) = 0;

  virtual void enterSimpleType(FridayParser::SimpleTypeContext *ctx) = 0;
  virtual void exitSimpleType(FridayParser::SimpleTypeContext *ctx) = 0;

  virtual void enterPointerType(FridayParser::PointerTypeContext *ctx) = 0;
  virtual void exitPointerType(FridayParser::PointerTypeContext *ctx) = 0;

  virtual void enterArrayType(FridayParser::ArrayTypeContext *ctx) = 0;
  virtual void exitArrayType(FridayParser::ArrayTypeContext *ctx) = 0;


};

