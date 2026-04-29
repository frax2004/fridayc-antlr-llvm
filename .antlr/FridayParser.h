
// Generated from c:/Dev/C++/fridayc-antlr-llvm/FridayParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  FridayParser : public antlr4::Parser {
public:
  enum {
    INLINE_COMMENT = 1, COMMENT = 2, SPACE = 3, STRUCT = 4, RETURN = 5, 
    PRINT = 6, FN = 7, FOR = 8, WHILE = 9, DEFER = 10, NAMESPACE = 11, USING = 12, 
    CONST = 13, LET = 14, NEW = 15, IF = 16, ELIF = 17, ELSE = 18, BOOL_LIT = 19, 
    NULL_LIT = 20, INT_LIT = 21, FLOAT_LIT = 22, STRING_LIT = 23, CHAR_LIT = 24, 
    LEFT_PAREN = 25, LEFT_SQUARE = 26, LEFT_CURLY = 27, RIGHT_PAREN = 28, 
    RIGHT_SQUARE = 29, RIGHT_CURLY = 30, SEMI = 31, COL = 32, COMMA = 33, 
    ARROW = 34, FAT_ARROW = 35, AND = 36, OR = 37, NOT = 38, AS = 39, SIZEOF = 40, 
    ALIGNOF = 41, PLUS = 42, MINUS = 43, STAR = 44, SLASH = 45, MODULO = 46, 
    LSHIFT = 47, RSHIFT = 48, AMPERSAND = 49, PIPELINE = 50, LESS = 51, 
    GREATER = 52, LESS_EQ = 53, GREATER_EQ = 54, EQUALS = 55, NOT_EQUALS = 56, 
    ASSIGN = 57, PLUS_ASSIGN = 58, MINUS_ASSIGN = 59, STAR_ASSIGN = 60, 
    SLASH_ASSIGN = 61, MODULO_ASSIGN = 62, LSHIFT_ASSIGN = 63, RSHIFT_ASSIGN = 64, 
    AMPERSAND_ASSIGN = 65, PIPELINE_ASSIGN = 66, TILDE = 67, DOT = 68, IDENTIFIER = 69, 
    NAMESPACE_IDENTIFIER = 70
  };

  enum {
    RuleProgram = 0, RuleTopLevelStatement = 1, RuleNamespaceStatement = 2, 
    RuleUsingStatement = 3, RuleStructStatement = 4, RuleFunctionStatement = 5, 
    RuleRegularStatement = 6, RuleDeferStatement = 7, RulePrintStatement = 8, 
    RuleDeferrableStatement = 9, RuleDeferrableScope = 10, RuleScope = 11, 
    RuleScopedStatement = 12, RuleReturnStatement = 13, RuleInlineScope = 14, 
    RuleFunctionBlock = 15, RuleExpr = 16, RuleSimpleType = 17, RuleFunctionType = 18, 
    RulePointerType = 19, RulePointedType = 20, RuleType = 21
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
  class NamespaceStatementContext;
  class UsingStatementContext;
  class StructStatementContext;
  class FunctionStatementContext;
  class RegularStatementContext;
  class DeferStatementContext;
  class PrintStatementContext;
  class DeferrableStatementContext;
  class DeferrableScopeContext;
  class ScopeContext;
  class ScopedStatementContext;
  class ReturnStatementContext;
  class InlineScopeContext;
  class FunctionBlockContext;
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
    NamespaceStatementContext *namespaceStatement();
    std::vector<TopLevelStatementContext *> topLevelStatement();
    TopLevelStatementContext* topLevelStatement(size_t i);

   
  };

  ProgramContext* program();

  class  TopLevelStatementContext : public antlr4::ParserRuleContext {
  public:
    TopLevelStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UsingStatementContext *usingStatement();
    StructStatementContext *structStatement();
    FunctionStatementContext *functionStatement();

   
  };

  TopLevelStatementContext* topLevelStatement();

  class  NamespaceStatementContext : public antlr4::ParserRuleContext {
  public:
    NamespaceStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMESPACE();
    antlr4::tree::TerminalNode *NAMESPACE_IDENTIFIER();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  NamespaceStatementContext* namespaceStatement();

  class  UsingStatementContext : public antlr4::ParserRuleContext {
  public:
    UsingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *NAMESPACE_IDENTIFIER();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  UsingStatementContext* usingStatement();

  class  StructStatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> fieldsNames;
    FridayParser::TypeContext *typeContext = nullptr;
    std::vector<TypeContext *> fieldsTypes;
    FridayParser::FunctionStatementContext *functionStatementContext = nullptr;
    std::vector<FunctionStatementContext *> methods;
    StructStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRUCT();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<FunctionStatementContext *> functionStatement();
    FunctionStatementContext* functionStatement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);

   
  };

  StructStatementContext* structStatement();

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
    FunctionBlockContext *functionBlock();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  FunctionStatementContext* functionStatement();

  class  RegularStatementContext : public antlr4::ParserRuleContext {
  public:
    RegularStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrintStatementContext *printStatement();
    DeferStatementContext *deferStatement();

   
  };

  RegularStatementContext* regularStatement();

  class  DeferStatementContext : public antlr4::ParserRuleContext {
  public:
    DeferStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFER();
    DeferrableStatementContext *deferrableStatement();

   
  };

  DeferStatementContext* deferStatement();

  class  PrintStatementContext : public antlr4::ParserRuleContext {
  public:
    PrintStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  PrintStatementContext* printStatement();

  class  DeferrableStatementContext : public antlr4::ParserRuleContext {
  public:
    DeferrableStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeferrableScopeContext *deferrableScope();
    RegularStatementContext *regularStatement();

   
  };

  DeferrableStatementContext* deferrableStatement();

  class  DeferrableScopeContext : public antlr4::ParserRuleContext {
  public:
    DeferrableScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<DeferrableStatementContext *> deferrableStatement();
    DeferrableStatementContext* deferrableStatement(size_t i);

   
  };

  DeferrableScopeContext* deferrableScope();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<ScopedStatementContext *> scopedStatement();
    ScopedStatementContext* scopedStatement(size_t i);

   
  };

  ScopeContext* scope();

  class  ScopedStatementContext : public antlr4::ParserRuleContext {
  public:
    ScopedStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeContext *scope();
    RegularStatementContext *regularStatement();
    ReturnStatementContext *returnStatement();

   
  };

  ScopedStatementContext* scopedStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExprContext *expr();

   
  };

  ReturnStatementContext* returnStatement();

  class  InlineScopeContext : public antlr4::ParserRuleContext {
  public:
    InlineScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FAT_ARROW();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();

   
  };

  InlineScopeContext* inlineScope();

  class  FunctionBlockContext : public antlr4::ParserRuleContext {
  public:
    FunctionBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeContext *scope();
    InlineScopeContext *inlineScope();

   
  };

  FunctionBlockContext* functionBlock();

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

