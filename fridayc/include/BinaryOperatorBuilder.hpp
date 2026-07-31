#pragma once

#include <Overload.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {

  /**
   * @brief Builder for binary operators
   */
  struct FRIDAY_API BinaryOperatorBuilder final : Builder<Overload*> {

  private:
    /**
     * @brief the name of the operator
     */
    string M_name { "" };

  private:
    /**
     * @brief the type of the left operand
     */
    Type* M_lhs { nullptr };

  private:
    /**
     * @brief the type of the right operand
     */
    Type* M_rhs { nullptr };

  private:
    /**
     * @brief the result type
     */
    Type* M_ret { nullptr };

  private:
    /**
     * @brief the parent symbol table
     */
    ISymbolTable* M_parent { nullptr };

  public:
    /**
     * @brief Construct a binary operator builder
     * @param name the operator name
     */
    BinaryOperatorBuilder(string name);

  public:
    /**
     * @brief Default copy constructor
     */
    BinaryOperatorBuilder(BinaryOperatorBuilder const&) = default;

  public:
    /**
     * @brief Default move constructor
     */
    BinaryOperatorBuilder(BinaryOperatorBuilder &&) = default;

  public:
    /**
     * @brief Default destructor
     */
    ~BinaryOperatorBuilder() override = default;

  public:
    /**
     * @brief Default copy assignment operator
     */
    auto operator=(BinaryOperatorBuilder const&) -> BinaryOperatorBuilder& = default;

  public:
    /**
     * @brief Default move assignment operator
     */
    auto operator=(BinaryOperatorBuilder &&) -> BinaryOperatorBuilder& = default;

  public:
    /**
     * @brief Set the parent symbol table
     * @param parent the parent symbol table
     * @return reference to this object for chaining
     */
    auto within(ISymbolTable& parent) -> BinaryOperatorBuilder&;

  public:
    /**
     * @brief Set left operand type
     * @param type the left operand type
     * @return reference to this object for chaining
     */
    auto left(Type& type) -> BinaryOperatorBuilder&;

  public:
    /**
     * @brief Set right operand type
     * @param type the right operand type
     * @return reference to this object for chaining
     */
    auto right(Type& type) -> BinaryOperatorBuilder&;

  public:
    /**
     * @brief Set return type
     * @param type the return type
     * @return reference to this object for chaining
     */
    auto returns(Type& type) -> BinaryOperatorBuilder&;

  public:
    /**
     * @brief Builds the operator
     * @return reference to the built operator
     */
    auto build() -> Overload* override;
  };
}