
// Generated from FridayParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FridayParserListener.h"


/**
 * This class provides an empty implementation of FridayParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  FridayParserBaseListener : public FridayParserListener {
public:

  virtual void enterProgram(FridayParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(FridayParser::ProgramContext * /*ctx*/) override { }

  virtual void enterTopLevelStatement(FridayParser::TopLevelStatementContext * /*ctx*/) override { }
  virtual void exitTopLevelStatement(FridayParser::TopLevelStatementContext * /*ctx*/) override { }

  virtual void enterNativeFunctionStatement(FridayParser::NativeFunctionStatementContext * /*ctx*/) override { }
  virtual void exitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext * /*ctx*/) override { }

  virtual void enterNamespaceStatement(FridayParser::NamespaceStatementContext * /*ctx*/) override { }
  virtual void exitNamespaceStatement(FridayParser::NamespaceStatementContext * /*ctx*/) override { }

  virtual void enterUsingStatement(FridayParser::UsingStatementContext * /*ctx*/) override { }
  virtual void exitUsingStatement(FridayParser::UsingStatementContext * /*ctx*/) override { }

  virtual void enterStructStatement(FridayParser::StructStatementContext * /*ctx*/) override { }
  virtual void exitStructStatement(FridayParser::StructStatementContext * /*ctx*/) override { }

  virtual void enterFunctionStatement(FridayParser::FunctionStatementContext * /*ctx*/) override { }
  virtual void exitFunctionStatement(FridayParser::FunctionStatementContext * /*ctx*/) override { }

  virtual void enterStatement(FridayParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(FridayParser::StatementContext * /*ctx*/) override { }

  virtual void enterDeferrableStatement(FridayParser::DeferrableStatementContext * /*ctx*/) override { }
  virtual void exitDeferrableStatement(FridayParser::DeferrableStatementContext * /*ctx*/) override { }

  virtual void enterDeclarationStatement(FridayParser::DeclarationStatementContext * /*ctx*/) override { }
  virtual void exitDeclarationStatement(FridayParser::DeclarationStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(FridayParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(FridayParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterForStatement(FridayParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(FridayParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(FridayParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(FridayParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterExpressionStatement(FridayParser::ExpressionStatementContext * /*ctx*/) override { }
  virtual void exitExpressionStatement(FridayParser::ExpressionStatementContext * /*ctx*/) override { }

  virtual void enterDeferStatement(FridayParser::DeferStatementContext * /*ctx*/) override { }
  virtual void exitDeferStatement(FridayParser::DeferStatementContext * /*ctx*/) override { }

  virtual void enterPrintStatement(FridayParser::PrintStatementContext * /*ctx*/) override { }
  virtual void exitPrintStatement(FridayParser::PrintStatementContext * /*ctx*/) override { }

  virtual void enterScope(FridayParser::ScopeContext * /*ctx*/) override { }
  virtual void exitScope(FridayParser::ScopeContext * /*ctx*/) override { }

  virtual void enterReturnStatement(FridayParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(FridayParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterInlineScope(FridayParser::InlineScopeContext * /*ctx*/) override { }
  virtual void exitInlineScope(FridayParser::InlineScopeContext * /*ctx*/) override { }

  virtual void enterFunctionScope(FridayParser::FunctionScopeContext * /*ctx*/) override { }
  virtual void exitFunctionScope(FridayParser::FunctionScopeContext * /*ctx*/) override { }

  virtual void enterMemberAccessExpression(FridayParser::MemberAccessExpressionContext * /*ctx*/) override { }
  virtual void exitMemberAccessExpression(FridayParser::MemberAccessExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext * /*ctx*/) override { }

  virtual void enterStringLiteralExpression(FridayParser::StringLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitStringLiteralExpression(FridayParser::StringLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterNewExpression(FridayParser::NewExpressionContext * /*ctx*/) override { }
  virtual void exitNewExpression(FridayParser::NewExpressionContext * /*ctx*/) override { }

  virtual void enterArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterExplicitCastExpression(FridayParser::ExplicitCastExpressionContext * /*ctx*/) override { }
  virtual void exitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext * /*ctx*/) override { }

  virtual void enterIntLiteralExpression(FridayParser::IntLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitIntLiteralExpression(FridayParser::IntLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterIdentifierExpression(FridayParser::IdentifierExpressionContext * /*ctx*/) override { }
  virtual void exitIdentifierExpression(FridayParser::IdentifierExpressionContext * /*ctx*/) override { }

  virtual void enterBinaryExpression(FridayParser::BinaryExpressionContext * /*ctx*/) override { }
  virtual void exitBinaryExpression(FridayParser::BinaryExpressionContext * /*ctx*/) override { }

  virtual void enterGroupingExpression(FridayParser::GroupingExpressionContext * /*ctx*/) override { }
  virtual void exitGroupingExpression(FridayParser::GroupingExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext * /*ctx*/) override { }

  virtual void enterSubscriptExpression(FridayParser::SubscriptExpressionContext * /*ctx*/) override { }
  virtual void exitSubscriptExpression(FridayParser::SubscriptExpressionContext * /*ctx*/) override { }

  virtual void enterBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterCharLiteralExpression(FridayParser::CharLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitCharLiteralExpression(FridayParser::CharLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterCallExpression(FridayParser::CallExpressionContext * /*ctx*/) override { }
  virtual void exitCallExpression(FridayParser::CallExpressionContext * /*ctx*/) override { }

  virtual void enterNullLiteralExpression(FridayParser::NullLiteralExpressionContext * /*ctx*/) override { }
  virtual void exitNullLiteralExpression(FridayParser::NullLiteralExpressionContext * /*ctx*/) override { }

  virtual void enterType(FridayParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(FridayParser::TypeContext * /*ctx*/) override { }

  virtual void enterFunctionType(FridayParser::FunctionTypeContext * /*ctx*/) override { }
  virtual void exitFunctionType(FridayParser::FunctionTypeContext * /*ctx*/) override { }

  virtual void enterSimpleType(FridayParser::SimpleTypeContext * /*ctx*/) override { }
  virtual void exitSimpleType(FridayParser::SimpleTypeContext * /*ctx*/) override { }

  virtual void enterPointerType(FridayParser::PointerTypeContext * /*ctx*/) override { }
  virtual void exitPointerType(FridayParser::PointerTypeContext * /*ctx*/) override { }

  virtual void enterArrayType(FridayParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(FridayParser::ArrayTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

