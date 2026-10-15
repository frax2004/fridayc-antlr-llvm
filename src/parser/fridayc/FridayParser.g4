parser grammar FridayParser;

options {
  tokenVocab = FridayScanner; 
  language = Java;
}

///////////////////////////////////////////////////
/// STATEMENTS

  //////////////////////////////
  ///
  /// Abstract statements
  ///
  //////////////////////////////
  translationUnit
  : topLevelStatement* EOF
  ;

  topLevelStatement
  : usingStatement
  | namespaceStatement
  | structStatement
  | enumStatement
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
  namespaceStatement
  : NAMESPACE names += IDENTIFIER (DOT names += IDENTIFIER)*? SEMI
  ;

  usingStatement
  : USING names += IDENTIFIER (DOT names += IDENTIFIER)*? SEMI
  ;


  functionStatement
  : accessModifier = (PRIVATE | PUBLIC)? FN name = (IDENTIFIER | OPERATOR_IDENTIFIER) LEFT_PAREN (
      paramsNames += IDENTIFIER COL paramsTypes += type 
      (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
    )? RIGHT_PAREN ARROW returnType = type block = functionScope                  # FreeFunctionStatement
  | accessModifier = (PRIVATE | PUBLIC)? NATIVE FN name = IDENTIFIER LEFT_PAREN (
      paramsNames += IDENTIFIER COL paramsTypes += type 
      (COMMA paramsNames += IDENTIFIER COL paramsTypes += type)* 
    )? RIGHT_PAREN ARROW returnType = type SEMI                                   # NativeFunctionStatement
  ;

  enumStatement
  : accessModifier = (PRIVATE | PUBLIC)? ENUM name = IDENTIFIER LEFT_CURLY 
    (enumerators += IDENTIFIER (COMMA enumerators += IDENTIFIER)*?)?
  RIGHT_CURLY
  ;

  structStatement
  : accessModifier = (PRIVATE | PUBLIC)? STRUCT structName = IDENTIFIER (LESS typenames += IDENTIFIER (COMMA typenames += IDENTIFIER)*? GREATER)?
    LEFT_CURLY (
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
  | FOR (
    (
      varname = IDENTIFIER COL 
      from = expression 
      rangeOp = (DOTDOT | DOTDOTEQ) 
      to = expression
    ) | (
      (enumerator = IDENTIFIER COMMA)? 
      itername = IDENTIFIER COL slice = expression 
    )
  ) 
    (WHERE filterExpr = expression)?
    scope = syntacticalScope                                                                    # ForStatement
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
  syntacticalScope
  : LEFT_CURLY (statement*) RIGHT_CURLY
  ;

  functionScope
  : LEFT_CURLY (statement*) RIGHT_CURLY # BasicBlock
  | FAT_ARROW expression SEMI           # TrailingBlock
  ;

  lambdaScope
 : LEFT_CURLY (statement*) RIGHT_CURLY # LambdaBasicBlock
  | FAT_ARROW expression               # LambdaTrailingBlock
  ;
  //////////////////////////////
  //////////////////////////////
  //////////////////////////////

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////


///////////////////////////////////////////////////
///
/// EXPRESSIONS
///
///////////////////////////////////////////////////
  expression
  : id = IDENTIFIER      # IdentifierExpression
  | literal = INT_LIT    # IntLiteralExpression
  | literal = CHAR_LIT   # CharLiteralExpression
  | literal = STRING_LIT # stringLiteralExpression
  | literal = FLOAT_LIT  # FloatLiteralExpression
  | literal = BOOL_LIT   # BoolLiteralExpression
  | literal = NULL_LIT   # NullLiteralExpression
  | type COLCOL member = (IDENTIFIER | OPERATOR_IDENTIFIER)                                              # MemberAccessExpression
  | NEW type LEFT_CURLY (
      fields += IDENTIFIER COL initializers += expression 
      (COMMA fields += IDENTIFIER COL initializers += expression)*?
    )? RIGHT_CURLY                                                                                       # NewExpression
  | LEFT_SQUARE (values += expression (COMMA values += expression)*?)? RIGHT_SQUARE                      # ArrayLiteralExpression
  | operand = expression postfixOperator = (INCREMENT | DECREMENT)                                       # UnaryPostfixExpression
  | func = expression LEFT_PAREN (args += expression (COMMA args += expression)*)? RIGHT_PAREN           # CallExpression
  | array = expression LEFT_SQUARE index = expression RIGHT_SQUARE                                       # SubscriptExpression
  | object = expression DOT member = (IDENTIFIER | OPERATOR_IDENTIFIER)                                  # MemberAccessExpression
  | <assoc = right> unaryOperator = (PLUS | MINUS | NOT | TILDE | STAR | AMPERSAND) operand = expression # UnaryPrefixExpression
  | <assoc = right> unaryOperator = (SIZEOF | ALIGNOF) target = type                                     # CompTimeUnaryPrefixExpression
  | <assoc = right> expr = expression AS target = type                                                   # ExplicitCastExpression
  | left = expression binaryOperator = (STAR | SLASH | MODULO) right = expression                        # BinaryExpression
  | left = expression binaryOperator = (PLUS | MINUS) right = expression                                 # BinaryExpression
  | left = expression binaryOperator = (LSHIFT | RSHIFT) right = expression                              # BinaryExpression
  | left = expression binaryOperator = (LESS | LESS_EQ | GREATER | GREATER_EQ) right = expression        # BinaryExpression
  | left = expression binaryOperator = (EQUALS | NOT_EQUALS) right = expression                          # BinaryExpression
  | left = expression binaryOperator = AMPERSAND right = expression                                      # BinaryExpression
  | left = expression binaryOperator = PIPELINE right = expression                                       # BinaryExpression
  | left = expression binaryOperator = AND right = expression                                            # BinaryExpression
  | left = expression binaryOperator = OR right = expression                                             # BinaryExpression
  | <assoc = right> trueValue = expression IF condition = expression ELSE falseValue = expression        # TernaryExpression
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
    ) right = expression                                                             # AssignmentExpression
  | LEFT_PAREN (
    paramsNames += IDENTIFIER COL type (COMMA paramsNames += IDENTIFIER COL type)*?
    )? RIGHT_PAREN ARROW returnType = type block = lambdaScope                       # LambdaExpression
  | LEFT_PAREN expression RIGHT_PAREN                                                # GroupingExpression
  ;


  type
  : (namespaceNames += IDENTIFIER (DOT namespaceNames += IDENTIFIER)*? DOT)? 
    name = IDENTIFIER
    (LESS typeParameters += type (COMMA typeParameters += type)*? GREATER)?                               # SimpleType
  | STAR+ pointedType = type                                                                              # PointerType
  | (LEFT_SQUARE RIGHT_SQUARE) elementType = type                                                         # ArrayType
  | FN LEFT_PAREN (paramsTypes += type (COMMA paramsTypes += type)*)? RIGHT_PAREN ARROW returnType = type # FunctionType
  ;


///////////////////////////////////////////////////
