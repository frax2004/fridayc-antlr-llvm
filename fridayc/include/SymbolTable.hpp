#pragma once

//* ////////////////////////////////////////////////////////////////

//* //////////////////////////
#include <Symbol.hpp>
//* //////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api::inline typesystem {

  /**
   * @brief Symbol Table interface
   */
  struct FRIDAY_API ISymbolTable : NonCopyable {
    
  public:
    /**
     * @brief The type of a symbol filter predicate
     */
    using symbol_filter_type = function<bool (ISymbol*)>;

  public:
    /**
     * @brief Default constructor
     */
    constexpr ISymbolTable() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr virtual ~ISymbolTable() override = default;

  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve(string_view id) const -> ISymbol* = 0;

  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @param predicate a symbol filter
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve_if(string_view id, symbol_filter_type predicate) const -> ISymbol* = 0;

  public:
    /**
     * @brief Finds the most similar symbol by edit distance on their qualified identifiers
     * @param name the qualified identifier searched
     * @param filter a filter predicate for the symbol
     * @param maxEditDistance the maximum edit distance allowed
     * @return the found symbol such that `predicate(symbol) == true` and `edist(name, symbol.name) <= maxEditDistance`
     */
    virtual auto most_similar(string_view name, symbol_filter_type filter, u64 maxEditDistance = 0) const noexcept -> ISymbol* = 0;

  public:
    /**
     * @brief Attempt to define a symbol in the symbol table by its qualified id
     * @param symbol reference to the symbol instance
     * @return `true` if the symbol is succesfully defined, that is, no other symbol with the same qualified id was previously defined
     */
    virtual auto define(ISymbol* symbol) -> bool = 0;

  public:
    /**
     * @brief Checks if a symbol is defined in this symbol table
     * @param id
     * @param predicate
     * @return `true` if a symbol `s` exists such that `s.id == id` and `predicate(s) == true`
     */
    virtual auto is_defined(string_view id, symbol_filter_type predicate) const -> bool = 0;

  public:
    /**
     * @brief Get the parent symbol table
     */
    virtual auto get_parent() const -> ISymbolTable* = 0;

  public:
    /**
     * @brief Get all the symbols defined in this symbol table
     */
    virtual auto get_symbols() const -> vector<ISymbol*> = 0;
  };


  /**
   * @brief Primary symbol table implementation
   */
  template<derived_from<ISymbol>... Ts>
  struct FRIDAY_API SymbolTable : ISymbolTable {

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
     * @brief Checks if the type of the symbol is one of the allowed types in the symbol table
     * @tparam ...Bases list of allowed types in the symbol table
     * @param object the symbol to check
     * @return `true` if the runtime type of the symbol is one of the allowed types
     */
    template<class... Bases>
    static auto assert_valid_type(ISymbol* object) -> bool;

  public:
    /**
     * @brief Default constructor
     */
    constexpr SymbolTable() = default;

  public:
    /**
     * @brief Default destructor
     */
    virtual ~SymbolTable() override = default;

  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve(string_view id) const -> ISymbol* override;
  
  public:
    /**
     * @brief Search a symbol in this symbol table
     * @param id the qualified id of the symbol
     * @param predicate a symbol filter
     * @return reference to the symbol or `nullptr`
     */
    virtual auto retrieve_if(string_view id, symbol_filter_type predicate) const -> ISymbol* override;

  public:
    /**
     * @brief Finds the most similar symbol by edit distance on their qualified identifiers
     * @param name the qualified identifier searched
     * @param filter a filter predicate for the symbol
     * @param maxEditDistance the maximum edit distance allowed
     * @return the found symbol such that `predicate(symbol) == true` and `edist(name, symbol.name) <= maxEditDistance`
     */
    virtual auto most_similar(string_view id, symbol_filter_type filter, u64 maxEditDistance = 0) const noexcept -> ISymbol* final override;

  public:
    /**
     * @brief Attempt to define a symbol in the symbol table by its qualified id
     * @param symbol reference to the symbol instance
     * @return `true` if the symbol is succesfully defined, that is, no other symbol with the same qualified id was previously defined
     */
    virtual auto define(ISymbol* symbol) -> bool final override;

  public:
    /**
     * @brief Checks if a symbol is defined in this symbol table
     * @param id
     * @param predicate
     * @return `true` if a symbol `s` exists such that `s.id == id` and `predicate(s) == true`
     */
    virtual auto is_defined(string_view id, symbol_filter_type predicate) const -> bool final override;

  public:
    /**
     * @brief Get all the symbols defined in this symbol table
     */
    virtual auto get_symbols() const -> vector<ISymbol*> final override;
  };
}

#include <SymbolTable.inl>
