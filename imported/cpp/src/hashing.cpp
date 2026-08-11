#include <cpp/hashing.hpp>

namespace cpp {
  auto transparent_string_hash::operator()(std::string_view s) const -> u64 {
    return std::hash<std::string_view>{}(s);
  }
  
  auto transparent_string_hash::operator()(std::string const& s) const -> u64 {
    return std::hash<std::string>{}(s);
  }
  
  auto transparent_string_hash::operator()(const i8* s) const -> u64 {
    return std::hash<std::string_view>{}(s);
  }
}
