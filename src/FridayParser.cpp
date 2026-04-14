
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
      "simpleType", "functionType", "pointerType", "type"
    },
    std::vector<std::string>{
      "", "'struct'", "'return'", "'print'", "'fn'", "", "'null'", "'('", 
      "'['", "'{'", "')'", "']'", "'}'", "';'", "':'", "','", "'*'", "'/'", 
      "'-'", "'+'", "'%'", "'->'", "'=>'"
    },
    std::vector<std::string>{
      "", "STRUCT", "RETURN", "PRINT", "FN", "BOOL_LIT", "NULL_LIT", "LEFT_PAREN", 
      "LEFT_SQUARE", "LEFT_CURLY", "RIGHT_PAREN", "RIGHT_SQUARE", "RIGHT_CURLY", 
      "SEMI", "COL", "COMMA", "STAR", "SLASH", "MINUS", "PLUS", "MODULO", 
      "ARROW", "FAT_ARROW", "IDENTIFIER", "COMMENT", "SPACE", "INT_LIT", 
      "FLOAT_LIT", "STRING_LIT", "CHAR_LIT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,29,161,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,5,0,28,8,0,10,
  	0,12,0,31,9,0,1,0,1,0,1,1,1,1,1,2,1,2,3,2,39,8,2,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,4,1,4,1,4,3,4,50,8,4,1,5,1,5,1,5,1,5,1,6,1,6,5,6,58,8,6,10,6,12,
  	6,61,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,5,7,75,8,7,10,
  	7,12,7,78,9,7,3,7,80,8,7,1,7,1,7,1,7,1,7,1,7,3,7,87,8,7,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,5,8,96,8,8,10,8,12,8,99,9,8,3,8,101,8,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,3,8,110,8,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,
  	8,123,8,8,10,8,12,8,126,9,8,1,9,1,9,1,10,1,10,1,10,1,10,1,10,5,10,135,
  	8,10,10,10,12,10,138,9,10,3,10,140,8,10,1,10,1,10,1,10,1,10,1,11,5,11,
  	147,8,11,10,11,12,11,150,9,11,1,11,1,11,3,11,154,8,11,1,12,1,12,1,12,
  	3,12,159,8,12,1,12,0,1,16,13,0,2,4,6,8,10,12,14,16,18,20,22,24,0,3,3,
  	0,5,6,23,23,26,29,1,0,18,19,2,0,16,17,20,20,169,0,29,1,0,0,0,2,34,1,0,
  	0,0,4,36,1,0,0,0,6,42,1,0,0,0,8,49,1,0,0,0,10,51,1,0,0,0,12,55,1,0,0,
  	0,14,64,1,0,0,0,16,109,1,0,0,0,18,127,1,0,0,0,20,129,1,0,0,0,22,148,1,
  	0,0,0,24,158,1,0,0,0,26,28,3,2,1,0,27,26,1,0,0,0,28,31,1,0,0,0,29,27,
  	1,0,0,0,29,30,1,0,0,0,30,32,1,0,0,0,31,29,1,0,0,0,32,33,5,0,0,1,33,1,
  	1,0,0,0,34,35,3,14,7,0,35,3,1,0,0,0,36,38,5,2,0,0,37,39,3,16,8,0,38,37,
  	1,0,0,0,38,39,1,0,0,0,39,40,1,0,0,0,40,41,5,13,0,0,41,5,1,0,0,0,42,43,
  	5,3,0,0,43,44,3,16,8,0,44,45,5,13,0,0,45,7,1,0,0,0,46,50,3,12,6,0,47,
  	50,3,6,3,0,48,50,3,4,2,0,49,46,1,0,0,0,49,47,1,0,0,0,49,48,1,0,0,0,50,
  	9,1,0,0,0,51,52,5,22,0,0,52,53,3,16,8,0,53,54,5,13,0,0,54,11,1,0,0,0,
  	55,59,5,9,0,0,56,58,3,8,4,0,57,56,1,0,0,0,58,61,1,0,0,0,59,57,1,0,0,0,
  	59,60,1,0,0,0,60,62,1,0,0,0,61,59,1,0,0,0,62,63,5,12,0,0,63,13,1,0,0,
  	0,64,65,5,4,0,0,65,66,5,23,0,0,66,79,5,7,0,0,67,68,5,23,0,0,68,69,5,14,
  	0,0,69,76,3,24,12,0,70,71,5,15,0,0,71,72,5,23,0,0,72,73,5,14,0,0,73,75,
  	3,24,12,0,74,70,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,
  	80,1,0,0,0,78,76,1,0,0,0,79,67,1,0,0,0,79,80,1,0,0,0,80,81,1,0,0,0,81,
  	82,5,10,0,0,82,83,5,21,0,0,83,86,3,24,12,0,84,87,3,12,6,0,85,87,3,10,
  	5,0,86,84,1,0,0,0,86,85,1,0,0,0,87,15,1,0,0,0,88,89,6,8,-1,0,89,110,7,
  	0,0,0,90,91,5,23,0,0,91,100,5,7,0,0,92,97,3,16,8,0,93,94,5,15,0,0,94,
  	96,3,16,8,0,95,93,1,0,0,0,96,99,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,
  	101,1,0,0,0,99,97,1,0,0,0,100,92,1,0,0,0,100,101,1,0,0,0,101,102,1,0,
  	0,0,102,110,5,10,0,0,103,104,7,1,0,0,104,110,3,16,8,4,105,106,5,7,0,0,
  	106,107,3,16,8,0,107,108,5,10,0,0,108,110,1,0,0,0,109,88,1,0,0,0,109,
  	90,1,0,0,0,109,103,1,0,0,0,109,105,1,0,0,0,110,124,1,0,0,0,111,112,10,
  	3,0,0,112,113,7,2,0,0,113,123,3,16,8,4,114,115,10,2,0,0,115,116,7,1,0,
  	0,116,123,3,16,8,3,117,118,10,6,0,0,118,119,5,8,0,0,119,120,3,16,8,0,
  	120,121,5,11,0,0,121,123,1,0,0,0,122,111,1,0,0,0,122,114,1,0,0,0,122,
  	117,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,125,17,1,
  	0,0,0,126,124,1,0,0,0,127,128,5,23,0,0,128,19,1,0,0,0,129,130,5,4,0,0,
  	130,139,5,7,0,0,131,136,3,24,12,0,132,133,5,15,0,0,133,135,3,24,12,0,
  	134,132,1,0,0,0,135,138,1,0,0,0,136,134,1,0,0,0,136,137,1,0,0,0,137,140,
  	1,0,0,0,138,136,1,0,0,0,139,131,1,0,0,0,139,140,1,0,0,0,140,141,1,0,0,
  	0,141,142,5,10,0,0,142,143,5,21,0,0,143,144,3,24,12,0,144,21,1,0,0,0,
  	145,147,5,16,0,0,146,145,1,0,0,0,147,150,1,0,0,0,148,146,1,0,0,0,148,
  	149,1,0,0,0,149,153,1,0,0,0,150,148,1,0,0,0,151,154,3,18,9,0,152,154,
  	3,20,10,0,153,151,1,0,0,0,153,152,1,0,0,0,154,23,1,0,0,0,155,159,3,18,
  	9,0,156,159,3,22,11,0,157,159,3,20,10,0,158,155,1,0,0,0,158,156,1,0,0,
  	0,158,157,1,0,0,0,159,25,1,0,0,0,17,29,38,49,59,76,79,86,97,100,109,122,
  	124,136,139,148,153,158
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
    setState(29);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::FN) {
      setState(26);
      topLevelStatement();
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(32);
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
    setState(34);
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
    setState(36);
    match(FridayParser::RETURN);

    setState(38);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1015808224) != 0)) {
      setState(37);
      expr(0);
    }
    setState(40);
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
    setState(42);
    match(FridayParser::PRINT);
    setState(43);
    expr(0);
    setState(44);
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
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        block();
        break;
      }

      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 2);
        setState(47);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(48);
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
    setState(51);
    match(FridayParser::FAT_ARROW);
    setState(52);
    expr(0);
    setState(53);
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
    setState(55);
    match(FridayParser::LEFT_CURLY);

    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 524) != 0)) {
      setState(56);
      statement();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
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
    setState(64);
    match(FridayParser::FN);
    setState(65);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(66);
    match(FridayParser::LEFT_PAREN);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(67);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
      setState(68);
      match(FridayParser::COL);
      setState(69);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(70);
        match(FridayParser::COMMA);
        setState(71);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
        setState(72);
        match(FridayParser::COL);
        setState(73);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(81);
    match(FridayParser::RIGHT_PAREN);
    setState(82);
    match(FridayParser::ARROW);
    setState(83);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->returnType = type();
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        setState(84);
        block();
        break;
      }

      case FridayParser::FAT_ARROW: {
        setState(85);
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

tree::TerminalNode* FridayParser::CallContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

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
//----------------- PrimaryContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::PrimaryContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::INT_LIT() {
  return getToken(FridayParser::INT_LIT, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::CHAR_LIT() {
  return getToken(FridayParser::CHAR_LIT, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::STRING_LIT() {
  return getToken(FridayParser::STRING_LIT, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::FLOAT_LIT() {
  return getToken(FridayParser::FLOAT_LIT, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::BOOL_LIT() {
  return getToken(FridayParser::BOOL_LIT, 0);
}

tree::TerminalNode* FridayParser::PrimaryContext::NULL_LIT() {
  return getToken(FridayParser::NULL_LIT, 0);
}

FridayParser::PrimaryContext::PrimaryContext(ExprContext *ctx) { copyFrom(ctx); }

void FridayParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}
void FridayParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FridayParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}

std::any FridayParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FridayParserVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
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
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PrimaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(89);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1015021664) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(90);
      match(FridayParser::IDENTIFIER);
      setState(91);
      match(FridayParser::LEFT_PAREN);
      setState(100);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1015808224) != 0)) {
        setState(92);
        antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
        antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
        setState(97);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == FridayParser::COMMA) {
          setState(93);
          match(FridayParser::COMMA);
          setState(94);
          antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
          antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
          setState(99);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(102);
      match(FridayParser::RIGHT_PAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
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
      setState(104);
      expr(4);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<GroupingContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(105);
      match(FridayParser::LEFT_PAREN);
      setState(106);
      expr(0);
      setState(107);
      match(FridayParser::RIGHT_PAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(124);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(122);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(111);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(112);
          antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1245184) != 0))) {
            antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(113);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(114);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(115);
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
          setState(116);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->array = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(117);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(118);
          match(FridayParser::LEFT_SQUARE);
          setState(119);
          antlrcpp::downCast<SubscriptContext *>(_localctx)->index = expr(0);
          setState(120);
          match(FridayParser::RIGHT_SQUARE);
          break;
        }

        default:
          break;
        } 
      }
      setState(126);
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
    setState(127);
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
    setState(129);
    match(FridayParser::FN);
    setState(130);
    match(FridayParser::LEFT_PAREN);
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8454160) != 0)) {
      setState(131);
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(132);
        match(FridayParser::COMMA);
        setState(133);
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
        setState(138);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(141);
    match(FridayParser::RIGHT_PAREN);
    setState(142);
    match(FridayParser::ARROW);
    setState(143);
    type();
   
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

FridayParser::SimpleTypeContext* FridayParser::PointerTypeContext::simpleType() {
  return getRuleContext<FridayParser::SimpleTypeContext>(0);
}

FridayParser::FunctionTypeContext* FridayParser::PointerTypeContext::functionType() {
  return getRuleContext<FridayParser::FunctionTypeContext>(0);
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
    setState(148);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::STAR) {
      setState(145);
      match(FridayParser::STAR);
      setState(150);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        setState(151);
        simpleType();
        break;
      }

      case FridayParser::FN: {
        setState(152);
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
  enterRule(_localctx, 24, FridayParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(155);
      simpleType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      pointerType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(157);
      functionType();
      break;
    }

    default:
      break;
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
