#pragma once
#include <Common.hpp>

namespace friday::inline core::inline collections {
  template<class T>
  requires is_pointer_v<T>
  struct PointerGraph {
  
    private:
    unordered_map<T, set<T>> M_adjacencyList;
  
    public:
    auto addEdge(T from, T to) -> void;
    template<class Visitor>
    auto depthFirstVisit(Visitor&& visitor) -> void;
    auto getCycles() -> vector<vector<T>>;
  };
}


#include <PointerGraph.inl>
