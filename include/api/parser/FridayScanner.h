
// Generated from FridayScanner.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  FridayScanner : public antlr4::Lexer {
public:
  enum {
    COMMENT = 1, SPACE = 2, STRUCT = 3, RETURN = 4, PRINT = 5, FN = 6, BOOL_LIT = 7, 
    NULL_LIT = 8, LEFT_PAREN = 9, LEFT_SQUARE = 10, LEFT_CURLY = 11, RIGHT_PAREN = 12, 
    RIGHT_SQUARE = 13, RIGHT_CURLY = 14, SEMI = 15, COL = 16, COMMA = 17, 
    STAR = 18, SLASH = 19, MINUS = 20, PLUS = 21, MODULO = 22, ARROW = 23, 
    FAT_ARROW = 24, IDENTIFIER = 25, INT_LIT = 26, FLOAT_LIT = 27, STRING_LIT = 28, 
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

