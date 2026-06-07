// #pragma once

// #include <SemanticError.hpp>
// #include <FridayParserBaseVisitor.h>
// #include <CompilationContext.hpp>
// #include <StaticAnalyzer.hpp>

// namespace friday::inline api::inline pipeline {

//   struct TypeChecker : FridayParserBaseVisitor, StaticAnalizer {
    
//     private:
//     CompilationContext* M_ctx { nullptr };
//     map<ant::tree::ParseTree*, Type> M_properties { };
//     vector<SemanticError> M_errors { };
//     stack<ISymbolTable*> M_symbolTables { };

//     public:
//     TypeChecker(CompilationContext& ctx) noexcept;

//     auto check() -> vector<SemanticError>;

//     auto visitProgram(FridayParser::ProgramContext *ctx) -> any;
//     auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> any;
//     auto visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> any;
//     auto visitUsingStatement(FridayParser::UsingStatementContext *ctx) -> any;
//     auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> any;
//     auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> any;
//     auto visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> any;
//     auto visitIfStatement(FridayParser::IfStatementContext *ctx) -> any;
//     auto visitForStatement(FridayParser::ForStatementContext *ctx) -> any;
//     auto visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> any;
//     auto visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> any;
//     auto visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> any;
//     auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> any;
//     auto visitScope(FridayParser::ScopeContext *ctx) -> any;
//     auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> any;
//     auto visitInlineScope(FridayParser::InlineScopeContext *ctx) -> any;



//     auto visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> any;
//     auto visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> any;
//     auto visitstringLiteralExpression(FridayParser::stringLiteralExpressionContext *ctx) -> any;
//     auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> any;
//     auto visitNewExpression(FridayParser::NewExpressionContext *ctx) -> any;
//     auto visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> any;
//     auto visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> any;
//     auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> any;
//     auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> any;
//     auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> any;
//     auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> any;
//     auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> any;
//     auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> any;
//     auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> any;
//     auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> any;
//     auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> any;
//     auto visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> any;



//     auto visitType(FridayParser::TypeContext *ctx) -> any;
//     auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> any;
//     auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> any;
//     auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> any;
//     auto visitArrayType(FridayParser::ArrayTypeContext *ctx) -> any;

//     private:
//     auto errorAt(ant::Token* token, string message) -> void;
//     auto pushScope(ISymbolTable& scope) -> void;
//     auto popScope() -> ISymbolTable*;
//     auto topScope() -> ISymbolTable*;

//     template<class T>
//     auto byVisiting() const noexcept -> function<any (T*)>;
//   };
// }


// #include <TypeCheckerVisitor.inl>