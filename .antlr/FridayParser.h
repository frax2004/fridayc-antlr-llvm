
// Generated from c:/Dev/C++/fridayc-antlr-llvm/FridayParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  FridayParser : public antlr4::Parser {
public:
  enum {
    STRUCT = 1, RETURN = 2, PRINT = 3, FN = 4, BOOL_LIT = 5, NULL_LIT = 6, 
    LEFT_PAREN = 7, LEFT_SQUARE = 8, LEFT_CURLY = 9, RIGHT_PAREN = 10, RIGHT_SQUARE = 11, 
    RIGHT_CURLY = 12, SEMI = 13, COL = 14, COMMA = 15, STAR = 16, SLASH = 17, 
    MINUS = 18, PLUS = 19, MODULO = 20, ARROW = 21, FAT_ARROW = 22, IDENTIFIER = 23, 
    COMMENT = 24, SPACE = 25, INT_LIT = 26, FLOAT_LIT = 27, STRING_LIT = 28, 
    CHAR_LIT = 29
  };

  enum {
    RuleProgram = 0, RuleTopLevelStatement = 1, RuleReturnStatement = 2, 
    RulePrintStatement = 3, RuleStatement = 4, RuleInlineBlock = 5, RuleBlock = 6, 
    RuleFunctionStatement = 7, RuleExpr = 8, RuleSimpleType = 9, RuleFunctionType = 10, 
    RulePointerType = 11, RulePointedType = 12, RuleType = 13
  };

  explicit FridayParser(antlr4::TokenStream *input);

  FridayParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~FridayParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class TopLevelStatementContext;
  class ReturnStatementContext;
  class PrintStatementContext;
  class StatementContext;
  class InlineBlockContext;
  class BlockContext;
  class FunctionStatementContext;
  class ExprContext;
  class SimpleTypeContext;
  class FunctionTypeContext;
  class PointerTypeContext;
  class PointedTypeContext;
  class TypeContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<TopLevelStatementContext *> topLevelStatement();
    TopLevelStatementContext* topLevelStatement(size_t i);

   
  };

  ProgramContext* program();

  class  TopLevelStatementContext : public antlr4::ParserRuleContext {
  public:
    TopLevelStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionStatementContext *functionStatement();

   
  };

  TopLevelStatementContext* topLevelStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExprContext *expr();

   
  };

  ReturnStatementContext* returnStatement();

  class  PrintStatementContext : public antlr4::ParserRuleContext {
  public:
    PrintStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  PrintStatementContext* printStatement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    PrintStatementContext *printStatement();
    ReturnStatementContext *returnStatement();

   
  };

  StatementContext* statement();

  class  InlineBlockContext : public antlr4::ParserRuleContext {
  public:
    InlineBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FAT_ARROW();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  InlineBlockContext* inlineBlock();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

   
  };

  BlockContext* block();

  class  FunctionStatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> paramsNames;
    FridayParser::TypeContext *typeContext = nullptr;
    std::vector<TypeContext *> paramsTypes;
    FridayParser::TypeContext *returnType = nullptr;
    FunctionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *ARROW();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    BlockContext *block();
    InlineBlockContext *inlineBlock();
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  FunctionStatementContext* functionStatement();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public ExprContext {
  public:
    CallContext(ExprContext *ctx);

    FridayParser::ExprContext *func = nullptr;
    FridayParser::ExprContext *exprContext = nullptr;
    std::vector<ExprContext *> args;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
  };

  class  IdentifierContext : public ExprContext {
  public:
    IdentifierContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
  };

  class  CharLiteralContext : public ExprContext {
  public:
    CharLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *CHAR_LIT();
  };

  class  StringLiteralContext : public ExprContext {
  public:
    StringLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *STRING_LIT();
  };

  class  BoolLiteralContext : public ExprContext {
  public:
    BoolLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *BOOL_LIT();
  };

  class  FloatLiteralContext : public ExprContext {
  public:
    FloatLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *FLOAT_LIT();
  };

  class  IntLiteralContext : public ExprContext {
  public:
    IntLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT_LIT();
  };

  class  GroupingContext : public ExprContext {
  public:
    GroupingContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
  };

  class  SubscriptContext : public ExprContext {
  public:
    SubscriptContext(ExprContext *ctx);

    FridayParser::ExprContext *array = nullptr;
    FridayParser::ExprContext *index = nullptr;
    antlr4::tree::TerminalNode *LEFT_SQUARE();
    antlr4::tree::TerminalNode *RIGHT_SQUARE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
  };

  class  BinaryContext : public ExprContext {
  public:
    BinaryContext(ExprContext *ctx);

    FridayParser::ExprContext *left = nullptr;
    antlr4::Token *binaryOperator = nullptr;
    FridayParser::ExprContext *right = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MODULO();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
  };

  class  NullLiteralContext : public ExprContext {
  public:
    NullLiteralContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NULL_LIT();
  };

  class  UnaryContext : public ExprContext {
  public:
    UnaryContext(ExprContext *ctx);

    antlr4::Token *unaryOperator = nullptr;
    ExprContext *expr();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  SimpleTypeContext : public antlr4::ParserRuleContext {
  public:
    SimpleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

   
  };

  SimpleTypeContext* simpleType();

  class  FunctionTypeContext : public antlr4::ParserRuleContext {
  public:
    FridayParser::TypeContext *typeContext = nullptr;
    std::vector<TypeContext *> paramsTypes;
    FridayParser::TypeContext *returnType = nullptr;
    FunctionTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *ARROW();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  FunctionTypeContext* functionType();

  class  PointerTypeContext : public antlr4::ParserRuleContext {
  public:
    PointerTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PointedTypeContext *pointedType();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);

   
  };

  PointerTypeContext* pointerType();

  class  PointedTypeContext : public antlr4::ParserRuleContext {
  public:
    PointedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleTypeContext *simpleType();
    FunctionTypeContext *functionType();

   
  };

  PointedTypeContext* pointedType();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleTypeContext *simpleType();
    PointerTypeContext *pointerType();
    FunctionTypeContext *functionType();

   
  };

  TypeContext* type();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

