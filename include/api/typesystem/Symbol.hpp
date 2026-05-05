#pragma once

#include "core/Common.hpp"

namespace friday::inline api::inline typechecker {

  struct SymbolTable;
  

  /// @brief Represents an abstract symbol in the symbol table
  struct Symbol {
    static auto getDemangledId(String const& id) -> String;
    virtual auto getQualifiedId() const -> String = 0;
    virtual auto getFullQualifiedId() const -> String = 0;
    virtual auto getMangledId() const -> String = 0;
    virtual auto getDeclaringSymbolTable() -> SymbolTable* = 0;
    virtual auto getAttributes() const -> Attributes const& = 0;
  }; // struct Symbol
} // namespace friday::api::typesystem
