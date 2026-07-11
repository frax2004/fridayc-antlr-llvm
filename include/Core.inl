#ifdef __INTELLISENSE__
#include <Core.hpp>
#endif

template<class T>
auto hash<vector<Pointer<T>>>::operator()(vector<Pointer<T>> const& vec) const noexcept -> size_t {    
  size_t seed = vec.size();
  for(auto ptr : vec) {
    seed ^= hash<Pointer<T>>{}(ptr) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }
  return seed;
}