#pragma once

//* ////////////////////////////////////////////////////////////////

//* //////////////////////////
#include "Common.hpp"
//* //////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api {

  struct ISymbol;

  /**
   * @brief Symbol Table interface
   */
  struct ISymbolTable  {
  public:
    /**
     * @brief the type of the symbol container
     */
    using container_type = unordered_map<string, ISymbol*, transparent_string_hash, equal_to<>>;

  private:
    /**
     * @brief the symbol map
     */
    container_type M_symbols{};
    
  public:
    /**
     * @brief The type of a symbol filter predicate
     */
    using symbol_filter_type = function<bool (ISymbol*)>;

  protected:
    /**
     * @brief Default constructor
     */
    ISymbolTable() = default;

  public:
    /**
     * @brief Default destructor
     */
    virtual ~ISymbolTable() = default;

  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve(string_view id) const -> ISymbol*;

  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @param predicate a symbol filter
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve_if(string_view id, symbol_filter_type predicate) const -> ISymbol*;

  public:
    /**
     * @brief Finds the most similar symbol by edit distance on their qualified identifiers
     * @param name the qualified identifier searched
     * @param filter a filter predicate for the symbol
     * @param maxEditDistance the maximum edit distance allowed
     * @return the found symbol such that `predicate(symbol) == true` and `edist(name, symbol.name) <= maxEditDistance`
     */
    auto most_similar(string_view name, symbol_filter_type filter, u64 maxEditDistance = 0) const noexcept -> ISymbol*;

  public:
    /**
     * @brief Attempt to define a symbol in the symbol table by its qualified id
     * @param symbol reference to the symbol instance
     * @return `true` if the symbol is succesfully defined, that is, no other symbol with the same qualified id was previously defined
     */
    auto define(ISymbol* symbol) -> bool;

  public:
    /**
     * @brief Checks if a symbol is defined in this symbol table
     * @param id
     * @param predicate
     * @return `true` if a symbol `s` exists such that `s.id == id` and `predicate(s) == true`
     */
    auto is_defined(string_view id, symbol_filter_type predicate) const -> bool;

  public:
    /**
     * @brief Get the parent symbol table
     */
    virtual auto get_parent() const -> ISymbolTable* = 0;

  public:
    /**
     * @brief Get all the symbols defined in this symbol table
     */
    auto get_symbols() const -> vector<ISymbol*>;
  };

}

