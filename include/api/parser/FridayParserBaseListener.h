
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

  virtual void enterReturnStatement(FridayParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(FridayParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterPrintStatement(FridayParser::PrintStatementContext * /*ctx*/) override { }
  virtual void exitPrintStatement(FridayParser::PrintStatementContext * /*ctx*/) override { }

  virtual void enterStatement(FridayParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(FridayParser::StatementContext * /*ctx*/) override { }

  virtual void enterInlineBlock(FridayParser::InlineBlockContext * /*ctx*/) override { }
  virtual void exitInlineBlock(FridayParser::InlineBlockContext * /*ctx*/) override { }

  virtual void enterBlock(FridayParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(FridayParser::BlockContext * /*ctx*/) override { }

  virtual void enterFunctionStatement(FridayParser::FunctionStatementContext * /*ctx*/) override { }
  virtual void exitFunctionStatement(FridayParser::FunctionStatementContext * /*ctx*/) override { }

  virtual void enterCall(FridayParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(FridayParser::CallContext * /*ctx*/) override { }

  virtual void enterIdentifier(FridayParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(FridayParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterCharLiteral(FridayParser::CharLiteralContext * /*ctx*/) override { }
  virtual void exitCharLiteral(FridayParser::CharLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(FridayParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(FridayParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterBoolLiteral(FridayParser::BoolLiteralContext * /*ctx*/) override { }
  virtual void exitBoolLiteral(FridayParser::BoolLiteralContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(FridayParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(FridayParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterIntLiteral(FridayParser::IntLiteralContext * /*ctx*/) override { }
  virtual void exitIntLiteral(FridayParser::IntLiteralContext * /*ctx*/) override { }

  virtual void enterGrouping(FridayParser::GroupingContext * /*ctx*/) override { }
  virtual void exitGrouping(FridayParser::GroupingContext * /*ctx*/) override { }

  virtual void enterSubscript(FridayParser::SubscriptContext * /*ctx*/) override { }
  virtual void exitSubscript(FridayParser::SubscriptContext * /*ctx*/) override { }

  virtual void enterBinary(FridayParser::BinaryContext * /*ctx*/) override { }
  virtual void exitBinary(FridayParser::BinaryContext * /*ctx*/) override { }

  virtual void enterNullLiteral(FridayParser::NullLiteralContext * /*ctx*/) override { }
  virtual void exitNullLiteral(FridayParser::NullLiteralContext * /*ctx*/) override { }

  virtual void enterUnary(FridayParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(FridayParser::UnaryContext * /*ctx*/) override { }

  virtual void enterSimpleType(FridayParser::SimpleTypeContext * /*ctx*/) override { }
  virtual void exitSimpleType(FridayParser::SimpleTypeContext * /*ctx*/) override { }

  virtual void enterFunctionType(FridayParser::FunctionTypeContext * /*ctx*/) override { }
  virtual void exitFunctionType(FridayParser::FunctionTypeContext * /*ctx*/) override { }

  virtual void enterPointerType(FridayParser::PointerTypeContext * /*ctx*/) override { }
  virtual void exitPointerType(FridayParser::PointerTypeContext * /*ctx*/) override { }

  virtual void enterPointedType(FridayParser::PointedTypeContext * /*ctx*/) override { }
  virtual void exitPointedType(FridayParser::PointedTypeContext * /*ctx*/) override { }

  virtual void enterType(FridayParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(FridayParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

