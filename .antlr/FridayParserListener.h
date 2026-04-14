
// Generated from c:/Dev/C++/fridayc-antlr-llvm/FridayParser.g4 by ANTLR 4.13.1

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

  virtual void enterReturnStatement(FridayParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(FridayParser::ReturnStatementContext *ctx) = 0;

  virtual void enterPrintStatement(FridayParser::PrintStatementContext *ctx) = 0;
  virtual void exitPrintStatement(FridayParser::PrintStatementContext *ctx) = 0;

  virtual void enterStatement(FridayParser::StatementContext *ctx) = 0;
  virtual void exitStatement(FridayParser::StatementContext *ctx) = 0;

  virtual void enterInlineBlock(FridayParser::InlineBlockContext *ctx) = 0;
  virtual void exitInlineBlock(FridayParser::InlineBlockContext *ctx) = 0;

  virtual void enterBlock(FridayParser::BlockContext *ctx) = 0;
  virtual void exitBlock(FridayParser::BlockContext *ctx) = 0;

  virtual void enterFunctionStatement(FridayParser::FunctionStatementContext *ctx) = 0;
  virtual void exitFunctionStatement(FridayParser::FunctionStatementContext *ctx) = 0;

  virtual void enterCall(FridayParser::CallContext *ctx) = 0;
  virtual void exitCall(FridayParser::CallContext *ctx) = 0;

  virtual void enterPrimary(FridayParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(FridayParser::PrimaryContext *ctx) = 0;

  virtual void enterGrouping(FridayParser::GroupingContext *ctx) = 0;
  virtual void exitGrouping(FridayParser::GroupingContext *ctx) = 0;

  virtual void enterSubscript(FridayParser::SubscriptContext *ctx) = 0;
  virtual void exitSubscript(FridayParser::SubscriptContext *ctx) = 0;

  virtual void enterBinary(FridayParser::BinaryContext *ctx) = 0;
  virtual void exitBinary(FridayParser::BinaryContext *ctx) = 0;

  virtual void enterUnary(FridayParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(FridayParser::UnaryContext *ctx) = 0;

  virtual void enterSimpleType(FridayParser::SimpleTypeContext *ctx) = 0;
  virtual void exitSimpleType(FridayParser::SimpleTypeContext *ctx) = 0;

  virtual void enterFunctionType(FridayParser::FunctionTypeContext *ctx) = 0;
  virtual void exitFunctionType(FridayParser::FunctionTypeContext *ctx) = 0;

  virtual void enterPointerType(FridayParser::PointerTypeContext *ctx) = 0;
  virtual void exitPointerType(FridayParser::PointerTypeContext *ctx) = 0;

  virtual void enterType(FridayParser::TypeContext *ctx) = 0;
  virtual void exitType(FridayParser::TypeContext *ctx) = 0;


};

