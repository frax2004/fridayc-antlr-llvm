
// Generated from FridayParser.g4 by ANTLR 4.13.2


#include "FridayParserListener.h"
#include "FridayParserVisitor.h"

#include "FridayParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct FridayParserStaticData final {
  FridayParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FridayParserStaticData(const FridayParserStaticData&) = delete;
  FridayParserStaticData(FridayParserStaticData&&) = delete;
  FridayParserStaticData& operator=(const FridayParserStaticData&) = delete;
  FridayParserStaticData& operator=(FridayParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag fridayparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FridayParserStaticData> fridayparserParserStaticData = nullptr;

void fridayparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (fridayparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(fridayparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FridayParserStaticData>(
    std::vector<std::string>{
      "program", "topLevelStatement", "returnStatement", "printStatement", 
      "statement", "inlineBlock", "block", "functionStatement", "expr", 
      "simpleType", "functionType", "pointerType", "pointedType", "type"
    },
    std::vector<std::string>{
      "", "", "", "'struct'", "'return'", "'print'", "'fn'", "", "'null'", 
      "'('", "'['", "'{'", "')'", "']'", "'}'", "';'", "':'", "','", "'*'", 
      "'/'", "'-'", "'+'", "'%'", "'->'", "'=>'"
    },
    std::vector<std::string>{
      "", "COMMENT", "SPACE", "STRUCT", "RETURN", "PRINT", "FN", "BOOL_LIT", 
      "NULL_LIT", "LEFT_PAREN", "LEFT_SQUARE", "LEFT_CURLY", "RIGHT_PAREN", 
      "RIGHT_SQUARE", "RIGHT_CURLY", "SEMI", "COL", "COMMA", "STAR", "SLASH", 
      "MINUS", "PLUS", "MODULO", "ARROW", "FAT_ARROW", "IDENTIFIER", "INT_LIT", 
      "FLOAT_LIT", "STRING_LIT", "CHAR_LIT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,29,170,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,5,0,
  	30,8,0,10,0,12,0,33,9,0,1,0,1,0,1,1,1,1,1,2,1,2,3,2,41,8,2,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,52,8,4,1,5,1,5,1,5,1,5,1,6,1,6,5,6,60,8,
  	6,10,6,12,6,63,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,
  	7,77,8,7,10,7,12,7,80,9,7,3,7,82,8,7,1,7,1,7,1,7,1,7,1,7,3,7,89,8,7,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,105,8,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,123,8,
  	8,10,8,12,8,126,9,8,3,8,128,8,8,1,8,5,8,131,8,8,10,8,12,8,134,9,8,1,9,
  	1,9,1,10,1,10,1,10,1,10,1,10,5,10,143,8,10,10,10,12,10,146,9,10,3,10,
  	148,8,10,1,10,1,10,1,10,1,10,1,11,4,11,155,8,11,11,11,12,11,156,1,11,
  	1,11,1,12,1,12,3,12,163,8,12,1,13,1,13,1,13,3,13,168,8,13,1,13,0,1,16,
  	14,0,2,4,6,8,10,12,14,16,18,20,22,24,26,0,2,1,0,20,21,2,0,18,19,22,22,
  	183,0,31,1,0,0,0,2,36,1,0,0,0,4,38,1,0,0,0,6,44,1,0,0,0,8,51,1,0,0,0,
  	10,53,1,0,0,0,12,57,1,0,0,0,14,66,1,0,0,0,16,104,1,0,0,0,18,135,1,0,0,
  	0,20,137,1,0,0,0,22,154,1,0,0,0,24,162,1,0,0,0,26,167,1,0,0,0,28,30,3,
  	2,1,0,29,28,1,0,0,0,30,33,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,34,1,
  	0,0,0,33,31,1,0,0,0,34,35,5,0,0,1,35,1,1,0,0,0,36,37,3,14,7,0,37,3,1,
  	0,0,0,38,40,5,4,0,0,39,41,3,16,8,0,40,39,1,0,0,0,40,41,1,0,0,0,41,42,
  	1,0,0,0,42,43,5,15,0,0,43,5,1,0,0,0,44,45,5,5,0,0,45,46,3,16,8,0,46,47,
  	5,15,0,0,47,7,1,0,0,0,48,52,3,12,6,0,49,52,3,6,3,0,50,52,3,4,2,0,51,48,
  	1,0,0,0,51,49,1,0,0,0,51,50,1,0,0,0,52,9,1,0,0,0,53,54,5,24,0,0,54,55,
  	3,16,8,0,55,56,5,15,0,0,56,11,1,0,0,0,57,61,5,11,0,0,58,60,3,8,4,0,59,
  	58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,64,1,0,0,0,63,
  	61,1,0,0,0,64,65,5,14,0,0,65,13,1,0,0,0,66,67,5,6,0,0,67,68,5,25,0,0,
  	68,81,5,9,0,0,69,70,5,25,0,0,70,71,5,16,0,0,71,78,3,26,13,0,72,73,5,17,
  	0,0,73,74,5,25,0,0,74,75,5,16,0,0,75,77,3,26,13,0,76,72,1,0,0,0,77,80,
  	1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,81,69,
  	1,0,0,0,81,82,1,0,0,0,82,83,1,0,0,0,83,84,5,12,0,0,84,85,5,23,0,0,85,
  	88,3,26,13,0,86,89,3,12,6,0,87,89,3,10,5,0,88,86,1,0,0,0,88,87,1,0,0,
  	0,89,15,1,0,0,0,90,91,6,8,-1,0,91,105,5,25,0,0,92,105,5,26,0,0,93,105,
  	5,29,0,0,94,105,5,28,0,0,95,105,5,27,0,0,96,105,5,7,0,0,97,105,5,8,0,
  	0,98,99,7,0,0,0,99,105,3,16,8,4,100,101,5,9,0,0,101,102,3,16,8,0,102,
  	103,5,12,0,0,103,105,1,0,0,0,104,90,1,0,0,0,104,92,1,0,0,0,104,93,1,0,
  	0,0,104,94,1,0,0,0,104,95,1,0,0,0,104,96,1,0,0,0,104,97,1,0,0,0,104,98,
  	1,0,0,0,104,100,1,0,0,0,105,132,1,0,0,0,106,107,10,3,0,0,107,108,7,1,
  	0,0,108,131,3,16,8,4,109,110,10,2,0,0,110,111,7,0,0,0,111,131,3,16,8,
  	3,112,113,10,6,0,0,113,114,5,10,0,0,114,115,3,16,8,0,115,116,5,13,0,0,
  	116,131,1,0,0,0,117,118,10,5,0,0,118,127,5,9,0,0,119,124,3,16,8,0,120,
  	121,5,17,0,0,121,123,3,16,8,0,122,120,1,0,0,0,123,126,1,0,0,0,124,122,
  	1,0,0,0,124,125,1,0,0,0,125,128,1,0,0,0,126,124,1,0,0,0,127,119,1,0,0,
  	0,127,128,1,0,0,0,128,129,1,0,0,0,129,131,5,12,0,0,130,106,1,0,0,0,130,
  	109,1,0,0,0,130,112,1,0,0,0,130,117,1,0,0,0,131,134,1,0,0,0,132,130,1,
  	0,0,0,132,133,1,0,0,0,133,17,1,0,0,0,134,132,1,0,0,0,135,136,5,25,0,0,
  	136,19,1,0,0,0,137,138,5,6,0,0,138,147,5,9,0,0,139,144,3,26,13,0,140,
  	141,5,17,0,0,141,143,3,26,13,0,142,140,1,0,0,0,143,146,1,0,0,0,144,142,
  	1,0,0,0,144,145,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,0,147,139,1,0,0,
  	0,147,148,1,0,0,0,148,149,1,0,0,0,149,150,5,12,0,0,150,151,5,23,0,0,151,
  	152,3,26,13,0,152,21,1,0,0,0,153,155,5,18,0,0,154,153,1,0,0,0,155,156,
  	1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,158,159,3,24,
  	12,0,159,23,1,0,0,0,160,163,3,18,9,0,161,163,3,20,10,0,162,160,1,0,0,
  	0,162,161,1,0,0,0,163,25,1,0,0,0,164,168,3,18,9,0,165,168,3,22,11,0,166,
  	168,3,20,10,0,167,164,1,0,0,0,167,165,1,0,0,0,167,166,1,0,0,0,168,27,
  	1,0,0,0,17,31,40,51,61,78,81,88,104,124,127,130,132,144,147,156,162,167
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fridayparserParserStaticData = std::move(staticData);
}

}

FridayParser::FridayParser(TokenStream *input) : FridayParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FridayParser::FridayParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FridayParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *fridayparserParserStaticData->atn, fridayparserParserStaticData->decisionToDFA, fridayparserParserStaticData->sharedContextCache, options);
}

FridayParser::~FridayParser() {
  delete _interpreter;
}

const atn::ATN& FridayParser::getATN() const {
  return *fridayparserParserStaticData->atn;
}

std::string FridayParser::getGrammarFileName() const {
  return "FridayParser.g4";
}

const std::vector<std::string>& FridayParser::getRuleNames() const {
  return fridayparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& FridayParser::getVocabulary() const {
  return fridayparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FridayParser::getSerializedATN() const {
  return fridayparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

FridayParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::ProgramContext::EOF() {
  return getToken(FridayParser::EOF, 0);
}

std::vector<FridayParser::TopLevelStatementContext *> FridayParser::ProgramContext::topLevelStatement() {
  return getRuleContexts<FridayParser::TopLevelStatementContext>();
}

FridayParser::TopLevelStatementContext* FridayParser::ProgramContext::topLevelStatement(size_t i) {
  return getRuleContext<FridayParser::TopLevelStatementContext>(i);
}


size_t FridayParser::ProgramContext::getRuleIndex() const {
  return FridayParser::RuleProgram;
}

void FridayParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void FridayParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any FridayParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::ProgramContext* FridayParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FridayParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::FN) {
      setState(28);
      topLevelStatement();
      setState(33);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(34);
    match(FridayParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopLevelStatementContext ------------------------------------------------------------------

FridayParser::TopLevelStatementContext::TopLevelStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::FunctionStatementContext* FridayParser::TopLevelStatementContext::functionStatement() {
  return getRuleContext<FridayParser::FunctionStatementContext>(0);
}


size_t FridayParser::TopLevelStatementContext::getRuleIndex() const {
  return FridayParser::RuleTopLevelStatement;
}

void FridayParser::TopLevelStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopLevelStatement(this);
}

void FridayParser::TopLevelStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopLevelStatement(this);
}


std::any FridayParser::TopLevelStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitTopLevelStatement(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::TopLevelStatementContext* FridayParser::topLevelStatement() {
  TopLevelStatementContext *_localctx = _tracker.createInstance<TopLevelStatementContext>(_ctx, getState());
  enterRule(_localctx, 2, FridayParser::RuleTopLevelStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    functionStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

FridayParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::ReturnStatementContext::RETURN() {
  return getToken(FridayParser::RETURN, 0);
}

tree::TerminalNode* FridayParser::ReturnStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}

FridayParser::ExprContext* FridayParser::ReturnStatementContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}


size_t FridayParser::ReturnStatementContext::getRuleIndex() const {
  return FridayParser::RuleReturnStatement;
}

void FridayParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void FridayParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any FridayParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::ReturnStatementContext* FridayParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, FridayParser::RuleReturnStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(FridayParser::RETURN);

    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1043334016) != 0)) {
      setState(39);
      expr(0);
    }
    setState(42);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

FridayParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::PrintStatementContext::PRINT() {
  return getToken(FridayParser::PRINT, 0);
}

FridayParser::ExprContext* FridayParser::PrintStatementContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::PrintStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::PrintStatementContext::getRuleIndex() const {
  return FridayParser::RulePrintStatement;
}

void FridayParser::PrintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintStatement(this);
}

void FridayParser::PrintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintStatement(this);
}


std::any FridayParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::PrintStatementContext* FridayParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, FridayParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(FridayParser::PRINT);
    setState(45);
    expr(0);
    setState(46);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

FridayParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::BlockContext* FridayParser::StatementContext::block() {
  return getRuleContext<FridayParser::BlockContext>(0);
}

FridayParser::PrintStatementContext* FridayParser::StatementContext::printStatement() {
  return getRuleContext<FridayParser::PrintStatementContext>(0);
}

FridayParser::ReturnStatementContext* FridayParser::StatementContext::returnStatement() {
  return getRuleContext<FridayParser::ReturnStatementContext>(0);
}


size_t FridayParser::StatementContext::getRuleIndex() const {
  return FridayParser::RuleStatement;
}

void FridayParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void FridayParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any FridayParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::StatementContext* FridayParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 8, FridayParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(48);
        block();
        break;
      }

      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 2);
        setState(49);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(50);
        returnStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InlineBlockContext ------------------------------------------------------------------

FridayParser::InlineBlockContext::InlineBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::InlineBlockContext::FAT_ARROW() {
  return getToken(FridayParser::FAT_ARROW, 0);
}

FridayParser::ExprContext* FridayParser::InlineBlockContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::InlineBlockContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::InlineBlockContext::getRuleIndex() const {
  return FridayParser::RuleInlineBlock;
}

void FridayParser::InlineBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInlineBlock(this);
}

void FridayParser::InlineBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInlineBlock(this);
}


std::any FridayParser::InlineBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitInlineBlock(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::InlineBlockContext* FridayParser::inlineBlock() {
  InlineBlockContext *_localctx = _tracker.createInstance<InlineBlockContext>(_ctx, getState());
  enterRule(_localctx, 10, FridayParser::RuleInlineBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(FridayParser::FAT_ARROW);
    setState(54);
    expr(0);
    setState(55);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

FridayParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::BlockContext::LEFT_CURLY() {
  return getToken(FridayParser::LEFT_CURLY, 0);
}

tree::TerminalNode* FridayParser::BlockContext::RIGHT_CURLY() {
  return getToken(FridayParser::RIGHT_CURLY, 0);
}

std::vector<FridayParser::StatementContext *> FridayParser::BlockContext::statement() {
  return getRuleContexts<FridayParser::StatementContext>();
}

FridayParser::StatementContext* FridayParser::BlockContext::statement(size_t i) {
  return getRuleContext<FridayParser::StatementContext>(i);
}


size_t FridayParser::BlockContext::getRuleIndex() const {
  return FridayParser::RuleBlock;
}

void FridayParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void FridayParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any FridayParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::BlockContext* FridayParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 12, FridayParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(FridayParser::LEFT_CURLY);

    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2096) != 0)) {
      setState(58);
      statement();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(FridayParser::RIGHT_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionStatementContext ------------------------------------------------------------------

FridayParser::FunctionStatementContext::FunctionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::FunctionStatementContext::FN() {
  return getToken(FridayParser::FN, 0);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::ARROW() {
  return getToken(FridayParser::ARROW, 0);
}

std::vector<tree::TerminalNode *> FridayParser::FunctionStatementContext::IDENTIFIER() {
  return getTokens(FridayParser::IDENTIFIER);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::IDENTIFIER(size_t i) {
  return getToken(FridayParser::IDENTIFIER, i);
}

std::vector<FridayParser::TypeContext *> FridayParser::FunctionStatementContext::type() {
  return getRuleContexts<FridayParser::TypeContext>();
}

FridayParser::TypeContext* FridayParser::FunctionStatementContext::type(size_t i) {
  return getRuleContext<FridayParser::TypeContext>(i);
}

FridayParser::BlockContext* FridayParser::FunctionStatementContext::block() {
  return getRuleContext<FridayParser::BlockContext>(0);
}

FridayParser::InlineBlockContext* FridayParser::FunctionStatementContext::inlineBlock() {
  return getRuleContext<FridayParser::InlineBlockContext>(0);
}

std::vector<tree::TerminalNode *> FridayParser::FunctionStatementContext::COL() {
  return getTokens(FridayParser::COL);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::COL(size_t i) {
  return getToken(FridayParser::COL, i);
}

std::vector<tree::TerminalNode *> FridayParser::FunctionStatementContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::FunctionStatementContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}


size_t FridayParser::FunctionStatementContext::getRuleIndex() const {
  return FridayParser::RuleFunctionStatement;
}

void FridayParser::FunctionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionStatement(this);
}

void FridayParser::FunctionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionStatement(this);
}


std::any FridayParser::FunctionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitFunctionStatement(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::FunctionStatementContext* FridayParser::functionStatement() {
  FunctionStatementContext *_localctx = _tracker.createInstance<FunctionStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, FridayParser::RuleFunctionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(FridayParser::FN);
    setState(67);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(68);
    match(FridayParser::LEFT_PAREN);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(69);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
      setState(70);
      match(FridayParser::COL);
      setState(71);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(72);
        match(FridayParser::COMMA);
        setState(73);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
        setState(74);
        match(FridayParser::COL);
        setState(75);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
        setState(80);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(83);
    match(FridayParser::RIGHT_PAREN);
    setState(84);
    match(FridayParser::ARROW);
    setState(85);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->returnType = type();
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        setState(86);
        block();
        break;
      }

      case FridayParser::FAT_ARROW: {
        setState(87);
        inlineBlock();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FridayParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FridayParser::ExprContext::getRuleIndex() const {
  return FridayParser::RuleExpr;
}

void FridayParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CallContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::CallContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

std::vector<FridayParser::ExprContext *> FridayParser::CallContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::CallContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::CallContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::CallContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}

FridayParser::CallContext::CallContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void FridayParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

std::any FridayParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IdentifierContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::IdentifierContext::IdentifierContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}
void FridayParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}

std::any FridayParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CharLiteralContext::CHAR_LIT() {
  return getToken(FridayParser::CHAR_LIT, 0);
}

FridayParser::CharLiteralContext::CharLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::CharLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharLiteral(this);
}
void FridayParser::CharLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharLiteral(this);
}

std::any FridayParser::CharLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitCharLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::StringLiteralContext::STRING_LIT() {
  return getToken(FridayParser::STRING_LIT, 0);
}

FridayParser::StringLiteralContext::StringLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void FridayParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}

std::any FridayParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::BoolLiteralContext::BOOL_LIT() {
  return getToken(FridayParser::BOOL_LIT, 0);
}

FridayParser::BoolLiteralContext::BoolLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::BoolLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolLiteral(this);
}
void FridayParser::BoolLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolLiteral(this);
}

std::any FridayParser::BoolLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitBoolLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::FloatLiteralContext::FLOAT_LIT() {
  return getToken(FridayParser::FLOAT_LIT, 0);
}

FridayParser::FloatLiteralContext::FloatLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::FloatLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLiteral(this);
}
void FridayParser::FloatLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLiteral(this);
}

std::any FridayParser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IntLiteralContext::INT_LIT() {
  return getToken(FridayParser::INT_LIT, 0);
}

FridayParser::IntLiteralContext::IntLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::IntLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLiteral(this);
}
void FridayParser::IntLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLiteral(this);
}

std::any FridayParser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GroupingContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::GroupingContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

FridayParser::ExprContext* FridayParser::GroupingContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::GroupingContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

FridayParser::GroupingContext::GroupingContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::GroupingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrouping(this);
}
void FridayParser::GroupingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrouping(this);
}

std::any FridayParser::GroupingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitGrouping(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::SubscriptContext::LEFT_SQUARE() {
  return getToken(FridayParser::LEFT_SQUARE, 0);
}

tree::TerminalNode* FridayParser::SubscriptContext::RIGHT_SQUARE() {
  return getToken(FridayParser::RIGHT_SQUARE, 0);
}

std::vector<FridayParser::ExprContext *> FridayParser::SubscriptContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::SubscriptContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

FridayParser::SubscriptContext::SubscriptContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::SubscriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscript(this);
}
void FridayParser::SubscriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscript(this);
}

std::any FridayParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryContext ------------------------------------------------------------------

std::vector<FridayParser::ExprContext *> FridayParser::BinaryContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::BinaryContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

tree::TerminalNode* FridayParser::BinaryContext::STAR() {
  return getToken(FridayParser::STAR, 0);
}

tree::TerminalNode* FridayParser::BinaryContext::SLASH() {
  return getToken(FridayParser::SLASH, 0);
}

tree::TerminalNode* FridayParser::BinaryContext::MODULO() {
  return getToken(FridayParser::MODULO, 0);
}

tree::TerminalNode* FridayParser::BinaryContext::PLUS() {
  return getToken(FridayParser::PLUS, 0);
}

tree::TerminalNode* FridayParser::BinaryContext::MINUS() {
  return getToken(FridayParser::MINUS, 0);
}

FridayParser::BinaryContext::BinaryContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::BinaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary(this);
}
void FridayParser::BinaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary(this);
}

std::any FridayParser::BinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitBinary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::NullLiteralContext::NULL_LIT() {
  return getToken(FridayParser::NULL_LIT, 0);
}

FridayParser::NullLiteralContext::NullLiteralContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::NullLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullLiteral(this);
}
void FridayParser::NullLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullLiteral(this);
}

std::any FridayParser::NullLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitNullLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

FridayParser::ExprContext* FridayParser::UnaryContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::UnaryContext::PLUS() {
  return getToken(FridayParser::PLUS, 0);
}

tree::TerminalNode* FridayParser::UnaryContext::MINUS() {
  return getToken(FridayParser::MINUS, 0);
}

FridayParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}
void FridayParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}

std::any FridayParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::ExprContext* FridayParser::expr() {
   return expr(0);
}

FridayParser::ExprContext* FridayParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FridayParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FridayParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, FridayParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(91);
        match(FridayParser::IDENTIFIER);
        break;
      }

      case FridayParser::INT_LIT: {
        _localctx = _tracker.createInstance<IntLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(92);
        match(FridayParser::INT_LIT);
        break;
      }

      case FridayParser::CHAR_LIT: {
        _localctx = _tracker.createInstance<CharLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(93);
        match(FridayParser::CHAR_LIT);
        break;
      }

      case FridayParser::STRING_LIT: {
        _localctx = _tracker.createInstance<StringLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(94);
        match(FridayParser::STRING_LIT);
        break;
      }

      case FridayParser::FLOAT_LIT: {
        _localctx = _tracker.createInstance<FloatLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(95);
        match(FridayParser::FLOAT_LIT);
        break;
      }

      case FridayParser::BOOL_LIT: {
        _localctx = _tracker.createInstance<BoolLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(96);
        match(FridayParser::BOOL_LIT);
        break;
      }

      case FridayParser::NULL_LIT: {
        _localctx = _tracker.createInstance<NullLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(97);
        match(FridayParser::NULL_LIT);
        break;
      }

      case FridayParser::MINUS:
      case FridayParser::PLUS: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(98);
        antlrcpp::downCast<UnaryContext *>(_localctx)->unaryOperator = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == FridayParser::MINUS

        || _la == FridayParser::PLUS)) {
          antlrcpp::downCast<UnaryContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(99);
        expr(4);
        break;
      }

      case FridayParser::LEFT_PAREN: {
        _localctx = _tracker.createInstance<GroupingContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(100);
        match(FridayParser::LEFT_PAREN);
        setState(101);
        expr(0);
        setState(102);
        match(FridayParser::RIGHT_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(132);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(130);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(106);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(107);
          antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4980736) != 0))) {
            antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(108);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(109);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(110);
          antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::MINUS

          || _la == FridayParser::PLUS)) {
            antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(111);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->array = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(112);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(113);
          match(FridayParser::LEFT_SQUARE);
          setState(114);
          antlrcpp::downCast<SubscriptContext *>(_localctx)->index = expr(0);
          setState(115);
          match(FridayParser::RIGHT_SQUARE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->func = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(117);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(118);
          match(FridayParser::LEFT_PAREN);
          setState(127);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1043334016) != 0)) {
            setState(119);
            antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
            antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
            setState(124);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == FridayParser::COMMA) {
              setState(120);
              match(FridayParser::COMMA);
              setState(121);
              antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
              antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
              setState(126);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(129);
          match(FridayParser::RIGHT_PAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(134);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SimpleTypeContext ------------------------------------------------------------------

FridayParser::SimpleTypeContext::SimpleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::SimpleTypeContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}


size_t FridayParser::SimpleTypeContext::getRuleIndex() const {
  return FridayParser::RuleSimpleType;
}

void FridayParser::SimpleTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleType(this);
}

void FridayParser::SimpleTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleType(this);
}


std::any FridayParser::SimpleTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitSimpleType(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::SimpleTypeContext* FridayParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, FridayParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(FridayParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

FridayParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::FunctionTypeContext::FN() {
  return getToken(FridayParser::FN, 0);
}

tree::TerminalNode* FridayParser::FunctionTypeContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::FunctionTypeContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* FridayParser::FunctionTypeContext::ARROW() {
  return getToken(FridayParser::ARROW, 0);
}

std::vector<FridayParser::TypeContext *> FridayParser::FunctionTypeContext::type() {
  return getRuleContexts<FridayParser::TypeContext>();
}

FridayParser::TypeContext* FridayParser::FunctionTypeContext::type(size_t i) {
  return getRuleContext<FridayParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::FunctionTypeContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::FunctionTypeContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}


size_t FridayParser::FunctionTypeContext::getRuleIndex() const {
  return FridayParser::RuleFunctionType;
}

void FridayParser::FunctionTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionType(this);
}

void FridayParser::FunctionTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionType(this);
}


std::any FridayParser::FunctionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitFunctionType(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::FunctionTypeContext* FridayParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, FridayParser::RuleFunctionType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(FridayParser::FN);
    setState(138);
    match(FridayParser::LEFT_PAREN);
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 33816640) != 0)) {
      setState(139);
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(140);
        match(FridayParser::COMMA);
        setState(141);
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
        setState(146);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(149);
    match(FridayParser::RIGHT_PAREN);
    setState(150);
    match(FridayParser::ARROW);
    setState(151);
    antlrcpp::downCast<FunctionTypeContext *>(_localctx)->returnType = type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerTypeContext ------------------------------------------------------------------

FridayParser::PointerTypeContext::PointerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::PointedTypeContext* FridayParser::PointerTypeContext::pointedType() {
  return getRuleContext<FridayParser::PointedTypeContext>(0);
}

std::vector<tree::TerminalNode *> FridayParser::PointerTypeContext::STAR() {
  return getTokens(FridayParser::STAR);
}

tree::TerminalNode* FridayParser::PointerTypeContext::STAR(size_t i) {
  return getToken(FridayParser::STAR, i);
}


size_t FridayParser::PointerTypeContext::getRuleIndex() const {
  return FridayParser::RulePointerType;
}

void FridayParser::PointerTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointerType(this);
}

void FridayParser::PointerTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointerType(this);
}


std::any FridayParser::PointerTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitPointerType(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::PointerTypeContext* FridayParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, FridayParser::RulePointerType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(153);
      match(FridayParser::STAR);
      setState(156); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FridayParser::STAR);
    setState(158);
    pointedType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointedTypeContext ------------------------------------------------------------------

FridayParser::PointedTypeContext::PointedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::SimpleTypeContext* FridayParser::PointedTypeContext::simpleType() {
  return getRuleContext<FridayParser::SimpleTypeContext>(0);
}

FridayParser::FunctionTypeContext* FridayParser::PointedTypeContext::functionType() {
  return getRuleContext<FridayParser::FunctionTypeContext>(0);
}


size_t FridayParser::PointedTypeContext::getRuleIndex() const {
  return FridayParser::RulePointedType;
}

void FridayParser::PointedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointedType(this);
}

void FridayParser::PointedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointedType(this);
}


std::any FridayParser::PointedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitPointedType(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::PointedTypeContext* FridayParser::pointedType() {
  PointedTypeContext *_localctx = _tracker.createInstance<PointedTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, FridayParser::RulePointedType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(160);
        simpleType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 2);
        setState(161);
        functionType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FridayParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::SimpleTypeContext* FridayParser::TypeContext::simpleType() {
  return getRuleContext<FridayParser::SimpleTypeContext>(0);
}

FridayParser::PointerTypeContext* FridayParser::TypeContext::pointerType() {
  return getRuleContext<FridayParser::PointerTypeContext>(0);
}

FridayParser::FunctionTypeContext* FridayParser::TypeContext::functionType() {
  return getRuleContext<FridayParser::FunctionTypeContext>(0);
}


size_t FridayParser::TypeContext::getRuleIndex() const {
  return FridayParser::RuleType;
}

void FridayParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void FridayParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any FridayParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FridayParser::TypeContext* FridayParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 26, FridayParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        simpleType();
        break;
      }

      case FridayParser::STAR: {
        enterOuterAlt(_localctx, 2);
        setState(165);
        pointerType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 3);
        setState(166);
        functionType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FridayParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FridayParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void FridayParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  fridayparserParserInitialize();
#else
  ::antlr4::internal::call_once(fridayparserParserOnceFlag, fridayparserParserInitialize);
#endif
}
