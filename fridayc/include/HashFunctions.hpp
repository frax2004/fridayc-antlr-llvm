#pragma once

#include <Core.hpp>
#include <Pointer.hpp>


/**
 * @brief Hash combine for a std::vector of raw pointers
 * @tparam T the pointed type
 */
template<class T>
struct FRIDAY_API hash<vector<T*>> {

public:
  /**
   * @brief Hash the vector
   * @param vec the vector
   * @return the combined hash of all the vector pointer elements
   */
  auto operator()(vector<T*> const& vec) const noexcept -> size_t;
};

/**
 * @brief A transparent string hash that works the same for strings, string views and raw strings
 */
struct FRIDAY_API transparent_string_hash {

public:
  /**
   * @brief Hash a string view
   * @param s the string view
   * @return hash value from `std::hash<string_view>{}(s)`
   */
  auto operator()(string_view s) const -> u64;

public:
  /**
   * @brief Hash a string
   * @param s the string
   * @return hash value from `std::hash<string>{}(s)`
   */
  auto operator()(string const& s) const -> u64;

public:
  /**
   * @brief Hash a raw string
   * @param s the raw string
   * @return hash value from `std::hash<string_view>{}(s)`
   */
  auto operator()(const i8* s) const -> u64;

public:
  /**
   * @brief type tag used by the standard library
   */
  struct is_transparent {};
};


#include <HashFunctions.inl>