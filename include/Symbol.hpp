#pragma once

#include <Common.hpp>
#include <Attributes.hpp>
#include <MangledNameBuilder.hpp>

namespace friday::inline api::inline typesystem {
  struct ISymbolTable;

  struct FRIDAY_API ISymbol : NonCopyable {
    constexpr ISymbol() = default;
    virtual ~ISymbol() override = default;

    static auto get_demangled_id(string_view id) -> string;

    virtual auto get_qualified_id() const -> string = 0;
    virtual auto get_declaring_symbol_table() const -> Pointer<ISymbolTable> = 0;
    virtual auto get_attributes() const -> Attributes = 0;
    virtual auto get_mangled_name_builder() const -> MangledNameBuilder = 0;
    virtual auto get_mangled_id() const -> string final;
    virtual auto get_full_qualified_id() const -> string final;
  };
}
