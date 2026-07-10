#ifdef __INTELLISENSE__
#include <Benchmark.hpp>
#endif


namespace friday::inline benchmark {

  template<class Func>
  auto measure(Func&& func, string label) -> string {
    auto begin = chrono::high_resolution_clock::now();
    func();
    auto end = chrono::high_resolution_clock::now();
    return format("{{ \"label\": \"{}\", \"time\": \"{}\"}}", label, chrono::duration_cast<chrono::milliseconds>(end - begin));
  }
}