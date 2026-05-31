// #pragma once

// #include <SemanticError.hpp>
// #include <FridayParserBaseVisitor.h>
// #include <CompilationContext.hpp>

// namespace friday::inline api::inline typechecker {

//   struct TypeChecker : public FridayParserBaseVisitor {
    
//     private:
//     CompilationContext* M_ctx;
//     Map<ant::tree::ParseTree*, Type> M_properties { };
//     Vector<SemanticError> M_errors { };
//     Stack<ISymbolTable*> M_symbolTables { };

//     public:
//     TypeChecker(CompilationContext& ctx) noexcept;

//     auto check() -> Vector<SemanticError>;

//     auto visitProgram(FridayParser::ProgramContext *ctx) -> std::any;
//     auto visitNativeFunctionStatement(FridayParser::NativeFunctionStatementContext *ctx) -> std::any;
//     auto visitNamespaceStatement(FridayParser::NamespaceStatementContext *ctx) -> std::any;
//     auto visitUsingStatement(FridayParser::UsingStatementContext *ctx) -> std::any;
//     auto visitStructStatement(FridayParser::StructStatementContext *ctx) -> std::any;
//     auto visitFunctionStatement(FridayParser::FunctionStatementContext *ctx) -> std::any;
//     auto visitDeclarationStatement(FridayParser::DeclarationStatementContext *ctx) -> std::any;
//     auto visitIfStatement(FridayParser::IfStatementContext *ctx) -> std::any;
//     auto visitForStatement(FridayParser::ForStatementContext *ctx) -> std::any;
//     auto visitWhileStatement(FridayParser::WhileStatementContext *ctx) -> std::any;
//     auto visitExpressionStatement(FridayParser::ExpressionStatementContext *ctx) -> std::any;
//     auto visitDeferStatement(FridayParser::DeferStatementContext *ctx) -> std::any;
//     auto visitPrintStatement(FridayParser::PrintStatementContext *ctx) -> std::any;
//     auto visitScope(FridayParser::ScopeContext *ctx) -> std::any;
//     auto visitReturnStatement(FridayParser::ReturnStatementContext *ctx) -> std::any;
//     auto visitInlineScope(FridayParser::InlineScopeContext *ctx) -> std::any;



//     auto visitMemberAccessExpression(FridayParser::MemberAccessExpressionContext *ctx) -> std::any;
//     auto visitUnaryPostfixExpression(FridayParser::UnaryPostfixExpressionContext *ctx) -> std::any;
//     auto visitStringLiteralExpression(FridayParser::StringLiteralExpressionContext *ctx) -> std::any;
//     auto visitFloatLiteralExpression(FridayParser::FloatLiteralExpressionContext *ctx) -> std::any;
//     auto visitNewExpression(FridayParser::NewExpressionContext *ctx) -> std::any;
//     auto visitArrayLiteralExpression(FridayParser::ArrayLiteralExpressionContext *ctx) -> std::any;
//     auto visitExplicitCastExpression(FridayParser::ExplicitCastExpressionContext *ctx) -> std::any;
//     auto visitIntLiteralExpression(FridayParser::IntLiteralExpressionContext *ctx) -> std::any;
//     auto visitIdentifierExpression(FridayParser::IdentifierExpressionContext *ctx) -> std::any;
//     auto visitBinaryExpression(FridayParser::BinaryExpressionContext *ctx) -> std::any;
//     auto visitGroupingExpression(FridayParser::GroupingExpressionContext *ctx) -> std::any;
//     auto visitUnaryPrefixExpression(FridayParser::UnaryPrefixExpressionContext *ctx) -> std::any;
//     auto visitSubscriptExpression(FridayParser::SubscriptExpressionContext *ctx) -> std::any;
//     auto visitBoolLiteralExpression(FridayParser::BoolLiteralExpressionContext *ctx) -> std::any;
//     auto visitCharLiteralExpression(FridayParser::CharLiteralExpressionContext *ctx) -> std::any;
//     auto visitCallExpression(FridayParser::CallExpressionContext *ctx) -> std::any;
//     auto visitNullLiteralExpression(FridayParser::NullLiteralExpressionContext *ctx) -> std::any;



//     auto visitType(FridayParser::TypeContext *ctx) -> std::any;
//     auto visitFunctionType(FridayParser::FunctionTypeContext *ctx) -> std::any;
//     auto visitSimpleType(FridayParser::SimpleTypeContext *ctx) -> std::any;
//     auto visitPointerType(FridayParser::PointerTypeContext *ctx) -> std::any;
//     auto visitArrayType(FridayParser::ArrayTypeContext *ctx) -> std::any;

//     private:
//     auto errorAt(ant::Token* token, String message) -> void;
//     auto pushScope(ISymbolTable& scope) -> void;
//     auto popScope() -> ISymbolTable*;
//     auto topScope() -> ISymbolTable*;

//     template<class T>
//     auto byVisiting() const noexcept -> std::function<std::any (T*)>;
//   };
// }


// #include <TypeChecker.inl>