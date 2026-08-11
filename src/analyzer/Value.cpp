#include <fridayc.hpp>

namespace friday::inline api {
  
  Constant::Constant(payload_type payload) noexcept 
    : M_payload { payload }  
  {}

  auto Constant::from_int(i64 value) noexcept -> Constant {
    return Constant{ value };
  }

  auto Constant::from_float(f64 value) noexcept -> Constant {
    return Constant{ value };
  }

  auto Constant::from_byte(i8 value) noexcept -> Constant {
    return Constant{ value };
  }

  auto Constant::from_bool(bool value) noexcept -> Constant {
    return Constant{ value };
  }

  auto Constant::from_str(string value) noexcept -> Constant {
    return Constant{ value };
  }

  auto Constant::from_null() noexcept -> Constant {
    return Constant{ nullptr };
  }

  auto Constant::get_kind() const noexcept -> Kind {
    return static_cast<Constant::Kind>(static_cast<underlying_type_t<Constant::Kind>>(this->M_payload.index()));
  }

  auto Constant::is_int() const noexcept -> bool {
    return holds_alternative<i64>(this->M_payload);
  }

  auto Constant::is_float() const noexcept -> bool {
    return holds_alternative<f64>(this->M_payload);
  }

  auto Constant::is_byte() const noexcept -> bool {
    return holds_alternative<i8>(this->M_payload);
  }

  auto Constant::is_bool() const noexcept -> bool {
    return holds_alternative<bool>(this->M_payload);
  }

  auto Constant::is_str() const noexcept -> bool {
    return holds_alternative<string>(this->M_payload);
  }

  auto Constant::is_null() const noexcept -> bool {
    return holds_alternative<nullptr_t>(this->M_payload);
  }

  auto Constant::to_int() const -> optional<i64> {
    return this->is_int() ? make_optional(get<i64>(this->M_payload)) : nullopt;
  }

  auto Constant::to_float() const -> optional<f64> {
    return this->is_float() ? make_optional(get<f64>(this->M_payload)) : nullopt;
  }

  auto Constant::to_byte() const -> optional<i8> {
    return this->is_byte() ? make_optional(get<i8>(this->M_payload)) : nullopt;
  }

  auto Constant::to_bool() const -> optional<bool> {
    return this->is_bool() ? make_optional(get<bool>(this->M_payload)) : nullopt;
  }

  auto Constant::to_str() const -> optional<string> {
    return this->is_str() ? make_optional(get<string>(this->M_payload)) : nullopt;
  }

  auto Constant::to_null() const -> optional<nullptr_t> {
    return this->is_null() ? make_optional(get<nullptr_t>(this->M_payload)) : nullopt;
  }

  
  Value::Value(Type* type, ValueCategory category, payload_type payload)
    : M_payload { payload }
    , M_type { type }
    , M_category { category }
  {}

  auto Value::from_namespace(Namespace* _namespace) -> Value {
    return Value {
      NamespaceType::get(),
      ValueCategory::RVALUE,
      _namespace
    };
  }

  auto Value::from_struct(Struct* _struct) -> Value {
    return Value {
      TypeType::get(),
      ValueCategory::RVALUE,
      _struct
    };
  }
  
  auto Value::from_unknown(Type* type, ValueCategory category) -> Value {
    return Value{
      category != ValueCategory::ILLEGAL ? type : ErrorType::get(),
      category,
      Constant::from_null()
    };
  }

  auto Value::from_rvalue(Type* type, llvm::Value* value) -> Value {
    return Value{
      type,
      ValueCategory::RVALUE,
      value
    };
  }

  auto Value::from_lvalue(Type* type, llvm::Value* value) -> Value {
    return Value{
      type,
      ValueCategory::LVALUE,
      value
    };
  }

  auto Value::from_constant(Type* type, Constant value) -> Value {
    return Value{
      type,
      ValueCategory::RVALUE,
      value
    };
  }

  auto Value::from_overload(Overload* overload) -> Value {
    return Value{
      UnresolvedOverloadType::get(),
      ValueCategory::RVALUE,
      overload
    };
  }
  
  auto Value::from_symbol(ISymbol* symbol) -> Value {
    if(symbol == nullptr) return Value::error_value();

    if(auto asVar = Variable::to_variable(symbol)) {
      return Value::from_lvalue(asVar->get_type(), nullptr);
    } else if(Overload::is_overload(symbol)) {
      return Value::from_overload(Overload::to_overload(symbol));
    } else if(Struct::is_struct(symbol)) {
      return Value::from_struct(Struct::to_struct(symbol));
    } else if(Namespace::is_namespace(symbol)) {
      return Value::from_namespace(Namespace::to_namespace(symbol));
    } else return Value::error_value();
  }

  auto Value::error_value() -> Value {
    return Value{
      ErrorType::get(),
      ValueCategory::ILLEGAL,
      unset{}
    };
  }

  auto Value::get_kind() const -> Value::Kind {
    return static_cast<Value::Kind>(static_cast<underlying_type_t<Value::Kind>>(this->M_payload.index()));
  }

  auto Value::get_type() const -> Type* {
    return this->M_type;
  }

  auto Value::get_category() const -> ValueCategory {
    return this->M_category;
  }

  auto Value::is_lvalue() const -> bool {
    return holds_alternative<llvm::Value*>(this->M_payload) and this->get_category() == ValueCategory::LVALUE;
  }

  auto Value::is_rvalue() const -> bool {
    return holds_alternative<llvm::Value*>(this->M_payload);
  }

  auto Value::is_constant() const -> bool {
    return holds_alternative<Constant>(this->M_payload);
  }

  auto Value::is_overload() const -> bool {
    return holds_alternative<Overload*>(this->M_payload);
  }

  auto Value::is_struct() const -> bool {
    return holds_alternative<Struct*>(this->M_payload);
  }

  auto Value::is_namespace() const -> bool {
    return holds_alternative<Namespace*>(this->M_payload);
  }
  
  auto Value::to_lvalue() const -> optional<llvm::Value*> {
    return this->is_lvalue() ? make_optional(get<llvm::Value*>(this->M_payload)) : nullopt;
  }

  auto Value::to_rvalue() const -> optional<llvm::Value*> {
    return this->is_rvalue() ? make_optional(get<llvm::Value*>(this->M_payload)) : nullopt;
  }

  auto Value::to_constant() const -> optional<Constant> {
    return this->is_constant() ? make_optional(get<Constant>(this->M_payload)) : nullopt;
  }

  auto Value::to_overload() const -> optional<Overload*> {
    return this->is_overload() ? make_optional(get<Overload*>(this->M_payload)) : nullopt;
  }

  auto Value::to_struct() const -> optional<Struct*> {
    return this->is_struct() ? make_optional(get<Struct*>(this->M_payload)) : nullopt;
  }

  auto Value::to_namespace() const -> optional<Namespace*> {
    return this->is_namespace() ? make_optional(get<Namespace*>(this->M_payload)) : nullopt;
  }

}