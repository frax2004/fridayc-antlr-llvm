#include <fridayc.hpp>
#include <CmdlineScanner.h>
#include <CmdlineParser.h>
#include <CmdlineParserBaseVisitor.h>


namespace friday {

  struct CmdlineBuilder : Builder<expected<CLI, vector<string>>>, CmdlineParserBaseVisitor {
    private:
    ant::tree::ParseTree* M_tree            = nullptr;
    string                M_outputPath      = "";
    string                M_libs            = "";
    set<string>           M_sources         = { };
    vector<string>        M_errors          = { };
    bitset<32>            M_flags           = { };
    CLI::WarningLevel     M_warningLevel    = CLI::WarningLevel::RESTRICTED;
    CLI::Subcommand       M_subcommand      = CLI::Subcommand::NONE;
    CLI::ProjectCategory  M_projectCategory = CLI::ProjectCategory::NONE;

    public:
    CmdlineBuilder(ant::tree::ParseTree* tree)
      : M_tree{ tree }
    {}

    auto visitQueryCommand(CmdlineParser::QueryCommandContext *ctx) -> any override {
      this->M_subcommand = CLI::Subcommand::NONE;
      return visitChildren(ctx);
    }

    auto visitBuildCommand(CmdlineParser::BuildCommandContext *ctx) -> any override {
      this->M_subcommand = CLI::Subcommand::BUILD;

      switch(ctx->what->getType()) {
        case CmdlineParser::EXE: {
          this->M_projectCategory = CLI::ProjectCategory::EXE;
          break;
        } case CmdlineParser::STATIC_LIB: {
          this->M_projectCategory = CLI::ProjectCategory::STATIC_LIB;
          break;
        } case CmdlineParser::SHARED_LIB: {
          this->M_projectCategory = CLI::ProjectCategory::SHARED_LIB;
          break;
        } 
      }

      static set allowedExtensions = {
        "fr"s,
        "fx"s
      };
 
      for(auto filename : ctx->filenames | views::transform(ant::Token::getText)) {
        if(not filesystem::is_regular_file(filename)) {
          if(filename.starts_with("--") or filename.starts_with("-")) {
            this->M_errors.push_back(format("Unknown option \"{}\"", filename));
          } else this->M_errors.push_back(
            format("Invalid filename \"{}\" does not exists or is not a file.", filename)
          );
        } else if(auto extension = filesystem::path{filename}.extension().generic_string(); allowedExtensions.contains(extension)) {
          this->M_errors.push_back(
            format(
              "Invalid filename \"{}\" has an unsupported extension \"{}\". Allowed extensions are {}", 
              filename, 
              extension, 
              allowedExtensions 
              | views::join_with(", "s) 
              | ranges::to<string>()
            )
          );
        } else this->M_sources.insert(filename);
      }
      
      this->visitChildren(ctx);
      return {};
    }

    auto visitNewCommand(CmdlineParser::NewCommandContext *ctx) -> any override {
      this->M_subcommand = CLI::Subcommand::NEW;

      switch(ctx->what->getType()) {
        case CmdlineParser::EXE: {
          this->M_projectCategory = CLI::ProjectCategory::EXE;
          break;
        } case CmdlineParser::STATIC_LIB: {
          this->M_projectCategory = CLI::ProjectCategory::STATIC_LIB;
          break;
        } case CmdlineParser::SHARED_LIB: {
          this->M_projectCategory = CLI::ProjectCategory::SHARED_LIB;
          break;
        } 
      }

      this->visitChildren(ctx);
      this->M_outputPath = ctx->FILENAME()->getText();

      return {};
    }

    auto visitWarningOption(CmdlineParser::WarningOptionContext *ctx) -> any override {
      auto id2warn = [](u64 id) -> CLI::WarningLevel {
        switch(id) {
          case CmdlineParser::WNONE: return CLI::WarningLevel::NONE;
          case CmdlineParser::WRESTRICTED: return CLI::WarningLevel::RESTRICTED;
          case CmdlineParser::WALL: return CLI::WarningLevel::ALL;
          default: unreachable();
        }
      };

      this->M_warningLevel = id2warn(ctx->level->getType());

      return {};
    }

    auto visitFlagOption(CmdlineParser::FlagOptionContext *ctx) -> any override {
      this->visitChildren(ctx);

      auto id2flag = [](u64 id) -> u32 {
        switch(id) {
          case CmdlineParser::EMIT:
          case CmdlineParser::EXT_EMIT: return CLI::EMIT;
          case CmdlineParser::VERBOSE:
          case CmdlineParser::EXT_VERBOSE: return CLI::VERBOSE;
          case CmdlineParser::HELP:
          case CmdlineParser::EXT_HELP: return CLI::HELP;
          case CmdlineParser::EXT_VERSION: return CLI::VERSION;
          case CmdlineParser::EXT_ODP: return CLI::ODP;
          default: return -1U;
        }
      };

      u32 flag = id2flag(ctx->value->getType());

      if(flag == -1U) {
        this->M_errors.push_back(format("Unknown option \"{}\"", ctx->getText()));
        return {};
      }

      this->M_flags.set(flag);

      return {};
    }

    auto visitLinkDirOption(CmdlineParser::LinkDirOptionContext *ctx) -> any override {
      this->visitChildren(ctx);
      string dirname = ctx->FILENAME()->getText();

      if(not filesystem::is_directory(dirname)) {
        this->M_errors.push_back(
          format("Invalid directory \"{}\" does not exists or is not a directory.", dirname)
        );
        return {};
      }

      this->M_libs.append(format("-L {} ", dirname));

      return {};
    }

    auto visitLinkLibOption(CmdlineParser::LinkLibOptionContext *ctx) -> any override {
      this->visitChildren(ctx);
      string filename = ctx->FILENAME()->getText();

      if(not filesystem::is_regular_file(filename)) {
        this->M_errors.push_back(
          format("Invalid filename \"{}\" does not exists or is not a library.", filename)
        );
        return {};
      }

      this->M_libs.append(format("-l {} ", ctx->FILENAME()->getText()));

      return {};
    }

    auto visitOutOption(CmdlineParser::OutOptionContext *ctx) -> any override {
      this->visitChildren(ctx);
      this->M_outputPath = ctx->getText();
      return {};
    }

    auto build() -> expected<CLI, vector<string>> {
      this->visit(this->M_tree);
      return this->M_errors.empty() ? expected<CLI, vector<string>>{{
        .outputPath = this->M_outputPath,
        .libs = this->M_libs,
        .sources = this->M_sources,
        .flags = this->M_flags,
        .warningLevel = this->M_warningLevel,
        .subcommand = this->M_subcommand,
        .projectCategory = this->M_projectCategory
      }} : unexpected{ this->M_errors };
    }
  };

  auto CLI::parse(span<string> args) -> expected<CLI, vector<string>> {
    stringstream stream;

    for(auto&& arg: args) {
      stream << arg << " ";
    }

    ant::ANTLRInputStream input{ stream };
    CmdlineScanner lexer{ &input };
    ant::CommonTokenStream tokens{ &lexer };
    CmdlineParser parser{ &tokens };
    auto cmdline = parser.commandLine();

    return CmdlineBuilder{ cmdline }.build();
  }
  
}