
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

    virtual std::any visitReturnStatement(FridayParser::ReturnStatementContext *context) = 0;

    virtual std::any visitPrintStatement(FridayParser::PrintStatementContext *context) = 0;

    virtual std::any visitStatement(FridayParser::StatementContext *context) = 0;

    virtual std::any visitInlineBlock(FridayParser::InlineBlockContext *context) = 0;

    virtual std::any visitBlock(FridayParser::BlockContext *context) = 0;

    virtual std::any visitFunctionStatement(FridayParser::FunctionStatementContext *context) = 0;

    virtual std::any visitCall(FridayParser::CallContext *context) = 0;

    virtual std::any visitPrimary(FridayParser::PrimaryContext *context) = 0;

    virtual std::any visitGrouping(FridayParser::GroupingContext *context) = 0;

    virtual std::any visitSubscript(FridayParser::SubscriptContext *context) = 0;

    virtual std::any visitBinary(FridayParser::BinaryContext *context) = 0;

    virtual std::any visitUnary(FridayParser::UnaryContext *context) = 0;

    virtual std::any visitSimpleType(FridayParser::SimpleTypeContext *context) = 0;

    virtual std::any visitFunctionType(FridayParser::FunctionTypeContext *context) = 0;

    virtual std::any visitPointerType(FridayParser::PointerTypeContext *context) = 0;

    virtual std::any visitType(FridayParser::TypeContext *context) = 0;


};

