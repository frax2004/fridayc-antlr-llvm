
// Generated from FridayParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FridayParser : public antlr4::Parser {
public:
  enum {
    INLINE_COMMENT = 1, COMMENT = 2, SPACE = 3, STRUCT = 4, RETURN = 5, 
    PRINT = 6, FN = 7, FOR = 8, WHILE = 9, DEFER = 10, NATIVE = 11, NAMESPACE = 12, 
    USING = 13, CONST = 14, LET = 15, NEW = 16, IF = 17, ELIF = 18, ELSE = 19, 
    AND = 20, OR = 21, NOT = 22, AS = 23, SIZEOF = 24, ALIGNOF = 25, BOOL_LIT = 26, 
    NULL_LIT = 27, INT_LIT = 28, FLOAT_LIT = 29, STRING_LIT = 30, CHAR_LIT = 31, 
    LEFT_PAREN = 32, LEFT_SQUARE = 33, LEFT_CURLY = 34, RIGHT_PAREN = 35, 
    RIGHT_SQUARE = 36, RIGHT_CURLY = 37, SEMI = 38, COL = 39, COMMA = 40, 
    ARROW = 41, FAT_ARROW = 42, INCREMENT = 43, DECREMENT = 44, PLUS = 45, 
    MINUS = 46, STAR = 47, SLASH = 48, MODULO = 49, LSHIFT = 50, RSHIFT = 51, 
    AMPERSAND = 52, PIPELINE = 53, LESS = 54, GREATER = 55, LESS_EQ = 56, 
    GREATER_EQ = 57, EQUALS = 58, NOT_EQUALS = 59, ASSIGN = 60, PLUS_ASSIGN = 61, 
    MINUS_ASSIGN = 62, STAR_ASSIGN = 63, SLASH_ASSIGN = 64, MODULO_ASSIGN = 65, 
    LSHIFT_ASSIGN = 66, RSHIFT_ASSIGN = 67, AMPERSAND_ASSIGN = 68, PIPELINE_ASSIGN = 69, 
    TILDE = 70, DOT = 71, IDENTIFIER = 72, NAMESPACE_IDENTIFIER = 73
  };

  enum {
    RuleProgram = 0, RuleTopLevelStatement = 1, RuleNativeFunctionStatement = 2, 
    RuleNamespaceStatement = 3, RuleUsingStatement = 4, RuleStructStatement = 5, 
    RuleFunctionStatement = 6, RuleStatement = 7, RuleDeferrableStatement = 8, 
    RuleDeclarationStatement = 9, RuleIfStatement = 10, RuleForStatement = 11, 
    RuleWhileStatement = 12, RuleExpressionStatement = 13, RuleDeferStatement = 14, 
    RulePrintStatement = 15, RuleScope = 16, RuleReturnStatement = 17, RuleInlineScope = 18, 
    RuleFunctionScope = 19, RuleExpression = 20, RuleType = 21, RuleFunctionType = 22, 
    RuleSimpleType = 23, RulePointerType = 24, RuleArrayType = 25
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
  class NativeFunctionStatementContext;
  class NamespaceStatementContext;
  class UsingStatementContext;
  class StructStatementContext;
  class FunctionStatementContext;
  class StatementContext;
  class DeferrableStatementContext;
  class DeclarationStatementContext;
  class IfStatementContext;
  class ForStatementContext;
  class WhileStatementContext;
  class ExpressionStatementContext;
  class DeferStatementContext;
  class PrintStatementContext;
  class ScopeContext;
  class ReturnStatementContext;
  class InlineScopeContext;
  class FunctionScopeContext;
  class ExpressionContext;
  class TypeContext;
  class FunctionTypeContext;
  class SimpleTypeContext;
  class PointerTypeContext;
  class ArrayTypeContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    NamespaceStatementContext *namespaceStatement();
    std::vector<TopLevelStatementContext *> topLevelStatement();
    TopLevelStatementContext* topLevelStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  TopLevelStatementContext : public antlr4::ParserRuleContext {
  public:
    TopLevelStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UsingStatementContext *usingStatement();
    StructStatementContext *structStatement();
    FunctionStatementContext *functionStatement();
    NativeFunctionStatementContext *nativeFunctionStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelStatementContext* topLevelStatement();

  class  NativeFunctionStatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> paramsNames;
    FridayParser::TypeContext *typeContext = nullptr;
    std::vector<TypeContext *> paramsTypes;
    FridayParser::TypeContext *returnType = nullptr;
    NativeFunctionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NATIVE();
    antlr4::tree::TerminalNode *FN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *ARROW();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NativeFunctionStatementContext* nativeFunctionStatement();

  class  NamespaceStatementContext : public antlr4::ParserRuleContext {
  public:
    NamespaceStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAMESPACE();
    antlr4::tree::TerminalNode *NAMESPACE_IDENTIFIER();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamespaceStatementContext* namespaceStatement();

  class  UsingStatementContext : public antlr4::ParserRuleContext {
  public:
    UsingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USING();
    antlr4::tree::TerminalNode *NAMESPACE_IDENTIFIER();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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
    FunctionScopeContext *functionScope();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionStatementContext* functionStatement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrintStatementContext *printStatement();
    ReturnStatementContext *returnStatement();
    ExpressionStatementContext *expressionStatement();
    IfStatementContext *ifStatement();
    ForStatementContext *forStatement();
    WhileStatementContext *whileStatement();
    DeclarationStatementContext *declarationStatement();
    ScopeContext *scope();
    DeferStatementContext *deferStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  DeferrableStatementContext : public antlr4::ParserRuleContext {
  public:
    DeferrableStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrintStatementContext *printStatement();
    ReturnStatementContext *returnStatement();
    ExpressionStatementContext *expressionStatement();
    IfStatementContext *ifStatement();
    ForStatementContext *forStatement();
    WhileStatementContext *whileStatement();
    DeclarationStatementContext *declarationStatement();
    ScopeContext *scope();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeferrableStatementContext* deferrableStatement();

  class  DeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *declarator = nullptr;
    antlr4::Token *id = nullptr;
    FridayParser::ExpressionContext *initializer = nullptr;
    DeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *COL();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationStatementContext* declarationStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  DeferStatementContext : public antlr4::ParserRuleContext {
  public:
    DeferStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFER();
    DeferrableStatementContext *deferrableStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeferStatementContext* deferStatement();

  class  PrintStatementContext : public antlr4::ParserRuleContext {
  public:
    PrintStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrintStatementContext* printStatement();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  InlineScopeContext : public antlr4::ParserRuleContext {
  public:
    InlineScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FAT_ARROW();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InlineScopeContext* inlineScope();

  class  FunctionScopeContext : public antlr4::ParserRuleContext {
  public:
    FunctionScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScopeContext *scope();
    InlineScopeContext *inlineScope();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionScopeContext* functionScope();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MemberAccessExpressionContext : public ExpressionContext {
  public:
    MemberAccessExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *object = nullptr;
    antlr4::Token *member = nullptr;
    antlr4::tree::TerminalNode *DOT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryPostfixExpressionContext : public ExpressionContext {
  public:
    UnaryPostfixExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *expr = nullptr;
    antlr4::Token *postfixOperator = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *DECREMENT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLiteralExpressionContext : public ExpressionContext {
  public:
    StringLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *STRING_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatLiteralExpressionContext : public ExpressionContext {
  public:
    FloatLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *FLOAT_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewExpressionContext : public ExpressionContext {
  public:
    NewExpressionContext(ExpressionContext *ctx);

    antlr4::Token *identifierToken = nullptr;
    std::vector<antlr4::Token *> fields;
    FridayParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> initializers;
    antlr4::tree::TerminalNode *NEW();
    TypeContext *type();
    antlr4::tree::TerminalNode *LEFT_CURLY();
    antlr4::tree::TerminalNode *RIGHT_CURLY();
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayLiteralExpressionContext : public ExpressionContext {
  public:
    ArrayLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_SQUARE();
    antlr4::tree::TerminalNode *RIGHT_SQUARE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExplicitCastExpressionContext : public ExpressionContext {
  public:
    ExplicitCastExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *expr = nullptr;
    antlr4::tree::TerminalNode *AS();
    TypeContext *type();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLiteralExpressionContext : public ExpressionContext {
  public:
    IntLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *INT_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierExpressionContext : public ExpressionContext {
  public:
    IdentifierExpressionContext(ExpressionContext *ctx);

    antlr4::Token *id = nullptr;
    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExpressionContext : public ExpressionContext {
  public:
    BinaryExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *left = nullptr;
    antlr4::Token *binaryOperator = nullptr;
    FridayParser::ExpressionContext *right = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *MODULO();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *LESS_EQ();
    antlr4::tree::TerminalNode *GREATER();
    antlr4::tree::TerminalNode *GREATER_EQ();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *NOT_EQUALS();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *PIPELINE();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *PLUS_ASSIGN();
    antlr4::tree::TerminalNode *MINUS_ASSIGN();
    antlr4::tree::TerminalNode *STAR_ASSIGN();
    antlr4::tree::TerminalNode *SLASH_ASSIGN();
    antlr4::tree::TerminalNode *MODULO_ASSIGN();
    antlr4::tree::TerminalNode *LSHIFT_ASSIGN();
    antlr4::tree::TerminalNode *RSHIFT_ASSIGN();
    antlr4::tree::TerminalNode *AMPERSAND_ASSIGN();
    antlr4::tree::TerminalNode *PIPELINE_ASSIGN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GroupingExpressionContext : public ExpressionContext {
  public:
    GroupingExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryPrefixExpressionContext : public ExpressionContext {
  public:
    UnaryPrefixExpressionContext(ExpressionContext *ctx);

    antlr4::Token *unaryOperator = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *AMPERSAND();
    antlr4::tree::TerminalNode *SIZEOF();
    antlr4::tree::TerminalNode *ALIGNOF();
    TypeContext *type();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubscriptExpressionContext : public ExpressionContext {
  public:
    SubscriptExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *array = nullptr;
    FridayParser::ExpressionContext *index = nullptr;
    antlr4::tree::TerminalNode *LEFT_SQUARE();
    antlr4::tree::TerminalNode *RIGHT_SQUARE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolLiteralExpressionContext : public ExpressionContext {
  public:
    BoolLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *BOOL_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharLiteralExpressionContext : public ExpressionContext {
  public:
    CharLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *CHAR_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExpressionContext : public ExpressionContext {
  public:
    CallExpressionContext(ExpressionContext *ctx);

    FridayParser::ExpressionContext *func = nullptr;
    FridayParser::ExpressionContext *expressionContext = nullptr;
    std::vector<ExpressionContext *> args;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullLiteralExpressionContext : public ExpressionContext {
  public:
    NullLiteralExpressionContext(ExpressionContext *ctx);

    antlr4::Token *literal = nullptr;
    antlr4::tree::TerminalNode *NULL_LIT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleTypeContext *simpleType();
    PointerTypeContext *pointerType();
    ArrayTypeContext *arrayType();
    FunctionTypeContext *functionType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionTypeContext* functionType();

  class  SimpleTypeContext : public antlr4::ParserRuleContext {
  public:
    SimpleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleTypeContext* simpleType();

  class  PointerTypeContext : public antlr4::ParserRuleContext {
  public:
    FridayParser::TypeContext *pointedType = nullptr;
    PointerTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PointerTypeContext* pointerType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    FridayParser::TypeContext *elementType = nullptr;
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> LEFT_SQUARE();
    antlr4::tree::TerminalNode* LEFT_SQUARE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RIGHT_SQUARE();
    antlr4::tree::TerminalNode* RIGHT_SQUARE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

