#include <fridayc.hpp>

namespace friday::api {
  using property_map = unordered_map<void*, unique_ptr<GrammarAttributes>>;
  property_map S_attributes { };
  
}