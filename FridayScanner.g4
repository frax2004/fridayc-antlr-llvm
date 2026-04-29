lexer grammar FridayScanner;

// Ignored characters
INLINE_COMMENT: '//'(~[\r\n])* -> skip;
COMMENT: '/*'([.\n\r])*'*/' -> skip;
SPACE: [ \t\r\n] -> skip;

// Keywords
STRUCT: 'struct';
RETURN: 'return';
PRINT: 'print';
FN: 'fn';
FOR: 'for';
WHILE: 'while';
DEFER: 'defer';
NAMESPACE: 'namespace';
USING: 'using';
CONST: 'const';
LET: 'let';
NEW: 'new';
IF: 'if';
ELIF: 'elif';
ELSE: 'else';

// Literals
BOOL_LIT: 'true' | 'false';
NULL_LIT: 'null';
INT_LIT: ('0' | [1-9][0-9]*);
FLOAT_LIT: ([1-9][0-9]*)'.'([0-9]+) | ([1-9][0-9]+)'.'([0-9]*);
STRING_LIT: '"'(.*?)'"';
CHAR_LIT: '\''(. | '\\'.)'\'';

// Symbols
LEFT_PAREN: '(';
LEFT_SQUARE: '[';
LEFT_CURLY: '{';
RIGHT_PAREN: ')';
RIGHT_SQUARE: ']';
RIGHT_CURLY: '}';
SEMI: ';';
COL: ':';
COMMA: ',';
ARROW: '->';
FAT_ARROW: '=>';
AND: 'and';
OR: 'or';
NOT: 'not';
AS: 'as';
SIZEOF: 'sizeof';
ALIGNOF: 'alignof';

// Operators
PLUS: '+';
MINUS: '-';
STAR: '*';
SLASH: '/';
MODULO: '%';
LSHIFT: '<<';
RSHIFT: '>>';
AMPERSAND: '&';
PIPELINE: '|';
LESS: '<';
GREATER: '>';
LESS_EQ: '<=';
GREATER_EQ: '>=';
EQUALS: '==';
NOT_EQUALS: '!=';
ASSIGN: '=';
PLUS_ASSIGN: '+=';
MINUS_ASSIGN: '-=';
STAR_ASSIGN: '*=';
SLASH_ASSIGN: '/=';
MODULO_ASSIGN: '%=';
LSHIFT_ASSIGN: '<<=';
RSHIFT_ASSIGN: '>>=';
AMPERSAND_ASSIGN: '&=';
PIPELINE_ASSIGN: '|=';
TILDE: '~';
DOT: '.';

// Identifier
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
NAMESPACE_IDENTIFIER: IDENTIFIER ('.' IDENTIFIER)*?;