
// Generated from FridayScanner.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FridayScanner : public antlr4::Lexer {
public:
  enum {
    STRUCT = 1, RETURN = 2, PRINT = 3, FN = 4, BOOL_LIT = 5, NULL_LIT = 6, 
    LEFT_PAREN = 7, LEFT_SQUARE = 8, LEFT_CURLY = 9, RIGHT_PAREN = 10, RIGHT_SQUARE = 11, 
    RIGHT_CURLY = 12, SEMI = 13, COL = 14, COMMA = 15, STAR = 16, SLASH = 17, 
    MINUS = 18, PLUS = 19, MODULO = 20, ARROW = 21, FAT_ARROW = 22, IDENTIFIER = 23, 
    COMMENT = 24, SPACE = 25, INT_LIT = 26, FLOAT_LIT = 27, STRING_LIT = 28, 
    CHAR_LIT = 29
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

