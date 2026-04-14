parser grammar FridayParser;
options {
  tokenVocab = FridayScanner; 
  language = Cpp;
}


///////////////////////////////////////////////////
/// STATEMENTS
program
  : topLevelStatement* EOF
  ;

topLevelStatement
  : functionStatement
  ;

returnStatement
  : RETURN (expr?) SEMI
  ;

printStatement
  : PRINT expr SEMI
  ;

statement
  : block
  | printStatement
  | returnStatement
  ;

inlineBlock
  : FAT_ARROW expr SEMI
  ;

block
  : LEFT_CURLY (statement*) RIGHT_CURLY
  ;
  
functionStatement
  : FN name = IDENTIFIER LEFT_PAREN (
    paramsNames += IDENTIFIER COL paramsTypes += type (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
  )? RIGHT_PAREN ARROW returnType = type (block | inlineBlock)
  ;
///////////////////////////////////////////////////



///////////////////////////////////////////////////
/// EXPRESSIONS
expr
  : IDENTIFIER # Identifier 
  | INT_LIT # IntLiteral
  | CHAR_LIT # CharLiteral
  | STRING_LIT # StringLiteral
  | FLOAT_LIT # FloatLiteral
  | BOOL_LIT # BoolLiteral
  | NULL_LIT # NullLiteral
  | array = expr LEFT_SQUARE index = expr RIGHT_SQUARE # Subscript
  | IDENTIFIER LEFT_PAREN (args += expr (COMMA args += expr)*)? RIGHT_PAREN # Call
  | unaryOperator = (PLUS | MINUS) expr # Unary
  | left = expr binaryOperator = (STAR | SLASH | MODULO) right = expr # Binary
  | left = expr binaryOperator = (PLUS | MINUS) right = expr # Binary
  | LEFT_PAREN expr RIGHT_PAREN # Grouping
  ;

simpleType
  : IDENTIFIER
  ;

functionType
  : FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW type
  ;

pointerType
  : (STAR)* (simpleType | functionType)
  ;

type
  : simpleType
  | pointerType
  | functionType
  ;

///////////////////////////////////////////////////
