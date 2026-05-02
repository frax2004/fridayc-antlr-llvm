
// Generated from FridayScanner.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FridayScanner : public antlr4::Lexer {
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

  explicit FridayScanner(antlr4::CharStream *input);

  ~FridayScanner() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

