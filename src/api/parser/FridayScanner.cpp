
// Generated from FridayScanner.g4 by ANTLR 4.13.2


#include "FridayScanner.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct FridayScannerStaticData final {
  FridayScannerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FridayScannerStaticData(const FridayScannerStaticData&) = delete;
  FridayScannerStaticData(FridayScannerStaticData&&) = delete;
  FridayScannerStaticData& operator=(const FridayScannerStaticData&) = delete;
  FridayScannerStaticData& operator=(FridayScannerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag fridayscannerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<FridayScannerStaticData> fridayscannerLexerStaticData = nullptr;

void fridayscannerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (fridayscannerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(fridayscannerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<FridayScannerStaticData>(
    std::vector<std::string>{
      "COMMENT", "SPACE", "STRUCT", "RETURN", "PRINT", "FN", "BOOL_LIT", 
      "NULL_LIT", "LEFT_PAREN", "LEFT_SQUARE", "LEFT_CURLY", "RIGHT_PAREN", 
      "RIGHT_SQUARE", "RIGHT_CURLY", "SEMI", "COL", "COMMA", "STAR", "SLASH", 
      "MINUS", "PLUS", "MODULO", "ARROW", "FAT_ARROW", "IDENTIFIER", "INT_LIT", 
      "FLOAT_LIT", "STRING_LIT", "CHAR_LIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,29,194,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,1,0,1,0,1,0,1,0,5,0,64,8,0,10,0,12,0,67,9,0,1,0,1,0,1,1,1,1,1,1,
  	1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,107,
  	8,6,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,
  	1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,
  	1,20,1,20,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,5,24,150,
  	8,24,10,24,12,24,153,9,24,1,25,1,25,1,25,5,25,158,8,25,10,25,12,25,161,
  	9,25,3,25,163,8,25,1,26,1,26,1,26,5,26,168,8,26,10,26,12,26,171,9,26,
  	3,26,173,8,26,1,26,1,26,5,26,177,8,26,10,26,12,26,180,9,26,1,27,1,27,
  	5,27,184,8,27,10,27,12,27,187,9,27,1,27,1,27,1,28,1,28,1,28,1,28,1,185,
  	0,29,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,1,0,6,2,0,10,10,13,13,3,0,9,10,13,13,32,32,
  	3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,49,57,1,0,48,
  	57,202,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,
  	11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,
  	0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,
  	0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,
  	43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,
  	0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,1,59,1,0,0,0,3,70,1,0,0,0,5,74,1,0,0,
  	0,7,81,1,0,0,0,9,88,1,0,0,0,11,94,1,0,0,0,13,106,1,0,0,0,15,108,1,0,0,
  	0,17,113,1,0,0,0,19,115,1,0,0,0,21,117,1,0,0,0,23,119,1,0,0,0,25,121,
  	1,0,0,0,27,123,1,0,0,0,29,125,1,0,0,0,31,127,1,0,0,0,33,129,1,0,0,0,35,
  	131,1,0,0,0,37,133,1,0,0,0,39,135,1,0,0,0,41,137,1,0,0,0,43,139,1,0,0,
  	0,45,141,1,0,0,0,47,144,1,0,0,0,49,147,1,0,0,0,51,162,1,0,0,0,53,172,
  	1,0,0,0,55,181,1,0,0,0,57,190,1,0,0,0,59,60,5,47,0,0,60,61,5,47,0,0,61,
  	65,1,0,0,0,62,64,8,0,0,0,63,62,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,
  	66,1,0,0,0,66,68,1,0,0,0,67,65,1,0,0,0,68,69,6,0,0,0,69,2,1,0,0,0,70,
  	71,7,1,0,0,71,72,1,0,0,0,72,73,6,1,0,0,73,4,1,0,0,0,74,75,5,115,0,0,75,
  	76,5,116,0,0,76,77,5,114,0,0,77,78,5,117,0,0,78,79,5,99,0,0,79,80,5,116,
  	0,0,80,6,1,0,0,0,81,82,5,114,0,0,82,83,5,101,0,0,83,84,5,116,0,0,84,85,
  	5,117,0,0,85,86,5,114,0,0,86,87,5,110,0,0,87,8,1,0,0,0,88,89,5,112,0,
  	0,89,90,5,114,0,0,90,91,5,105,0,0,91,92,5,110,0,0,92,93,5,116,0,0,93,
  	10,1,0,0,0,94,95,5,102,0,0,95,96,5,110,0,0,96,12,1,0,0,0,97,98,5,116,
  	0,0,98,99,5,114,0,0,99,100,5,117,0,0,100,107,5,101,0,0,101,102,5,102,
  	0,0,102,103,5,97,0,0,103,104,5,108,0,0,104,105,5,115,0,0,105,107,5,101,
  	0,0,106,97,1,0,0,0,106,101,1,0,0,0,107,14,1,0,0,0,108,109,5,110,0,0,109,
  	110,5,117,0,0,110,111,5,108,0,0,111,112,5,108,0,0,112,16,1,0,0,0,113,
  	114,5,40,0,0,114,18,1,0,0,0,115,116,5,91,0,0,116,20,1,0,0,0,117,118,5,
  	123,0,0,118,22,1,0,0,0,119,120,5,41,0,0,120,24,1,0,0,0,121,122,5,93,0,
  	0,122,26,1,0,0,0,123,124,5,125,0,0,124,28,1,0,0,0,125,126,5,59,0,0,126,
  	30,1,0,0,0,127,128,5,58,0,0,128,32,1,0,0,0,129,130,5,44,0,0,130,34,1,
  	0,0,0,131,132,5,42,0,0,132,36,1,0,0,0,133,134,5,47,0,0,134,38,1,0,0,0,
  	135,136,5,45,0,0,136,40,1,0,0,0,137,138,5,43,0,0,138,42,1,0,0,0,139,140,
  	5,37,0,0,140,44,1,0,0,0,141,142,5,45,0,0,142,143,5,62,0,0,143,46,1,0,
  	0,0,144,145,5,61,0,0,145,146,5,62,0,0,146,48,1,0,0,0,147,151,7,2,0,0,
  	148,150,7,3,0,0,149,148,1,0,0,0,150,153,1,0,0,0,151,149,1,0,0,0,151,152,
  	1,0,0,0,152,50,1,0,0,0,153,151,1,0,0,0,154,163,5,48,0,0,155,159,7,4,0,
  	0,156,158,7,5,0,0,157,156,1,0,0,0,158,161,1,0,0,0,159,157,1,0,0,0,159,
  	160,1,0,0,0,160,163,1,0,0,0,161,159,1,0,0,0,162,154,1,0,0,0,162,155,1,
  	0,0,0,163,52,1,0,0,0,164,173,5,48,0,0,165,169,7,4,0,0,166,168,7,5,0,0,
  	167,166,1,0,0,0,168,171,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,173,
  	1,0,0,0,171,169,1,0,0,0,172,164,1,0,0,0,172,165,1,0,0,0,173,174,1,0,0,
  	0,174,178,5,46,0,0,175,177,7,5,0,0,176,175,1,0,0,0,177,180,1,0,0,0,178,
  	176,1,0,0,0,178,179,1,0,0,0,179,54,1,0,0,0,180,178,1,0,0,0,181,185,5,
  	34,0,0,182,184,9,0,0,0,183,182,1,0,0,0,184,187,1,0,0,0,185,186,1,0,0,
  	0,185,183,1,0,0,0,186,188,1,0,0,0,187,185,1,0,0,0,188,189,5,34,0,0,189,
  	56,1,0,0,0,190,191,5,39,0,0,191,192,9,0,0,0,192,193,5,39,0,0,193,58,1,
  	0,0,0,10,0,65,106,151,159,162,169,172,178,185,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  fridayscannerLexerStaticData = std::move(staticData);
}

}

FridayScanner::FridayScanner(CharStream *input) : Lexer(input) {
  FridayScanner::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *fridayscannerLexerStaticData->atn, fridayscannerLexerStaticData->decisionToDFA, fridayscannerLexerStaticData->sharedContextCache);
}

FridayScanner::~FridayScanner() {
  delete _interpreter;
}

std::string FridayScanner::getGrammarFileName() const {
  return "FridayScanner.g4";
}

const std::vector<std::string>& FridayScanner::getRuleNames() const {
  return fridayscannerLexerStaticData->ruleNames;
}

const std::vector<std::string>& FridayScanner::getChannelNames() const {
  return fridayscannerLexerStaticData->channelNames;
}

const std::vector<std::string>& FridayScanner::getModeNames() const {
  return fridayscannerLexerStaticData->modeNames;
}

const dfa::Vocabulary& FridayScanner::getVocabulary() const {
  return fridayscannerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FridayScanner::getSerializedATN() const {
  return fridayscannerLexerStaticData->serializedATN;
}

const atn::ATN& FridayScanner::getATN() const {
  return *fridayscannerLexerStaticData->atn;
}




void FridayScanner::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  fridayscannerLexerInitialize();
#else
  ::antlr4::internal::call_once(fridayscannerLexerOnceFlag, fridayscannerLexerInitialize);
#endif
}
