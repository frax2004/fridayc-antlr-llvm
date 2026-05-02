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
      std::ranges::for_each(typeErrors, SemanticError::report);

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

  auto Compiler::visitFunctionScope(FridayParser::FunctionScopeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitScope(FridayParser::ScopeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitCallExpression(FridayParser::CallExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  
  auto Compiler::visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  
  auto Compiler::visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  
  auto Compiler::visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  
  auto Compiler::visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  
  auto Compiler::visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
  


  auto Compiler::visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> std::any {
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

  auto Compiler::visitPointedType(FridayParser::PointedTypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }

  auto Compiler::visitType(FridayParser::TypeContext *ctx) -> std::any {
    return visitChildren(ctx);
  }
 
}