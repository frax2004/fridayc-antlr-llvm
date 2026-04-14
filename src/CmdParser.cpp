#include "api/cmd/Parser.hpp"
#include "core/IO/Console.hpp"





namespace friday::inline api::inline cmd {

  namespace fs = std::filesystem;
  
  auto Parser::tokenize(Vector<StringRef> args) noexcept -> Vector<Token> {
    Vector<Token> tokens = {};

    const std::map<StringRef, Token> mapping = {
      {"-H", Token::OPT_HELP},
      {"--help", Token::OPT_HELP},
      {"-O", Token::OPT_OUTPUT},
      {"--output", Token::OPT_OUTPUT},
      {"-V", Token::OPT_VERSION},
      {"--version", Token::OPT_VERSION},
      {"-Wall", Token::OPT_WALL},
      {"-Wrestricted", Token::OPT_WRESTRICTED},
      {"-Wnone", Token::OPT_WNONE},
      {"build", Token::SUB_BUILD},
      {"run", Token::SUB_RUN},
    };

    for(auto arg : args) {
      if(auto it = mapping.find(arg); it != mapping.end()) {
        tokens.push_back(it->second);
      } else if(fs::exists(arg)) {
        tokens.push_back(Token{String{arg}});
      } else {
        bool condition = arg.starts_with("-") or arg.starts_with("--");
        tokens.push_back(condition ? Token::OPT_UNKNOWN : Token::UNKNOWN_ARG);
      }
    }

    return std::move(tokens);
  }

  auto Parser::parse(Vector<StringRef> args) noexcept -> std::tuple<Config, Vector<UnknownArgumentError>> {
    auto config = Config::defaults();
    auto tokens = Parser::tokenize(args);

    u64 i = 0;
    
    auto peek = [&i, &tokens](u64 ahead = 0) -> Opt<Token> {
      return i + ahead < tokens.size() ? std::make_optional(tokens[i + ahead]) : std::nullopt;
    };

    auto consume = [&i, &tokens] mutable -> Opt<Token> {
      return i < tokens.size() ? std::make_optional(tokens[i++]) : std::nullopt;
    };

    Vector<UnknownArgumentError> errors { };
    Opt<Token> token { };
    while((token = peek())) {
      token = consume();
      if(token == Token::OPT_HELP) {
        config.help = true;
      } else if(token == Token::OPT_VERSION) {
        config.version = true;
      } else if(token == Token::OPT_WALL) {
        if(config.warning.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify more than one warning level"});
        } else config.warning = WarningLevel::ALL;
      } else if(token == Token::OPT_WRESTRICTED) {
        if(config.warning.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify more than one warning level"});
        } else config.warning = WarningLevel::RESTRICTED;
      } else if(token == Token::OPT_WNONE) {
        if(config.warning.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify more than one warning level"});
        } else config.warning = WarningLevel::NONE;
      } else if(token == Token::OPT_OUTPUT) {
        if(config.output.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify the output path more than one time"});
        } else {
          StringRef opt = args[i-1];
          if(not ((token = peek()) and token->kind() == Token::PATH.kind())) {
            errors.push_back(UnknownArgumentError{
              "Expected a filename or a directory after {}{}\"{}\"{}, got {}{}\"{}\"{}"_f.format(
                Console::Color::BOLD,
                Console::Color::RED,
                opt,
                Console::Color::RESET,
                Console::Color::BOLD,
                Console::Color::RED,
                i < tokens.size() ? args[i] : "",
                Console::Color::RESET
              )
            });
          } else {
            config.output = token->lexeme();
          }
          consume();
        }
      } else if(token == Token::SUB_RUN) {
        if(config.mode.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify the execution mode more than one time"});
        } else {
          if(not ((token = peek()) and token->kind() == Token::PATH.kind())) {
            errors.push_back(UnknownArgumentError{
              "Expected a filename or a directory after {}{}\"run\"{}, got {}{}\"{}\"{}"_f.format(
                Console::Color::BOLD,
                Console::Color::RED,
                Console::Color::RESET,
                Console::Color::BOLD,
                Console::Color::RED,
                i < tokens.size() ? args[i] : "",
                Console::Color::RESET
              )
            });
          } else {
            config.input = token->lexeme();
            config.mode = Mode::RUN;
          }
          consume();
        }
      } else if(token == Token::SUB_BUILD) {
        if(config.mode.has_value()) {
          errors.push_back(UnknownArgumentError{"Cannot specify the execution mode more than one time"});
        } else {
          if(not ((token = peek()) and token->kind() == Token::PATH.kind())) {
            errors.push_back(UnknownArgumentError{
              "Expected a filename or a directory after {}{}\"build\"{}, got {}{}\"{}\"{}"_f.format(
                Console::Color::BOLD,
                Console::Color::RED,
                Console::Color::RESET,
                Console::Color::BOLD,
                Console::Color::RED,
                i < tokens.size() ? args[i] : "",
                Console::Color::RESET
              )
            });
          } else {
            config.input = token->lexeme();
            config.mode = Mode::BUILD;
          }
          consume();
        }
      } else if(token->kind() == Token::PATH.kind()) {
        errors.push_back(UnknownArgumentError{
          "Expected either one of {}{}\"-O\"{}, {}{}\"--output\"{}, {}{}\"build\"{} or {}{}\"run\"{} before the path {}{}\"{}\"{}"_f.format(
            Console::Color::RED,
            Console::Color::BOLD,
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            args[i-1],
            Console::Color::RESET
          )
        });
      } else if(token == Token::OPT_UNKNOWN) {
        errors.push_back(UnknownArgumentError{
          "Unexpected unknown option {}{}\"{}\"{}"_f.format(
            Console::Color::RED,
            Console::Color::BOLD,
            args[i-1],
            Console::Color::RESET
          )
        });
      } else {
        errors.push_back(UnknownArgumentError{
          "Unexpected unknown argument {}{}\"{}\"{}"_f.format(
            Console::Color::RED,
            Console::Color::BOLD,
            args[i-1],
            Console::Color::RESET
          )
        });
      }
    }

    if(not config.mode.has_value()) {
      errors.push_back(UnknownArgumentError{"No execution mode specified. Please specify one or type \"--help\" for more information about."});
    } else if(config.mode.has_value() && not config.input.has_value()) {
      errors.push_back(UnknownArgumentError{"No input file given. Please give one or type \"--help\" for more information about."});
    }

    return std::make_tuple(std::move(config), std::move(errors));
  }
}

