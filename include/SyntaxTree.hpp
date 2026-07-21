#pragma once

#include <Common.hpp>
#include <FridayParserBaseVisitor.h>
#include <Namespace.hpp>
#include <Scope.hpp>
#include <Value.hpp>

namespace friday::inline api::inline pipeline {

  struct TranslationUnitTree {

  };

  struct TopLevelStatementTree {

  };

  struct NamespaceStatementTree {
    rc<Namespace> namespace_ { };
  };

  struct UsingStatementTree {
    rc<Namespace> namespace_ { };
  };

  struct FreeFunctionStatementTree {
    rc<Scope>    scope    { };
    rc<Function> function { };
    rc<Overload> overload { };
  };

  struct NativeFunctionStatementTree {
    rc<Function> function { };
    rc<Overload> overload { };
  };

  struct StructStatementTree {
    rc<Struct> struct_ { };
  };

  struct PrintStatementTree {

  };

  struct ReturnStatementTree {
    
  };

  struct ExpressionStatementTree {

  };

  struct IfStatementTree {

  };

  struct ForStatementTree {

  };

  struct WhileStatementTree {

  };

  struct DeclarationStatementTree {

  };

  struct DeferStatementTree {

  };

  struct ScopeStatementTree {

  };

  struct SyntacticalScopeTree {

  };

  struct BasicBlockTree {

  };

  struct TrailingBlockTree {

  };

  struct MemberAccessExpressionTree {

  };

  struct UnaryPostfixExpressionTree {

  };

  struct FloatLiteralExpressionTree {

  };

  struct NewExpressionTree {

  };

  struct ArrayLiteralExpressionTree {

  };

  struct ExplicitCastExpressionTree {

  };

  struct IntLiteralExpressionTree {

  };

  struct IdentifierExpressionTree {

  };

  struct StringLiteralExpressionTree {

  };

  struct BinaryExpressionTree {

  };

  struct AssignmentExpressionTree {

  };

  struct GroupingExpressionTree {

  };

  struct UnaryPrefixExpressionTree {

  };

  struct SubscriptExpressionTree {

  };

  struct BoolLiteralExpressionTree {

  };

  struct CharLiteralExpressionTree {

  };

  struct CallExpressionTree {

  };

  struct NullLiteralExpressionTree {

  };

  struct CompTimeUnaryPrefixExpressionTree {

  };

  struct SimpleTypeTree {

  };

  struct PointerTypeTree {

  };

  struct ArrayTypeTree {

  };

  struct FunctionTypeTree {

  };

  using AttributeSetType = variant<
    TranslationUnitTree,
    TopLevelStatementTree,
    NamespaceStatementTree,
    UsingStatementTree,
    FreeFunctionStatementTree,
    NativeFunctionStatementTree,
    StructStatementTree,
    PrintStatementTree,
    ReturnStatementTree,
    ExpressionStatementTree,
    IfStatementTree,
    ForStatementTree,
    WhileStatementTree,
    DeclarationStatementTree,
    DeferStatementTree,
    ScopeStatementTree,
    SyntacticalScopeTree,
    BasicBlockTree,
    TrailingBlockTree,
    MemberAccessExpressionTree,
    UnaryPostfixExpressionTree,
    FloatLiteralExpressionTree,
    NewExpressionTree,
    ArrayLiteralExpressionTree,
    ExplicitCastExpressionTree,
    IntLiteralExpressionTree,
    IdentifierExpressionTree,
    StringLiteralExpressionTree,
    BinaryExpressionTree,
    AssignmentExpressionTree,
    GroupingExpressionTree,
    UnaryPrefixExpressionTree,
    SubscriptExpressionTree,
    BoolLiteralExpressionTree,
    CharLiteralExpressionTree,
    CallExpressionTree,
    NullLiteralExpressionTree,
    CompTimeUnaryPrefixExpressionTree,
    SimpleTypeTree,
    PointerTypeTree,
    ArrayTypeTree,
    FunctionTypeTree
  >;

  struct SyntaxTree : public ant::ParserRuleContext {

    private:
    AttributeSetType M_attributes;

    private:
    SyntaxTree(ant::ParserRuleContext *parent, u64 invokingState);
    virtual ~SyntaxTree() override = default;

    public:
    template<class Attr>
    auto assign(Attr&& value) -> void;

    template<class Visitor>
    auto visit(Visitor&& visitor) -> void;
  };

}

#include <SyntaxTree.inl>