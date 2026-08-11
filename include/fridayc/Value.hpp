#pragma once
#include "Common.hpp"


namespace friday::inline api {

  struct ISymbol;
  struct Type;
  struct Struct;
  struct Namespace;
  struct Overload;
  
  enum class ValueCategory : u8 {
    ILLEGAL,
    LVALUE,
    RVALUE
  };


  struct Constant final {
  private:
    using payload_type = variant<i64, f64, i8, bool, string, nullptr_t>;

    
  public:
    enum class Kind : u8 {
      INTEGER,
      FLOATING_POINT,
      BYTE,
      BOOLEAN,
      BYTE_POINTER,
      NULL_POINTER,
    };
    
    using enum Kind;
    
  private:
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::INTEGER), payload_type>, i64>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::FLOATING_POINT), payload_type>, f64>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::BYTE), payload_type>, i8>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::BOOLEAN), payload_type>, bool>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::BYTE_POINTER), payload_type>, string>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::NULL_POINTER), payload_type>, nullptr_t>);

  private:
    payload_type M_payload { };
  
  private:
    Constant(payload_type payload) noexcept;

  public:
    static auto from_int(i64 value) noexcept -> Constant;
    static auto from_float(f64 value) noexcept -> Constant;
    static auto from_byte(i8 value) noexcept -> Constant;
    static auto from_bool(bool value) noexcept -> Constant;
    static auto from_str(string value) noexcept -> Constant;
    static auto from_null() noexcept -> Constant;

    auto get_kind() const noexcept -> Kind;

    auto is_int() const noexcept -> bool;
    auto is_float() const noexcept -> bool;
    auto is_byte() const noexcept -> bool;
    auto is_bool() const noexcept -> bool;
    auto is_str() const noexcept -> bool;
    auto is_null() const noexcept -> bool;

    auto to_int() const -> optional<i64>;
    auto to_float() const -> optional<f64>;
    auto to_byte() const -> optional<i8>;
    auto to_bool() const -> optional<bool>;
    auto to_str() const -> optional<string>;
    auto to_null() const -> optional<nullptr_t>;
  };
  
  struct Value final {
  private:
    struct unset final {
      consteval auto operator==(unset const&) const -> bool = default;
      consteval auto operator!=(unset const&) const -> bool = default;
    };
    
  private:
    using payload_type = variant<unset, llvm::Value*, Constant, Overload*, Struct*, Namespace*>;
    
  public:
    enum class Kind : u8 {
      UNSET = 0,
      LLVMVALUE,
      CONSTANT,
      OVERLOAD,
      STRUCT,
      NAMESPACE,
    };

    using enum Kind;

    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::UNSET), payload_type>, unset>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::LLVMVALUE), payload_type>, llvm::Value*>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::CONSTANT), payload_type>, Constant>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::OVERLOAD), payload_type>, Overload*>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::STRUCT), payload_type>, Struct*>);
    static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Kind>>(Kind::NAMESPACE), payload_type>, Namespace*>);

  private:
    payload_type  M_payload  { unset{} };
    Type*         M_type     { nullptr };
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
    static auto from_constant(Type* type, Constant value) -> Value;
    static auto from_rvalue(Type* type, llvm::Value* value) -> Value;
    static auto from_lvalue(Type* type, llvm::Value* value) -> Value;
    static auto from_overload(Overload* overload) -> Value;
    static auto from_struct(Struct* _struct) -> Value;
    static auto from_unknown(Type* type, ValueCategory category) -> Value;

    auto get_kind() const -> Kind;
    auto get_type() const -> Type*;
    auto get_category() const -> ValueCategory;

    auto is_lvalue() const -> bool;
    auto is_rvalue() const -> bool;
    auto is_constant() const -> bool;
    auto is_overload() const -> bool;
    auto is_struct() const -> bool;
    auto is_namespace() const -> bool;

    auto to_lvalue() const -> optional<llvm::Value*>;
    auto to_rvalue() const -> optional<llvm::Value*>;
    auto to_constant() const -> optional<Constant>;
    auto to_overload() const -> optional<Overload*>;
    auto to_struct() const -> optional<Struct*>;
    auto to_namespace() const -> optional<Namespace*>;
    
  };
}