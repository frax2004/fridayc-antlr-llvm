#include <Symbol.hpp>

#include <Console.hpp>
#include <OperationNotSupportedError.hpp>

namespace friday::inline api::inline typesystem {
  auto ISymbol::getDemangledId(string const& id) -> string {
    return rtti::demangle(id.data())
    | views::split("::"s)
    | views::join_with("."s)
    | ranges::to<string>();
  }
  

}
