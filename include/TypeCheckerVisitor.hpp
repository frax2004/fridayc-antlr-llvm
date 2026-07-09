#pragma once

#include <SemanticError.hpp>
#include <StaticAnalyzer.hpp>

namespace friday::inline api::inline pipeline {

  struct TypeCheckerVisitor : StaticAnalyzer {
    private:
    stack<ISymbolTable*> M_symbolTables { };

    public:
    TypeCheckerVisitor(CompilationContext& ctx) noexcept;
    
    public:
    auto visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any override;
    auto visitIfStatement(FridayParser::IfStatementContext *ctx) -> any override;
    auto visitForStatement(FridayParser::ForStatementContext *ctx) -> any override;
    auto visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any override;
    auto visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any override;
    auto visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any override;
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any override;
    auto visitScope(FridayParser::ScopeContext *ctx) -> any override;
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any override;
    auto visitInlineScope(FridayParser::InlineScopeContext *ctx) -> any override;
    
    auto visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any override;
    auto visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any override;
    auto visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any override;
    auto visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any override;
    auto visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any override;
    auto visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any override;
    auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any override;
    auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any override;
    auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any override;
    auto visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any override;
    auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any override;
    auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any override;
    auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any override;
    auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any override;
    auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any override;
    auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any override;
    auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any override;
    
    virtual auto beginUnit(TranslationUnit& unit) -> void final override;
    virtual auto endUnit(TranslationUnit& unit) -> void final override;

    private:
    auto push(ISymbolTable& scope) -> void;
    auto pop() -> ISymbolTable*;
    auto top() -> ISymbolTable*;

    auto BYTE() -> Type*;
    auto INT() -> Type*;
    auto BOOL() -> Type*;
    auto VOID() -> Type*;
    auto FLOAT() -> Type*;

    template<class T>
    auto byVisiting() -> function<any (T*)> {
      return [this](T* ctx) { return this->visit(ctx); };
    }

    auto findBinaryOperator(string operatorName, Type* lhs, Type* rhs) -> weak<Function>;
  };
}
