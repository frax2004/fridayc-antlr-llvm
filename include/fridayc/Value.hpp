#pragma once
#include "Common.hpp"


namespace friday::inline api {

  struct ISymbol;
  struct Type;
  struct Struct;
  struct Namespace;
  struct Overload;
  struct Variable;
  
  struct unset final {
    consteval auto operator==(unset const&) const -> bool = default;
    consteval auto operator!=(unset const&) const -> bool = default;
  };

  enum class ValueCategory : u8 {
    ILLEGAL,
    LVALUE,
    RVALUE
  };

  struct Constant final {
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
    using payload_type = variant<i64, f64, i8, bool, string, nullptr_t>;

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
    
    auto to_llvm_constant() const -> llvm::Constant*;
  };
  
  struct Value final {
  public:
    enum class Kind : u8 {
      UNSET = 0,
      LLVMVALUE,
      VARIABLE,
      CONSTANT,
      OVERLOAD,
      STRUCT,
      NAMESPACE,
    };
    using payload_type = variant<
      unset, 
      llvm::Value*, 
      pair<Variable*, llvm::Value*>, 
      Constant, 
      Overload*, 
      Struct*, 
      Namespace*
    >;
    using enum Kind;

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
    static auto from_lvalue(Type* type, Variable* variable, llvm::Value* value) -> Value;
    static auto from_overload(Overload* overload) -> Value;
    static auto from_struct(Struct* _struct) -> Value;
    static auto from_field(Variable* field, ValueCategory category) -> Value;
    static auto from_unknown(Type* type, ValueCategory category) -> Value;

    auto kind() const -> Kind;
    auto type() const -> Type*;
    auto category() const -> ValueCategory;

    auto to_llvm_value() const -> llvm::Value*;
    auto is(ValueCategory category) const -> bool;
    auto holds(Kind kind) const -> bool;

    template<class T>
    auto unwrap() -> optional<T> {
      return holds_alternative<T>(this->M_payload) ? 
        make_optional(get<T>(this->M_payload)) : nullopt;
    }
  };
}