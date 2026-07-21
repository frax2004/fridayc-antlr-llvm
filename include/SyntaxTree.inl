#ifdef __INTELLISENSE__
#include <SyntaxTree.hpp>
#endif

namespace friday::inline api::inline pipeline {
  SyntaxTree::SyntaxTree(ant::ParserRuleContext *parent, u64 invokingState)
    : ant::ParserRuleContext{ parent, invokingState }
  {}

  template<class Attr>
  auto SyntaxTree::assign(Attr&& value) -> void {
    this->M_attributes = forward<Attr>(value);
  }

  template<class Visitor>
  auto SyntaxTree::visit(Visitor&& visitor) -> void {
    this->M_attributes.visit([&visitor](auto& val) -> void {
      if constexpr(same_as<TranslationUnitTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::declContext>(this), val);
      } else if constexpr(same_as<TopLevelStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::TopLevelStatementContext>(this), val);
      } else if constexpr(same_as<NamespaceStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::NamespaceStatementContext>(this), val);
      } else if constexpr(same_as<UsingStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::UsingStatementContext>(this), val);
      } else if constexpr(same_as<FreeFunctionStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::FreeFunctionStatementContext>(this), val);
      } else if constexpr(same_as<NativeFunctionStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::NativeFunctionStatementContext>(this), val);
      } else if constexpr(same_as<StructStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::StructStatementContext>(this), val);
      } else if constexpr(same_as<PrintStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::PrintStatementContext>(this), val);
      } else if constexpr(same_as<ReturnStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ReturnStatementContext>(this), val);
      } else if constexpr(same_as<ExpressionStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ExpressionStatementContext>(this), val);
      } else if constexpr(same_as<IfStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::IfStatementContext>(this), val);
      } else if constexpr(same_as<ForStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ForStatementContext>(this), val);
      } else if constexpr(same_as<WhileStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::WhileStatementContext>(this), val);
      } else if constexpr(same_as<DeclarationStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::DeclarationStatementContext>(this), val);
      } else if constexpr(same_as<DeferStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::DeferStatementContext>(this), val);
      } else if constexpr(same_as<ScopeStatementTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ScopeStatementContext>(this), val);
      } else if constexpr(same_as<SyntacticalScopeTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::SyntacticalScopeContext>(this), val);
      } else if constexpr(same_as<BasicBlockTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::BasicBlockContext>(this), val);
      } else if constexpr(same_as<TrailingBlockTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::TrailingBlockContext>(this), val);
      } else if constexpr(same_as<MemberAccessExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::MemberAccessExpressionContext>(this), val);
      } else if constexpr(same_as<UnaryPostfixExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::UnaryPostfixExpressionContext>(this), val);
      } else if constexpr(same_as<FloatLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::FloatLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<NewExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::NewExpressionContext>(this), val);
      } else if constexpr(same_as<ArrayLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ArrayLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<ExplicitCastExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ExplicitCastExpressionContext>(this), val);
      } else if constexpr(same_as<IntLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::IntLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<IdentifierExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::IdentifierExpressionContext>(this), val);
      } else if constexpr(same_as<StringLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::StringLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<BinaryExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::BinaryExpressionContext>(this), val);
      } else if constexpr(same_as<AssignmentExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::AssignmentExpressionContext>(this), val);
      } else if constexpr(same_as<GroupingExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::GroupingExpressionContext>(this), val);
      } else if constexpr(same_as<UnaryPrefixExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::UnaryPrefixExpressionContext>(this), val);
      } else if constexpr(same_as<SubscriptExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::SubscriptExpressionContext>(this), val);
      } else if constexpr(same_as<BoolLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::BoolLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<CharLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::CharLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<CallExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::CallExpressionContext>(this), val);
      } else if constexpr(same_as<NullLiteralExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::NullLiteralExpressionContext>(this), val);
      } else if constexpr(same_as<CompTimeUnaryPrefixExpressionTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::CompTimeUnaryPrefixExpressionContext>(this), val);
      } else if constexpr(same_as<SimpleTypeTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::SimpleTypeContext>(this), val);
      } else if constexpr(same_as<PointerTypeTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::PointerTypeContext>(this), val);
      } else if constexpr(same_as<ArrayTypeTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::ArrayTypeContext>(this), val);
      } else if constexpr(same_as<FunctionTypeTree, decltype(val)>) {
        invoke(visitor, dynamic_cast<FridayParser::FunctionTypeContext>(this), val);
      } else static_assert(false, "Invalid attribute type"); 
    });
  }
}
