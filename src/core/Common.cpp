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

  namespace rtti {
    auto nameOf(std::type_info const& info) noexcept -> String {
      return demangle(info.name());
    }
  }

}