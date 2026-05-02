
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
      "program", "topLevelStatement", "nativeFunctionStatement", "namespaceStatement", 
      "usingStatement", "structStatement", "functionStatement", "statement", 
      "deferrableStatement", "declarationStatement", "ifStatement", "forStatement", 
      "whileStatement", "expressionStatement", "deferStatement", "printStatement", 
      "scope", "returnStatement", "inlineScope", "functionScope", "expression", 
      "type", "simpleType", "functionType", "pointerType", "arrayType"
    },
    std::vector<std::string>{
      "", "", "", "", "'struct'", "'return'", "'print'", "'fn'", "'for'", 
      "'while'", "'defer'", "'native'", "'namespace'", "'using'", "'const'", 
      "'let'", "'new'", "'if'", "'elif'", "'else'", "'and'", "'or'", "'not'", 
      "'as'", "'sizeof'", "'alignof'", "", "'null'", "", "", "", "", "'('", 
      "'['", "'{'", "')'", "']'", "'}'", "';'", "':'", "','", "'->'", "'=>'", 
      "'++'", "'--'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<<'", "'>>'", 
      "'&'", "'|'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'='", 
      "'+='", "'-='", "'*='", "'/='", "'%='", "'<<='", "'>>='", "'&='", 
      "'|='", "'~'", "'.'"
    },
    std::vector<std::string>{
      "", "INLINE_COMMENT", "COMMENT", "SPACE", "STRUCT", "RETURN", "PRINT", 
      "FN", "FOR", "WHILE", "DEFER", "NATIVE", "NAMESPACE", "USING", "CONST", 
      "LET", "NEW", "IF", "ELIF", "ELSE", "AND", "OR", "NOT", "AS", "SIZEOF", 
      "ALIGNOF", "BOOL_LIT", "NULL_LIT", "INT_LIT", "FLOAT_LIT", "STRING_LIT", 
      "CHAR_LIT", "LEFT_PAREN", "LEFT_SQUARE", "LEFT_CURLY", "RIGHT_PAREN", 
      "RIGHT_SQUARE", "RIGHT_CURLY", "SEMI", "COL", "COMMA", "ARROW", "FAT_ARROW", 
      "INCREMENT", "DECREMENT", "PLUS", "MINUS", "STAR", "SLASH", "MODULO", 
      "LSHIFT", "RSHIFT", "AMPERSAND", "PIPELINE", "LESS", "GREATER", "LESS_EQ", 
      "GREATER_EQ", "EQUALS", "NOT_EQUALS", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", 
      "STAR_ASSIGN", "SLASH_ASSIGN", "MODULO_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", 
      "AMPERSAND_ASSIGN", "PIPELINE_ASSIGN", "TILDE", "DOT", "IDENTIFIER", 
      "NAMESPACE_IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,73,382,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,3,0,54,8,0,1,0,5,0,57,
  	8,0,10,0,12,0,60,9,0,1,0,1,0,1,1,1,1,1,1,1,1,3,1,68,8,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,81,8,2,10,2,12,2,84,9,2,3,2,86,8,2,
  	1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,5,5,110,8,5,10,5,12,5,113,9,5,1,5,1,5,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,127,8,6,10,6,12,6,130,9,6,3,6,132,8,6,1,
  	6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,148,8,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,158,8,8,1,9,1,9,1,9,1,9,3,9,164,8,9,1,
  	9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,177,8,10,10,10,
  	12,10,180,9,10,1,10,1,10,3,10,184,8,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,
  	1,15,1,16,1,16,5,16,209,8,16,10,16,12,16,212,9,16,1,16,1,16,1,17,1,17,
  	3,17,218,8,17,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,3,19,228,8,19,1,
  	20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,5,20,248,8,20,10,20,12,20,251,9,20,3,20,253,8,20,1,
  	20,1,20,1,20,1,20,1,20,1,20,5,20,261,8,20,10,20,12,20,264,9,20,3,20,266,
  	8,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,274,8,20,1,20,1,20,1,20,1,20,
  	3,20,280,8,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,319,
  	8,20,10,20,12,20,322,9,20,3,20,324,8,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,5,20,338,8,20,10,20,12,20,341,9,20,1,21,
  	1,21,1,21,1,21,3,21,347,8,21,1,22,1,22,1,23,1,23,1,23,1,23,1,23,5,23,
  	356,8,23,10,23,12,23,359,9,23,3,23,361,8,23,1,23,1,23,1,23,1,23,1,24,
  	4,24,368,8,24,11,24,12,24,369,1,24,1,24,1,25,1,25,4,25,376,8,25,11,25,
  	12,25,377,1,25,1,25,1,25,3,178,249,262,1,40,26,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,0,10,1,0,14,15,4,0,
  	22,22,45,47,52,52,70,70,1,0,24,25,1,0,47,49,1,0,45,46,1,0,50,51,1,0,54,
  	57,1,0,58,59,1,0,60,69,1,0,43,44,427,0,53,1,0,0,0,2,67,1,0,0,0,4,69,1,
  	0,0,0,6,92,1,0,0,0,8,96,1,0,0,0,10,100,1,0,0,0,12,116,1,0,0,0,14,147,
  	1,0,0,0,16,157,1,0,0,0,18,159,1,0,0,0,20,169,1,0,0,0,22,185,1,0,0,0,24,
  	192,1,0,0,0,26,196,1,0,0,0,28,199,1,0,0,0,30,202,1,0,0,0,32,206,1,0,0,
  	0,34,215,1,0,0,0,36,221,1,0,0,0,38,227,1,0,0,0,40,279,1,0,0,0,42,346,
  	1,0,0,0,44,348,1,0,0,0,46,350,1,0,0,0,48,367,1,0,0,0,50,375,1,0,0,0,52,
  	54,3,6,3,0,53,52,1,0,0,0,53,54,1,0,0,0,54,58,1,0,0,0,55,57,3,2,1,0,56,
  	55,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,1,0,0,0,60,
  	58,1,0,0,0,61,62,5,0,0,1,62,1,1,0,0,0,63,68,3,8,4,0,64,68,3,10,5,0,65,
  	68,3,12,6,0,66,68,3,4,2,0,67,63,1,0,0,0,67,64,1,0,0,0,67,65,1,0,0,0,67,
  	66,1,0,0,0,68,3,1,0,0,0,69,70,5,11,0,0,70,71,5,7,0,0,71,72,5,72,0,0,72,
  	85,5,32,0,0,73,74,5,72,0,0,74,75,5,39,0,0,75,82,3,42,21,0,76,77,5,40,
  	0,0,77,78,5,72,0,0,78,79,5,39,0,0,79,81,3,42,21,0,80,76,1,0,0,0,81,84,
  	1,0,0,0,82,80,1,0,0,0,82,83,1,0,0,0,83,86,1,0,0,0,84,82,1,0,0,0,85,73,
  	1,0,0,0,85,86,1,0,0,0,86,87,1,0,0,0,87,88,5,35,0,0,88,89,5,41,0,0,89,
  	90,3,42,21,0,90,91,5,38,0,0,91,5,1,0,0,0,92,93,5,12,0,0,93,94,5,73,0,
  	0,94,95,5,38,0,0,95,7,1,0,0,0,96,97,5,13,0,0,97,98,5,73,0,0,98,99,5,38,
  	0,0,99,9,1,0,0,0,100,101,5,4,0,0,101,102,5,72,0,0,102,111,5,34,0,0,103,
  	104,5,72,0,0,104,105,5,39,0,0,105,106,3,42,21,0,106,107,5,38,0,0,107,
  	110,1,0,0,0,108,110,3,12,6,0,109,103,1,0,0,0,109,108,1,0,0,0,110,113,
  	1,0,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,111,1,0,0,
  	0,114,115,5,37,0,0,115,11,1,0,0,0,116,117,5,7,0,0,117,118,5,72,0,0,118,
  	131,5,32,0,0,119,120,5,72,0,0,120,121,5,39,0,0,121,128,3,42,21,0,122,
  	123,5,40,0,0,123,124,5,72,0,0,124,125,5,39,0,0,125,127,3,42,21,0,126,
  	122,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,132,1,
  	0,0,0,130,128,1,0,0,0,131,119,1,0,0,0,131,132,1,0,0,0,132,133,1,0,0,0,
  	133,134,5,35,0,0,134,135,5,41,0,0,135,136,3,42,21,0,136,137,3,38,19,0,
  	137,13,1,0,0,0,138,148,3,30,15,0,139,148,3,34,17,0,140,148,3,26,13,0,
  	141,148,3,20,10,0,142,148,3,22,11,0,143,148,3,24,12,0,144,148,3,18,9,
  	0,145,148,3,32,16,0,146,148,3,28,14,0,147,138,1,0,0,0,147,139,1,0,0,0,
  	147,140,1,0,0,0,147,141,1,0,0,0,147,142,1,0,0,0,147,143,1,0,0,0,147,144,
  	1,0,0,0,147,145,1,0,0,0,147,146,1,0,0,0,148,15,1,0,0,0,149,158,3,30,15,
  	0,150,158,3,34,17,0,151,158,3,26,13,0,152,158,3,20,10,0,153,158,3,22,
  	11,0,154,158,3,24,12,0,155,158,3,18,9,0,156,158,3,32,16,0,157,149,1,0,
  	0,0,157,150,1,0,0,0,157,151,1,0,0,0,157,152,1,0,0,0,157,153,1,0,0,0,157,
  	154,1,0,0,0,157,155,1,0,0,0,157,156,1,0,0,0,158,17,1,0,0,0,159,160,7,
  	0,0,0,160,163,5,72,0,0,161,162,5,39,0,0,162,164,3,42,21,0,163,161,1,0,
  	0,0,163,164,1,0,0,0,164,165,1,0,0,0,165,166,5,60,0,0,166,167,3,40,20,
  	0,167,168,5,38,0,0,168,19,1,0,0,0,169,170,5,17,0,0,170,171,3,40,20,0,
  	171,178,3,14,7,0,172,173,5,18,0,0,173,174,3,40,20,0,174,175,3,14,7,0,
  	175,177,1,0,0,0,176,172,1,0,0,0,177,180,1,0,0,0,178,179,1,0,0,0,178,176,
  	1,0,0,0,179,183,1,0,0,0,180,178,1,0,0,0,181,182,5,19,0,0,182,184,3,14,
  	7,0,183,181,1,0,0,0,183,184,1,0,0,0,184,21,1,0,0,0,185,186,5,8,0,0,186,
  	187,3,14,7,0,187,188,3,40,20,0,188,189,5,38,0,0,189,190,3,40,20,0,190,
  	191,3,14,7,0,191,23,1,0,0,0,192,193,5,9,0,0,193,194,3,40,20,0,194,195,
  	3,14,7,0,195,25,1,0,0,0,196,197,3,40,20,0,197,198,5,38,0,0,198,27,1,0,
  	0,0,199,200,5,10,0,0,200,201,3,16,8,0,201,29,1,0,0,0,202,203,5,6,0,0,
  	203,204,3,40,20,0,204,205,5,38,0,0,205,31,1,0,0,0,206,210,5,34,0,0,207,
  	209,3,14,7,0,208,207,1,0,0,0,209,212,1,0,0,0,210,208,1,0,0,0,210,211,
  	1,0,0,0,211,213,1,0,0,0,212,210,1,0,0,0,213,214,5,37,0,0,214,33,1,0,0,
  	0,215,217,5,5,0,0,216,218,3,40,20,0,217,216,1,0,0,0,217,218,1,0,0,0,218,
  	219,1,0,0,0,219,220,5,38,0,0,220,35,1,0,0,0,221,222,5,42,0,0,222,223,
  	3,40,20,0,223,224,5,38,0,0,224,37,1,0,0,0,225,228,3,32,16,0,226,228,3,
  	36,18,0,227,225,1,0,0,0,227,226,1,0,0,0,228,39,1,0,0,0,229,230,6,20,-1,
  	0,230,280,5,72,0,0,231,280,5,28,0,0,232,280,5,31,0,0,233,280,5,30,0,0,
  	234,280,5,29,0,0,235,280,5,26,0,0,236,280,5,27,0,0,237,238,5,16,0,0,238,
  	239,3,42,21,0,239,252,5,34,0,0,240,241,5,72,0,0,241,242,5,39,0,0,242,
  	249,3,40,20,0,243,244,5,40,0,0,244,245,5,72,0,0,245,246,5,39,0,0,246,
  	248,3,40,20,0,247,243,1,0,0,0,248,251,1,0,0,0,249,250,1,0,0,0,249,247,
  	1,0,0,0,250,253,1,0,0,0,251,249,1,0,0,0,252,240,1,0,0,0,252,253,1,0,0,
  	0,253,254,1,0,0,0,254,255,5,37,0,0,255,280,1,0,0,0,256,265,5,33,0,0,257,
  	262,3,40,20,0,258,259,5,40,0,0,259,261,3,40,20,0,260,258,1,0,0,0,261,
  	264,1,0,0,0,262,263,1,0,0,0,262,260,1,0,0,0,263,266,1,0,0,0,264,262,1,
  	0,0,0,265,257,1,0,0,0,265,266,1,0,0,0,266,267,1,0,0,0,267,280,5,36,0,
  	0,268,269,7,1,0,0,269,280,3,40,20,14,270,273,7,2,0,0,271,274,3,40,20,
  	0,272,274,3,42,21,0,273,271,1,0,0,0,273,272,1,0,0,0,274,280,1,0,0,0,275,
  	276,5,32,0,0,276,277,3,40,20,0,277,278,5,35,0,0,278,280,1,0,0,0,279,229,
  	1,0,0,0,279,231,1,0,0,0,279,232,1,0,0,0,279,233,1,0,0,0,279,234,1,0,0,
  	0,279,235,1,0,0,0,279,236,1,0,0,0,279,237,1,0,0,0,279,256,1,0,0,0,279,
  	268,1,0,0,0,279,270,1,0,0,0,279,275,1,0,0,0,280,339,1,0,0,0,281,282,10,
  	11,0,0,282,283,7,3,0,0,283,338,3,40,20,12,284,285,10,10,0,0,285,286,7,
  	4,0,0,286,338,3,40,20,11,287,288,10,9,0,0,288,289,7,5,0,0,289,338,3,40,
  	20,10,290,291,10,8,0,0,291,292,7,6,0,0,292,338,3,40,20,9,293,294,10,7,
  	0,0,294,295,7,7,0,0,295,338,3,40,20,8,296,297,10,6,0,0,297,298,5,52,0,
  	0,298,338,3,40,20,7,299,300,10,5,0,0,300,301,5,53,0,0,301,338,3,40,20,
  	6,302,303,10,4,0,0,303,304,5,20,0,0,304,338,3,40,20,5,305,306,10,3,0,
  	0,306,307,5,21,0,0,307,338,3,40,20,4,308,309,10,2,0,0,309,310,7,8,0,0,
  	310,338,3,40,20,2,311,312,10,18,0,0,312,338,7,9,0,0,313,314,10,17,0,0,
  	314,323,5,32,0,0,315,320,3,40,20,0,316,317,5,40,0,0,317,319,3,40,20,0,
  	318,316,1,0,0,0,319,322,1,0,0,0,320,318,1,0,0,0,320,321,1,0,0,0,321,324,
  	1,0,0,0,322,320,1,0,0,0,323,315,1,0,0,0,323,324,1,0,0,0,324,325,1,0,0,
  	0,325,338,5,35,0,0,326,327,10,16,0,0,327,328,5,33,0,0,328,329,3,40,20,
  	0,329,330,5,36,0,0,330,338,1,0,0,0,331,332,10,15,0,0,332,333,5,71,0,0,
  	333,338,5,72,0,0,334,335,10,12,0,0,335,336,5,23,0,0,336,338,3,42,21,0,
  	337,281,1,0,0,0,337,284,1,0,0,0,337,287,1,0,0,0,337,290,1,0,0,0,337,293,
  	1,0,0,0,337,296,1,0,0,0,337,299,1,0,0,0,337,302,1,0,0,0,337,305,1,0,0,
  	0,337,308,1,0,0,0,337,311,1,0,0,0,337,313,1,0,0,0,337,326,1,0,0,0,337,
  	331,1,0,0,0,337,334,1,0,0,0,338,341,1,0,0,0,339,337,1,0,0,0,339,340,1,
  	0,0,0,340,41,1,0,0,0,341,339,1,0,0,0,342,347,3,44,22,0,343,347,3,48,24,
  	0,344,347,3,50,25,0,345,347,3,46,23,0,346,342,1,0,0,0,346,343,1,0,0,0,
  	346,344,1,0,0,0,346,345,1,0,0,0,347,43,1,0,0,0,348,349,5,72,0,0,349,45,
  	1,0,0,0,350,351,5,7,0,0,351,360,5,32,0,0,352,357,3,42,21,0,353,354,5,
  	40,0,0,354,356,3,42,21,0,355,353,1,0,0,0,356,359,1,0,0,0,357,355,1,0,
  	0,0,357,358,1,0,0,0,358,361,1,0,0,0,359,357,1,0,0,0,360,352,1,0,0,0,360,
  	361,1,0,0,0,361,362,1,0,0,0,362,363,5,35,0,0,363,364,5,41,0,0,364,365,
  	3,42,21,0,365,47,1,0,0,0,366,368,5,47,0,0,367,366,1,0,0,0,368,369,1,0,
  	0,0,369,367,1,0,0,0,369,370,1,0,0,0,370,371,1,0,0,0,371,372,3,42,21,0,
  	372,49,1,0,0,0,373,374,5,33,0,0,374,376,5,36,0,0,375,373,1,0,0,0,376,
  	377,1,0,0,0,377,375,1,0,0,0,377,378,1,0,0,0,378,379,1,0,0,0,379,380,3,
  	42,21,0,380,51,1,0,0,0,32,53,58,67,82,85,109,111,128,131,147,157,163,
  	178,183,210,217,227,249,252,262,265,273,279,320,323,337,339,346,357,360,
  	369,377
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
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::NAMESPACE) {
      setState(52);
      namespaceStatement();
    }
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 10384) != 0)) {
      setState(55);
      topLevelStatement();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
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

FridayParser::NativeFunctionStatementContext* FridayParser::TopLevelStatementContext::nativeFunctionStatement() {
  return getRuleContext<FridayParser::NativeFunctionStatementContext>(0);
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
    setState(67);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::USING: {
        enterOuterAlt(_localctx, 1);
        setState(63);
        usingStatement();
        break;
      }

      case FridayParser::STRUCT: {
        enterOuterAlt(_localctx, 2);
        setState(64);
        structStatement();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 3);
        setState(65);
        functionStatement();
        break;
      }

      case FridayParser::NATIVE: {
        enterOuterAlt(_localctx, 4);
        setState(66);
        nativeFunctionStatement();
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

//----------------- NativeFunctionStatementContext ------------------------------------------------------------------

FridayParser::NativeFunctionStatementContext::NativeFunctionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::NATIVE() {
  return getToken(FridayParser::NATIVE, 0);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::FN() {
  return getToken(FridayParser::FN, 0);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::ARROW() {
  return getToken(FridayParser::ARROW, 0);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> FridayParser::NativeFunctionStatementContext::IDENTIFIER() {
  return getTokens(FridayParser::IDENTIFIER);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::IDENTIFIER(size_t i) {
  return getToken(FridayParser::IDENTIFIER, i);
}

std::vector<FridayParser::TypeContext *> FridayParser::NativeFunctionStatementContext::type() {
  return getRuleContexts<FridayParser::TypeContext>();
}

FridayParser::TypeContext* FridayParser::NativeFunctionStatementContext::type(size_t i) {
  return getRuleContext<FridayParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::NativeFunctionStatementContext::COL() {
  return getTokens(FridayParser::COL);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::COL(size_t i) {
  return getToken(FridayParser::COL, i);
}

std::vector<tree::TerminalNode *> FridayParser::NativeFunctionStatementContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::NativeFunctionStatementContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}


size_t FridayParser::NativeFunctionStatementContext::getRuleIndex() const {
  return FridayParser::RuleNativeFunctionStatement;
}


FridayParser::NativeFunctionStatementContext* FridayParser::nativeFunctionStatement() {
  NativeFunctionStatementContext *_localctx = _tracker.createInstance<NativeFunctionStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, FridayParser::RuleNativeFunctionStatement);
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
    setState(69);
    match(FridayParser::NATIVE);
    setState(70);
    match(FridayParser::FN);
    setState(71);
    antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(72);
    match(FridayParser::LEFT_PAREN);
    setState(85);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(73);
      antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->identifierToken);
      setState(74);
      match(FridayParser::COL);
      setState(75);
      antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->typeContext);
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(76);
        match(FridayParser::COMMA);
        setState(77);
        antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->identifierToken);
        setState(78);
        match(FridayParser::COL);
        setState(79);
        antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->typeContext);
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(87);
    match(FridayParser::RIGHT_PAREN);
    setState(88);
    match(FridayParser::ARROW);
    setState(89);
    antlrcpp::downCast<NativeFunctionStatementContext *>(_localctx)->returnType = type();
    setState(90);
    match(FridayParser::SEMI);
   
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
  enterRule(_localctx, 6, FridayParser::RuleNamespaceStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(FridayParser::NAMESPACE);
    setState(93);
    match(FridayParser::NAMESPACE_IDENTIFIER);
    setState(94);
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
  enterRule(_localctx, 8, FridayParser::RuleUsingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(FridayParser::USING);
    setState(97);
    match(FridayParser::NAMESPACE_IDENTIFIER);
    setState(98);
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
  enterRule(_localctx, 10, FridayParser::RuleStructStatement);
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
    setState(100);
    match(FridayParser::STRUCT);
    setState(101);
    match(FridayParser::IDENTIFIER);
    setState(102);
    match(FridayParser::LEFT_CURLY);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FridayParser::FN || _la == FridayParser::IDENTIFIER) {
      setState(109);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case FridayParser::IDENTIFIER: {
          setState(103);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->fieldsNames.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->identifierToken);
          setState(104);
          match(FridayParser::COL);
          setState(105);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->typeContext = type();
          antlrcpp::downCast<StructStatementContext *>(_localctx)->fieldsTypes.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->typeContext);
          setState(106);
          match(FridayParser::SEMI);
          break;
        }

        case FridayParser::FN: {
          setState(108);
          antlrcpp::downCast<StructStatementContext *>(_localctx)->functionStatementContext = functionStatement();
          antlrcpp::downCast<StructStatementContext *>(_localctx)->methods.push_back(antlrcpp::downCast<StructStatementContext *>(_localctx)->functionStatementContext);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(114);
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
  enterRule(_localctx, 12, FridayParser::RuleFunctionStatement);
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
    setState(116);
    match(FridayParser::FN);
    setState(117);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->name = match(FridayParser::IDENTIFIER);
    setState(118);
    match(FridayParser::LEFT_PAREN);
    setState(131);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::IDENTIFIER) {
      setState(119);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
      setState(120);
      match(FridayParser::COL);
      setState(121);
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(122);
        match(FridayParser::COMMA);
        setState(123);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsNames.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->identifierToken);
        setState(124);
        match(FridayParser::COL);
        setState(125);
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionStatementContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionStatementContext *>(_localctx)->typeContext);
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(133);
    match(FridayParser::RIGHT_PAREN);
    setState(134);
    match(FridayParser::ARROW);
    setState(135);
    antlrcpp::downCast<FunctionStatementContext *>(_localctx)->returnType = type();
    setState(136);
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

FridayParser::ReturnStatementContext* FridayParser::StatementContext::returnStatement() {
  return getRuleContext<FridayParser::ReturnStatementContext>(0);
}

FridayParser::ExpressionStatementContext* FridayParser::StatementContext::expressionStatement() {
  return getRuleContext<FridayParser::ExpressionStatementContext>(0);
}

FridayParser::IfStatementContext* FridayParser::StatementContext::ifStatement() {
  return getRuleContext<FridayParser::IfStatementContext>(0);
}

FridayParser::ForStatementContext* FridayParser::StatementContext::forStatement() {
  return getRuleContext<FridayParser::ForStatementContext>(0);
}

FridayParser::WhileStatementContext* FridayParser::StatementContext::whileStatement() {
  return getRuleContext<FridayParser::WhileStatementContext>(0);
}

FridayParser::DeclarationStatementContext* FridayParser::StatementContext::declarationStatement() {
  return getRuleContext<FridayParser::DeclarationStatementContext>(0);
}

FridayParser::ScopeContext* FridayParser::StatementContext::scope() {
  return getRuleContext<FridayParser::ScopeContext>(0);
}

FridayParser::DeferStatementContext* FridayParser::StatementContext::deferStatement() {
  return getRuleContext<FridayParser::DeferStatementContext>(0);
}


size_t FridayParser::StatementContext::getRuleIndex() const {
  return FridayParser::RuleStatement;
}


FridayParser::StatementContext* FridayParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 14, FridayParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 1);
        setState(138);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(139);
        returnStatement();
        break;
      }

      case FridayParser::NEW:
      case FridayParser::NOT:
      case FridayParser::SIZEOF:
      case FridayParser::ALIGNOF:
      case FridayParser::BOOL_LIT:
      case FridayParser::NULL_LIT:
      case FridayParser::INT_LIT:
      case FridayParser::FLOAT_LIT:
      case FridayParser::STRING_LIT:
      case FridayParser::CHAR_LIT:
      case FridayParser::LEFT_PAREN:
      case FridayParser::LEFT_SQUARE:
      case FridayParser::PLUS:
      case FridayParser::MINUS:
      case FridayParser::STAR:
      case FridayParser::AMPERSAND:
      case FridayParser::TILDE:
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(140);
        expressionStatement();
        break;
      }

      case FridayParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(141);
        ifStatement();
        break;
      }

      case FridayParser::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(142);
        forStatement();
        break;
      }

      case FridayParser::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(143);
        whileStatement();
        break;
      }

      case FridayParser::CONST:
      case FridayParser::LET: {
        enterOuterAlt(_localctx, 7);
        setState(144);
        declarationStatement();
        break;
      }

      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 8);
        setState(145);
        scope();
        break;
      }

      case FridayParser::DEFER: {
        enterOuterAlt(_localctx, 9);
        setState(146);
        deferStatement();
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

FridayParser::ExpressionStatementContext* FridayParser::DeferrableStatementContext::expressionStatement() {
  return getRuleContext<FridayParser::ExpressionStatementContext>(0);
}

FridayParser::IfStatementContext* FridayParser::DeferrableStatementContext::ifStatement() {
  return getRuleContext<FridayParser::IfStatementContext>(0);
}

FridayParser::ForStatementContext* FridayParser::DeferrableStatementContext::forStatement() {
  return getRuleContext<FridayParser::ForStatementContext>(0);
}

FridayParser::WhileStatementContext* FridayParser::DeferrableStatementContext::whileStatement() {
  return getRuleContext<FridayParser::WhileStatementContext>(0);
}

FridayParser::DeclarationStatementContext* FridayParser::DeferrableStatementContext::declarationStatement() {
  return getRuleContext<FridayParser::DeclarationStatementContext>(0);
}

FridayParser::ScopeContext* FridayParser::DeferrableStatementContext::scope() {
  return getRuleContext<FridayParser::ScopeContext>(0);
}


size_t FridayParser::DeferrableStatementContext::getRuleIndex() const {
  return FridayParser::RuleDeferrableStatement;
}


FridayParser::DeferrableStatementContext* FridayParser::deferrableStatement() {
  DeferrableStatementContext *_localctx = _tracker.createInstance<DeferrableStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, FridayParser::RuleDeferrableStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::PRINT: {
        enterOuterAlt(_localctx, 1);
        setState(149);
        printStatement();
        break;
      }

      case FridayParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(150);
        returnStatement();
        break;
      }

      case FridayParser::NEW:
      case FridayParser::NOT:
      case FridayParser::SIZEOF:
      case FridayParser::ALIGNOF:
      case FridayParser::BOOL_LIT:
      case FridayParser::NULL_LIT:
      case FridayParser::INT_LIT:
      case FridayParser::FLOAT_LIT:
      case FridayParser::STRING_LIT:
      case FridayParser::CHAR_LIT:
      case FridayParser::LEFT_PAREN:
      case FridayParser::LEFT_SQUARE:
      case FridayParser::PLUS:
      case FridayParser::MINUS:
      case FridayParser::STAR:
      case FridayParser::AMPERSAND:
      case FridayParser::TILDE:
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(151);
        expressionStatement();
        break;
      }

      case FridayParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(152);
        ifStatement();
        break;
      }

      case FridayParser::FOR: {
        enterOuterAlt(_localctx, 5);
        setState(153);
        forStatement();
        break;
      }

      case FridayParser::WHILE: {
        enterOuterAlt(_localctx, 6);
        setState(154);
        whileStatement();
        break;
      }

      case FridayParser::CONST:
      case FridayParser::LET: {
        enterOuterAlt(_localctx, 7);
        setState(155);
        declarationStatement();
        break;
      }

      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 8);
        setState(156);
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

//----------------- DeclarationStatementContext ------------------------------------------------------------------

FridayParser::DeclarationStatementContext::DeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::ASSIGN() {
  return getToken(FridayParser::ASSIGN, 0);
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::ExpressionContext* FridayParser::DeclarationStatementContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::LET() {
  return getToken(FridayParser::LET, 0);
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::CONST() {
  return getToken(FridayParser::CONST, 0);
}

tree::TerminalNode* FridayParser::DeclarationStatementContext::COL() {
  return getToken(FridayParser::COL, 0);
}

FridayParser::TypeContext* FridayParser::DeclarationStatementContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
}


size_t FridayParser::DeclarationStatementContext::getRuleIndex() const {
  return FridayParser::RuleDeclarationStatement;
}


FridayParser::DeclarationStatementContext* FridayParser::declarationStatement() {
  DeclarationStatementContext *_localctx = _tracker.createInstance<DeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, FridayParser::RuleDeclarationStatement);
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
    setState(159);
    antlrcpp::downCast<DeclarationStatementContext *>(_localctx)->declarator = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == FridayParser::CONST

    || _la == FridayParser::LET)) {
      antlrcpp::downCast<DeclarationStatementContext *>(_localctx)->declarator = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(160);
    antlrcpp::downCast<DeclarationStatementContext *>(_localctx)->id = match(FridayParser::IDENTIFIER);
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FridayParser::COL) {
      setState(161);
      match(FridayParser::COL);
      setState(162);
      type();
    }
    setState(165);
    match(FridayParser::ASSIGN);
    setState(166);
    antlrcpp::downCast<DeclarationStatementContext *>(_localctx)->initializer = expression(0);
    setState(167);
    match(FridayParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

FridayParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::IfStatementContext::IF() {
  return getToken(FridayParser::IF, 0);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::IfStatementContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

std::vector<FridayParser::StatementContext *> FridayParser::IfStatementContext::statement() {
  return getRuleContexts<FridayParser::StatementContext>();
}

FridayParser::StatementContext* FridayParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<FridayParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::IfStatementContext::ELIF() {
  return getTokens(FridayParser::ELIF);
}

tree::TerminalNode* FridayParser::IfStatementContext::ELIF(size_t i) {
  return getToken(FridayParser::ELIF, i);
}

tree::TerminalNode* FridayParser::IfStatementContext::ELSE() {
  return getToken(FridayParser::ELSE, 0);
}


size_t FridayParser::IfStatementContext::getRuleIndex() const {
  return FridayParser::RuleIfStatement;
}


FridayParser::IfStatementContext* FridayParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, FridayParser::RuleIfStatement);

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
    setState(169);
    match(FridayParser::IF);
    setState(170);
    expression(0);
    setState(171);
    statement();
    setState(178);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(172);
        match(FridayParser::ELIF);
        setState(173);
        expression(0);
        setState(174);
        statement(); 
      }
      setState(180);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(183);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(181);
      match(FridayParser::ELSE);
      setState(182);
      statement();
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

//----------------- ForStatementContext ------------------------------------------------------------------

FridayParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::ForStatementContext::FOR() {
  return getToken(FridayParser::FOR, 0);
}

std::vector<FridayParser::StatementContext *> FridayParser::ForStatementContext::statement() {
  return getRuleContexts<FridayParser::StatementContext>();
}

FridayParser::StatementContext* FridayParser::ForStatementContext::statement(size_t i) {
  return getRuleContext<FridayParser::StatementContext>(i);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::ForStatementContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

tree::TerminalNode* FridayParser::ForStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::ForStatementContext::getRuleIndex() const {
  return FridayParser::RuleForStatement;
}


FridayParser::ForStatementContext* FridayParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, FridayParser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(FridayParser::FOR);
    setState(186);
    statement();
    setState(187);
    expression(0);
    setState(188);
    match(FridayParser::SEMI);
    setState(189);
    expression(0);
    setState(190);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

FridayParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FridayParser::WhileStatementContext::WHILE() {
  return getToken(FridayParser::WHILE, 0);
}

FridayParser::ExpressionContext* FridayParser::WhileStatementContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

FridayParser::StatementContext* FridayParser::WhileStatementContext::statement() {
  return getRuleContext<FridayParser::StatementContext>(0);
}


size_t FridayParser::WhileStatementContext::getRuleIndex() const {
  return FridayParser::RuleWhileStatement;
}


FridayParser::WhileStatementContext* FridayParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, FridayParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(FridayParser::WHILE);
    setState(193);
    expression(0);
    setState(194);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

FridayParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FridayParser::ExpressionContext* FridayParser::ExpressionStatementContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::ExpressionStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::ExpressionStatementContext::getRuleIndex() const {
  return FridayParser::RuleExpressionStatement;
}


FridayParser::ExpressionStatementContext* FridayParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, FridayParser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    expression(0);
    setState(197);
    match(FridayParser::SEMI);
   
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
  enterRule(_localctx, 28, FridayParser::RuleDeferStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(FridayParser::DEFER);
    setState(200);
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

FridayParser::ExpressionContext* FridayParser::PrintStatementContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::PrintStatementContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::PrintStatementContext::getRuleIndex() const {
  return FridayParser::RulePrintStatement;
}


FridayParser::PrintStatementContext* FridayParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, FridayParser::RulePrintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(FridayParser::PRINT);
    setState(203);
    expression(0);
    setState(204);
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
  enterRule(_localctx, 32, FridayParser::RuleScope);
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
    setState(206);
    match(FridayParser::LEFT_CURLY);

    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4749924579395424) != 0) || _la == FridayParser::TILDE

    || _la == FridayParser::IDENTIFIER) {
      setState(207);
      statement();
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(213);
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

FridayParser::ExpressionContext* FridayParser::ReturnStatementContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}


size_t FridayParser::ReturnStatementContext::getRuleIndex() const {
  return FridayParser::RuleReturnStatement;
}


FridayParser::ReturnStatementContext* FridayParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, FridayParser::RuleReturnStatement);
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
    setState(215);
    match(FridayParser::RETURN);

    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 16) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 16)) & 90072065025244993) != 0)) {
      setState(216);
      expression(0);
    }
    setState(219);
    match(FridayParser::SEMI);
   
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

FridayParser::ExpressionContext* FridayParser::InlineScopeContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::InlineScopeContext::SEMI() {
  return getToken(FridayParser::SEMI, 0);
}


size_t FridayParser::InlineScopeContext::getRuleIndex() const {
  return FridayParser::RuleInlineScope;
}


FridayParser::InlineScopeContext* FridayParser::inlineScope() {
  InlineScopeContext *_localctx = _tracker.createInstance<InlineScopeContext>(_ctx, getState());
  enterRule(_localctx, 36, FridayParser::RuleInlineScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(FridayParser::FAT_ARROW);
    setState(222);
    expression(0);
    setState(223);
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
  enterRule(_localctx, 38, FridayParser::RuleFunctionScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::LEFT_CURLY: {
        enterOuterAlt(_localctx, 1);
        setState(225);
        scope();
        break;
      }

      case FridayParser::FAT_ARROW: {
        enterOuterAlt(_localctx, 2);
        setState(226);
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

//----------------- ExpressionContext ------------------------------------------------------------------

FridayParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FridayParser::ExpressionContext::getRuleIndex() const {
  return FridayParser::RuleExpression;
}

void FridayParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MemberAccessExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::MemberAccessExpressionContext::DOT() {
  return getToken(FridayParser::DOT, 0);
}

FridayParser::ExpressionContext* FridayParser::MemberAccessExpressionContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::MemberAccessExpressionContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::MemberAccessExpressionContext::MemberAccessExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- UnaryPostfixExpressionContext ------------------------------------------------------------------

FridayParser::ExpressionContext* FridayParser::UnaryPostfixExpressionContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::UnaryPostfixExpressionContext::INCREMENT() {
  return getToken(FridayParser::INCREMENT, 0);
}

tree::TerminalNode* FridayParser::UnaryPostfixExpressionContext::DECREMENT() {
  return getToken(FridayParser::DECREMENT, 0);
}

FridayParser::UnaryPostfixExpressionContext::UnaryPostfixExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- StringLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::StringLiteralExpressionContext::STRING_LIT() {
  return getToken(FridayParser::STRING_LIT, 0);
}

FridayParser::StringLiteralExpressionContext::StringLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- FloatLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::FloatLiteralExpressionContext::FLOAT_LIT() {
  return getToken(FridayParser::FLOAT_LIT, 0);
}

FridayParser::FloatLiteralExpressionContext::FloatLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- NewExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::NewExpressionContext::NEW() {
  return getToken(FridayParser::NEW, 0);
}

FridayParser::TypeContext* FridayParser::NewExpressionContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
}

tree::TerminalNode* FridayParser::NewExpressionContext::LEFT_CURLY() {
  return getToken(FridayParser::LEFT_CURLY, 0);
}

tree::TerminalNode* FridayParser::NewExpressionContext::RIGHT_CURLY() {
  return getToken(FridayParser::RIGHT_CURLY, 0);
}

std::vector<tree::TerminalNode *> FridayParser::NewExpressionContext::COL() {
  return getTokens(FridayParser::COL);
}

tree::TerminalNode* FridayParser::NewExpressionContext::COL(size_t i) {
  return getToken(FridayParser::COL, i);
}

std::vector<tree::TerminalNode *> FridayParser::NewExpressionContext::IDENTIFIER() {
  return getTokens(FridayParser::IDENTIFIER);
}

tree::TerminalNode* FridayParser::NewExpressionContext::IDENTIFIER(size_t i) {
  return getToken(FridayParser::IDENTIFIER, i);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::NewExpressionContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::NewExpressionContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::NewExpressionContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::NewExpressionContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}

FridayParser::NewExpressionContext::NewExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- ArrayLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::ArrayLiteralExpressionContext::LEFT_SQUARE() {
  return getToken(FridayParser::LEFT_SQUARE, 0);
}

tree::TerminalNode* FridayParser::ArrayLiteralExpressionContext::RIGHT_SQUARE() {
  return getToken(FridayParser::RIGHT_SQUARE, 0);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::ArrayLiteralExpressionContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::ArrayLiteralExpressionContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::ArrayLiteralExpressionContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::ArrayLiteralExpressionContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}

FridayParser::ArrayLiteralExpressionContext::ArrayLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- ExplicitCastExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::ExplicitCastExpressionContext::AS() {
  return getToken(FridayParser::AS, 0);
}

FridayParser::TypeContext* FridayParser::ExplicitCastExpressionContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
}

FridayParser::ExpressionContext* FridayParser::ExplicitCastExpressionContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

FridayParser::ExplicitCastExpressionContext::ExplicitCastExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- IntLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IntLiteralExpressionContext::INT_LIT() {
  return getToken(FridayParser::INT_LIT, 0);
}

FridayParser::IntLiteralExpressionContext::IntLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- IdentifierExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::IdentifierExpressionContext::IDENTIFIER() {
  return getToken(FridayParser::IDENTIFIER, 0);
}

FridayParser::IdentifierExpressionContext::IdentifierExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- BinaryExpressionContext ------------------------------------------------------------------

std::vector<FridayParser::ExpressionContext *> FridayParser::BinaryExpressionContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::BinaryExpressionContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
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

tree::TerminalNode* FridayParser::BinaryExpressionContext::LSHIFT() {
  return getToken(FridayParser::LSHIFT, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::RSHIFT() {
  return getToken(FridayParser::RSHIFT, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::LESS() {
  return getToken(FridayParser::LESS, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::LESS_EQ() {
  return getToken(FridayParser::LESS_EQ, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::GREATER() {
  return getToken(FridayParser::GREATER, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::GREATER_EQ() {
  return getToken(FridayParser::GREATER_EQ, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::EQUALS() {
  return getToken(FridayParser::EQUALS, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::NOT_EQUALS() {
  return getToken(FridayParser::NOT_EQUALS, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::AMPERSAND() {
  return getToken(FridayParser::AMPERSAND, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::PIPELINE() {
  return getToken(FridayParser::PIPELINE, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::AND() {
  return getToken(FridayParser::AND, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::OR() {
  return getToken(FridayParser::OR, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::ASSIGN() {
  return getToken(FridayParser::ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::PLUS_ASSIGN() {
  return getToken(FridayParser::PLUS_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::MINUS_ASSIGN() {
  return getToken(FridayParser::MINUS_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::STAR_ASSIGN() {
  return getToken(FridayParser::STAR_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::SLASH_ASSIGN() {
  return getToken(FridayParser::SLASH_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::MODULO_ASSIGN() {
  return getToken(FridayParser::MODULO_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::LSHIFT_ASSIGN() {
  return getToken(FridayParser::LSHIFT_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::RSHIFT_ASSIGN() {
  return getToken(FridayParser::RSHIFT_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::AMPERSAND_ASSIGN() {
  return getToken(FridayParser::AMPERSAND_ASSIGN, 0);
}

tree::TerminalNode* FridayParser::BinaryExpressionContext::PIPELINE_ASSIGN() {
  return getToken(FridayParser::PIPELINE_ASSIGN, 0);
}

FridayParser::BinaryExpressionContext::BinaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- GroupingExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::GroupingExpressionContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

FridayParser::ExpressionContext* FridayParser::GroupingExpressionContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::GroupingExpressionContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

FridayParser::GroupingExpressionContext::GroupingExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- UnaryPrefixExpressionContext ------------------------------------------------------------------

FridayParser::ExpressionContext* FridayParser::UnaryPrefixExpressionContext::expression() {
  return getRuleContext<FridayParser::ExpressionContext>(0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::PLUS() {
  return getToken(FridayParser::PLUS, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::MINUS() {
  return getToken(FridayParser::MINUS, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::NOT() {
  return getToken(FridayParser::NOT, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::TILDE() {
  return getToken(FridayParser::TILDE, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::STAR() {
  return getToken(FridayParser::STAR, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::AMPERSAND() {
  return getToken(FridayParser::AMPERSAND, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::SIZEOF() {
  return getToken(FridayParser::SIZEOF, 0);
}

tree::TerminalNode* FridayParser::UnaryPrefixExpressionContext::ALIGNOF() {
  return getToken(FridayParser::ALIGNOF, 0);
}

FridayParser::TypeContext* FridayParser::UnaryPrefixExpressionContext::type() {
  return getRuleContext<FridayParser::TypeContext>(0);
}

FridayParser::UnaryPrefixExpressionContext::UnaryPrefixExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- SubscriptExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::SubscriptExpressionContext::LEFT_SQUARE() {
  return getToken(FridayParser::LEFT_SQUARE, 0);
}

tree::TerminalNode* FridayParser::SubscriptExpressionContext::RIGHT_SQUARE() {
  return getToken(FridayParser::RIGHT_SQUARE, 0);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::SubscriptExpressionContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::SubscriptExpressionContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

FridayParser::SubscriptExpressionContext::SubscriptExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- BoolLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::BoolLiteralExpressionContext::BOOL_LIT() {
  return getToken(FridayParser::BOOL_LIT, 0);
}

FridayParser::BoolLiteralExpressionContext::BoolLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- CharLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CharLiteralExpressionContext::CHAR_LIT() {
  return getToken(FridayParser::CHAR_LIT, 0);
}

FridayParser::CharLiteralExpressionContext::CharLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- CallExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::CallExpressionContext::LEFT_PAREN() {
  return getToken(FridayParser::LEFT_PAREN, 0);
}

tree::TerminalNode* FridayParser::CallExpressionContext::RIGHT_PAREN() {
  return getToken(FridayParser::RIGHT_PAREN, 0);
}

std::vector<FridayParser::ExpressionContext *> FridayParser::CallExpressionContext::expression() {
  return getRuleContexts<FridayParser::ExpressionContext>();
}

FridayParser::ExpressionContext* FridayParser::CallExpressionContext::expression(size_t i) {
  return getRuleContext<FridayParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> FridayParser::CallExpressionContext::COMMA() {
  return getTokens(FridayParser::COMMA);
}

tree::TerminalNode* FridayParser::CallExpressionContext::COMMA(size_t i) {
  return getToken(FridayParser::COMMA, i);
}

FridayParser::CallExpressionContext::CallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


//----------------- NullLiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* FridayParser::NullLiteralExpressionContext::NULL_LIT() {
  return getToken(FridayParser::NULL_LIT, 0);
}

FridayParser::NullLiteralExpressionContext::NullLiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }



FridayParser::ExpressionContext* FridayParser::expression() {
   return expression(0);
}

FridayParser::ExpressionContext* FridayParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FridayParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  FridayParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, FridayParser::RuleExpression, precedence);

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
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdentifierExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(230);
        antlrcpp::downCast<IdentifierExpressionContext *>(_localctx)->id = match(FridayParser::IDENTIFIER);
        break;
      }

      case FridayParser::INT_LIT: {
        _localctx = _tracker.createInstance<IntLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(231);
        antlrcpp::downCast<IntLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::INT_LIT);
        break;
      }

      case FridayParser::CHAR_LIT: {
        _localctx = _tracker.createInstance<CharLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(232);
        antlrcpp::downCast<CharLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::CHAR_LIT);
        break;
      }

      case FridayParser::STRING_LIT: {
        _localctx = _tracker.createInstance<StringLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(233);
        antlrcpp::downCast<StringLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::STRING_LIT);
        break;
      }

      case FridayParser::FLOAT_LIT: {
        _localctx = _tracker.createInstance<FloatLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(234);
        antlrcpp::downCast<FloatLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::FLOAT_LIT);
        break;
      }

      case FridayParser::BOOL_LIT: {
        _localctx = _tracker.createInstance<BoolLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(235);
        antlrcpp::downCast<BoolLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::BOOL_LIT);
        break;
      }

      case FridayParser::NULL_LIT: {
        _localctx = _tracker.createInstance<NullLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(236);
        antlrcpp::downCast<NullLiteralExpressionContext *>(_localctx)->literal = match(FridayParser::NULL_LIT);
        break;
      }

      case FridayParser::NEW: {
        _localctx = _tracker.createInstance<NewExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(237);
        match(FridayParser::NEW);
        setState(238);
        type();
        setState(239);
        match(FridayParser::LEFT_CURLY);
        setState(252);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FridayParser::IDENTIFIER) {
          setState(240);
          antlrcpp::downCast<NewExpressionContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
          antlrcpp::downCast<NewExpressionContext *>(_localctx)->fields.push_back(antlrcpp::downCast<NewExpressionContext *>(_localctx)->identifierToken);
          setState(241);
          match(FridayParser::COL);
          setState(242);
          antlrcpp::downCast<NewExpressionContext *>(_localctx)->expressionContext = expression(0);
          antlrcpp::downCast<NewExpressionContext *>(_localctx)->initializers.push_back(antlrcpp::downCast<NewExpressionContext *>(_localctx)->expressionContext);
          setState(249);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
          while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1 + 1) {
              setState(243);
              match(FridayParser::COMMA);
              setState(244);
              antlrcpp::downCast<NewExpressionContext *>(_localctx)->identifierToken = match(FridayParser::IDENTIFIER);
              antlrcpp::downCast<NewExpressionContext *>(_localctx)->fields.push_back(antlrcpp::downCast<NewExpressionContext *>(_localctx)->identifierToken);
              setState(245);
              match(FridayParser::COL);
              setState(246);
              antlrcpp::downCast<NewExpressionContext *>(_localctx)->expressionContext = expression(0);
              antlrcpp::downCast<NewExpressionContext *>(_localctx)->initializers.push_back(antlrcpp::downCast<NewExpressionContext *>(_localctx)->expressionContext); 
            }
            setState(251);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
          }
        }
        setState(254);
        match(FridayParser::RIGHT_CURLY);
        break;
      }

      case FridayParser::LEFT_SQUARE: {
        _localctx = _tracker.createInstance<ArrayLiteralExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(256);
        match(FridayParser::LEFT_SQUARE);
        setState(265);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 16) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 16)) & 90072065025244993) != 0)) {
          setState(257);
          expression(0);
          setState(262);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
          while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1 + 1) {
              setState(258);
              match(FridayParser::COMMA);
              setState(259);
              expression(0); 
            }
            setState(264);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
          }
        }
        setState(267);
        match(FridayParser::RIGHT_SQUARE);
        break;
      }

      case FridayParser::NOT:
      case FridayParser::PLUS:
      case FridayParser::MINUS:
      case FridayParser::STAR:
      case FridayParser::AMPERSAND:
      case FridayParser::TILDE: {
        _localctx = _tracker.createInstance<UnaryPrefixExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(268);
        antlrcpp::downCast<UnaryPrefixExpressionContext *>(_localctx)->unaryOperator = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 22) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 22)) & 281476109172737) != 0))) {
          antlrcpp::downCast<UnaryPrefixExpressionContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(269);
        expression(14);
        break;
      }

      case FridayParser::SIZEOF:
      case FridayParser::ALIGNOF: {
        _localctx = _tracker.createInstance<UnaryPrefixExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(270);
        antlrcpp::downCast<UnaryPrefixExpressionContext *>(_localctx)->unaryOperator = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == FridayParser::SIZEOF

        || _la == FridayParser::ALIGNOF)) {
          antlrcpp::downCast<UnaryPrefixExpressionContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(273);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(271);
          expression(0);
          break;
        }

        case 2: {
          setState(272);
          type();
          break;
        }

        default:
          break;
        }
        break;
      }

      case FridayParser::LEFT_PAREN: {
        _localctx = _tracker.createInstance<GroupingExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(275);
        match(FridayParser::LEFT_PAREN);
        setState(276);
        expression(0);
        setState(277);
        match(FridayParser::RIGHT_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(339);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(337);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(281);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(282);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 985162418487296) != 0))) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(283);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(284);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(285);
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
          setState(286);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(287);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(288);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::LSHIFT

          || _la == FridayParser::RSHIFT)) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(289);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(290);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(291);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 270215977642229760) != 0))) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(292);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(293);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(294);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::EQUALS

          || _la == FridayParser::NOT_EQUALS)) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(295);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(296);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(297);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = match(FridayParser::AMPERSAND);
          setState(298);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(7);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(299);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(300);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = match(FridayParser::PIPELINE);
          setState(301);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(6);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(302);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(303);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = match(FridayParser::AND);
          setState(304);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(5);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(305);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(306);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = match(FridayParser::OR);
          setState(307);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(4);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(308);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(309);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 60) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 60)) & 1023) != 0))) {
            antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(310);
          antlrcpp::downCast<BinaryExpressionContext *>(_localctx)->right = expression(2);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<UnaryPostfixExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->expr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(311);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(312);
          antlrcpp::downCast<UnaryPostfixExpressionContext *>(_localctx)->postfixOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FridayParser::INCREMENT

          || _la == FridayParser::DECREMENT)) {
            antlrcpp::downCast<UnaryPostfixExpressionContext *>(_localctx)->postfixOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<CallExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->func = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(313);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(314);
          match(FridayParser::LEFT_PAREN);
          setState(323);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 16) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 16)) & 90072065025244993) != 0)) {
            setState(315);
            antlrcpp::downCast<CallExpressionContext *>(_localctx)->expressionContext = expression(0);
            antlrcpp::downCast<CallExpressionContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallExpressionContext *>(_localctx)->expressionContext);
            setState(320);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == FridayParser::COMMA) {
              setState(316);
              match(FridayParser::COMMA);
              setState(317);
              antlrcpp::downCast<CallExpressionContext *>(_localctx)->expressionContext = expression(0);
              antlrcpp::downCast<CallExpressionContext *>(_localctx)->args.push_back(antlrcpp::downCast<CallExpressionContext *>(_localctx)->expressionContext);
              setState(322);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(325);
          match(FridayParser::RIGHT_PAREN);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<SubscriptExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->array = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(326);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(327);
          match(FridayParser::LEFT_SQUARE);
          setState(328);
          antlrcpp::downCast<SubscriptExpressionContext *>(_localctx)->index = expression(0);
          setState(329);
          match(FridayParser::RIGHT_SQUARE);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<MemberAccessExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->object = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(331);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(332);
          match(FridayParser::DOT);
          setState(333);
          antlrcpp::downCast<MemberAccessExpressionContext *>(_localctx)->member = match(FridayParser::IDENTIFIER);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ExplicitCastExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->expr = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(334);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(335);
          match(FridayParser::AS);
          setState(336);
          type();
          break;
        }

        default:
          break;
        } 
      }
      setState(341);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
  enterRule(_localctx, 42, FridayParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FridayParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(342);
        simpleType();
        break;
      }

      case FridayParser::STAR: {
        enterOuterAlt(_localctx, 2);
        setState(343);
        pointerType();
        break;
      }

      case FridayParser::LEFT_SQUARE: {
        enterOuterAlt(_localctx, 3);
        setState(344);
        arrayType();
        break;
      }

      case FridayParser::FN: {
        enterOuterAlt(_localctx, 4);
        setState(345);
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
  enterRule(_localctx, 44, FridayParser::RuleSimpleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
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
  enterRule(_localctx, 46, FridayParser::RuleFunctionType);
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
    setState(350);
    match(FridayParser::FN);
    setState(351);
    match(FridayParser::LEFT_PAREN);
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 140746078290048) != 0) || _la == FridayParser::IDENTIFIER) {
      setState(352);
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
      antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FridayParser::COMMA) {
        setState(353);
        match(FridayParser::COMMA);
        setState(354);
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext = type();
        antlrcpp::downCast<FunctionTypeContext *>(_localctx)->paramsTypes.push_back(antlrcpp::downCast<FunctionTypeContext *>(_localctx)->typeContext);
        setState(359);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(362);
    match(FridayParser::RIGHT_PAREN);
    setState(363);
    match(FridayParser::ARROW);
    setState(364);
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
  enterRule(_localctx, 48, FridayParser::RulePointerType);

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
    setState(367); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(366);
              match(FridayParser::STAR);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(369); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(371);
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
  enterRule(_localctx, 50, FridayParser::RuleArrayType);

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
    setState(375); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(373);
              match(FridayParser::LEFT_SQUARE);
              setState(374);
              match(FridayParser::RIGHT_SQUARE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(377); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(379);
    type();
   
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
    case 20: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FridayParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);
    case 6: return precpred(_ctx, 5);
    case 7: return precpred(_ctx, 4);
    case 8: return precpred(_ctx, 3);
    case 9: return precpred(_ctx, 2);
    case 10: return precpred(_ctx, 18);
    case 11: return precpred(_ctx, 17);
    case 12: return precpred(_ctx, 16);
    case 13: return precpred(_ctx, 15);
    case 14: return precpred(_ctx, 12);

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
