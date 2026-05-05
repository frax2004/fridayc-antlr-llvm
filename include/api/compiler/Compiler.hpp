#pragma once

#include "api/parser/FridayParserBaseVisitor.h"
#include "core/util/TranslationUnit.hpp"  

namespace friday::inline api::inline compiler {

  struct Compiler final : public FridayParserBaseVisitor {

    auto compile(TranslationUnit& unit) -> void;

    auto visitProgram(FridayParser::ProgramContext *ctx) -> std::any override;
    auto visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any override;
    auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any override;
    auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any override;
    auto visitStatement(FridayParser::StatementContext *ctx) -> std::any override;
    auto visitFunctionScope(FridayParser::FunctionScopeContext *ctx) -> std::any override;
    auto visitScope(FridayParser::ScopeContext *ctx) -> std::any override;
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any override;
    auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> std::any override;
    auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> std::any override;
    auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> std::any override;
    auto visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> std::any override;
    auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> std::any override;
    auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> std::any override;
    auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> std::any override;
    auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> std::any override;
    auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> std::any override;
    auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> std::any override;
    auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> std::any override;
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any override;
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any override;
    auto visitPointerTypeType(FridayParser::PointerTypeTypeContext *ctx) -> std::any override;
    auto visitPointedType(FridayParser::PointedTypeContext *ctx) -> std::any override;
    
    auto visitType(FridayParser::TypeContext *ctx) -> std::any override;

    private:
    TranslationUnit* M_unit;
  };
}