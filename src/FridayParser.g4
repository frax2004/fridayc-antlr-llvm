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
  | nativeFunctionStatement
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////



  //////////////////////////////
  ///
  /// Top level statements
  ///
  //////////////////////////////
  nativeFunctionStatement
  : NATIVE FN name = IDENTIFIER LEFT_PAREN (
    paramsNames += IDENTIFIER COL paramsTypes += type (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
  )? RIGHT_PAREN ARROW returnType = type SEMI
  ;

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
  /// Statements
  ///
  //////////////////////////////
  statement
  : printStatement
  | returnStatement
  | expressionStatement
  | ifStatement
  | forStatement
  | whileStatement
  | declarationStatement
  | scope
  | deferStatement
  ;

  deferrableStatement
  : printStatement
  | returnStatement
  | expressionStatement
  | ifStatement
  | forStatement
  | whileStatement
  | declarationStatement
  | scope
  ;

  declarationStatement
  : declarator = (LET | CONST) id = IDENTIFIER (COL type)? ASSIGN initializer = expression SEMI;

  ifStatement
  : IF expression statement (ELIF expression statement)*? (ELSE statement)?;
  
  forStatement
  : FOR statement expression SEMI expression statement;

  whileStatement
  : WHILE expression statement;

  expressionStatement: expression SEMI;
  deferStatement: DEFER deferrableStatement;
  printStatement: PRINT expression SEMI;
  scope: LEFT_CURLY (statement*) RIGHT_CURLY;
  returnStatement: RETURN (expression?) SEMI;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////



  //////////////////////////////
  ///
  /// Scope helpers
  ///
  //////////////////////////////
  inlineScope: FAT_ARROW expression SEMI;
  functionScope: scope | inlineScope;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


///////////////////////////////////////////////////
/// EXPRESSIONS
expression
: id = IDENTIFIER # IdentifierExpression
| literal = INT_LIT # IntLiteralExpression
| literal = CHAR_LIT # CharLiteralExpression
| literal = STRING_LIT # StringLiteralExpression
| literal = FLOAT_LIT # FloatLiteralExpression
| literal = BOOL_LIT # BoolLiteralExpression
| literal = NULL_LIT # NullLiteralExpression
| NEW type LEFT_CURLY (fields += IDENTIFIER COL initializers += expression (COMMA fields += IDENTIFIER COL initializers += expression)*?)? RIGHT_CURLY # NewExpression
| LEFT_SQUARE (expression (COMMA expression)*?)? RIGHT_SQUARE # ArrayLiteralExpression
| expr = expression postfixOperator = (INCREMENT | DECREMENT) # UnaryPostfixExpression
| func = expression LEFT_PAREN (args += expression (COMMA args += expression)*)? RIGHT_PAREN # CallExpression
| array = expression LEFT_SQUARE index = expression RIGHT_SQUARE # SubscriptExpression
| object = expression DOT member = IDENTIFIER # MemberAccessExpression
| <assoc=right> unaryOperator = (PLUS | MINUS | NOT | TILDE | STAR | AMPERSAND) expression # UnaryPrefixExpression
| <assoc=right> unaryOperator = (SIZEOF | ALIGNOF) (expression | type) # UnaryPrefixExpression
| <assoc=right> expr = expression AS type # ExplicitCastExpression
| left = expression binaryOperator = (STAR | SLASH | MODULO) right = expression # BinaryExpression
| left = expression binaryOperator = (PLUS | MINUS) right = expression # BinaryExpression
| left = expression binaryOperator = (LSHIFT | RSHIFT) right = expression # BinaryExpression
| left = expression binaryOperator = (LESS | LESS_EQ | GREATER | GREATER_EQ) right = expression # BinaryExpression
| left = expression binaryOperator = (EQUALS | NOT_EQUALS) right = expression # BinaryExpression
| left = expression binaryOperator = AMPERSAND right = expression # BinaryExpression
| left = expression binaryOperator = PIPELINE right = expression # BinaryExpression
| left = expression binaryOperator = AND right = expression # BinaryExpression
| left = expression binaryOperator = OR right = expression # BinaryExpression
| <assoc=right> left = expression binaryOperator = (ASSIGN | PLUS_ASSIGN | MINUS_ASSIGN | STAR_ASSIGN | SLASH_ASSIGN | MODULO_ASSIGN | LSHIFT_ASSIGN | RSHIFT_ASSIGN | AMPERSAND_ASSIGN | PIPELINE_ASSIGN) right = expression # BinaryExpression
| LEFT_PAREN expression RIGHT_PAREN # GroupingExpression
;


type
: simpleType
| pointerType
| arrayType
| functionType
;

functionType
: FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW returnType = type
;

simpleType: IDENTIFIER;
pointerType: STAR+ pointedType = type;
arrayType: (LEFT_SQUARE RIGHT_SQUARE)+ elementType = type;
///////////////////////////////////////////////////
