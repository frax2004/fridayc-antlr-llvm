#pragma once

#include <Common.hpp>
#include <FridayParserBaseVisitor.h>
#include <Namespace.hpp>
#include <Scope.hpp>
#include <Value.hpp>

namespace friday::inline api::inline pipeline {

  template<derived_from<ant::tree::ParseTree> C>
  struct SyntaxTree {
    using context_type = C;

    private:
    Pointer<context_type> M_context { nullptr };

    public:
    SyntaxTree(context_type& ctx);
    constexpr SyntaxTree(SyntaxTree const&) = default;
    constexpr SyntaxTree(SyntaxTree &&) = default;
    constexpr auto operator=(SyntaxTree const&) -> SyntaxTree& = default;
    constexpr auto operator=(SyntaxTree &&) -> SyntaxTree& = default;
    constexpr virtual ~SyntaxTree() noexcept = default;

    public:
    virtual auto context() const -> context_type& final;
    virtual auto accept(ant::tree::ParseTreeVisitor& visitor) -> void final;
  };

  struct TranslationUnitTree : SyntaxTree<FridayParser::TranslationUnitContext> {

  };

  struct TopLevelStatementTree : SyntaxTree<FridayParser::TopLevelStatementContext> {

  };

  struct NamespaceStatementTree : SyntaxTree<FridayParser::NamespaceStatementContext> {
    rc<Namespace> namespace_ { };
  };

  struct UsingStatementTree : SyntaxTree<FridayParser::UsingStatementContext> {
    rc<Namespace> namespace_ { };
  };

  struct FreeFunctionStatementTree : SyntaxTree<FridayParser::FreeFunctionStatementContext> {
    rc<Scope>    scope    { };
    rc<Function> function { };
    rc<Overload> overload { };
  };

  struct NativeFunctionStatementTree : SyntaxTree<FridayParser::NativeFunctionStatementContext> {
    rc<Function> function { };
    rc<Overload> overload { };
  };

  struct StructStatementTree : SyntaxTree<FridayParser::StructStatementContext> {
    rc<Struct> struct_ { };
  };

  struct PrintStatementTree : SyntaxTree<FridayParser::PrintStatementContext> {

  };

  struct ReturnStatementTree : SyntaxTree<FridayParser::ReturnStatementContext> {
    
  };

  struct ExpressionStatementTree : SyntaxTree<FridayParser::ExpressionStatementContext> {

  };

  struct IfStatementTree : SyntaxTree<FridayParser::IfStatementContext> {

  };

  struct ForStatementTree : SyntaxTree<FridayParser::ForStatementContext> {

  };

  struct WhileStatementTree : SyntaxTree<FridayParser::WhileStatementContext> {

  };

  struct DeclarationStatementTree : SyntaxTree<FridayParser::DeclarationStatementContext> {

  };

  struct DeferStatementTree : SyntaxTree<FridayParser::DeferStatementContext> {

  };

  struct ScopeStatementTree : SyntaxTree<FridayParser::ScopeStatementContext> {

  };

  struct SyntacticalScopeTree : SyntaxTree<FridayParser::SyntacticalScopeContext> {

  };

  struct BasicBlockTree : SyntaxTree<FridayParser::BasicBlockContext> {

  };

  struct TrailingBlockTree : SyntaxTree<FridayParser::TrailingBlockContext> {

  };

  struct MemberAccessExpressionTree : SyntaxTree<FridayParser::MemberAccessExpressionContext> {

  };

  struct UnaryPostfixExpressionTree : SyntaxTree<FridayParser::UnaryPostfixExpressionContext> {

  };

  struct FloatLiteralExpressionTree : SyntaxTree<FridayParser::FloatLiteralExpressionContext> {

  };

  struct NewExpressionTree : SyntaxTree<FridayParser::NewExpressionContext> {

  };

  struct ArrayLiteralExpressionTree : SyntaxTree<FridayParser::ArrayLiteralExpressionContext> {

  };

  struct ExplicitCastExpressionTree : SyntaxTree<FridayParser::ExplicitCastExpressionContext> {

  };

  struct IntLiteralExpressionTree : SyntaxTree<FridayParser::IntLiteralExpressionContext> {

  };

  struct IdentifierExpressionTree : SyntaxTree<FridayParser::IdentifierExpressionContext> {

  };

  struct StringLiteralExpressionTree : SyntaxTree<FridayParser::StringLiteralExpressionContext> {

  };

  struct BinaryExpressionTree : SyntaxTree<FridayParser::BinaryExpressionContext> {

  };

  struct AssignmentExpressionTree : SyntaxTree<FridayParser::AssignmentExpressionContext> {

  };

  struct GroupingExpressionTree : SyntaxTree<FridayParser::GroupingExpressionContext> {

  };

  struct UnaryPrefixExpressionTree : SyntaxTree<FridayParser::UnaryPrefixExpressionContext> {

  };

  struct SubscriptExpressionTree : SyntaxTree<FridayParser::SubscriptExpressionContext> {

  };

  struct BoolLiteralExpressionTree : SyntaxTree<FridayParser::BoolLiteralExpressionContext> {

  };

  struct CharLiteralExpressionTree : SyntaxTree<FridayParser::CharLiteralExpressionContext> {

  };

  struct CallExpressionTree : SyntaxTree<FridayParser::CallExpressionContext> {

  };

  struct NullLiteralExpressionTree : SyntaxTree<FridayParser::NullLiteralExpressionContext> {

  };

  struct CompTimeUnaryPrefixExpressionTree : SyntaxTree<FridayParser::CompTimeUnaryPrefixExpressionContext> {

  };

  struct SimpleTypeTree : SyntaxTree<FridayParser::SimpleTypeContext> {

  };

  struct PointerTypeTree : SyntaxTree<FridayParser::PointerTypeContext> {

  };

  struct ArrayTypeTree : SyntaxTree<FridayParser::ArrayTypeContext> {

  };

  struct FunctionTypeTree : SyntaxTree<FridayParser::FunctionTypeContext> {

  };

}