#pragma once
#include <StaticAnalyzer.hpp>
#include <llvm/IR/IRBuilder.h>


namespace friday::inline api::inline pipeline {
  // will emit the llvm object files
  struct FRIDAY_API LLVMObjectEmitterVisitor final : StaticAnalyzer {
  
    private:
    weak<llvm::Module>    M_currentModule { };
    rc<llvm::IRBuilder<>> M_builder       { nullptr };

    public:
    LLVMObjectEmitterVisitor(CompilationContext& ctx);
    ~LLVMObjectEmitterVisitor() override = default;

    auto visitFreeFunctionStatement(FridayParser::FreeFunctionStatementContext *ctx) -> any override;
    auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any override;
    auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any override;
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any override;
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any override;
    auto visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any override;
    auto visitIfStatement(FridayParser::IfStatementContext *ctx) -> any override;
    auto visitForStatement(FridayParser::ForStatementContext *ctx) -> any override;
    auto visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any override;
    auto visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any override;
    auto visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any override;
    auto visitScopeStatement(FridayParser::ScopeStatementContext *ctx) -> any override;
    auto visitSyntacticalScope(FridayParser::SyntacticalScopeContext *ctx) -> any override;
    auto visitBasicBlock(FridayParser::BasicBlockContext *ctx) -> any override;
    auto visitTrailingBlock(FridayParser::TrailingBlockContext *ctx) -> any override;

    auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any override;
    auto visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any override;
    auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any override;
    auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any override;
    auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any override;
    auto visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any override;
    auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any override;
    auto visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> any override;

    // auto visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any override;
    // auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any override;
    // auto visitAssignmentExpression(FridayParser::AssignmentExpressionContext *ctx) -> any override;
    // auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any override;
    // auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any override;
    // auto visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any override;

    // auto visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any override;
    // auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any override;
    // auto visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any override;
    // auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any override;
    // auto visitCompTimeUnaryPrefixExpression(FridayParser::CompTimeUnaryPrefixExpressionContext *ctx) -> any override;

    virtual auto on_unit_begin(TranslationUnit& unit) -> void final override;
    virtual auto on_unit_end(TranslationUnit& unit) -> void final override;

    private:
    auto current() const -> rc<llvm::Module>;
  };
}
