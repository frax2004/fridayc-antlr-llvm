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
    auto visitBlock(FridayParser::BlockContext *ctx) -> std::any override;
    auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any override;
    auto visitCall(FridayParser::CallContext *ctx) -> std::any override;
    auto visitIdentifier(FridayParser::IdentifierContext *ctx) -> std::any override;
    auto visitCharLiteral(FridayParser::CharLiteralContext *ctx) -> std::any override;
    auto visitStringLiteral(FridayParser::StringLiteralContext *ctx) -> std::any override;
    auto visitBoolLiteral(FridayParser::BoolLiteralContext *ctx) -> std::any override;
    auto visitFloatLiteral(FridayParser::FloatLiteralContext *ctx) -> std::any override;
    auto visitIntLiteral(FridayParser::IntLiteralContext *ctx) -> std::any override;
    auto visitGrouping(FridayParser::GroupingContext *ctx) -> std::any override;
    auto visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any override;
    auto visitBinary(FridayParser::BinaryContext *ctx) -> std::any override;
    auto visitUnary(FridayParser::UnaryContext *ctx) -> std::any override;
    auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any override;
    auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any override;
    auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any override;
    auto visitType(FridayParser::TypeContext *ctx) -> std::any override;

    private:
    TranslationUnit* M_unit;
  };
}