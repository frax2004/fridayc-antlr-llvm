#ifdef __INTELLISENSE__
#include <PointerGraph.hpp>
#endif


namespace friday::inline core::inline collections {
  template<class T>
  requires is_pointer_v<T>
  template<class Visitor>
  auto PointerGraph<T>::dfs(Visitor&& visitor) -> void {
    
    unordered_set<T> marked;
  
    auto mark = [&marked](T node) { marked.insert(node); };
    auto isMarked = [&marked](T node) -> bool { return marked.contains(node); };
  
    auto recurse = [this, &visitor, &mark, &isMarked](this auto&& self, T node) {
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
  
  template<class T>
  requires is_pointer_v<T>
  auto PointerGraph<T>::add_edge(T from, T to) -> void {
    this->M_adjacencyList[from].insert(to);
  }
  
  template<class T>
  requires is_pointer_v<T>
  auto PointerGraph<T>::detect_cycles() -> vector<vector<T>> {
    unordered_set<T> marked;
    unordered_set<T> onStack;
    vector<T> path;
    vector<vector<T>> cycles;
  
    auto mark = [&](T node) { marked.insert(node); };
    auto isMarked = [&](T node) -> bool { return marked.contains(node); };
    auto isAncestor = [&](T node) -> bool { return onStack.contains(node); };
    auto visit = [&](T node) -> void {
      onStack.insert(node);
      path.push_back(node);
    };
  
    auto detectCycle = [&](this auto&& self, T node) -> void {
  
      mark(node);
      visit(node);
  
      if(this->M_adjacencyList.contains(node)) {
        for(auto vert : this->M_adjacencyList.at(node)) {
          if(isAncestor(vert)) {
            auto it = ranges::find(path, vert);
            cycles.emplace_back(it, path.end()).push_back(vert);
          } else if(not isMarked(vert)) {
            self(vert);
          }
        }
      }
  
      path.pop_back();
      onStack.erase(node);
    };
  
    for(auto& node : this->M_adjacencyList | views::keys) {
      if(not isMarked(node)) {
        detectCycle(node);
      }
    }
  
    return cycles;
  }
}
