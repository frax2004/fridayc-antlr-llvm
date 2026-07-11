#pragma once

#include <Core.hpp>

namespace friday::inline benchmark {

  template<class Func>
  auto measure(Func&& func, string label) -> string;
}

#include <Benchmark.inl>