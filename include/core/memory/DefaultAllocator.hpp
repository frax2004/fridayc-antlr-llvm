#pragma once

#include "Allocator.hpp"

namespace friday::inline core::inline memory {
  
  /// @brief Default operator new allocator
  struct DefaultAllocator final : public Allocator {

    /// @brief Default emtpy constructor
    constexpr inline DefaultAllocator() noexcept = default;

    /// @brief Default empty destructor
    constexpr inline virtual ~DefaultAllocator() noexcept = default;

    /// @brief Allocates memory
    /// @param bytes the bytes to allocate
    /// @return pointer to the allocated memory
    auto allocate(u64 bytes) noexcept -> Pointer<void> override;

    /// @brief Deallocates memory
    /// @param memory pointer to the allocated memory
    /// @throws `OperationNotSupportedError` instance if the allocator does not support deallocation
    auto deallocate(Pointer<void> memory) -> void override;

  }; // struct DefaultAllocator
} // namespace friday::core::memory