#include <fridayc.hpp>


namespace friday::inline api {
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::INTEGER), Constant::payload_type>, i64>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::FLOATING_POINT), Constant::payload_type>, f64>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BYTE), Constant::payload_type>, i8>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BOOLEAN), Constant::payload_type>, bool>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BYTE_POINTER), Constant::payload_type>, string>);
  static_assert(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::NULL_POINTER), Constant::payload_type>, nullptr_t>);

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

  auto Constant::to_llvm_constant() const -> llvm::Constant* {
    auto value_extractor = []<typename T>(T&& value) -> llvm::Constant* {
      using alternative_type = remove_cvref_t<decltype(value)>;

      if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::INTEGER), Constant::payload_type>, alternative_type>) {
        return llvm::ConstantInt::getSigned(LLVM.get_int_type(64), value);
      } else if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::FLOATING_POINT), Constant::payload_type>, alternative_type>) {
        return llvm::ConstantFP::get(LLVM.get_double_type(), value);
      } else if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BYTE), Constant::payload_type>, alternative_type>) {
        return llvm::ConstantInt::get(LLVM.get_int_type(8), value);
      } else if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BOOLEAN), Constant::payload_type>, alternative_type>) {
        return llvm::ConstantInt::getBool(LLVM.get_int_type(1), value);
      } else if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::BYTE_POINTER), Constant::payload_type>, alternative_type>) {
        return LLVM.builder().CreateGlobalString(value, "", 0, &LLVM.module());
      } else if constexpr(same_as<variant_alternative_t<static_cast<underlying_type_t<Constant::Kind>>(Constant::Kind::NULL_POINTER), Constant::payload_type>, alternative_type>) {
        return llvm::Constant::getNullValue(LLVM.get_void_type());
      } else throw RuntimeError{"Internal Error"};
    };

    return visit(value_extractor, this->M_payload);
  }
}