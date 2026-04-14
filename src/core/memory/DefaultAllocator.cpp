#include "core/memory/DefaultAllocator.hpp"

namespace friday::inline core::inline memory {
  auto DefaultAllocator::allocate(u64 bytes) noexcept -> Pointer<void> {
    Pointer<void> data = new byte[bytes] { 0 };
    return data;
  }

  auto DefaultAllocator::deallocate(Pointer<void> memory) -> void {
    byte* data = static_cast<byte*>(memory.get());
    delete[] data;
  }
}