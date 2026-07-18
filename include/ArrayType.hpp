#pragma once

#include <Struct.hpp>

namespace friday::inline api::inline typesystem {

  struct FRIDAY_API ArrayType final : Struct {

    private:
    ArrayType(Namespace& global, Type& elementType, string name) noexcept;

    public:
    ~ArrayType() override = default;

    public:
    static auto get(Namespace& global, Type& elementType) noexcept -> Pointer<Type>;

    auto get_element_type() const noexcept -> Pointer<Type>;

    static auto to_array(Pointer<Type> type) -> Pointer<ArrayType>;
    static auto is_array(Pointer<Type> type) -> bool;
  };
}

