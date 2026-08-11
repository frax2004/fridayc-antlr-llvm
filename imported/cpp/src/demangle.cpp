#include <cpp/demangle.hpp>
#include <cpp/primitives.hpp>

#include <memory>

namespace cpp {
#if defined(__GNUC__) || defined(__clang__)
#include <cxxabi.h>
  std::string demangle(const char* name) noexcept {
    i32 status = -4;

    std::unique_ptr<char, void(*)(void*)> result {
      abi::__cxa_demangle(name, nullptr, nullptr, &status),
      free
    };

    return status == 0 ? result.get() : name;
  }
#else
  std::string demangle(const char* name) noexcept {
    return std::string{ name };
  }
#endif
}