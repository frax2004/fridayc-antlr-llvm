#include <fridayc.hpp>


namespace friday::inline api {
  auto Type::size() const -> u64 {
    return LLVM.size_of(this->to_llvm_type());
  }

  auto Type::alignment() const -> u64 {
    return LLVM.alignment_of(this->to_llvm_type());
  }
}