#include <fridayc.hpp>


namespace friday::inline api {
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::UNSET), Value::payload_type>, unset>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::LLVMVALUE), Value::payload_type>, llvm::Value*>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::VARIABLE), Value::payload_type>, pair<Variable*, llvm::Value*>>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::CONSTANT), Value::payload_type>, Constant>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::OVERLOAD), Value::payload_type>, Overload*>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::STRUCT), Value::payload_type>, Struct*>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::NAMESPACE), Value::payload_type>, Namespace*>);
  
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

  auto Value::from_lvalue(Type* type, Variable* variable, llvm::Value* value) -> Value {
    return Value{
      type,
      ValueCategory::LVALUE,
      make_pair(variable, value)
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

  auto Value::from_field(Variable* field, ValueCategory category) -> Value {
    return Value {
      field->get_type(),
      category,
      pair<Variable*, llvm::Value*>(field, nullptr)
    };
  }

  auto Value::from_symbol(ISymbol* symbol) -> Value {
    if(symbol == nullptr) return Value::error_value();

    if(auto asVar = Variable::to_variable(symbol)) {
      return Value::from_lvalue(asVar->get_type(), Variable::to_variable(symbol), nullptr);
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

  auto Value::kind() const -> Value::Kind {
    return static_cast<Value::Kind>(static_cast<underlying_type_t<Value::Kind>>(this->M_payload.index()));
  }

  auto Value::type() const -> Type* {
    return this->M_type;
  }

  auto Value::category() const -> ValueCategory {
    return this->M_category;
  }
  
  auto Value::is(ValueCategory category) const -> bool {
    return this->category() == category;
  }

  auto Value::holds(Kind kind) const -> bool {
    return this->M_payload.index() == static_cast<u64>(to_underlying(kind));
  }

  auto Value::to_llvm_value() const -> llvm::Value* {
    auto value_extractor = []<typename T>(T&& payload) -> llvm::Value* {
      using alternative_type = remove_cvref_t<decltype(payload)>;

      if constexpr (same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::LLVMVALUE), Value::payload_type>, alternative_type>) {
        return llvm::cast<llvm::Value>(payload);
      } else if constexpr (same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::VARIABLE), Value::payload_type>, alternative_type>) {
        return llvm::cast<llvm::Value>(payload.second);
      } else if constexpr (same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::CONSTANT), Value::payload_type>, alternative_type>) {
        return llvm::cast<llvm::Value>(payload.to_llvm_constant());
      } else if constexpr (same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::STRUCT), Value::payload_type>, alternative_type>) {
        return llvm::cast<llvm::Value>(Reflection::reflect_type(dynamic_cast<Type*>(payload)));
      } else if constexpr (same_as<variant_alternative_t<static_cast<underlying_type_t<Value::Kind>>(Value::Kind::NAMESPACE), Value::payload_type>, alternative_type>) {
        return llvm::cast<llvm::Value>(Reflection::reflect_namespace(payload));
      } else throw RuntimeError{"Internal Error."};
    };

    return visit(value_extractor, this->M_payload);
  }

}