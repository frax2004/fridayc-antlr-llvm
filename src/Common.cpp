#include <Common.hpp>


namespace friday::inline core::rtti {
#if defined(__GNUC__) || defined(__clang__)
#include <cxxabi.h>
  String demangle(const char* name) noexcept {
    i32 status = -4;

    std::unique_ptr<char, void(*)(void*)> result {
      abi::__cxa_demangle(name, nullptr, nullptr, &status),
      std::free
    };

    return status == 0 ? result.get() : name;
  }
#else
  String demangle(const char* name) noexcept {
    return String{ name };
  }
#endif

  auto nameOf(std::type_info const& info) noexcept -> String {
    return demangle(info.name());
  }

}