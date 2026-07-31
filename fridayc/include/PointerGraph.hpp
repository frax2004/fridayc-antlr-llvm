#pragma once
#include <Common.hpp>

namespace friday::inline core::inline collections {
  template<class T>
  requires is_pointer_v<T>
  struct FRIDAY_API PointerGraph final {
  
    private:
    unordered_map<T, set<T>> M_adjacencyList { };
  
    public:
    auto add_edge(T from, T to) -> void;
    template<class Visitor>
    auto dfs(Visitor&& visitor) -> void;
    auto detect_cycles() -> vector<vector<T>>;
  };
}


#include <PointerGraph.inl>
