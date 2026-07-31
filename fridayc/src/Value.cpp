#include <Value.hpp>
#include <UnresolvedOverloadType.hpp>
#include <TypeType.hpp>
#include <NamespaceType.hpp>
#include <Struct.hpp>
#include <Overload.hpp>
#include <ErrorType.hpp>
#include <Namespace.hpp>

namespace friday::inline api::inline typesystem {
  
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
  
  auto Value::from_unknown_value(Type* type, ValueCategory category, Pointer<llvm::Value> value) -> Value {
    return Value{
      category != ValueCategory::ILLEGAL ? type : ErrorType::get(),
      category,
      value
    };
  }

  auto Value::from_value(Type* type, Pointer<llvm::Value> value) -> Value {
    return Value{
      type,
      ValueCategory::RVALUE,
      value      
    };
  }

  auto Value::from_variable(Type* type, Pointer<llvm::Value> value) -> Value {
    return Value{
      type, 
      ValueCategory::LVALUE,
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
    if(symbol.expired()) return Value::error_value();

    ISymbol* ref = symbol.lock();

    if(auto asVar = Variable::to_variable(ref.get())) {
      return Value::from_variable(asVar->get_type(), nullptr);
    } else if(Overload::is_overload(ref.get())) {
      return Value::from_overload(dynamic_pointer_cast<Overload>(ref));
    } else if(Struct::is_struct(ref.get())) {
      return Value::from_struct(dynamic_pointer_cast<Struct>(ref));
    } else if(Namespace::is_namespace(ref.get())) {
      return Value::from_namespace(dynamic_pointer_cast<Namespace>(ref));
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
    return static_cast<Value::Kind>(this->M_payload.index());
  }

  auto Value::get_type() const -> Type* {
    return this->M_type;
  }

  auto Value::get_category() const -> ValueCategory {
    return this->M_category;
  }

  auto Value::is_llvm_value() const -> bool {
    return holds_alternative<Pointer<llvm::Value>>(this->M_payload);
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

  auto Value::to_llvm_value() const -> optional<Pointer<llvm::Value>> {
    return this->is_llvm_value() ? make_optional(get<Pointer<llvm::Value>>(this->M_payload)) : nullopt;
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