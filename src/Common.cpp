#include <Common.hpp>


namespace friday::inline core::rtti {
#if defined(__GNUC__) || defined(__clang__)
#include <cxxabi.h>
  string demangle(const char* name) noexcept {
    i32 status = -4;

    unique_ptr<char, void(*)(void*)> result {
      abi::__cxa_demangle(name, nullptr, nullptr, &status),
      free
    };

    return status == 0 ? result.get() : name;
  }
#else
  string demangle(const char* name) noexcept {
    return string{ name };
  }
#endif

  auto nameOf(type_info const& info) noexcept -> string {
    return demangle(info.name());
  }

}