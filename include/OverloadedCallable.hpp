#pragma once

#include <Core.hpp>

namespace friday::inline core {

  template<class... Callables>
  struct FRIDAY_API OverloadedCallable : public Callables... {
    using Callables::operator()...;
  }; 

}