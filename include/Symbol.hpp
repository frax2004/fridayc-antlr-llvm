#pragma once

#include <Common.hpp>
#include <Attributes.hpp>


namespace friday::inline api::inline typesystem {
  struct ISymbolTable;

  struct ISymbol {
    static auto getDemangledId(String const& id) -> String;

    virtual auto getMangledId() const -> String = 0;
    virtual auto getQualifiedId() const -> String = 0;
    virtual auto getFullQualifiedId() const -> String = 0;
    virtual auto getDeclaringSymbolTable() -> ISymbolTable* = 0;
    virtual auto getAttributes() const -> Attributes = 0;
  };
}
