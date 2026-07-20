#include <Core.hpp>


auto transparent_string_hash::operator()(string_view s) const -> u64 {
  return hash<string_view>{}(s);
}

auto transparent_string_hash::operator()(string const& s) const -> u64 {
  return hash<string>{}(s);
}

auto transparent_string_hash::operator()(const i8* s) const -> u64 {
  return hash<string_view>{}(s);
}

