#pragma once
#include <unordered_map>
#include <set>
#include <vector>
#include <functional>



namespace graphlib {
  struct DirectedGraph final {
    using node_type = void*;
    using adjacency_list_type = std::unordered_map<node_type, std::set<node_type>>;
    using cycle_type = std::vector<node_type>;
    using visitor_type = std::function<void (node_type)>;

    private:
    adjacency_list_type M_adjacencyList { };

  public:
    auto add_edge(node_type from, node_type to) -> void;
    auto dfs(visitor_type visitor) -> void;
    auto detect_cycles() -> std::vector<cycle_type>;
  };

}