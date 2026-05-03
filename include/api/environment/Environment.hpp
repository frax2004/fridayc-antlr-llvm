#pragma once

#include "Symbol.hpp"

namespace friday::inline api::inline environment {


  struct Namespace {
    static auto global() -> Namespace*;
    
    Namespace* M_parent;
  };


}
