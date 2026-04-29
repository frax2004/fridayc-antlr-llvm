parser grammar FridayParser;

options {
  tokenVocab = FridayScanner; 
  language = Cpp;
}


///////////////////////////////////////////////////
/// STATEMENTS
  /// Abstract statements
  program: namespaceStatement? topLevelStatement* EOF;

  topLevelStatement
  : usingStatement
  | structStatement
  | functionStatement
  ;

  /// Top level statements
  namespaceStatement: NAMESPACE NAMESPACE_IDENTIFIER SEMI;
  usingStatement: USING NAMESPACE_IDENTIFIER SEMI;

  structStatement: STRUCT IDENTIFIER LEFT_CURLY 
    ((fieldsNames += IDENTIFIER COL fieldsTypes += type SEMI) | methods += functionStatement)*
  RIGHT_CURLY
  ;

  functionStatement
  : FN name = IDENTIFIER LEFT_PAREN (
    paramsNames += IDENTIFIER COL paramsTypes += type (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
  )? RIGHT_PAREN ARROW returnType = type functionBlock
  ;

  /// Regular statements
  regularStatement
  : printStatement
  | deferStatement
  ;

  deferStatement: DEFER deferrableStatement;
  printStatement: PRINT expr SEMI;
  
  /// Deferrable statements
  deferrableStatement
  : deferrableScope
  | regularStatement
  ;

  deferrableScope
  : LEFT_CURLY (deferrableStatement*) RIGHT_CURLY
  ;

  /// Scoped statements
  scope
  : LEFT_CURLY (scopedStatement*) RIGHT_CURLY
  ;

  scopedStatement
  : scope
  | regularStatement
  | returnStatement
  ;

  returnStatement: RETURN (expr?) SEMI;

  /// Scope helpers
  inlineScope
  : FAT_ARROW expr SEMI
  ;

  functionBlock
  : scope
  | inlineScope
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
  | func = expr LEFT_PAREN (args += expr (COMMA args += expr)*)? RIGHT_PAREN # Call
  | unaryOperator = (PLUS | MINUS) expr # Unary
  | left = expr binaryOperator = (STAR | SLASH | MODULO) right = expr # Binary
  | left = expr binaryOperator = (PLUS | MINUS) right = expr # Binary
  | LEFT_PAREN expr RIGHT_PAREN # Grouping
  ;

simpleType
  : IDENTIFIER
  ;

functionType
  : FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW returnType = type
  ;

pointerType
  : STAR+ pointedType
  ;

pointedType
  : simpleType 
  | functionType
  ;

type
  : simpleType
  | pointerType
  | functionType
  ;

///////////////////////////////////////////////////
