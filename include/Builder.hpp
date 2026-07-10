#pragma once

namespace friday::inline core {
  template<class T>
  struct Builder {
    virtual ~Builder() = default;
    virtual auto build() -> T = 0;
  };
}