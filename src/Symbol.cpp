#include "api/typechecker/Symbol.hpp"

#include "core/IO/Console.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typechecker {

  auto mangle(StringRef name) -> String {
    auto error = OperationNotSupportedError{"TODO: implement universal name mangler"};    
    Console::warning("{}\n{}"_f.format(error.what(), error.trace()));
    return String{ name };
  }
  
  auto demangle(StringRef mangledName) -> String {
    auto error = OperationNotSupportedError{"TODO: implement universal name mangler"};    
    Console::warning("{}\n{}"_f.format(error.what(), error.trace()));
    return String{ mangledName };
  }
}
