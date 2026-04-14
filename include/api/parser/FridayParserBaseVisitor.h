
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

  virtual std::any visitReturnStatement(FridayParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStatement(FridayParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(FridayParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInlineBlock(FridayParser::InlineBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(FridayParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(FridayParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(FridayParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGrouping(FridayParser::GroupingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubscript(FridayParser::SubscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinary(FridayParser::BinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnary(FridayParser::UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleType(FridayParser::SimpleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionType(FridayParser::FunctionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointerType(FridayParser::PointerTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(FridayParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

