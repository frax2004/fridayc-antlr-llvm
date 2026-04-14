#pragma once

#include "core/Common.hpp"
#include "Pointer.hpp"



namespace friday::inline core::inline memory {

  /// @brief Primary allocator struct
  struct Allocator {
    /// @brief Default empty constructor
    constexpr inline Allocator() noexcept = default;

    /// @brief Default empty destructor
    constexpr inline virtual ~Allocator() noexcept = default;

    /// @brief Allocates memory
    /// @param bytes the bytes to allocate
    /// @return pointer to the allocated memory
    virtual auto allocate(u64 bytes) noexcept -> Pointer<void> = 0;

    /// @brief Deallocates memory
    /// @param memory pointer to the allocated memory
    /// @throws `OperationNotSupportedError` instance if the allocator does not support deallocation
    virtual auto deallocate(Pointer<void> memory) -> void = 0;
  }; // struct Allocator


  /// @brief AllocatorType trait
  /// @tparam T the type to check if it is an allocator
  /// @returns `true` if
  ///
  /// - `T` has an **allocate()** method of type `(u64) -> Pointer<void>`
  /// 
  /// - `T` has a **deallocate()** method of type `(u64) -> void`
  template<class T>
  concept AllocatorType = std::derived_from<T, Allocator> or requires (T alloc, u64 bytes, Pointer<void> memory) {
    requires std::invocable<decltype(&T::allocate), u64>;
    requires std::invocable<decltype(&T::deallocate), Pointer<void>>;
    { alloc.allocate(bytes)    } -> std::convertible_to<Pointer<void>>;
    { alloc.deallocate(memory) } -> std::same_as<void>;
  }; // concept AllocatorType<T>

} // namespace friday::core::memory
