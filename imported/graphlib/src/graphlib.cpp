#include <graphlib/directed_graph.hpp>
#include <unordered_set>
#include <ranges>


namespace graphlib {
  auto DirectedGraph::add_edge(node_type from, node_type to) -> void {
    this->M_adjacencyList[from].insert(to);
  }

  auto DirectedGraph::dfs(visitor_type visitor) -> void {
    std::unordered_set<node_type> marked;
  
    auto mark = [&marked](node_type node) { marked.insert(node); };
    auto isMarked = [&marked](node_type node) -> bool { return marked.contains(node); };
  
    auto recurse = [this, &visitor, &mark, &isMarked](this auto&& self, node_type node) {
      if(isMarked(node)) return;
      visitor(node);
      mark(node);
  
      auto it = this->M_adjacencyList.find(node);
      if(it != this->M_adjacencyList.end()) {
        for(auto& node : it->second) {
          self(node);
        }
      }
    };
  
    for(auto& [node, _] : this->M_adjacencyList) {
      if(not isMarked(node)) {
        recurse(node);
      }
    }
  }

  auto DirectedGraph::detect_cycles() -> std::vector<cycle_type> {
    std::unordered_set<node_type> marked;
    std::unordered_set<node_type> onStack;
    std::vector<node_type> path;
    std::vector<cycle_type> cycles;
  
    auto mark = [&](node_type node) { marked.insert(node); };
    auto isMarked = [&](node_type node) -> bool { return marked.contains(node); };
    auto isAncestor = [&](node_type node) -> bool { return onStack.contains(node); };
    auto visit = [&](node_type node) -> void {
      onStack.insert(node);
      path.push_back(node);
    };

    auto detectCycle = [&](this auto&& self, node_type node) -> void {
      mark(node);
      visit(node);
  
      if(this->M_adjacencyList.contains(node)) {
        for(auto vert : this->M_adjacencyList.at(node)) {
          if(isAncestor(vert)) {
            auto it = std::ranges::find(path, vert);
            cycles.emplace_back(it, path.end()).push_back(vert);
          } else if(not isMarked(vert)) {
            self(vert);
          }
        }
      }
  
      path.pop_back();
      onStack.erase(node);
    };
  
    for(auto& node : this->M_adjacencyList | std::views::keys) {
      if(not isMarked(node)) {
        detectCycle(node);
      }
    }
  
    return cycles;
  }
}