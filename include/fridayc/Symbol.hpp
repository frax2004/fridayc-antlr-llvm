#pragma once

//* ////////////////////////////////////////////////////////////////

//* //////////////////////////
#include "Common.hpp"
//* //////////////////////////

//* //////////////////////////
#include "Metadata.hpp"
//* //////////////////////////

//* //////////////////////////
#include "NameMangler.hpp"
//* //////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api {

  /**
   * @brief Represents a set of symbols
   */
  struct ISymbolTable;

  /**
   * @brief Represents a symbol in a symbol table
   */
  struct ISymbol {
  public:
    /**
     * @brief Default Constructor
     */
    constexpr ISymbol() = default;

  public:
    /**
     * @brief Default destructor
     */
    constexpr virtual ~ISymbol() = default;

  public:
    /**
     * @brief Get the demangled identifier
     * @param id mangled identifier
     * @return demangled identifier
     */
    static auto get_demangled_id(string_view id) -> string;

  public:
    /**
     * @brief Get the type of the symbol
     */
    virtual auto get_type() const -> Type* = 0;

  public:
    /**
     * @brief Get the qualified id of the symbol
     */
    virtual auto get_qualified_id() const -> string = 0;

  public:
    /**
     * @brief Get the symbol table where the symbol was defined
     */
    virtual auto get_declaring_symbol_table() const -> ISymbolTable* = 0;

  public:
    /**
     * @brief Get the attributes of the symbol
     */
    virtual auto get_attributes() const -> Attributes = 0;

  public:
    /**
     * @brief Get the name mangler builder for this symbol
     */
    virtual auto get_mangled_name_builder() const -> NameMangler = 0;

  public:
    /**
     * @brief Get the mangled name of this symbol
     */
    auto get_mangled_id() const -> string;

  public:
    /**
     * @brief Get the full qualified identifier of this symbol
     */
    auto get_full_qualified_id() const -> string;
  };

}
