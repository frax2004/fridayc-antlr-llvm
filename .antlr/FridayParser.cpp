
// Generated from c:/Dev/C++/fridayc-antlr-llvm/FridayParser.g4 by ANTLR 4.13.1



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
FridayParserStaticData *fridayparserParserStaticData = nullptr;

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
      "statement", "inlineBlock", "block", "functionBlock", "functionStatement", 
      "expr", "simpleType", "functionType", "pointerType", "pointedType", 
      "type"
    },
    std::vector<std::string>{
      "", "", "", "", "'struct'", "'return'", "'print'", "'fn'", "'for'", 
      "'while'", "'defer'", "'namespace'", "'using'", "'const'", "'let'", 
      "'new'", "'if'", "'elif'", "'else'", "", "'null'", "", "", "", "", 
      "'('", "'['", "'{'", "')'", "']'", "'}'", "';'", "':'", "','", "'->'", 
      "'=>'", "'and'", "'or'", "'not'", "'as'", "'sizeof'", "'alignof'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", 
      "'>'", "'<='", "'>='", "'=='", "'!='", "'='", "'+='", "'-='", "'*='", 
      "'/='", "'%='", "'<<='", "'>>='", "'&='", "'|='", "'~'", "'.'"
    },
    std::vector<std::string>{
      "", "INLINE_COMMENT", "COMMENT", "SPACE", "STRUCT", "RETURN", "PRINT", 
      "FN", "FOR", "WHILE", "DEFER", "NAMESPACE", "USING", "CONST", "LET", 
      "NEW", "IF", "ELIF", "ELSE", "BOOL_LIT", "NULL_LIT", "INT_LIT", "FLOAT_LIT", 
      "STRING_LIT", "CHAR_LIT", "LEFT_PAREN", "LEFT_SQUARE", "LEFT_CURLY", 
      "RIGHT_PAREN", "RIGHT_SQUARE", "RIGHT_CURLY", "SEMI", "COL", "COMMA", 
      "ARROW", "FAT_ARROW", "AND", "OR", "NOT", "AS", "SIZEOF", "ALIGNOF", 
      "PLUS", "MINUS", "STAR", "SLASH", "MODULO", "LSHIFT", "RSHIFT", "AMPERSAND", 
      "PIPELINE", "LESS", "GREATER", "LESS_EQ", "GREATER_EQ", "EQUALS", 
      "NOT_EQUALS", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "STAR_ASSIGN", 
      "SLASH_ASSIGN", "MODULO_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", 
      "AMPERSAND_ASSIGN", "PIPELINE_ASSIGN", "TILDE", "DOT", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,69,174,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,5,0,32,8,0,10,0,12,0,35,9,0,1,0,1,0,1,1,1,1,1,2,1,2,3,2,43,8,2,
  	1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,54,8,4,1,5,1,5,1,5,1,5,1,6,1,
  	6,5,6,62,8,6,10,6,12,6,65,9,6,1,6,1,6,1,7,1,7,3,7,71,8,7,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,83,8,8,10,8,12,8,86,9,8,3,8,88,8,8,1,
  	8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,3,9,109,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,5,9,127,8,9,10,9,12,9,130,9,9,3,9,132,8,9,1,9,5,9,135,8,9,10,
  	9,12,9,138,9,9,1,10,1,10,1,11,1,11,1,11,1,11,1,11,5,11,147,8,11,10,11,
  	12,11,150,9,11,3,11,152,8,11,1,11,1,11,1,11,1,11,1,12,4,12,159,8,12,11,
  	12,12,12,160,1,12,1,12,1,13,1,13,3,13,167,8,13,1,14,1,14,1,14,3,14,172,
  	8,14,1,14,0,1,18,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,2,1,0,42,
  	43,1,0,44,46,186,0,33,1,0,0,0,2,38,1,0,0,0,4,40,1,0,0,0,6,46,1,0,0,0,
  	8,53,1,0,0,0,10,55,1,0,0,0,12,59,1,0,0,0,14,70,1,0,0,0,16,72,1,0,0,0,
  	18,108,1,0,0,0,20,139,1,0,0,0,22,141,1,0,0,0,24,158,1,0,0,0,26,166,1,
  	0,0,0,28,171,1,0,0,0,30,32,3,2,1,0,31,30,1,0,0,0,32,35,1,0,0,0,33,31,
  	1,0,0,0,33,34,1,0,0,0,34,36,1,0,0,0,35,33,1,0,0,0,36,37,5,0,0,1,37,1,
  	1,0,0,0,38,39,3,16,8,0,39,3,1,0,0,0,40,42,5,5,0,0,41,43,3,18,9,0,42,41,
  	1,0,0,0,42,43,1,0,0,0,43,44,1,0,0,0,44,45,5,31,0,0,45,5,1,0,0,0,46,47,
  	5,6,0,0,47,48,3,18,9,0,48,49,5,31,0,0,49,7,1,0,0,0,50,54,3,12,6,0,51,
  	54,3,6,3,0,52,54,3,4,2,0,53,50,1,0,0,0,53,51,1,0,0,0,53,52,1,0,0,0,54,
  	9,1,0,0,0,55,56,5,35,0,0,56,57,3,18,9,0,57,58,5,31,0,0,58,11,1,0,0,0,
  	59,63,5,27,0,0,60,62,3,8,4,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,
  	0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,30,0,0,67,13,1,0,
  	0,0,68,71,3,12,6,0,69,71,3,10,5,0,70,68,1,0,0,0,70,69,1,0,0,0,71,15,1,
  	0,0,0,72,73,5,7,0,0,73,74,5,69,0,0,74,87,5,25,0,0,75,76,5,69,0,0,76,77,
  	5,32,0,0,77,84,3,28,14,0,78,79,5,33,0,0,79,80,5,69,0,0,80,81,5,32,0,0,
  	81,83,3,28,14,0,82,78,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,
  	0,85,88,1,0,0,0,86,84,1,0,0,0,87,75,1,0,0,0,87,88,1,0,0,0,88,89,1,0,0,
  	0,89,90,5,28,0,0,90,91,5,34,0,0,91,92,3,28,14,0,92,93,3,14,7,0,93,17,
  	1,0,0,0,94,95,6,9,-1,0,95,109,5,69,0,0,96,109,5,21,0,0,97,109,5,24,0,
  	0,98,109,5,23,0,0,99,109,5,22,0,0,100,109,5,19,0,0,101,109,5,20,0,0,102,
  	103,7,0,0,0,103,109,3,18,9,4,104,105,5,25,0,0,105,106,3,18,9,0,106,107,
  	5,28,0,0,107,109,1,0,0,0,108,94,1,0,0,0,108,96,1,0,0,0,108,97,1,0,0,0,
  	108,98,1,0,0,0,108,99,1,0,0,0,108,100,1,0,0,0,108,101,1,0,0,0,108,102,
  	1,0,0,0,108,104,1,0,0,0,109,136,1,0,0,0,110,111,10,3,0,0,111,112,7,1,
  	0,0,112,135,3,18,9,4,113,114,10,2,0,0,114,115,7,0,0,0,115,135,3,18,9,
  	3,116,117,10,6,0,0,117,118,5,26,0,0,118,119,3,18,9,0,119,120,5,29,0,0,
  	120,135,1,0,0,0,121,122,10,5,0,0,122,131,5,25,0,0,123,128,3,18,9,0,124,
  	125,5,33,0,0,125,127,3,18,9,0,126,124,1,0,0,0,127,130,1,0,0,0,128,126,
  	1,0,0,0,128,129,1,0,0,0,129,132,1,0,0,0,130,128,1,0,0,0,131,123,1,0,0,
  	0,131,132,1,0,0,0,132,133,1,0,0,0,133,135,5,28,0,0,134,110,1,0,0,0,134,
  	113,1,0,0,0,134,116,1,0,0,0,134,121,1,0,0,0,135,138,1,0,0,0,136,134,1,
  	0,0,0,136,137,1,0,0,0,137,19,1,0,0,0,138,136,1,0,0,0,139,140,5,69,0,0,
  	140,21,1,0,0,0,141,142,5,7,0,0,142,151,5,25,0,0,143,148,3,28,14,0,144,
  	145,5,33,0,0,145,147,3,28,14,0,146,144,1,0,0,0,147,150,1,0,0,0,148,146,
  	1,0,0,0,148,149,1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,151,143,1,0,0,
  	0,151,152,1,0,0,0,152,153,1,0,0,0,153,154,5,28,0,0,154,155,5,34,0,0,155,
  	156,3,28,14,0,156,23,1,0,0,0,157,159,5,44,0,0,158,157,1,0,0,0,159,160,
  	1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,162,1,0,0,0,162,163,3,26,
  	13,0,163,25,1,0,0,0,164,167,3,20,10,0,165,167,3,22,11,0,166,164,1,0,0,
  	0,166,165,1,0,0,0,167,27,1,0,0,0,168,172,3,20,10,0,169,172,3,24,12,0,
  	170,172,3,22,11,0,171,168,1,0,0,0,171,169,1,0,0,0,171,170,1,0,0,0,172,
  	29,1,0,0,0,17,33,42,53,63,70,84,87,108,128,131,134,136,148,151,160,166,
  	171
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fridayparserParserStaticData = staticData.release();
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
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::FN) {
      setState(30);
      topLevelStatement();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
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
    setState(38);
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
    setState(40);
    match(FridayParser::RETURN);

    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 19) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 19)) & 1125899932008575) != 0)) {
      setState(41);
      expr(0);
    }
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
    setState(46);
    match(FridayParser::PRINT);
    setState(47);
    expr(0);
    setState(48);
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
    setState(53);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(50);
        block();
        break;
      }

      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 2);
        setState(51);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(52);
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
    setState(55);
    match(FridayParser::FAT_ARROW);
    setState(56);
    expr(0);
    setState(57);
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
    setState(59);
    match(FridayParser::LEFT_CURLY);

    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 134217824) != 0)) {
      setState(60);
      statement();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(FridayParser::RIGHT_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionBlockContext ------------------------------------------------------------------

FridayParser::FunctionBlockContext::FunctionBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::BlockContext* FridayParser::FunctionBlockContext::block() {
  return getRuleContext<FridayParser::BlockContext>(0);
}

FridayParser::InlineBlockContext* FridayParser::FunctionBlockContext::inlineBlock() {
  return getRuleContext<FridayParser::InlineBlockContext>(0);
}


size_t FridayParser::FunctionBlockContext::getRuleIndex() const {
  return FridayParser::RuleFunctionBlock;
}


FridayParser::FunctionBlockContext* FridayParser::functionBlock() {
  FunctionBlockContext *_localctx = _tracker.createInstance<FunctionBlockContext>(_ctx, getState());
  enterRule(_localctx, 14, FridayParser::RuleFunctionBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(70);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(68);
        block();
        break;
      }

      case FridayParser::FAT_ARROW: {
        enterOuterAlt(_localctx, 2);
        setState(69);
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

FridayParser::FunctionBlockContext* FridayParser::FunctionStatementContext::functionBlock() {
  return getRuleContext<FridayParser::FunctionBlockContext>(0);
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


FridayParser::FunctionStatementContext* FridayParser::functionStatement() {
  FunctionStatementContext *_localctx = _tracker.createInstance<FunctionStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, FridayParser::RuleFunctionStatement);
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
    setState(72);
    match(FridayParser::FN);
    setState(73);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(74);
    match(FridayParser::LEFT_PAREN);
    setState(87);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(75);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
      setState(76);
      match(FridayParser::COL);
      setState(77);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(78);
        match(FridayParser::COMMA);
        setState(79);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
        setState(80);
        match(FridayParser::COL);
        setState(81);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
        setState(86);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(89);
    match(FridayParser::RIGHT_PAREN);
    setState(90);
    match(FridayParser::ARROW);
    setState(91);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->returnType = type();
    setState(92);
    functionBlock();
   
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


//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IdentifierContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::IdentifierContext::IdentifierContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- CharLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CharLiteralContext::CHAR_LIT() {
  return getToken(FridayParser::CHAR_LIT, 0);
}

FridayParser::CharLiteralContext::CharLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- StringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::StringLiteralContext::STRING_LIT() {
  return getToken(FridayParser::STRING_LIT, 0);
}

FridayParser::StringLiteralContext::StringLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- BoolLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::BoolLiteralContext::BOOL_LIT() {
  return getToken(FridayParser::BOOL_LIT, 0);
}

FridayParser::BoolLiteralContext::BoolLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::FloatLiteralContext::FLOAT_LIT() {
  return getToken(FridayParser::FLOAT_LIT, 0);
}

FridayParser::FloatLiteralContext::FloatLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IntLiteralContext::INT_LIT() {
  return getToken(FridayParser::INT_LIT, 0);
}

FridayParser::IntLiteralContext::IntLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


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


//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::NullLiteralContext::NULL_LIT() {
  return getToken(FridayParser::NULL_LIT, 0);
}

FridayParser::NullLiteralContext::NullLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


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



FridayParser::ExprContext* FridayParser::expr() {
   return expr(0);
}

FridayParser::ExprContext* FridayParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FridayParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FridayParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, FridayParser::RuleExpr, precedence);

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
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(95);
        match(FridayParser::IDENTIFIER);
        break;
      }

      case FridayParser::INT_LIT: {
        _localctx = _tracker.createInstance<IntLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(96);
        match(FridayParser::INT_LIT);
        break;
      }

      case FridayParser::CHAR_LIT: {
        _localctx = _tracker.createInstance<CharLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(97);
        match(FridayParser::CHAR_LIT);
        break;
      }

      case FridayParser::STRING_LIT: {
        _localctx = _tracker.createInstance<StringLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(98);
        match(FridayParser::STRING_LIT);
        break;
      }

      case FridayParser::FLOAT_LIT: {
        _localctx = _tracker.createInstance<FloatLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(99);
        match(FridayParser::FLOAT_LIT);
        break;
      }

      case FridayParser::BOOL_LIT: {
        _localctx = _tracker.createInstance<BoolLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(100);
        match(FridayParser::BOOL_LIT);
        break;
      }

      case FridayParser::NULL_LIT: {
        _localctx = _tracker.createInstance<NullLiteralContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(101);
        match(FridayParser::NULL_LIT);
        break;
      }

      case FridayParser::PLUS:
      case FridayParser::MINUS: {
        _localctx = _tracker.createInstance<UnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(102);
        antlrcpp::downCast<UnaryContext *>(_localctx)->unaryOperator = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == FridayParser::PLUS

        || _la == FridayParser::MINUS)) {
          antlrcpp::downCast<UnaryContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(103);
        expr(4);
        break;
      }

      case FridayParser::LEFT_PAREN: {
        _localctx = _tracker.createInstance<GroupingContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(104);
        match(FridayParser::LEFT_PAREN);
        setState(105);
        expr(0);
        setState(106);
        match(FridayParser::RIGHT_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(136);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(134);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(110);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(111);
          antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 123145302310912) != 0))) {
            antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(112);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(113);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(114);
          antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::PLUS

          || _la == FridayParser::MINUS)) {
            antlrcpp::downCast<BinaryContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(115);
          antlrcpp::downCast<BinaryContext *>(_localctx)->right = expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->array = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(116);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(117);
          match(FridayParser::LEFT_SQUARE);
          setState(118);
          antlrcpp::downCast<SubscriptContext *>(_localctx)->index = expr(0);
          setState(119);
          match(FridayParser::RIGHT_SQUARE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->func = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(121);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(122);
          match(FridayParser::LEFT_PAREN);
          setState(131);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 19) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 19)) & 1125899932008575) != 0)) {
            setState(123);
            antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
            antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
            setState(128);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == FridayParser::COMMA) {
              setState(124);
              match(FridayParser::COMMA);
              setState(125);
              antlrcpp::downCast<CallContext *>(_localctx)->exprContext = expr(0);
              antlrcpp::downCast<CallContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallContext *>(_localctx)->exprContext);
              setState(130);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(133);
          match(FridayParser::RIGHT_PAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(138);
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


FridayParser::SimpleTypeContext* FridayParser::simpleType() {
  SimpleTypeContext *_localctx = _tracker.createInstance<SimpleTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, FridayParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
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


FridayParser::FunctionTypeContext* FridayParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, FridayParser::RuleFunctionType);
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
    setState(141);
    match(FridayParser::FN);
    setState(142);
    match(FridayParser::LEFT_PAREN);
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & 4611686155866341377) != 0)) {
      setState(143);
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
      setState(148);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(144);
        match(FridayParser::COMMA);
        setState(145);
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
        setState(150);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(153);
    match(FridayParser::RIGHT_PAREN);
    setState(154);
    match(FridayParser::ARROW);
    setState(155);
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


FridayParser::PointerTypeContext* FridayParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, FridayParser::RulePointerType);
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
    setState(158); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(157);
      match(FridayParser::STAR);
      setState(160); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == FridayParser::STAR);
    setState(162);
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


FridayParser::PointedTypeContext* FridayParser::pointedType() {
  PointedTypeContext *_localctx = _tracker.createInstance<PointedTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, FridayParser::RulePointedType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(166);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        simpleType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 2);
        setState(165);
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


FridayParser::TypeContext* FridayParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 28, FridayParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(168);
        simpleType();
        break;
      }

      case FridayParser::STAR: {
        enterOuterAlt(_localctx, 2);
        setState(169);
        pointerType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 3);
        setState(170);
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
    case 9: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
