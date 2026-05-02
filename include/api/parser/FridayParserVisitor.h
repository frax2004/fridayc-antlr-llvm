
// Generated from FridayParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "FridayParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by FridayParser.
 */
class  FridayParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by FridayParser.
   */
    virtual std::any visitProgram(FridayParser::ProgramContext *context) = 0;

    virtual std::any visitTopLevelStatement(FridayParser::TopLevelStatementContext *context) = 0;

    virtual std::any visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *context) = 0;

    virtual std::any visitNamespaceStatement(FridayParser::NamespaceStatementContext *context) = 0;

    virtual std::any visitUsingStatement(FridayParser::UsingStatementContext *context) = 0;

    virtual std::any visitStructStatement(FridayParser::StructStatementContext *context) = 0;

    virtual std::any visitFunctionStatement(FridayParser::FunctionStatementContext *context) = 0;

    virtual std::any visitStatement(FridayParser::StatementContext *context) = 0;

    virtual std::any visitDeferrableStatement(FridayParser::DeferrableStatementContext *context) = 0;

    virtual std::any visitDeclarationStatement(FridayParser::DeclarationStatementContext *context) = 0;

    virtual std::any visitIfStatement(FridayParser::IfStatementContext *context) = 0;

    virtual std::any visitForStatement(FridayParser::ForStatementContext *context) = 0;

    virtual std::any visitWhileStatement(FridayParser::WhileStatementContext *context) = 0;

    virtual std::any visitExpressionStatement(FridayParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitDeferStatement(FridayParser::DeferStatementContext *context) = 0;

    virtual std::any visitPrintStatement(FridayParser::PrintStatementContext *context) = 0;

    virtual std::any visitScope(FridayParser::ScopeContext *context) = 0;

    virtual std::any visitReturnStatement(FridayParser::ReturnStatementContext *context) = 0;

    virtual std::any visitInlineScope(FridayParser::InlineScopeContext *context) = 0;

    virtual std::any visitFunctionScope(FridayParser::FunctionScopeContext *context) = 0;

    virtual std::any visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *context) = 0;

    virtual std::any visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *context) = 0;

    virtual std::any visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *context) = 0;

    virtual std::any visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *context) = 0;

    virtual std::any visitNewExpression(FridayParser::NewExpressionContext *context) = 0;

    virtual std::any visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *context) = 0;

    virtual std::any visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *context) = 0;

    virtual std::any visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *context) = 0;

    virtual std::any visitIdentifierExpression(FridayParser::IdentifierExpressionContext *context) = 0;

    virtual std::any visitBinaryExpression(FridayParser::BinaryExpressionContext *context) = 0;

    virtual std::any visitGroupingExpression(FridayParser::GroupingExpressionContext *context) = 0;

    virtual std::any visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *context) = 0;

    virtual std::any visitSubscriptExpression(FridayParser::SubscriptExpressionContext *context) = 0;

    virtual std::any visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *context) = 0;

    virtual std::any visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *context) = 0;

    virtual std::any visitCallExpression(FridayParser::CallExpressionContext *context) = 0;

    virtual std::any visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *context) = 0;

    virtual std::any visitType(FridayParser::TypeContext *context) = 0;

    virtual std::any visitFunctionType(FridayParser::FunctionTypeContext *context) = 0;

    virtual std::any visitSimpleType(FridayParser::SimpleTypeContext *context) = 0;

    virtual std::any visitPointerType(FridayParser::PointerTypeContext *context) = 0;

    virtual std::any visitArrayType(FridayParser::ArrayTypeContext *context) = 0;


};

