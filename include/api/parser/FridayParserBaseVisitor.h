
// Generated from FridayParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FridayParserVisitor.h"


/**
 * This class provides an empty implementation of FridayParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  FridayParserBaseVisitor : public FridayParserVisitor {
public:

  virtual std::any visitProgram(FridayParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUsingStatement(FridayParser::UsingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructStatement(FridayParser::StructStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(FridayParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeferrableStatement(FridayParser::DeferrableStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(FridayParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(FridayParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(FridayParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeferStatement(FridayParser::DeferStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStatement(FridayParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScope(FridayParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(FridayParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInlineScope(FridayParser::InlineScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionScope(FridayParser::FunctionScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpression(FridayParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallExpression(FridayParser::CallExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(FridayParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionType(FridayParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleType(FridayParser::SimpleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointerType(FridayParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(FridayParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

