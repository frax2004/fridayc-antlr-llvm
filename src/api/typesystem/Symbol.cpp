#include "api/typesystem/Symbol.hpp"

#include "core/IO/Console.hpp"
#include "core/errors/OperationNotSupportedError.hpp"

namespace friday::inline api::inline typesystem {
  auto Symbol::getDemangledId(String const& id) -> String {
    return rtti::demangle(id.data());
  }
}
