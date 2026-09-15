lexer grammar CmdlineScanner;

SPACE: [ \t\r\n] -> skip;

BUILD: 'build';
EXE: 'exe';
NEW: 'new';
STATIC_LIB: 'static-lib';
SHARED_LIB: 'shared-lib';

LINK_LIB_OPT: '-l';
LINK_DIR_OPT: '-L';

OUT_OPT: 
  '--output' 
  | '-O';

EXT_EMIT: '--emit';
EXT_HELP: '--help';
EXT_VERSION: '--version';
EXT_VERBOSE: '--verbose';
EXT_ODP: '--open-diagnostic-panel';
EMIT: '-E';
HELP: '-H';
VERBOSE: '-V';
WALL: '-Wall';
WRESTRICTED: '-Wrestricted';
WNONE: '-Wnone';

FILENAME: 
    '"' (~["\r\n])* '"'
  | '\'' (~['\r\n])* '\''
  | ~[ \t\r\n"']+
;