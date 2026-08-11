#pragma once
#include "Common.hpp"
#include "Value.hpp"
#include "BuiltinTypes.hpp"
#include <FridayParser.h>

namespace friday::inline api {

  struct Namespace;
  struct Scope;
  struct Function;
  struct Overload;
  struct TranslationUnit;

  /**
   * @brief Interface for a grammar attribute set
   */
  struct GrammarAttributes {

  public:
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

  struct TranslationUnitAttributes;
  struct TopLevelStatementAttributes;
  struct NamespaceStatementAttributes;
  struct UsingStatementAttributes;
  struct FunctionStatementAttributes;
  struct NativeFunctionStatementAttributes;
  struct FreeFunctionStatementAttributes;
  struct StructStatementAttributes;
  struct StatementAttributes;
  struct ScopeStatementAttributes;
  struct IfStatementAttributes;
  struct DeferStatementAttributes;
  struct ExpressionStatementAttributes;
  struct PrintStatementAttributes;
  struct ReturnStatementAttributes;
  struct WhileStatementAttributes;
  struct ForStatementAttributes;
  struct DeclarationStatementAttributes;
  struct SyntacticalScopeAttributes;
  struct FunctionScopeAttributes;
  struct TrailingBlockAttributes;
  struct BasicBlockAttributes;
  struct ExpressionAttributes;
  struct MemberAccessExpressionAttributes;
  struct UnaryPostfixExpressionAttributes;
  struct FloatLiteralExpressionAttributes;
  struct NewExpressionAttributes;
  struct ArrayLiteralExpressionAttributes;
  struct ExplicitCastExpressionAttributes;
  struct IntLiteralExpressionAttributes;
  struct IdentifierExpressionAttributes;
  struct StringLiteralExpressionAttributes;
  struct BinaryExpressionAttributes;
  struct AssignmentExpressionAttributes;
  struct GroupingExpressionAttributes;
  struct UnaryPrefixExpressionAttributes;
  struct SubscriptExpressionAttributes;
  struct BoolLiteralExpressionAttributes;
  struct CharLiteralExpressionAttributes;
  struct CallExpressionAttributes;
  struct NullLiteralExpressionAttributes;
  struct CompTimeUnaryPrefixExpressionAttributes;
  struct TypeAttributes;
  struct ArrayTypeAttributes;
  struct SimpleTypeAttributes;
  struct FunctionTypeAttributes;
  struct PointerTypeAttributes;

 struct TranslationUnitAttributes : public GrammarAttributes {
    TranslationUnit* translationUnit { nullptr };

  };

  struct TopLevelStatementAttributes : public GrammarAttributes {

  };

  struct NamespaceStatementAttributes : public GrammarAttributes {
    Namespace* namespace_ { nullptr };

  };

  struct UsingStatementAttributes : public GrammarAttributes {
    Namespace* namespace_ { nullptr };

  };

  struct FunctionStatementAttributes : public GrammarAttributes {
    llvm::Function* llvm_function { nullptr };
    Function*       function { nullptr };
    Overload*       overload { nullptr };
  };

  struct NativeFunctionStatementAttributes : public FunctionStatementAttributes {
  };

  struct FreeFunctionStatementAttributes : public FunctionStatementAttributes {
    FunctionScopeAttributes* scope { nullptr };

  };

  struct StructStatementAttributes : public GrammarAttributes {
    Struct*           struct_     { nullptr };
    llvm::StructType* llvm_struct { nullptr };
  };

  struct StatementAttributes : public GrammarAttributes {

  };

  struct ScopeStatementAttributes : public StatementAttributes {

  };

  struct IfStatementAttributes : public StatementAttributes {

  };

  struct DeferStatementAttributes : public StatementAttributes {

  };

  struct ExpressionStatementAttributes : public StatementAttributes {

  };

  struct PrintStatementAttributes : public StatementAttributes {

  };

  struct ReturnStatementAttributes : public StatementAttributes {

  };

  struct WhileStatementAttributes : public StatementAttributes {

  };

  struct ForStatementAttributes : public StatementAttributes {

  };

  struct DeclarationStatementAttributes : public StatementAttributes {

  };

  struct SyntacticalScopeAttributes : public GrammarAttributes {
    Scope* scope { nullptr };
  };

  struct FunctionScopeAttributes : public GrammarAttributes {
    FreeFunctionStatementAttributes* function { nullptr };
    Scope* scope { nullptr };
  };

  struct TrailingBlockAttributes : public FunctionScopeAttributes {

  };

  struct BasicBlockAttributes : public FunctionScopeAttributes {

  };

  struct ExpressionAttributes : public GrammarAttributes {
    Value value = Value::error_value();
  };

  struct MemberAccessExpressionAttributes : public ExpressionAttributes {

  };

  struct UnaryPostfixExpressionAttributes : public ExpressionAttributes {

  };

  struct FloatLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct NewExpressionAttributes : public ExpressionAttributes {

  };

  struct ArrayLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct ExplicitCastExpressionAttributes : public ExpressionAttributes {

  };

  struct IntLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct IdentifierExpressionAttributes : public ExpressionAttributes {

  };

  struct StringLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct BinaryExpressionAttributes : public ExpressionAttributes {

  };

  struct AssignmentExpressionAttributes : public ExpressionAttributes {

  };

  struct GroupingExpressionAttributes : public ExpressionAttributes {

  };

  struct UnaryPrefixExpressionAttributes : public ExpressionAttributes {

  };

  struct SubscriptExpressionAttributes : public ExpressionAttributes {

  };

  struct BoolLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct CharLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct CallExpressionAttributes : public ExpressionAttributes {

  };

  struct NullLiteralExpressionAttributes : public ExpressionAttributes {

  };

  struct CompTimeUnaryPrefixExpressionAttributes : public ExpressionAttributes {

  };

  struct TypeAttributes : public GrammarAttributes {
    Type* type = ErrorType::get();
  };

  struct ArrayTypeAttributes : public TypeAttributes {

  };

  struct SimpleTypeAttributes : public TypeAttributes {

  };

  struct FunctionTypeAttributes : public TypeAttributes {

  };

  struct PointerTypeAttributes : public TypeAttributes {

  };

  using ContextAttributeMap = TypeMap<
    TypeMapEntry<FridayParser::TranslationUnitContext, TranslationUnitAttributes>,
    TypeMapEntry<FridayParser::TopLevelStatementContext, TopLevelStatementAttributes>,
    TypeMapEntry<FridayParser::NamespaceStatementContext, NamespaceStatementAttributes>,
    TypeMapEntry<FridayParser::UsingStatementContext, UsingStatementAttributes>,
    TypeMapEntry<FridayParser::FunctionStatementContext, FunctionStatementAttributes>,
    TypeMapEntry<FridayParser::NativeFunctionStatementContext, NativeFunctionStatementAttributes>,
    TypeMapEntry<FridayParser::FreeFunctionStatementContext, FreeFunctionStatementAttributes>,
    TypeMapEntry<FridayParser::StructStatementContext, StructStatementAttributes>,
    TypeMapEntry<FridayParser::StatementContext, StatementAttributes>,
    TypeMapEntry<FridayParser::ScopeStatementContext, ScopeStatementAttributes>,
    TypeMapEntry<FridayParser::IfStatementContext, IfStatementAttributes>,
    TypeMapEntry<FridayParser::DeferStatementContext, DeferStatementAttributes>,
    TypeMapEntry<FridayParser::ExpressionStatementContext, ExpressionStatementAttributes>,
    TypeMapEntry<FridayParser::PrintStatementContext, PrintStatementAttributes>,
    TypeMapEntry<FridayParser::ReturnStatementContext, ReturnStatementAttributes>,
    TypeMapEntry<FridayParser::WhileStatementContext, WhileStatementAttributes>,
    TypeMapEntry<FridayParser::ForStatementContext, ForStatementAttributes>,
    TypeMapEntry<FridayParser::DeclarationStatementContext, DeclarationStatementAttributes>,
    TypeMapEntry<FridayParser::SyntacticalScopeContext, SyntacticalScopeAttributes>,
    TypeMapEntry<FridayParser::FunctionScopeContext, FunctionScopeAttributes>,
    TypeMapEntry<FridayParser::TrailingBlockContext, TrailingBlockAttributes>,
    TypeMapEntry<FridayParser::BasicBlockContext, BasicBlockAttributes>,
    TypeMapEntry<FridayParser::ExpressionContext, ExpressionAttributes>,
    TypeMapEntry<FridayParser::MemberAccessExpressionContext, MemberAccessExpressionAttributes>,
    TypeMapEntry<FridayParser::UnaryPostfixExpressionContext, UnaryPostfixExpressionAttributes>,
    TypeMapEntry<FridayParser::FloatLiteralExpressionContext, FloatLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::NewExpressionContext, NewExpressionAttributes>,
    TypeMapEntry<FridayParser::ArrayLiteralExpressionContext, ArrayLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::ExplicitCastExpressionContext, ExplicitCastExpressionAttributes>,
    TypeMapEntry<FridayParser::IntLiteralExpressionContext, IntLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::IdentifierExpressionContext, IdentifierExpressionAttributes>,
    TypeMapEntry<FridayParser::StringLiteralExpressionContext, StringLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::BinaryExpressionContext, BinaryExpressionAttributes>,
    TypeMapEntry<FridayParser::AssignmentExpressionContext, AssignmentExpressionAttributes>,
    TypeMapEntry<FridayParser::GroupingExpressionContext, GroupingExpressionAttributes>,
    TypeMapEntry<FridayParser::UnaryPrefixExpressionContext, UnaryPrefixExpressionAttributes>,
    TypeMapEntry<FridayParser::SubscriptExpressionContext, SubscriptExpressionAttributes>,
    TypeMapEntry<FridayParser::BoolLiteralExpressionContext, BoolLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::CharLiteralExpressionContext, CharLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::CallExpressionContext, CallExpressionAttributes>,
    TypeMapEntry<FridayParser::NullLiteralExpressionContext, NullLiteralExpressionAttributes>,
    TypeMapEntry<FridayParser::CompTimeUnaryPrefixExpressionContext, CompTimeUnaryPrefixExpressionAttributes>,
    TypeMapEntry<FridayParser::TypeContext, TypeAttributes>,
    TypeMapEntry<FridayParser::ArrayTypeContext, ArrayTypeAttributes>,
    TypeMapEntry<FridayParser::SimpleTypeContext, SimpleTypeAttributes>,
    TypeMapEntry<FridayParser::FunctionTypeContext, FunctionTypeAttributes>,
    TypeMapEntry<FridayParser::PointerTypeContext, PointerTypeAttributes>
  >;


  template<class Context>
  requires(ContextAttributeMap::contains<Context>)
  auto $(Context* ctx) -> ContextAttributeMap::at<Context>& {
    void* __ctx = dynamic_cast<void*>(ctx);
    using property_map = unordered_map<void*, unique_ptr<GrammarAttributes>>;
    using Attributes = ContextAttributeMap::at<Context>;
    extern property_map S_attributes;

    if(S_attributes.contains(__ctx)) {
      auto attributes = S_attributes.at(__ctx).get();
      auto actual = dynamic_cast<Attributes*>(attributes);
      if(actual == nullptr) {
        throw RuntimeError{
          format(
            "Bad attribute set query type '{}{}{}{}'. Context {}{}{}{} has attribute set of type '{}{}{}{}'",
            Console::Color::RED,
            Console::Color::BOLD,
            demangle(typeid(Attributes).name()),
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            __ctx,
            Console::Color::RESET,
            Console::Color::RED,
            Console::Color::BOLD,
            demangle(typeid(attributes).name()),
            Console::Color::RESET
          )
        };
      } else return *dynamic_cast<Attributes*>(actual);
    } else return *dynamic_cast<Attributes*>(
      S_attributes
      .emplace(
        __ctx, 
        unique_ptr<Attributes>(new Attributes{}))
      .first
      ->second
      .get()
    );
  }

}
