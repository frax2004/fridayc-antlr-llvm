#include "api/compiler/Compiler.hpp"
#include "api/parser/Parser.hpp"
#include "api/typechecker/TypeChecker.hpp"

namespace friday::inline api::inline compiler {
  
  auto Compiler::compile(TranslationUnit& unit) -> void {
    this->M_unit = &unit;

    std::ifstream stream{ unit.getPath() };
    String filename = unit.getPath().generic_string();

    ant::ANTLRInputStream input{stream};
    ErrorListener errorListener{ filename };

    FridayScanner scanner{ &input };
    scanner.removeErrorListeners();
    scanner.addErrorListener(&errorListener);

    ant::CommonTokenStream tokens{ &scanner };

    FridayParser parser{ &tokens };
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    try { unit.setParseTree(parser.program()); } catch(const ant::RecognitionException& _) {}

    if(not errorListener.errors().empty()) {
      std::ranges::for_each(errorListener.errors(), SyntaxError::report);
      
      return Console::note(
        "{} {}{}error(s){} encountered while parsing this source file. "_f.format(
          errorListener.errors().size(), Console::Color::BOLD, Console::Color::RED, Console::Color::RESET
        )
      );
    }
    
    auto typeErrors = TypeChecker{ unit }.check();
    
    if(not typeErrors.empty()) {
      std::ranges::for_each(typeErrors, SyntaxError::report);

      return Console::note(
        "{} {}{}error(s){} encountered during semantic analysis of this source file. "_f.format(
          typeErrors.size(),
          Console::Color::BOLD,
          Console::Color::RED,
          Console::Color::RESET
        )
      );
    }

    
  }

  auto Compiler::visitProgram(FridayParser::ProgramContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitTopLevelStatement(FridayParser::TopLevelStatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitStatement(FridayParser::StatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitBlock(FridayParser::BlockContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitCall(FridayParser::CallContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitPrimary(FridayParser::PrimaryContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitGrouping(FridayParser::GroupingContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitSubscript(FridayParser::SubscriptContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitBinary(FridayParser::BinaryContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitUnary(FridayParser::UnaryContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitType(FridayParser::TypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
 
}