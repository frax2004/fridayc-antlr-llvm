#pragma once
#include "Common.hpp"

namespace friday::inline api {
  
  struct Namespace;
  struct Type;

  struct Reflection {
  private:
    Reflection() = default;
  
  public:
    static auto reflect_namespace(Namespace* nsp) -> llvm::Value*;
    static auto reflect_type(Type* nsp) -> llvm::Value*;

  };

}