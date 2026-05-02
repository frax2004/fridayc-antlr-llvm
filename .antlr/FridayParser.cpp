
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
      "program", "topLevelStatement", "namespaceStatement", "usingStatement", 
      "structStatement", "functionStatement", "statement", "deferStatement", 
      "printStatement", "scope", "returnStatement", "deferrableStatement", 
      "inlineScope", "functionScope", "expr", "simpleType", "functionType", 
      "pointerType", "arrayType", "type"
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
      "AMPERSAND_ASSIGN", "PIPELINE_ASSIGN", "TILDE", "DOT", "IDENTIFIER", 
      "NAMESPACE_IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,70,228,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,3,0,42,8,0,1,
  	0,5,0,45,8,0,10,0,12,0,48,9,0,1,0,1,0,1,1,1,1,1,1,3,1,55,8,1,1,2,1,2,
  	1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,74,8,
  	4,10,4,12,4,77,9,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,
  	5,91,8,5,10,5,12,5,94,9,5,3,5,96,8,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,
  	1,6,3,6,107,8,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,5,9,118,8,9,10,9,
  	12,9,121,9,9,1,9,1,9,1,10,1,10,3,10,127,8,10,1,10,1,10,1,11,1,11,1,11,
  	3,11,134,8,11,1,12,1,12,1,12,1,12,1,13,1,13,3,13,142,8,13,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,158,8,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,5,14,176,8,14,10,14,12,14,179,9,14,3,14,181,8,14,1,14,5,
  	14,184,8,14,10,14,12,14,187,9,14,1,15,1,15,1,16,1,16,1,16,1,16,1,16,5,
  	16,196,8,16,10,16,12,16,199,9,16,3,16,201,8,16,1,16,1,16,1,16,1,16,1,
  	17,4,17,208,8,17,11,17,12,17,209,1,17,1,17,1,18,1,18,4,18,216,8,18,11,
  	18,12,18,217,1,18,1,18,1,19,1,19,1,19,1,19,3,19,226,8,19,1,19,0,1,28,
  	20,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,2,1,0,42,
  	43,1,0,44,46,244,0,41,1,0,0,0,2,54,1,0,0,0,4,56,1,0,0,0,6,60,1,0,0,0,
  	8,64,1,0,0,0,10,80,1,0,0,0,12,106,1,0,0,0,14,108,1,0,0,0,16,111,1,0,0,
  	0,18,115,1,0,0,0,20,124,1,0,0,0,22,133,1,0,0,0,24,135,1,0,0,0,26,141,
  	1,0,0,0,28,157,1,0,0,0,30,188,1,0,0,0,32,190,1,0,0,0,34,207,1,0,0,0,36,
  	215,1,0,0,0,38,225,1,0,0,0,40,42,3,4,2,0,41,40,1,0,0,0,41,42,1,0,0,0,
  	42,46,1,0,0,0,43,45,3,2,1,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,
  	46,47,1,0,0,0,47,49,1,0,0,0,48,46,1,0,0,0,49,50,5,0,0,1,50,1,1,0,0,0,
  	51,55,3,6,3,0,52,55,3,8,4,0,53,55,3,10,5,0,54,51,1,0,0,0,54,52,1,0,0,
  	0,54,53,1,0,0,0,55,3,1,0,0,0,56,57,5,11,0,0,57,58,5,70,0,0,58,59,5,31,
  	0,0,59,5,1,0,0,0,60,61,5,12,0,0,61,62,5,70,0,0,62,63,5,31,0,0,63,7,1,
  	0,0,0,64,65,5,4,0,0,65,66,5,69,0,0,66,75,5,27,0,0,67,68,5,69,0,0,68,69,
  	5,32,0,0,69,70,3,38,19,0,70,71,5,31,0,0,71,74,1,0,0,0,72,74,3,10,5,0,
  	73,67,1,0,0,0,73,72,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,
  	76,78,1,0,0,0,77,75,1,0,0,0,78,79,5,30,0,0,79,9,1,0,0,0,80,81,5,7,0,0,
  	81,82,5,69,0,0,82,95,5,25,0,0,83,84,5,69,0,0,84,85,5,32,0,0,85,92,3,38,
  	19,0,86,87,5,33,0,0,87,88,5,69,0,0,88,89,5,32,0,0,89,91,3,38,19,0,90,
  	86,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,96,1,0,0,0,94,
  	92,1,0,0,0,95,83,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,98,5,28,0,0,98,
  	99,5,34,0,0,99,100,3,38,19,0,100,101,3,26,13,0,101,11,1,0,0,0,102,107,
  	3,16,8,0,103,107,3,14,7,0,104,107,3,20,10,0,105,107,3,18,9,0,106,102,
  	1,0,0,0,106,103,1,0,0,0,106,104,1,0,0,0,106,105,1,0,0,0,107,13,1,0,0,
  	0,108,109,5,10,0,0,109,110,3,22,11,0,110,15,1,0,0,0,111,112,5,6,0,0,112,
  	113,3,28,14,0,113,114,5,31,0,0,114,17,1,0,0,0,115,119,5,27,0,0,116,118,
  	3,12,6,0,117,116,1,0,0,0,118,121,1,0,0,0,119,117,1,0,0,0,119,120,1,0,
  	0,0,120,122,1,0,0,0,121,119,1,0,0,0,122,123,5,30,0,0,123,19,1,0,0,0,124,
  	126,5,5,0,0,125,127,3,28,14,0,126,125,1,0,0,0,126,127,1,0,0,0,127,128,
  	1,0,0,0,128,129,5,31,0,0,129,21,1,0,0,0,130,134,3,16,8,0,131,134,3,20,
  	10,0,132,134,3,18,9,0,133,130,1,0,0,0,133,131,1,0,0,0,133,132,1,0,0,0,
  	134,23,1,0,0,0,135,136,5,35,0,0,136,137,3,28,14,0,137,138,5,31,0,0,138,
  	25,1,0,0,0,139,142,3,18,9,0,140,142,3,24,12,0,141,139,1,0,0,0,141,140,
  	1,0,0,0,142,27,1,0,0,0,143,144,6,14,-1,0,144,158,5,69,0,0,145,158,5,21,
  	0,0,146,158,5,24,0,0,147,158,5,23,0,0,148,158,5,22,0,0,149,158,5,19,0,
  	0,150,158,5,20,0,0,151,152,7,0,0,0,152,158,3,28,14,4,153,154,5,25,0,0,
  	154,155,3,28,14,0,155,156,5,28,0,0,156,158,1,0,0,0,157,143,1,0,0,0,157,
  	145,1,0,0,0,157,146,1,0,0,0,157,147,1,0,0,0,157,148,1,0,0,0,157,149,1,
  	0,0,0,157,150,1,0,0,0,157,151,1,0,0,0,157,153,1,0,0,0,158,185,1,0,0,0,
  	159,160,10,3,0,0,160,161,7,1,0,0,161,184,3,28,14,4,162,163,10,2,0,0,163,
  	164,7,0,0,0,164,184,3,28,14,3,165,166,10,6,0,0,166,167,5,26,0,0,167,168,
  	3,28,14,0,168,169,5,29,0,0,169,184,1,0,0,0,170,171,10,5,0,0,171,180,5,
  	25,0,0,172,177,3,28,14,0,173,174,5,33,0,0,174,176,3,28,14,0,175,173,1,
  	0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,1,0,0,0,178,181,1,0,0,0,
  	179,177,1,0,0,0,180,172,1,0,0,0,180,181,1,0,0,0,181,182,1,0,0,0,182,184,
  	5,28,0,0,183,159,1,0,0,0,183,162,1,0,0,0,183,165,1,0,0,0,183,170,1,0,
  	0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,29,1,0,0,0,187,
  	185,1,0,0,0,188,189,5,69,0,0,189,31,1,0,0,0,190,191,5,7,0,0,191,200,5,
  	25,0,0,192,197,3,38,19,0,193,194,5,33,0,0,194,196,3,38,19,0,195,193,1,
  	0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,201,1,0,0,0,
  	199,197,1,0,0,0,200,192,1,0,0,0,200,201,1,0,0,0,201,202,1,0,0,0,202,203,
  	5,28,0,0,203,204,5,34,0,0,204,205,3,38,19,0,205,33,1,0,0,0,206,208,5,
  	44,0,0,207,206,1,0,0,0,208,209,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,
  	0,210,211,1,0,0,0,211,212,3,38,19,0,212,35,1,0,0,0,213,214,5,26,0,0,214,
  	216,5,29,0,0,215,213,1,0,0,0,216,217,1,0,0,0,217,215,1,0,0,0,217,218,
  	1,0,0,0,218,219,1,0,0,0,219,220,3,38,19,0,220,37,1,0,0,0,221,226,3,30,
  	15,0,222,226,3,34,17,0,223,226,3,36,18,0,224,226,3,32,16,0,225,221,1,
  	0,0,0,225,222,1,0,0,0,225,223,1,0,0,0,225,224,1,0,0,0,226,39,1,0,0,0,
  	22,41,46,54,73,75,92,95,106,119,126,133,141,157,177,180,183,185,197,200,
  	209,217,225
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

FridayParser::NamespaceStatementContext* FridayParser::ProgramContext::namespaceStatement() {
  return getRuleContext<FridayParser::NamespaceStatementContext>(0);
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
    setState(41);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::NAMESPACE) {
      setState(40);
      namespaceStatement();
    }
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4240) != 0)) {
      setState(43);
      topLevelStatement();
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
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

FridayParser::UsingStatementContext* FridayParser::TopLevelStatementContext::usingStatement() {
  return getRuleContext<FridayParser::UsingStatementContext>(0);
}

FridayParser::StructStatementContext* FridayParser::TopLevelStatementContext::structStatement() {
  return getRuleContext<FridayParser::StructStatementContext>(0);
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
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::USING: {
        enterOuterAlt(_localctx, 1);
        setState(51);
        usingStatement();
        break;
      }

      case FridayParser::STRUCT: {
        enterOuterAlt(_localctx, 2);
        setState(52);
        structStatement();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 3);
        setState(53);
        functionStatement();
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

//----------------- NamespaceStatementContext ------------------------------------------------------------------

FridayParser::NamespaceStatementContext::NamespaceStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::NamespaceStatementContext::NAMESPACE() {
  return getToken(FridayParser::NAMESPACE, 0);
}

tree::TerminalNode* FridayParser::NamespaceStatementContext::NAMESPACE_IDENTIFIER() {
  return getToken(FridayParser::NAMESPACE_IDENTIFIER, 0);
}

tree::TerminalNode* FridayParser::NamespaceStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::NamespaceStatementContext::getRuleIndex() const {
  return FridayParser::RuleNamespaceStatement;
}


FridayParser::NamespaceStatementContext* FridayParser::namespaceStatement() {
  NamespaceStatementContext *_localctx = _tracker.createInstance<NamespaceStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, FridayParser::RuleNamespaceStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(FridayParser::NAMESPACE);
    setState(57);
    match(FridayParser::NAMESPACE_IDENTIFIER);
    setState(58);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UsingStatementContext ------------------------------------------------------------------

FridayParser::UsingStatementContext::UsingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::UsingStatementContext::USING() {
  return getToken(FridayParser::USING, 0);
}

tree::TerminalNode* FridayParser::UsingStatementContext::NAMESPACE_IDENTIFIER() {
  return getToken(FridayParser::NAMESPACE_IDENTIFIER, 0);
}

tree::TerminalNode* FridayParser::UsingStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::UsingStatementContext::getRuleIndex() const {
  return FridayParser::RuleUsingStatement;
}


FridayParser::UsingStatementContext* FridayParser::usingStatement() {
  UsingStatementContext *_localctx = _tracker.createInstance<UsingStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, FridayParser::RuleUsingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(FridayParser::USING);
    setState(61);
    match(FridayParser::NAMESPACE_IDENTIFIER);
    setState(62);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructStatementContext ------------------------------------------------------------------

FridayParser::StructStatementContext::StructStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::StructStatementContext::STRUCT() {
  return getToken(FridayParser::STRUCT, 0);
}

std::vector<tree::TerminalNode *> FridayParser::StructStatementContext::IDENTIFIER() {
  return getTokens(FridayParser::IDENTIFIER);
}

tree::TerminalNode* FridayParser::StructStatementContext::IDENTIFIER(size_t i) {
  return getToken(FridayParser::IDENTIFIER, i);
}

tree::TerminalNode* FridayParser::StructStatementContext::LEFT_CURLY() {
  return getToken(FridayParser::LEFT_CURLY, 0);
}

tree::TerminalNode* FridayParser::StructStatementContext::RIGHT_CURLY() {
  return getToken(FridayParser::RIGHT_CURLY, 0);
}

std::vector<FridayParser::FunctionStatementContext *> FridayParser::StructStatementContext::functionStatement() {
  return getRuleContexts<FridayParser::FunctionStatementContext>();
}

FridayParser::FunctionStatementContext* FridayParser::StructStatementContext::functionStatement(size_t i) {
  return getRuleContext<FridayParser::FunctionStatementContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::StructStatementContext::COL() {
  return getTokens(FridayParser::COL);
}

tree::TerminalNode* FridayParser::StructStatementContext::COL(size_t i) {
  return getToken(FridayParser::COL, i);
}

std::vector<tree::TerminalNode *> FridayParser::StructStatementContext::SEMI() {
  return getTokens(FridayParser::SEMI);
}

tree::TerminalNode* FridayParser::StructStatementContext::SEMI(size_t i) {
  return getToken(FridayParser::SEMI, i);
}

std::vector<FridayParser::TypeContext *> FridayParser::StructStatementContext::type() {
  return getRuleContexts<FridayParser::TypeContext>();
}

FridayParser::TypeContext* FridayParser::StructStatementContext::type(size_t i) {
  return getRuleContext<FridayParser::TypeContext>(i);
}


size_t FridayParser::StructStatementContext::getRuleIndex() const {
  return FridayParser::RuleStructStatement;
}


FridayParser::StructStatementContext* FridayParser::structStatement() {
  StructStatementContext *_localctx = _tracker.createInstance<StructStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, FridayParser::RuleStructStatement);
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
    match(FridayParser::STRUCT);
    setState(65);
    match(FridayParser::IDENTIFIER);
    setState(66);
    match(FridayParser::LEFT_CURLY);
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::FN

    || _la == FridayParser::IDENTIFIER) {
      setState(73);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FridayParser::IDENTIFIER: {
          setState(67);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->fieldsNames.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->identifierToken);
          setState(68);
          match(FridayParser::COL);
          setState(69);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->typeContext = type();
          antlrcpp::downCast<StructStatementContext *>(_localctx)->fieldsTypes.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->typeContext);
          setState(70);
          match(FridayParser::SEMI);
          break;
        }

        case FridayParser::FN: {
          setState(72);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->functionStatementContext = functionStatement();
          antlrcpp::downCast<StructStatementContext *>(_localctx)->methods.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->functionStatementContext);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
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

FridayParser::FunctionScopeContext* FridayParser::FunctionStatementContext::functionScope() {
  return getRuleContext<FridayParser::FunctionScopeContext>(0);
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
  enterRule(_localctx, 10, FridayParser::RuleFunctionStatement);
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
    setState(80);
    match(FridayParser::FN);
    setState(81);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(82);
    match(FridayParser::LEFT_PAREN);
    setState(95);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(83);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
      setState(84);
      match(FridayParser::COL);
      setState(85);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(86);
        match(FridayParser::COMMA);
        setState(87);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
        setState(88);
        match(FridayParser::COL);
        setState(89);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(97);
    match(FridayParser::RIGHT_PAREN);
    setState(98);
    match(FridayParser::ARROW);
    setState(99);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->returnType = type();
    setState(100);
    functionScope();
   
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

FridayParser::PrintStatementContext* FridayParser::StatementContext::printStatement() {
  return getRuleContext<FridayParser::PrintStatementContext>(0);
}

FridayParser::DeferStatementContext* FridayParser::StatementContext::deferStatement() {
  return getRuleContext<FridayParser::DeferStatementContext>(0);
}

FridayParser::ReturnStatementContext* FridayParser::StatementContext::returnStatement() {
  return getRuleContext<FridayParser::ReturnStatementContext>(0);
}

FridayParser::ScopeContext* FridayParser::StatementContext::scope() {
  return getRuleContext<FridayParser::ScopeContext>(0);
}


size_t FridayParser::StatementContext::getRuleIndex() const {
  return FridayParser::RuleStatement;
}


FridayParser::StatementContext* FridayParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, FridayParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 1);
        setState(102);
        printStatement();
        break;
      }

      case FridayParser::DEFER: {
        enterOuterAlt(_localctx, 2);
        setState(103);
        deferStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(104);
        returnStatement();
        break;
      }

      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 4);
        setState(105);
        scope();
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

//----------------- DeferStatementContext ------------------------------------------------------------------

FridayParser::DeferStatementContext::DeferStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::DeferStatementContext::DEFER() {
  return getToken(FridayParser::DEFER, 0);
}

FridayParser::DeferrableStatementContext* FridayParser::DeferStatementContext::deferrableStatement() {
  return getRuleContext<FridayParser::DeferrableStatementContext>(0);
}


size_t FridayParser::DeferStatementContext::getRuleIndex() const {
  return FridayParser::RuleDeferStatement;
}


FridayParser::DeferStatementContext* FridayParser::deferStatement() {
  DeferStatementContext *_localctx = _tracker.createInstance<DeferStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, FridayParser::RuleDeferStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(FridayParser::DEFER);
    setState(109);
    deferrableStatement();
   
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
  enterRule(_localctx, 16, FridayParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(FridayParser::PRINT);
    setState(112);
    expr(0);
    setState(113);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

FridayParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::ScopeContext::LEFT_CURLY() {
  return getToken(FridayParser::LEFT_CURLY, 0);
}

tree::TerminalNode* FridayParser::ScopeContext::RIGHT_CURLY() {
  return getToken(FridayParser::RIGHT_CURLY, 0);
}

std::vector<FridayParser::StatementContext *> FridayParser::ScopeContext::statement() {
  return getRuleContexts<FridayParser::StatementContext>();
}

FridayParser::StatementContext* FridayParser::ScopeContext::statement(size_t i) {
  return getRuleContext<FridayParser::StatementContext>(i);
}


size_t FridayParser::ScopeContext::getRuleIndex() const {
  return FridayParser::RuleScope;
}


FridayParser::ScopeContext* FridayParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 18, FridayParser::RuleScope);
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
    setState(115);
    match(FridayParser::LEFT_CURLY);

    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 134218848) != 0)) {
      setState(116);
      statement();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(122);
    match(FridayParser::RIGHT_CURLY);
   
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
  enterRule(_localctx, 20, FridayParser::RuleReturnStatement);
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
    setState(124);
    match(FridayParser::RETURN);

    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 19) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 19)) & 1125899932008575) != 0)) {
      setState(125);
      expr(0);
    }
    setState(128);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeferrableStatementContext ------------------------------------------------------------------

FridayParser::DeferrableStatementContext::DeferrableStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::PrintStatementContext* FridayParser::DeferrableStatementContext::printStatement() {
  return getRuleContext<FridayParser::PrintStatementContext>(0);
}

FridayParser::ReturnStatementContext* FridayParser::DeferrableStatementContext::returnStatement() {
  return getRuleContext<FridayParser::ReturnStatementContext>(0);
}

FridayParser::ScopeContext* FridayParser::DeferrableStatementContext::scope() {
  return getRuleContext<FridayParser::ScopeContext>(0);
}


size_t FridayParser::DeferrableStatementContext::getRuleIndex() const {
  return FridayParser::RuleDeferrableStatement;
}


FridayParser::DeferrableStatementContext* FridayParser::deferrableStatement() {
  DeferrableStatementContext *_localctx = _tracker.createInstance<DeferrableStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, FridayParser::RuleDeferrableStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 1);
        setState(130);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(131);
        returnStatement();
        break;
      }

      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 3);
        setState(132);
        scope();
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

//----------------- InlineScopeContext ------------------------------------------------------------------

FridayParser::InlineScopeContext::InlineScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::InlineScopeContext::FAT_ARROW() {
  return getToken(FridayParser::FAT_ARROW, 0);
}

FridayParser::ExprContext* FridayParser::InlineScopeContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::InlineScopeContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::InlineScopeContext::getRuleIndex() const {
  return FridayParser::RuleInlineScope;
}


FridayParser::InlineScopeContext* FridayParser::inlineScope() {
  InlineScopeContext *_localctx = _tracker.createInstance<InlineScopeContext>(_ctx, getState());
  enterRule(_localctx, 24, FridayParser::RuleInlineScope);

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
    match(FridayParser::FAT_ARROW);
    setState(136);
    expr(0);
    setState(137);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionScopeContext ------------------------------------------------------------------

FridayParser::FunctionScopeContext::FunctionScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::ScopeContext* FridayParser::FunctionScopeContext::scope() {
  return getRuleContext<FridayParser::ScopeContext>(0);
}

FridayParser::InlineScopeContext* FridayParser::FunctionScopeContext::inlineScope() {
  return getRuleContext<FridayParser::InlineScopeContext>(0);
}


size_t FridayParser::FunctionScopeContext::getRuleIndex() const {
  return FridayParser::RuleFunctionScope;
}


FridayParser::FunctionScopeContext* FridayParser::functionScope() {
  FunctionScopeContext *_localctx = _tracker.createInstance<FunctionScopeContext>(_ctx, getState());
  enterRule(_localctx, 26, FridayParser::RuleFunctionScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(141);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(139);
        scope();
        break;
      }

      case FridayParser::FAT_ARROW: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        inlineScope();
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

//----------------- BinaryExpressionContext ------------------------------------------------------------------

std::vector<FridayParser::ExprContext *> FridayParser::BinaryExpressionContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::BinaryExpressionContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::STAR() {
  return getToken(FridayParser::STAR, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::SLASH() {
  return getToken(FridayParser::SLASH, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::MODULO() {
  return getToken(FridayParser::MODULO, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::PLUS() {
  return getToken(FridayParser::PLUS, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::MINUS() {
  return getToken(FridayParser::MINUS, 0);
}

FridayParser::BinaryExpressionContext::BinaryExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- StringLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::StringLiteralExpressionContext::STRING_LIT() {
  return getToken(FridayParser::STRING_LIT, 0);
}

FridayParser::StringLiteralExpressionContext::StringLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- FloatLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::FloatLiteralExpressionContext::FLOAT_LIT() {
  return getToken(FridayParser::FLOAT_LIT, 0);
}

FridayParser::FloatLiteralExpressionContext::FloatLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- GroupingExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::GroupingExpressionContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

FridayParser::ExprContext* FridayParser::GroupingExpressionContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::GroupingExpressionContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

FridayParser::GroupingExpressionContext::GroupingExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- SubscriptExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::SubscriptExpressionContext::LEFT_SQUARE() {
  return getToken(FridayParser::LEFT_SQUARE, 0);
}

tree::TerminalNode* FridayParser::SubscriptExpressionContext::RIGHT_SQUARE() {
  return getToken(FridayParser::RIGHT_SQUARE, 0);
}

std::vector<FridayParser::ExprContext *> FridayParser::SubscriptExpressionContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::SubscriptExpressionContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

FridayParser::SubscriptExpressionContext::SubscriptExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- BoolLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::BoolLiteralExpressionContext::BOOL_LIT() {
  return getToken(FridayParser::BOOL_LIT, 0);
}

FridayParser::BoolLiteralExpressionContext::BoolLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- UnaryExpressionContext ------------------------------------------------------------------

FridayParser::ExprContext* FridayParser::UnaryExpressionContext::expr() {
  return getRuleContext<FridayParser::ExprContext>(0);
}

tree::TerminalNode* FridayParser::UnaryExpressionContext::PLUS() {
  return getToken(FridayParser::PLUS, 0);
}

tree::TerminalNode* FridayParser::UnaryExpressionContext::MINUS() {
  return getToken(FridayParser::MINUS, 0);
}

FridayParser::UnaryExpressionContext::UnaryExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- CharLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CharLiteralExpressionContext::CHAR_LIT() {
  return getToken(FridayParser::CHAR_LIT, 0);
}

FridayParser::CharLiteralExpressionContext::CharLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- CallExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CallExpressionContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::CallExpressionContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

std::vector<FridayParser::ExprContext *> FridayParser::CallExpressionContext::expr() {
  return getRuleContexts<FridayParser::ExprContext>();
}

FridayParser::ExprContext* FridayParser::CallExpressionContext::expr(size_t i) {
  return getRuleContext<FridayParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::CallExpressionContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::CallExpressionContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}

FridayParser::CallExpressionContext::CallExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- IntLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IntLiteralExpressionContext::INT_LIT() {
  return getToken(FridayParser::INT_LIT, 0);
}

FridayParser::IntLiteralExpressionContext::IntLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- NullLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::NullLiteralExpressionContext::NULL_LIT() {
  return getToken(FridayParser::NULL_LIT, 0);
}

FridayParser::NullLiteralExpressionContext::NullLiteralExpressionContext(ExprContext *ctx) { copyFrom(ctx); }


//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IdentifierExpressionContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::IdentifierExpressionContext::IdentifierExpressionContext(ExprContext *ctx) { copyFrom(ctx); }



FridayParser::ExprContext* FridayParser::expr() {
   return expr(0);
}

FridayParser::ExprContext* FridayParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FridayParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FridayParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, FridayParser::RuleExpr, precedence);

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
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(144);
        match(FridayParser::IDENTIFIER);
        break;
      }

      case FridayParser::INT_LIT: {
        _localctx = _tracker.createInstance<IntLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(145);
        match(FridayParser::INT_LIT);
        break;
      }

      case FridayParser::CHAR_LIT: {
        _localctx = _tracker.createInstance<CharLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(146);
        match(FridayParser::CHAR_LIT);
        break;
      }

      case FridayParser::STRING_LIT: {
        _localctx = _tracker.createInstance<StringLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(147);
        match(FridayParser::STRING_LIT);
        break;
      }

      case FridayParser::FLOAT_LIT: {
        _localctx = _tracker.createInstance<FloatLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(148);
        match(FridayParser::FLOAT_LIT);
        break;
      }

      case FridayParser::BOOL_LIT: {
        _localctx = _tracker.createInstance<BoolLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(149);
        match(FridayParser::BOOL_LIT);
        break;
      }

      case FridayParser::NULL_LIT: {
        _localctx = _tracker.createInstance<NullLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(150);
        match(FridayParser::NULL_LIT);
        break;
      }

      case FridayParser::PLUS:
      case FridayParser::MINUS: {
        _localctx = _tracker.createInstance<UnaryExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(151);
        antlrcpp::downCast<UnaryExpressionContext *>(_localctx)->unaryOperator = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == FridayParser::PLUS

        || _la == FridayParser::MINUS)) {
          antlrcpp::downCast<UnaryExpressionContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(152);
        expr(4);
        break;
      }

      case FridayParser::LEFT_PAREN: {
        _localctx = _tracker.createInstance<GroupingExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(153);
        match(FridayParser::LEFT_PAREN);
        setState(154);
        expr(0);
        setState(155);
        match(FridayParser::RIGHT_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(159);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(160);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 123145302310912) != 0))) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(161);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expr(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(162);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(163);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::PLUS

          || _la == FridayParser::MINUS)) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(164);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expr(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<SubscriptExpressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->array = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(166);
          match(FridayParser::LEFT_SQUARE);
          setState(167);
          antlrcpp::downCast<SubscriptExpressionContext *>(_localctx)->index = expr(0);
          setState(168);
          match(FridayParser::RIGHT_SQUARE);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CallExpressionContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->func = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(171);
          match(FridayParser::LEFT_PAREN);
          setState(180);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 19) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 19)) & 1125899932008575) != 0)) {
            setState(172);
            antlrcpp::downCast<CallExpressionContext *>(_localctx)->exprContext = expr(0);
            antlrcpp::downCast<CallExpressionContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallExpressionContext *>(_localctx)->exprContext);
            setState(177);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == FridayParser::COMMA) {
              setState(173);
              match(FridayParser::COMMA);
              setState(174);
              antlrcpp::downCast<CallExpressionContext *>(_localctx)->exprContext = expr(0);
              antlrcpp::downCast<CallExpressionContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallExpressionContext *>(_localctx)->exprContext);
              setState(179);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(182);
          match(FridayParser::RIGHT_PAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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
  enterRule(_localctx, 30, FridayParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
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
  enterRule(_localctx, 32, FridayParser::RuleFunctionType);
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
    setState(190);
    match(FridayParser::FN);
    setState(191);
    match(FridayParser::LEFT_PAREN);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & 4611686155866865665) != 0)) {
      setState(192);
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(193);
        match(FridayParser::COMMA);
        setState(194);
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
        setState(199);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(202);
    match(FridayParser::RIGHT_PAREN);
    setState(203);
    match(FridayParser::ARROW);
    setState(204);
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

FridayParser::TypeContext* FridayParser::PointerTypeContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
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
  enterRule(_localctx, 34, FridayParser::RulePointerType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(206);
              match(FridayParser::STAR);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(209); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(211);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

FridayParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::TypeContext* FridayParser::ArrayTypeContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> FridayParser::ArrayTypeContext::LEFT_SQUARE() {
  return getTokens(FridayParser::LEFT_SQUARE);
}

tree::TerminalNode* FridayParser::ArrayTypeContext::LEFT_SQUARE(size_t i) {
  return getToken(FridayParser::LEFT_SQUARE, i);
}

std::vector<tree::TerminalNode *> FridayParser::ArrayTypeContext::RIGHT_SQUARE() {
  return getTokens(FridayParser::RIGHT_SQUARE);
}

tree::TerminalNode* FridayParser::ArrayTypeContext::RIGHT_SQUARE(size_t i) {
  return getToken(FridayParser::RIGHT_SQUARE, i);
}


size_t FridayParser::ArrayTypeContext::getRuleIndex() const {
  return FridayParser::RuleArrayType;
}


FridayParser::ArrayTypeContext* FridayParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, FridayParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(215); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(213);
              match(FridayParser::LEFT_SQUARE);
              setState(214);
              match(FridayParser::RIGHT_SQUARE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(217); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(219);
    type();
   
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

FridayParser::ArrayTypeContext* FridayParser::TypeContext::arrayType() {
  return getRuleContext<FridayParser::ArrayTypeContext>(0);
}

FridayParser::FunctionTypeContext* FridayParser::TypeContext::functionType() {
  return getRuleContext<FridayParser::FunctionTypeContext>(0);
}


size_t FridayParser::TypeContext::getRuleIndex() const {
  return FridayParser::RuleType;
}


FridayParser::TypeContext* FridayParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 38, FridayParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(225);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(221);
        simpleType();
        break;
      }

      case FridayParser::STAR: {
        enterOuterAlt(_localctx, 2);
        setState(222);
        pointerType();
        break;
      }

      case FridayParser::LEFT_SQUARE: {
        enterOuterAlt(_localctx, 3);
        setState(223);
        arrayType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 4);
        setState(224);
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
    case 14: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

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
