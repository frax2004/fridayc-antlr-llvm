#include "api/typechecker/Struct.hpp"

namespace friday::inline api::inline typechecker {

  auto Struct::getErrorType() -> Struct* {
    static Struct S_errorType { "<error-type>" };
    return &S_errorType;
  }
}
