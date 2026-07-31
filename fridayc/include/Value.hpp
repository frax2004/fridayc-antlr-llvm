#pragma once

#include <ValueCategory.hpp>
#include <llvm/IR/Value.h>

namespace friday::inline api::inline typesystem {

  struct ISymbol;
  struct Type;
  struct Struct;
  struct Namespace;
  struct Overload;

  struct FRIDAY_API Value final {
    private:
    struct FRIDAY_API unset final {
      consteval auto operator==(unset const&) const -> bool = default;
      consteval auto operator!=(unset const&) const -> bool = default;
    };

    private:
    using payload_type = variant<unset, Pointer<llvm::Value>, Overload*, Struct*, Namespace*>;

    public:
    enum Kind : u64 {
      UNSET = 0,
      VALUE,
      OVERLOAD,
      STRUCT,
      NAMESPACE,
    };

    static_assert(same_as<variant_alternative_t<Kind::UNSET, payload_type>, unset>);
    static_assert(same_as<variant_alternative_t<Kind::VALUE, payload_type>, Pointer<llvm::Value>>);
    static_assert(same_as<variant_alternative_t<Kind::OVERLOAD, payload_type>, Overload*>);
    static_assert(same_as<variant_alternative_t<Kind::STRUCT, payload_type>, Struct*>);
    static_assert(same_as<variant_alternative_t<Kind::NAMESPACE, payload_type>, Namespace*>);

    public:
    payload_type  M_payload  { unset{} };
    Type* M_type     { nullptr };
    ValueCategory M_category { ValueCategory::ILLEGAL };

    private:
    Value(Type* type, ValueCategory category, payload_type payload);

    public:
    Value(Value const&) = default;
    Value(Value &&) = default;
    ~Value() = default;

    auto operator=(Value const&) -> Value& = default;
    auto operator=(Value &&) -> Value& = default;
    auto operator==(Value const&) const -> bool = default;
    auto operator!=(Value const&) const -> bool = default;


    public:
    static auto error_value() -> Value;
    static auto from_symbol(ISymbol* symbol) -> Value;
    static auto from_namespace(Namespace* _namespace) -> Value;
    static auto from_value(Type* type, Pointer<llvm::Value> value) -> Value;
    static auto from_variable(Type* type, Pointer<llvm::Value> value) -> Value;
    static auto from_overload(Overload* overload) -> Value;
    static auto from_struct(Struct* _struct) -> Value;
    static auto from_unknown_value(
      Type* type, 
      ValueCategory category, 
      Pointer<llvm::Value> value
    ) -> Value;

    auto get_kind() const -> Kind;
    auto get_type() const -> Type*;
    auto get_category() const -> ValueCategory;

    auto is_llvm_value() const -> bool;
    auto is_overload() const -> bool;
    auto is_struct() const -> bool;
    auto is_namespace() const -> bool;

    auto to_llvm_value() const -> optional<Pointer<llvm::Value>>;
    auto to_overload() const -> optional<Overload*>;
    auto to_struct() const -> optional<Struct*>;
    auto to_namespace() const -> optional<Namespace*>;
    
  };
}