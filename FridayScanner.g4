lexer grammar FridayScanner;

STRUCT: 'struct';
RETURN: 'return';
PRINT: 'print';
FN: 'fn';
BOOL_LIT: 'true' | 'false';
NULL_LIT: 'null';

LEFT_PAREN: '(';
LEFT_SQUARE: '[';
LEFT_CURLY: '{';
RIGHT_PAREN: ')';
RIGHT_SQUARE: ']';
RIGHT_CURLY: '}';
SEMI: ';';
COL: ':';
COMMA: ',';
STAR: '*';
SLASH: '/';
MINUS: '-';
PLUS: '+';
MODULO: '%';

ARROW: '->';
FAT_ARROW: '=>';

IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;


COMMENT: '//'~[\r\n] -> skip;
SPACE: [ \t\r\n] -> skip;

INT_LIT: [\-+]? ('0' | [1-9][0-9]*);
FLOAT_LIT: [\-+]? ('0' | [1-9][0-9]*)'.'([0-9]*);
STRING_LIT: '"'(.*?)'"';
CHAR_LIT: '\''.'\'';

