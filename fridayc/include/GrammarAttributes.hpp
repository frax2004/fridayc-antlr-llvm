#pragma once

//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <Common.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <Namespace.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <Scope.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <Value.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <PolymorphicFactory.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api::inline pipeline {

  /**
   * @brief Interface for a grammar attribute set
   */
  struct FRIDAY_API GrammarAttributes {

  public:
    friend struct PolymorphicFactory<GrammarAttributes>;
    using Factory = PolymorphicFactory<GrammarAttributes>;

  protected:
    /**
     * @brief Default constructor
     */
    constexpr GrammarAttributes() noexcept = default;

  protected:
    /**
     * @brief Default copy constructor
     */
    constexpr GrammarAttributes(GrammarAttributes const&) noexcept = default;

  protected:
    /**
     * @brief Default move constructor
     */
    constexpr GrammarAttributes(GrammarAttributes &&) noexcept = default;

  protected:
    /**
     * @brief Default copy assignment operator
     */
    constexpr auto operator=(GrammarAttributes const&) noexcept -> GrammarAttributes& = default;

  protected:
    /**
     * @brief Default move assignment operator
     */
    constexpr auto operator=(GrammarAttributes &&) noexcept -> GrammarAttributes& = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr virtual ~GrammarAttributes() noexcept = default;
  };

  /**
   * @brief Grammar attribute set for a TranslationUnitContext instance
   */
  struct TranslationUnitAttributes final : GrammarAttributes {
    TranslationUnit* translationUnit { nullptr };
  };

  /**
   * @brief Grammar attribute set for a TopLevelStatementContext instance
   */
  struct TopLevelStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a NamespaceStatementContext instance
   */
  struct NamespaceStatementAttributes final : GrammarAttributes {
    Namespace* namespace_ { nullptr };
  };

  /**
   * @brief Grammar attribute set for a UsingStatementContext instance
   */
  struct UsingStatementAttributes final : GrammarAttributes {
    Namespace* namespace_ { nullptr };
  };

  /**
   * @brief Grammar attribute set for a FreeFunctionStatementContext instance
   */
  struct FreeFunctionStatementAttributes final : GrammarAttributes {
    Scope*    scope    { nullptr };
    Function* function { nullptr };
    Overload* overload { nullptr };
  };

  /**
   * @brief Grammar attribute set for a NativeFunctionStatementContext instance
   */
  struct NativeFunctionStatementAttributes final : GrammarAttributes {
    Function* function { nullptr };
    Overload* overload { nullptr };
  };

  /**
   * @brief Grammar attribute set for a StructStatementContext instance
   */
  struct StructStatementAttributes final : GrammarAttributes {
    Struct* struct_ { nullptr };
  };

  /**
   * @brief Grammar attribute set for a PrintStatementContext instance
   */
  struct PrintStatementAttributes final : GrammarAttributes {
    
  };

  /**
   * @brief Grammar attribute set for a ReturnStatementContext instance
   */
  struct ReturnStatementAttributes final : GrammarAttributes {
    
  };

  /**
   * @brief Grammar attribute set for a ExpressionStatementContext instance
   */
  struct ExpressionStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a IfStatementContext instance
   */
  struct IfStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a ForStatementContext instance
   */
  struct ForStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a WhileStatementContext instance
   */
  struct WhileStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a DeclarationStatementContext instance
   */
  struct DeclarationStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a DeferStatementContext instance
   */
  struct DeferStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a ScopeStatementContext instance
   */
  struct ScopeStatementAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a SyntacticalScopeContext instance
   */
  struct SyntacticalScopeAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a BasicBlockContext instance
   */
  struct BasicBlockAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a TrailingBlockContext instance
   */
  struct TrailingBlockAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a MemberAccessExpressionContext instance
   */
  struct MemberAccessExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a UnaryPostfixExpressionContext instance
   */
  struct UnaryPostfixExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a FloatLiteralExpressionContext instance
   */
  struct FloatLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a NewExpressionContext instance
   */
  struct NewExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a ArrayLiteralExpressionContext instance
   */
  struct ArrayLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a ExplicitCastExpressionContext instance
   */
  struct ExplicitCastExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a IntLiteralExpressionContext instance
   */
  struct IntLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a IdentifierExpressionContext instance
   */
  struct IdentifierExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a StringLiteralExpressionContext instance
   */
  struct StringLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a BinaryExpressionContext instance
   */
  struct BinaryExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a AssignmentExpressionContext instance
   */
  struct AssignmentExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a GroupingExpressionContext instance
   */
  struct GroupingExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a UnaryPrefixExpressionContext instance
   */
  struct UnaryPrefixExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a SubscriptExpressionContext instance
   */
  struct SubscriptExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a BoolLiteralExpressionContext instance
   */
  struct BoolLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a CharLiteralExpressionContext instance
   */
  struct CharLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a CallExpressionContext instance
   */
  struct CallExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a NullLiteralExpressionContext instance
   */
  struct NullLiteralExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a CompTimeUnaryPrefixExpressionContext instance
   */
  struct CompTimeUnaryPrefixExpressionAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a SimpleTypeContext instance
   */
  struct SimpleTypeAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a PointerTypeContext instance
   */
  struct PointerTypeAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a ArrayTypeContext instance
   */
  struct ArrayTypeAttributes final : GrammarAttributes {

  };

  /**
   * @brief Grammar attribute set for a FunctionTypeContext instance
   */
  struct FunctionTypeAttributes final : GrammarAttributes {

  };

}
