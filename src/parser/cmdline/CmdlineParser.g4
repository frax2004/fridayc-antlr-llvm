parser grammar CmdlineParser;

options {
  tokenVocab = CmdlineScanner; 
  language = Cpp;
}

commandLine:
  (opts += option)+                                                                         # QueryCommand
  | BUILD what = (EXE | STATIC_LIB | SHARED_LIB) (filenames += FILENAME)* (opts += option)* # BuildCommand
  | NEW what = (EXE | STATIC_LIB | SHARED_LIB) FILENAME                                     # NewCommand
  ;

option: value = (
    EXT_EMIT
    | EXT_HELP
    | EXT_VERSION
    | EXT_VERBOSE
    | EXT_ODP
    | EMIT
    | HELP
    | VERBOSE
  )                                      # FlagOption
  | level = (WALL | WRESTRICTED | WNONE) # WarningOption
  | LINK_DIR_OPT FILENAME                # LinkDirOption
  | LINK_LIB_OPT FILENAME                # LinkLibOption
  | OUT_OPT FILENAME                     # OutOption
  ;