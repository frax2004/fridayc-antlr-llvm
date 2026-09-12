#pragma once
#include "Common.hpp"


namespace friday::inline api {

  struct Type  {
    constexpr Type() = default;
    constexpr virtual ~Type() = default;

    virtual auto get_name() const noexcept -> string_view = 0;
    virtual auto to_llvm_type() const noexcept -> llvm::Type* = 0;
    virtual auto to_llvm_abi_type() const noexcept -> llvm::Type*;
    auto size() const -> u64;
    auto alignment() const -> u64;

    static auto get_c_short_type() -> Type*;
    static auto get_c_int_type() -> Type*;
    static auto get_c_float_type() -> Type*;
    static auto get_int_type() -> Type*;
    static auto get_byte_type() -> Type*;
    static auto get_bool_type() -> Type*;
    static auto get_float_type() -> Type*;
    static auto get_voidptr_type() -> Type*;
    static auto get_byteptr_type() -> Type*;
    static auto get_void_type() -> Type*;
    static auto get_overload_type() -> Type*;
    static auto get_type_type() -> Type*;
    static auto get_namespace_type() -> Type*;

    auto is_convertible_to(Type* to) -> optional<llvm::Instruction::CastOps>;
    auto is_primitive_type() -> bool;
    auto is_integral_type() -> bool;
    auto is_floating_type() -> bool;
    auto is_slice_type() -> bool;
    auto is_pointer_type() -> bool;
    auto is_aggregate_type() -> bool;
    auto is_overload_type() -> bool;
    auto is_function_type() -> bool;
    auto is_type_type() -> bool;
    auto is_namespace_type() -> bool;
    auto is_error_type() -> bool;
  };
}
