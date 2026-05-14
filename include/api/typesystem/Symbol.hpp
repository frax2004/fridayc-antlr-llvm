#pragma once

#include "Attributes.hpp"
#include "core/Common.hpp"

namespace friday::inline api::inline typesystem {

  struct SymbolTable;
  
  /// @brief Represents an abstract symbol in the symbol table
  struct Symbol {
    /// @brief Get the demangled identifier for a symbol
    /// @param id the mangled identifier
    /// @return the demangled identifier
    static auto getDemangledId(String const& id) -> String;

    /// @brief Get the qualified id
    /// @return the qualified id
    virtual auto getQualifiedId() const -> String = 0;
    /// @brief Get the full qualified id
    /// @return the full qualified id
    virtual auto getFullQualifiedId() const -> String = 0;
    /// @brief Get the mangled id
    /// @return the mangled id
    virtual auto getMangledId() const -> String = 0;
    /// @brief Get the declaring symbol table
    /// @return the declaring symbol table
    virtual auto getDeclaringSymbolTable() -> SymbolTable* = 0;
    /// @brief Get the attributes for this symbol
    /// @return the attributes for this symbol
    virtual auto getAttributes() const -> Attributes const& = 0;
  }; // struct Symbol
} // namespace friday::api::typesystem
