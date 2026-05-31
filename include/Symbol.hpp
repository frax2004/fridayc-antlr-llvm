#pragma once

#include <Common.hpp>
#include <Attributes.hpp>


namespace friday::inline api::inline typesystem {
  struct ISymbolTable;

  struct ISymbol {
    static auto getDemangledId(string const& id) -> string;

    virtual auto getMangledId() const -> string = 0;
    virtual auto getQualifiedId() const -> string = 0;
    virtual auto getFullQualifiedId() const -> string = 0;
    virtual auto getDeclaringSymbolTable() -> ISymbolTable* = 0;
    virtual auto getAttributes() const -> Attributes = 0;
  };
}
