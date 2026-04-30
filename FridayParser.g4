parser grammar FridayParser;

options {
  tokenVocab = FridayScanner; 
  language = Cpp;
}


///////////////////////////////////////////////////
/// STATEMENTS

  //////////////////////////////
  ///
  /// Abstract statements
  ///
  //////////////////////////////
  program: namespaceStatement? topLevelStatement* EOF;

  topLevelStatement
  : usingStatement
  | structStatement
  | functionStatement
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////



  //////////////////////////////
  ///
  /// Top level statements
  ///
  //////////////////////////////
  namespaceStatement: NAMESPACE NAMESPACE_IDENTIFIER SEMI;
  usingStatement: USING NAMESPACE_IDENTIFIER SEMI;

  structStatement: STRUCT IDENTIFIER LEFT_CURLY 
    ((fieldsNames += IDENTIFIER COL fieldsTypes += type SEMI) | methods += functionStatement)*
  RIGHT_CURLY
  ;

  functionStatement
  : FN name = IDENTIFIER LEFT_PAREN (
    paramsNames += IDENTIFIER COL paramsTypes += type (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
  )? RIGHT_PAREN ARROW returnType = type functionScope
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////




  //////////////////////////////
  ///
  /// Regular statements
  ///
  //////////////////////////////
  regularStatement
  : printStatement
  | deferStatement
  ;

  deferStatement: DEFER deferrableStatement;
  printStatement: PRINT expr SEMI;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////
  



  //////////////////////////////
  ///
  /// Deferrable statements
  /// 
  //////////////////////////////
  deferrableStatement
  : deferrableScope
  | regularStatement
  ;

  deferrableScope: LEFT_CURLY (deferrableStatement*) RIGHT_CURLY;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////



  //////////////////////////////
  ///
  /// Scoped statements
  ///
  //////////////////////////////
  scope: LEFT_CURLY (scopedStatement*) RIGHT_CURLY;

  scopedStatement
  : scope
  | regularStatement
  | returnStatement
  ;

  returnStatement: RETURN (expr?) SEMI;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////




  //////////////////////////////
  ///
  /// Scope helpers
  ///
  //////////////////////////////
  inlineScope: FAT_ARROW expr SEMI;
  functionScope: scope | inlineScope;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


///////////////////////////////////////////////////
/// EXPRESSIONS
expr
  : IDENTIFIER # IdentifierExpression
  | INT_LIT # IntLiteralExpression
  | CHAR_LIT # CharLiteralExpression
  | STRING_LIT # StringLiteralExpression
  | FLOAT_LIT # FloatLiteralExpression
  | BOOL_LIT # BoolLiteralExpression
  | NULL_LIT # NullLiteralExpression
  | array = expr LEFT_SQUARE index = expr RIGHT_SQUARE # SubscriptExpression
  | func = expr LEFT_PAREN (args += expr (COMMA args += expr)*)? RIGHT_PAREN # CallExpression
  | unaryOperator = (PLUS | MINUS) expr # UnaryExpression
  | left = expr binaryOperator = (STAR | SLASH | MODULO) right = expr # BinaryExpression
  | left = expr binaryOperator = (PLUS | MINUS) right = expr # BinaryExpression
  | LEFT_PAREN expr RIGHT_PAREN # GroupingExpression
  ;

simpleType: IDENTIFIER;

functionType
  : FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW returnType = type
  ;

pointerType: STAR+ type;
arrayType: (LEFT_SQUARE RIGHT_SQUARE)+ type;

type
  : simpleType
  | pointerType
  | arrayType
  | functionType
  ;

///////////////////////////////////////////////////
