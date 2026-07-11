#pragma once

namespace friday::inline core {
  template<class T>
  struct FRIDAY_API Builder {
    virtual ~Builder() = default;
    virtual auto build() -> T = 0;
  };
}