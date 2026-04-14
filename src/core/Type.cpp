#include "core/Common.hpp"
namespace friday::inline core {


#if defined(__GNUC__) || defined(__clang__)
#include <cxxabi.h>
  static String demangle(const char* name) {
    i32 status = -4;

    std::unique_ptr<char, void(*)(void*)> result {
      abi::__cxa_demangle(name, nullptr, nullptr, &status),
      std::free
    };

    return status == 0 ? result.get() : name;
  }
#else
  static String demangle(const char* name) {
    return String{ name };
  }
#endif

Type::Type(const std::type_info& type) noexcept 
    : M_typeInfo { &type }
  {}

  auto Type::name() const noexcept -> String {
    return demangle(this->M_typeInfo->name());
  }

  auto Type::unwrap() const noexcept -> const std::type_info& {
    return *this->M_typeInfo;
  }

  auto Type::operator<=>(Type const& other) const noexcept -> std::strong_ordering {
    return std::type_index{ *this->M_typeInfo } <=> std::type_index{ *other.M_typeInfo };
  }

}