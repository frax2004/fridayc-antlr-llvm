parser grammar FridayParser;

options {
  tokenVocab = FridayScanner; 
  language = Cpp;
}


@parser::postinclude {
#include "Namespace.hpp"
#include "Scope.hpp"
#include "Value.hpp"
}

///////////////////////////////////////////////////
/// STATEMENTS

  //////////////////////////////
  ///
  /// Abstract statements
  ///
  //////////////////////////////
  translationUnit
  : topLevelStatement*? EOF
  ;

  topLevelStatement
  : usingStatement
  | namespaceStatement
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
  namespaceStatement returns [weak<Namespace> namespaceDecl]
  : NAMESPACE IDENTIFIER SEMI
  ;

  usingStatement
  : USING IDENTIFIER SEMI
  ;


  functionStatement returns [weak<Function> functionDecl, weak<Overload> overloadDecl]
  : accessModifier = (PRIVATE | PUBLIC)? FN name = IDENTIFIER LEFT_PAREN (
      paramsNames += IDENTIFIER 
      COL 
      paramsTypes += type 
      (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
    )? RIGHT_PAREN ARROW returnType = type block = functionScope                  # FreeFunctionStatement
  | accessModifier = (PRIVATE | PUBLIC)? NATIVE FN name = IDENTIFIER LEFT_PAREN (
      paramsNames += IDENTIFIER 
      COL 
      paramsTypes += type 
      (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
    )? RIGHT_PAREN ARROW returnType = type SEMI                                   # NativeFunctionStatement
  ;

  structStatement returns [weak<Struct> structDecl]
  : accessModifier = (PRIVATE | PUBLIC)? STRUCT structName = IDENTIFIER LEFT_CURLY (
      (accessModifier = (PRIVATE | PUBLIC)? fieldsNames += IDENTIFIER COL fieldsTypes += type SEMI) 
      | methods += functionStatement
    )*
    RIGHT_CURLY
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
  : PRINT expression SEMI                                                                       # PrintStatement
  | RETURN (expression?) SEMI                                                                   # ReturnStatement
  | expression SEMI                                                                             # ExpressionStatement
  | IF conditions += expression scopes += syntacticalScope (
      ELIF conditions += expression scopes += syntacticalScope
    )*? (ELSE elseStatement = statement)?                                                       # IfStatement
  | FOR statement expression SEMI expression statement                                          # ForStatement
  | WHILE condition = expression scope = syntacticalScope                                       # WhileStatement
  | declarator = (LET | CONST) id = IDENTIFIER (COL type)? ASSIGN initializer = expression SEMI # DeclarationStatement
  | DEFER statement                                                                             # DeferStatement
  | syntacticalScope                                                                            # ScopeStatement
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////



  //////////////////////////////
  ///
  /// Scope helpers
  ///
  //////////////////////////////
  syntacticalScope returns [rc<Scope> scope]
  : LEFT_CURLY (statement*) RIGHT_CURLY
  ;

  functionScope returns [rc<Scope> scope]
  : LEFT_CURLY (statement*) RIGHT_CURLY # BasicBlock
  | FAT_ARROW expression SEMI           # TrailingBlock
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


///////////////////////////////////////////////////
/// EXPRESSIONS
expression returns [Value value = Value::error_value()]
: id = IDENTIFIER      # IdentifierExpression
| literal = INT_LIT    # IntLiteralExpression
| literal = CHAR_LIT   # CharLiteralExpression
| literal = STRING_LIT # stringLiteralExpression
| literal = FLOAT_LIT  # FloatLiteralExpression
| literal = BOOL_LIT   # BoolLiteralExpression
| literal = NULL_LIT   # NullLiteralExpression
| NEW type LEFT_CURLY (
    fields += IDENTIFIER COL initializers += expression 
    (COMMA fields += IDENTIFIER COL initializers += expression)*?
  )? RIGHT_CURLY                                                                                       # NewExpression
| LEFT_SQUARE (values += expression (COMMA values += expression)*?)? RIGHT_SQUARE                      # ArrayLiteralExpression
| operand = expression postfixOperator = (INCREMENT | DECREMENT)                                       # UnaryPostfixExpression
| func = expression LEFT_PAREN (args += expression (COMMA args += expression)*)? RIGHT_PAREN           # CallExpression
| array = expression LEFT_SQUARE index = expression RIGHT_SQUARE                                       # SubscriptExpression
| object = expression DOT member = IDENTIFIER                                                          # MemberAccessExpression
| <assoc = right> unaryOperator = (PLUS | MINUS | NOT | TILDE | STAR | AMPERSAND) operand = expression # UnaryPrefixExpression
| <assoc = right> unaryOperator = (SIZEOF | ALIGNOF) type                                              # CompTimeUnaryPrefixExpression
| <assoc = right> expr = expression AS type                                                            # ExplicitCastExpression
| left = expression binaryOperator = (STAR | SLASH | MODULO) right = expression                        # BinaryExpression
| left = expression binaryOperator = (PLUS | MINUS) right = expression                                 # BinaryExpression
| left = expression binaryOperator = (LSHIFT | RSHIFT) right = expression                              # BinaryExpression
| left = expression binaryOperator = (LESS | LESS_EQ | GREATER | GREATER_EQ) right = expression        # BinaryExpression
| left = expression binaryOperator = (EQUALS | NOT_EQUALS) right = expression                          # BinaryExpression
| left = expression binaryOperator = AMPERSAND right = expression                                      # BinaryExpression
| left = expression binaryOperator = PIPELINE right = expression                                       # BinaryExpression
| left = expression binaryOperator = AND right = expression                                            # BinaryExpression
| left = expression binaryOperator = OR right = expression                                             # BinaryExpression
| <assoc = right> left = expression binaryOperator = (
  ASSIGN
  | PLUS_ASSIGN
  | MINUS_ASSIGN
  | STAR_ASSIGN
  | SLASH_ASSIGN
  | MODULO_ASSIGN
  | LSHIFT_ASSIGN
  | RSHIFT_ASSIGN
  | AMPERSAND_ASSIGN                 
  | PIPELINE_ASSIGN
  ) right = expression              # AssignmentExpression
| LEFT_PAREN expression RIGHT_PAREN # GroupingExpression
;


type returns [Pointer<Type> typeId = ErrorType::get()]
: IDENTIFIER                                                                                            # SimpleType
| STAR+ pointedType = type                                                                              # PointerType
| (LEFT_SQUARE RIGHT_SQUARE) elementType = type                                                         # ArrayType
| FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW returnType = type # FunctionType
;

///////////////////////////////////////////////////
